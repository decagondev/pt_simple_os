bootsector.bin: boot/bootsector.asm
	nasm -f bin boot/bootsector.asm -o bootsector.bin

run: bootsector.bin
	qemu-system-i386 bootsector.bin --curses