.global prob7
.text

prob7:
    movq $0, %r8 # sum
    movq $0, %r9 # i

    .l1:
        cmp %r9, %rsi
        je .l1done
        movq (%rdx, %r9, 8), %rcx
        addq %rcx, %r8
        incq %r9
        jmp .l1
    
        .l1done:
        movq %r8, %r10 # r10 = max
        decq %rdi # c counter thingy
        movq %rsi, %r9 
        decq %r9    # i = b - 1

        .l2: 
            cmp $0, %r9
            jl .returner
            movq (%rdx, %r9, 8), %rcx
            subq %rcx, %r8w
            movq (%rdx, %rdi, 8), %rcx
            addq %rcx, %r8
            cmp %r10, %r8
            jg .changemax
            decq %rdi
            decq %r9
            jmp .l2

            .changemax:
                movq %r8, %r10
                decq %rdi
                decq %r9
                jmp .l2

            .returner:
                movq %r10, %rax
                ret
