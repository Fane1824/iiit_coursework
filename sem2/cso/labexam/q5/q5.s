.global prob5
.text

prob5:
    movq $0, %r8 # c0
    movq $0, %r9 # i
    
    .l1:
        cmp %r9, %rdi
        je .l2
        movq (%rsi, %r9, 8), %r10
        cmp $0, %r10
        je .inccount
        incq %r9
        jmp .l1

        .inccount:
            incq %r8
            incq %r9
            jmp .l1

        .l2:
            movq $0, %r9
            .l2l:
                cmp %r9, %rdi
                je .end
                cmp %r8, %r9
                jl .zerosetter
                movq $1, (%rsi, %r9, 8)
                incq %r9
                jmp .l2l

                .zerosetter:
                    movq $0, (%rsi, %r9, 8)
                    incq %r9
                    jmp .l2l

                .end:
                    ret


