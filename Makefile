OUT_DIR = out
TARGET = main

SRC_DIR = src
SRC_SUBDIRS = $(SRC_DIR) $(SRC_DIR)/base $(SRC_DIR)/os

TARGET_SRC_FILE = $(SRC_DIR)/$(TARGET).c
SRC_FILES = $(foreach dir,$(SRC_SUBDIRS),$(wildcard $(dir)/*.c))
SRC_FILES_NO_MAIN = $(filter-out $(TARGET_SRC_FILE), $(SRC_FILES))

INC_SUBDIRS = $(foreach dir,$(SRC_SUBDIRS),-I$(dir))

CFLAGS = -O3 -Wall -lSDL2_ttf $(INC_SUBDIRS) -g -rdynamic


all: $(OUT_DIR)/$(TARGET)

test:
	@echo $(SRC_FILES_NO_MAIN)

clean:
	rm -rf $(OUT_DIR)

format:
	clang-format -i $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.h)

$(OUT_DIR):
	mkdir -p $@

# symlink the assets to the out folder to executable can find it easily
$(OUT_DIR)/firacode.ttf: assets/firacode.ttf
	ln -s $(realpath $<) $@

$(OUT_DIR)/$(TARGET): $(TARGET_SRC_FILE) $(SRC_FILES_NO_MAIN) | $(OUT_DIR)
	gcc -o $@ $^ `sdl2-config --cflags --libs` $(CFLAGS) 

.PHONY: test clean format

