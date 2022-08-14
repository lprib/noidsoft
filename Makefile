OUT_DIR = out
TARGET = main

SRC_DIR = src
SRC_SUBDIRS = $(SRC_DIR) $(SRC_DIR)/base $(SRC_DIR)/mmi $(SRC_DIR)/ui 

TARGET_SRC_FILE = $(SRC_DIR)/$(TARGET).c
SRC_FILES = $(foreach dir,$(SRC_SUBDIRS),$(wildcard $(dir)/*.c))
SRC_FILES_NO_MAIN = $(filter-out $(TARGET_SRC_FILE), $(SRC_FILES))


CFLAGS = -O3 -Wall -lSDL2_ttf -Isrc -g -rdynamic


all: $(OUT_DIR)/$(TARGET)

clean:
	rm -rf $(OUT_DIR)

$(OUT_DIR):
	mkdir -p $@

# Just put everything in to one big GCC compilation unit for now.
$(OUT_DIR)/$(TARGET): $(TARGET_SRC_FILE) $(SRC_FILES_NO_MAIN) | $(OUT_DIR)
	gcc -o $@ $^ `sdl2-config --cflags --libs` $(CFLAGS) 

.PHONY: test clean format

