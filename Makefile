OUT_DIR = out

SRC_DIR = src
GENERIC_SUBDIRS = $(SRC_DIR)/base $(SRC_DIR)/mmi $(SRC_DIR)/ui

LINUX_TARGET = $(OUT_DIR)/main_linux
LINUX_TARGET_SRC_FILE = $(SRC_DIR)/linux/main.c

LINUX_SUBDIRS = $(GENERIC_SUBDIRS) $(SRC_DIR)/linux
LINUX_SRC_FILES = $(foreach dir,$(LINUX_SUBDIRS),$(wildcard $(dir)/*.c))
LINUX_SRC_FILES_NO_MAIN = $(filter-out $(LINUX_TARGET_SRC_FILE), $(LINUX_SRC_FILES))

AVR_MCU = atmega2560
AVR_TTY = /dev/ttyUSB0
AVR_PROGRAMMER = wiring
AVR_BAUD = 115200

AVR_TARGET = $(OUT_DIR)/main_avr.o
AVR_TARGET_SRC_FILE = $(SRC_DIR)/avr/main.c

AVR_SUBDIRS = $(GENERIC_SUBDIRS) $(SRC_DIR)/avr
AVR_SRC_FILES = $(foreach dir,$(AVR_SUBDIRS),$(wildcard $(dir)/*.c))
AVR_SRC_FILES_NO_MAIN = $(filter-out $(AVR_TARGET_SRC_FILE), $(AVR_SRC_FILES))

COMMON_CFLAGS = -Isrc -Wall
# Need -Wno-array-bounds because gcc complains about volatile register read/writes
AVR_CFLAGS = $(COMMON_CFLAGS) -O3 -mmcu=$(AVR_MCU) -Wno-array-bounds
LINUX_CFLAGS = $(COMMON_CFLAGS) -O3 -lSDL2_ttf -g -rdynamic `sdl2-config --cflags --libs`


linux: $(LINUX_TARGET)
run: linux
	./$(LINUX_TARGET)


avr: $(AVR_TARGET)
program: avr
	avrdude -p$(AVR_MCU) -c$(AVR_PROGRAMMER) -P$(AVR_TTY) -b$(AVR_BAUD) -D -Uflash:w:$(AVR_TARGET)
com:
	picocom -b9600 --imap lfcrlf $(AVR_TTY)

clean:
	rm -rf $(OUT_DIR)

$(OUT_DIR):
	mkdir -p $@

# Just put everything in to one big GCC compilation unit for now.
$(LINUX_TARGET): $(LINUX_TARGET_SRC_FILE) $(LINUX_SRC_FILES_NO_MAIN) | $(OUT_DIR)
	gcc -o$@ $^ $(LINUX_CFLAGS)

$(AVR_TARGET): $(AVR_TARGET_SRC_FILE) $(AVR_SRC_FILES_NO_MAIN) | $(OUT_DIR)
	avr-gcc -o$@ $^ $(AVR_CFLAGS)

.PHONY: linux run avr program com clean

