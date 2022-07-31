OUT_DIR = out
SRC_DIR = src
TARGET = main

OTHER_SRC_FILES = $(filter-out $(SRC_DIR)/$(TARGET).c, $(wildcard $(SRC_DIR)/*.c))

CFLAGS=-Isrc -O3 -Wall -lSDL2_ttf


all: $(OUT_DIR)/$(TARGET)

test:
	@echo $(OTHER_SRC_FILES)

clean:
	rm -rf $(OUT_DIR)

format:
	clang-format -i $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.h)

$(OUT_DIR):
	mkdir -p $@

# symlink the assets to the out folder to executable can find it easily
$(OUT_DIR)/firacode.ttf: assets/firacode.ttf
	ln -s $(realpath $<) $@

$(OUT_DIR)/$(TARGET): $(SRC_DIR)/main.c $(OTHER_SRC_FILES) | $(OUT_DIR)
	gcc -o $@ $^ `sdl2-config --cflags --libs` $(CFLAGS) 

.PHONY: test clean format

