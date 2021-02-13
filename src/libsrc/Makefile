TARGET := libdasample.so
CC := gcc
CFLAGS := -fPIC
LD := ld
LDLIBS := -lsqlite3 -lparson
LDFLAGS := -shared
DESTLIB  =  /usr/local/lib
DESTINC  =  /usr/local/include

SRCS := refer.c existFile.c referSingleData.c referArrayData.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET).1.0

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

$(TARGET).1.0: $(OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) -soname $(TARGET).1 -o $@

clean:
	rm -f *.o *.so

install:  all
	install $(TARGET).1.0 $(DESTLIB)
	ldconfig $(DESTLIB)
	ln -f -s -r $(DESTLIB)/$(TARGET).1 $(DESTLIB)/$(TARGET)
	install -m 0644 ../../include/libdasample.h $(DESTINC)
