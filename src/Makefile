# $@ = target file
# $< = first dep
# $^ = all deps

# constants
CC = i686-elf-gcc
LD = i686-elf-ld
LDFLAGS = -Ttext 0x1000
LDFORMAT = --oformat binary
GDB = i686-elf-gdb

CFLAGS = -g -ffreestanding

bootsector.bin: boot/bootsector.asm
	nasm -f bin $< -o $@

kernel.o: kernel/kernel.c
	# call a croos compiler with some options outputing the kernel.o file
	${CC} ${CFLAGS} -c $< -o $@

sys.o: drivers/sys.c
	# call a croos compiler with some options outputing the sys.o file
	${CC} ${CFLAGS} -c $< -o $@

vga.o: drivers/vga.c
	# call a croos compiler with some options outputing the vga.o file
	${CC} ${CFLAGS} -c $< -o $@

utils.o: kernel/utils.c
	# call a croos compiler with some options outputing the vga.o file
	${CC} ${CFLAGS} -c $< -o $@

kernel_entry.o: boot/kernel_entry.asm
	nasm -f elf $< -o $@

rustkern.o: kernel/rustkern.rs
	rustc $< --emit=obj --target=i686-unknown-linux-gnu

stringy.o: kernel/stringy.cpp
	i686-elf-g++ -c $< -o $@ -ffreestanding

kernel.bin: kernel_entry.o kernel.o sys.o utils.o rustkern.o stringy.o vga.o
	${LD} -o $@ ${LDFLAGS} $^ ${LDFORMAT}

os.bin: bootsector.bin kernel.bin
	cat $^ > $@

run: os.bin
	qemu-system-i386 $< --curses

clean: *.bin *.o
	rm *.bin *.o