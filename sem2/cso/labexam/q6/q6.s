.global prob6
.text

prob6:
    movq %rdi, %rax
    cmp $0, %rsi
    je .end
    cqto
    idivq %rsi
    movq %rsi, %rdi
    movq %rdx, %rsi
    jmp prob6

    .end:
        ret