CC = c89
CFLAGS = -Wall -Wextra -Wpedantic -O3
PREFIX = ~/.local

build/coin-count: src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -vrf build

install: build/coin-count
	cp $^ $(PREFIX)/bin/

.PHONY: clean install
