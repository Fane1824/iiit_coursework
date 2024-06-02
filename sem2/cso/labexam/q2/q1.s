.global prob2
.text

prob2:
    movq $0, %r8 # i
    movq $0, %r9 # cnt
    movq $2, %r11
    
    .l1:
        cmp $0, %rdi
        je .checker
        movq (%rsi, %r8, 8), %r10
        movq %rdi, %rax
        cqto
        idivq %r11
        movq %rdx, %r10
        movq %rax, %rdi
        incq %r8
        cmp $1, %r10
        je .inccount
        jmp .l1

        .inccount:
            incq %r9
            jmp .l1

        .checker:
            movq %r9, %rax
            cqto
            idivq %r11
            cmp $1, %rdx
            je .returnone
            movq $0, %rax
            ret

            .returnone:
                movq $1, %rax
                ret