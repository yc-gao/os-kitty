qemu:
	make -C kernel
	qemu-system-i386 -cdrom kernel/kernel.iso

clean:
	make -C kernel clean