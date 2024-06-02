.global prob11
.text

prob11:
    pushq %r12
    pushq %r13
    movq $0, %r8 # total
    movq $0, %r9 # i 
    .l1:
        cmp %r9, %rdi
        je .donefor
        movq (%rsi, %r9, 8), %r10
        cmp $1, %r10
        je .rightadder
        addq %r9, %r8
        incq %r9
        jmp .l1

        .rightadder:
            addq %rdi, %r8
            decq %r8
            subq %r9, %r8
            incq %r9
            jmp .l1
    
    .donefor:
        movq $0, %r10 # l = 0
        movq %rdi, %r11
        decq %r11 # r = n-1
        movq $0, %rcx # count
        .while:
            cmp %r11, %r10
            jg .newfor
            movq (%rsi, %r10, 8), %r12
            cmp $0, %r12
            je .cond1
            movq (%rsi, %r11, 8), %r12
            cmp $1, %r12 
            je .cond2
            incq %r10
            decq %r11
            jmp .while

            .cond1:
                subq %r10, %r8
                addq %rdi, %r8
                subq %r10, %r8
                decq %r8
                movq %r8, (%rdx, %rcx, 8)
                incq %rcx
                movq (%rsi, %r11, 8), %r12
                cmp $1, %r12 
                je .cond2
                incq %r10
                decq %r11
                jmp .while
            
            .cond2:
                addq %r11, %r8
                subq %rdi, %r8
                incq %r8
                addq %r11, %r8
                movq %r8, (%rdx, %rcx, 8)
                incq %rcx
                incq %r10
                decq %r11
                jmp .while
        
        .newfor:
            movq %rcx, %r9 # i
            .finalfor:
                cmp %r9, %rdi
                je .end
                movq %r8, (%rdx, %r9, 8)
                incq %r9
                jmp .finalfor

                .end:
                    popq %r13
                    popq %r12
                    ret
                
