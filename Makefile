OUT_DIR = out

SRC_DIR = src
GENERIC_SUBDIRS = $(SRC_DIR)/base $(SRC_DIR)/mmi $(SRC_DIR)/ui

LINUX_TARGET = $(OUT_DIR)/main_linux
LINUX_TARGET_SRC_FILE = $(SRC_DIR)/linux/main.c

LINUX_SUBDIRS = $(GENERIC_SUBDIRS) $(SRC_DIR)/linux
LINUX_SRC_FILES = $(foreach dir,$(LINUX_SUBDIRS),$(wildcard $(dir)/*.c))
LINUX_SRC_FILES_NO_MAIN = $(filter-out $(LINUX_TARGET_SRC_FILE), $(LINUX_SRC_FILES))
LINUX_CFLAGS = -O3 -Wall -lSDL2_ttf -Isrc -g -rdynamic

linux: $(LINUX_TARGET)

run: linux
	./$(LINUX_TARGET)

clean:
	rm -rf $(OUT_DIR)

$(OUT_DIR):
	mkdir -p $@

# Just put everything in to one big GCC compilation unit for now.
$(LINUX_TARGET): $(LINUX_TARGET_SRC_FILE) $(LINUX_SRC_FILES_NO_MAIN) | $(OUT_DIR)
	gcc -o $@ $^ `sdl2-config --cflags --libs` $(LINUX_CFLAGS) 

.PHONY: test clean format

