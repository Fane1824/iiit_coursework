.global prob4
.text

prob4:
    movq %rdi, %rsi # a = n
    movq $0, %r8    # b = 0
    movq $10, %r9
    .while:
        cmp $0, %rsi
        je .checker
        
        movq %rsi, %rax
        cqto
        idivq %r9
        movq %rax, %rsi
        movq %rdx, %r10 # a mod 10
        imulq $10, %r8
        addq %r10, %r8
        jmp .while
    
        .checker:
            cmp %rdi, %r8
            je .retone
            movq $0, %rax
            ret

            .retone:
                movq $1, %rax
                ret