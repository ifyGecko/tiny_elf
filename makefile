default:
	make tiny_asm
	make tiny_c
	make elf32_hex_dump

tiny_asm: tiny.s
	as --32 tiny.s -o tiny_asm.o
	ld.bfd -T tiny.lds --nmagic -m elf_i386 --strip-all tiny_asm.o -o tiny_asm

tiny_c: tiny.c
	gcc -fno-ident -fno-asynchronous-unwind-tables -Os -nostdlib -m32 -c tiny.c -o tiny_c.o
	ld.bfd -T tiny.lds --nmagic -m elf_i386 --strip-all tiny_c.o -o tiny_c

elf32_hex_dump: elf32_hex_dump.c
	gcc elf32_hex_dump.c -o elf32_hex_dump

clean:
	rm -f tiny_asm.o tiny_c.o elf32_hex_dump tiny_asm tiny_c *~ \#*
