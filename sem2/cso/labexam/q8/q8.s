.global prob8
.text

prob8:
    movq $0, %r8 # i
    decq %rdi
    .l1:
        cmp %rdi, %r8 
        je .nextloop
        movq $0, %r9 # j
        .l2:
            incq %r8
            cmp %rdi, %r9
            je .l1  
            decq %r8  
            movq (%rsi, %r9, 8), %r10   # arr[j]
            incq %r9
            movq (%rsi, %r9, 8), %r11   # arr[j+1]
            decq %r9
            cmp %r11, %r10
            jg .changer
            incq %r9
            jmp .l2

            .changer:
                movq %r11, (%rsi, %r9, 8)
                incq %r9
                movq %r10, (%rsi, %r9, 8)
                jmp .l2
            
        .nextloop:
            movq $0, %r8 # i
            incq %rdi
            .l3:
                cmp %rdi, %r8
                jge .end
                incq %r8
                cmp %r8, %rdi
                jg .ifstatement
                decq %r8
                addq $2, %r8
                jmp .l3

                .ifstatement:
                    decq %r8
                    movq (%rsi, %r8, 8), %r10   # arr[j]
                    incq %r8
                    movq (%rsi, %r8, 8), %r11   # arr[j+1]
                    decq %r8         
                    movq %r11, (%rsi, %r8, 8)
                    incq %r8
                    movq %r10, (%rsi, %r8, 8) 
                    decq %r8                   
                    addq $2, %r8
                    jmp .l3                

                .end:
                    ret

