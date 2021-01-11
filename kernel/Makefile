CFLAGS?=-ffreestanding -O2 -m32
CPPFLAGS?=
LDFLAGS?=-nostdlib

all: kernel.iso

OBJS+=main.o \
terminal.o \
string.o

BOOT_DIR=boot
include $(BOOT_DIR)/Makefile

.c.o:
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^

.s.o:
	$(CC) -o $@ -c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^

kernel.bin: boot/link.ld $(OBJS)
	$(CC) -o $@ -T$< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS)

kernel.iso: kernel.bin
	grub-file --is-x86-multiboot $^
	rm -rf isodir
	mkdir -p isodir/boot/grub
	cp $< isodir/boot/
	echo "menuentry \"os\" {\n    multiboot /boot/$^\n}" > isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir
	rm -rf isodir

clean:
	rm -rf kernel.iso kernel.bin $(OBJS)
