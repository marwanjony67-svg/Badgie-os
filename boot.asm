[BITS 16]
[ORG 0x7C00]

start:
    mov ax, 0x07C0
    mov ds, ax
    mov si, welcome_msg
    call print_string

hang:
    jmp $

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

welcome_msg db 'Loading BudgieOS Kernel...', 0
times 510-($-$$) db 0
dw 0xAA55
