# $@ = target file
# $< = first dep
# $^ = all deps

bootsector.bin: boot/bootsector.asm
	nasm -f bin $< -o $@

run: bootsector.bin
	qemu-system-i386 $< --curses

clean: *.bin
	rm *.bin