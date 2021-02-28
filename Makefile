TARGET ?= nucleus
SRC_DIRS ?= ./src ./lib
CC = clang
SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
LDLIBS =  -lSDL2 -lSDL2_image -lSDL2_ttf

CFLAGS ?= -ansi -Wall -Werror -D_DEFAULT_SOURCE -Isrc/ -Ilib/

%.o: %.c
	@echo [ CC ] $<
	@$(CC) $(CFLAGS) -c $< -o $@
$(TARGET): $(OBJS)

	@echo [ BIN ] $<
	@$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBS) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) 

