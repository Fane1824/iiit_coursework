.global prob3
.text

prob3:
    movq $0, %r8
    movq $1, %r9
    movq $3, %r10
    movq $5, %r11

    .l1:
        cmp %r8, %rdi
        je .end
        movq %r9, %rax
        cqto
        idivq %r10
        cmp $0, %rdx
        je .divbythree
        movq %r9, %rax
        cqto
        idivq %r11   
        cmp $0, %rdx
        je .divbyfive
        movq %r9, (%rsi, %r8, 8)
        incq %r8
        incq %r9
        jmp .l1

        .divbythree:
            movq %r9, %rax
            cqto
            idivq %r11   
            cmp $0, %rdx
            je .divbyboth
            movq $-1, (%rsi, %r8, 8)
            incq %r8
            incq %r9
            jmp .l1   

            .divbyboth:
                movq $-3, (%rsi, %r8, 8)
                incq %r8
                incq %r9
                jmp .l1                

        .divbyfive:
            movq $-2, (%rsi, %r8, 8)
            incq %r8
            incq %r9
            jmp .l1  

        .end:
            ret