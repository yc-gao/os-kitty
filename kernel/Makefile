CFLAGS?=-ffreestanding -O2 -m32
CPPFLAGS?=
LDFLAGS?=-nostdlib

all: kernel.bin

OBJS+=main.o

BOOT_DIR=boot
include $(BOOT_DIR)/Makefile

.c.o:
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^

.s.o:
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^

kernel.bin: boot/link.ld $(OBJS)
	$(CC) -o $@ -T$< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS)


clean:
	rm -rf kernel.bin $(OBJS)
