CC=gcc
RM=rm
CFLAGS+=-O0 -g -Wall
TARGET=menu.exe
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SOURCES))

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJS) $(TARGET)
