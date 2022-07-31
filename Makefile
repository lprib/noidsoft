OUT_DIR = out
SRC_DIR = src
TARGET = main

OTHER_SRC_FILES = $(filter-out $(SRC_DIR)/$(TARGET).c, $(wildcard $(SRC_DIR)/*.c))

CFLAGS=-Isrc -O3 -Wall


all: $(OUT_DIR)/$(TARGET)

test:
	@echo $(OTHER_SRC_FILES)

clean:
	rm -rf $(OUT_DIR)

$(OUT_DIR):
	mkdir -p $@

$(OUT_DIR)/$(TARGET): $(SRC_DIR)/main.c $(OTHER_SRC_FILES) | $(OUT_DIR)
	gcc -o $@ $^ $(CFLAGS) `sdl2-config --cflags --libs`

.PHONY: test clean

