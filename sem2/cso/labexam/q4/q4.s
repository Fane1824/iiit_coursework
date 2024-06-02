.global lenfinder
.global prob4
.text

lenfinder:
    movq $0, %r8 # ci
    movq $10, %r9
    
    .l1:
        cmp $0, %rdi
        je .returner
        movq %rdi, %rax
        cqto
        idivq %r9
        movq %rax, %rdi
        incq %r8
        jmp .l1
        
        .returner:
            movq %r8, %rax
            ret

prob4:
    pushq %r12
    pushq %r13
    movq %rdi, %r8 # a
    movq $0, %r9 # i 
    movq %rdx, %r10
    movq $10, %r11

    .l4:
        cmp $0, %r8
        je .l2
        movq %r8, %rax
        cqto
        idivq %r11
        movq %rdx, (%rsi, %r9, 8)
        movq %rax, %r8
        incq %r9
        jmp .l4

        .l2:
            movq $0, %r9 # i 
            movq %r10, %r8 # n/2
            sarq %r8
            .l3:
                cmp %r9, %r8
                je .retone
                movq (%rsi, %r9, 8), %r12
                decq %r10
                movq (%rsi, %r10, 8), %r13
                cmp %r12, %r13
                jne .retzero
                incq %r9
                jmp .l3

                .retzero:
                    popq %r13
                    popq %r12
                    movq $0, %rax
                    ret                    

                .retone:
                    popq %r13
                    popq %r12
                    movq $1, %rax
                    ret
