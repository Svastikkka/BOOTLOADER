# BOOTLOADER

### Commands
```bash
# Need to go further
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -ffreestanding -c boot.c -o boot.o.c
ld -m elf_i386 -T link.ld -o boot.bin boot.o boot.o.c --oformat binary
qemu-system-i386 -drive format=raw,file=boot.bin
dd if=boot.bin of=boot.img bs=512 count=1
```
