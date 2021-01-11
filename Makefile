qemu: kernel.iso
	qemu-system-i386 -cdrom $^

kernel/kernel.bin:
	make -C kernel

kernel.iso: kernel/kernel.bin
	grub-file --is-x86-multiboot $^
	rm -rf isodir
	mkdir -p isodir/boot/grub
	mkdir -p isodir/boot/kernel
	cp $< isodir/boot/kernel
	echo "menuentry \"os\" {\n    multiboot /boot/$^\n}" > isodir/boot/grub/grub.cfg
	grub-mkrescue -o $@ isodir
	rm -rf isodir

clean:
	rm -rf kernel.iso
	make -C kernel clean