[org 0x7C00]
bits 16

extern c_main   ; C function

start:
    cli                 ; Disable interrupts
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00      ; Setup stack

    sti                 ; Enable interrupts

    call c_main         ; Jump to C code

hang:
    jmp hang            ; Infinite loop

times 510-($-$$) db 0   ; Fill remaining bytes
dw 0xAA55               ; Boot signature