# $@ = target file
# $< = first dep
# $^ = all deps

# constants
CC = gcc
GDB = gdb

CFLAGS = -g -ffreestanding

bootsector.bin: boot/bootsector.asm
	nasm -f bin $< -o $@

kernel.o: kernel/kernel.c
	# call a croos compiler with some options outputing the kernel.o file
	${CC} ${CFLAGS} -c $< -o $@

run: bootsector.bin
	qemu-system-i386 $< --curses

clean: *.bin
	rm *.bin