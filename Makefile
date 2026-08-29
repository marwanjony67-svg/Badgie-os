CC = g++
ASM = nasm
CFLAGS = -m32 -fno-builtin -nostdlib -fno-exceptions -fno-rtti

all: budgie.iso

boot.bin: boot.asm
	$(asm) -f bin boot.asm -o boot.bin

kernel.o: kernel.cpp
	$(CC) $(CFLAGS) -c kernel.cpp -o kernel.o

clean:
	rm -rf *.o *.bin *.iso
