.global prob10
.text

prob10:
    movq $0, %r8 # ceven
    movq $0, %r9 # codd
    movq $0, %r10 # i
    movq $2, %rcx # 2
    
    .l1:
        cmp %rdi, %r10
        je .lcheck
        movq (%rsi, %r10, 8), %r11
        movq %r11, %rax
        cqto
        idivq %rcx
        cmp $1, %rdx
        je .oddc
        incq %r8
        incq %r10
        jmp .l1

        .oddc:
            incq %r9
            incq %r10
            jmp .l1
        
        .lcheck:
            cmp $0, %r8
            je .ender
            cmp $0, %r9
            je .ender
            movq $0, %r10 # i
            decq %rdi # n - 1
            jmp .for1

            .ender:
                ret

            .for1:
                cmp %r10, %rdi
                je .end
                movq $0, %r8 # j
                .for2:
                    incq %r10
                    cmp %r8, %rdi
                    je .for1
                    decq %r10
                    movq (%rsi, %r8, 8), %r9 # arr[j]
                    incq %r8
                    movq (%rsi, %r8, 8), %rcx # arr[j+1]
                    decq %r8
                    cmp %rcx, %r9
                    jg .update 
                    incq %r8
                    jmp .for2

                    .update:
                        movq %rcx, (%rsi, %r8, 8)
                        incq %r8
                        movq %r9, (%rsi, %r8, 8)
                        jmp .for2  

            .end:
                ret                      

