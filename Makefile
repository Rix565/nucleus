TARGET ?= nucleus
SRC_DIRS ?= ./src
CC = clang
SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(addsuffix .o,$(basename $(SRCS)))
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

CFLAGS ?= -ansi -Wall -Werror

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBS) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) 

