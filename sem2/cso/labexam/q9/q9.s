.global prob9
.text

prob9:
    movq (%rsi), %rcx # rcx is max
    movq $1, %r8 # i
    .preloop:
        cmp %r8, %rdi
        je .l1cond
        movq (%rsi, %r8, 8), %r9
        cmp %rcx, %r9             
        jg .updatemax  
        incq %r8
        jmp .preloop

        .updatemax:
            movq %rcx, %r9
            incq %r8
            jmp .preloop
    
    .l1cond:
        movq $1, %r8
        jmp .l1
        
    .l1:
        cmp %r8, %rcx
        je .returnn
        movq $0, %r9 # found
        movq $0, %r10 # j
        .l2:
            cmp %r10, %rdi
            je .findchecker
            movq (%rsi, %r10, 8), %r11
            cmp %r11, %r8
            je .foundupdater
            incq %r10
            jmp .l2

            .foundupdater:
                movq $1, %r9
                jmp .findchecker
            
            .findchecker:
                incq %r8
                cmp $0, %r9
                jne .l1
                decq %r8
                movq %r8, %rax
                ret
            


        .returnn:
            movq %rcx, %rax
            incq %rax
            ret