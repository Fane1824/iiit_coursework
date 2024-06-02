.global prob1
.text

prob1:
    cmp $1, %rdx
    je .add
    cmp $2, %rdx
    je .subtract
    cmp $3, %rdx
    je .divide
    cmp $4, %rdx
    je .multiply
    movq %rdi, %rax
    cqto
    idivq %rsi
    movq %rdx, %rax
    ret

    .add:
        addq %rdi, %rsi
        movq %rsi, %rax
        ret

    .subtract:
        subq %rsi, %rdi
        movq %rdi, %rax
        ret

    .divide:
        movq %rdi, %rax
        cqto
        idivq %rsi
        ret

    .multiply:
        movq $1, %r8
        movq $0, %r9
        .l1:
            cmp %r9, %rsi
            je .end
            imulq %rdi, %r8
            incq %r9
            jmp .l1

            .end:
                movq %r8, %rax
                ret