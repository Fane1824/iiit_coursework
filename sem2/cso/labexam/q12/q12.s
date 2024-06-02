.global prob12
.text

prob12:
    cmp $0, %rdi
    je .retzero
    movq %rdi, %rsi # a = n
    movq $0, %r8 # sum = 0
    movq $10, %r9 # 10
    
    .l1:
        cmp $0, %rsi
        je .sumchecker
        movq %rsi, %rax
        cqto
        idivq %r9
        movq %rdx, %r10 # temp
        movq %rax, %rsi
        movq $1, %r11 # temp2
        .l2: 
            cmp $0, %r10
            je .restarter
            decq %r10
            cmp $0, %r10
            je .restarter
            incq %r10
            imulq %r10, %r11
            decq %r10
            jmp .l2

        .restarter:
            addq %r11, %r8
            jmp .l1
        
        .sumchecker:
            cmp %rdi, %r8
            jne .retzero
            movq $1, %rax
            ret           

    .retzero:
        movq $0, %rax
        ret