.global scores
.text

scores:
    movq $0, %rcx   # setting the value of i to 0
    movq $-1, %r11  # setting the value of stack top pointer to -1
    movq $0, %rax   # setting the value of the return register to 0
    pushq %r12  # saves current value of r13 (calle save register)
    pushq %r13  # saves current value of r13 (calle save register)

    .forloop:
        cmp %rcx, %rsi  # comparing the value of i with n. If they are not equal, enter the loop
        je .end # jumping to end code block if the value of i is equal to the value of n
        movb (%rdi, %rcx, 1), %r8b  # stores the value of the ith element of the character array in a temporary storage register
        cmp $68, %r8b   # comparing the ith element of the array with ASCII value of 'D'. If they are not equal, check for the next condition
        je .c1  # jumping to c1 code block if they are equal
        cmp $67, %r8b   # comparing the ith element of the array with ASCII value of 'C'. If they are not equal, check for the next condition
        je .c2  # jumping to c2 code block if they are equal
        cmp $43, %r8b   # comparing the ith element of the array with ASCII value of '+'. If they are not equal, convert the value to an integer
        je .c3  # jumping to c3 code block if they are equal
        sub $48, %r8b   # converting ASCII digit to integer value
        movzbq %r8b, %r9    # moves with zero extension from byte to quad
        incq %r11   # increments the value of the stack top pointer
        movq %r9, (%rdx, %r11, 8)   # pushes the value of the recorded score to the stack
        addq %r9, %rax  # adds the recorded score to the sum and stores it in the return register
        incq %rcx   # increments the value of i
        jmp .forloop    # looping back to the start of the forloop code block
            
            .c1:
                movq (%rdx, %r11, 8), %r12  # pops the score from the stack and stores it in a temporary storage register
                salq $1, %r12   # multiplies the score by 2 
                incq %r11   # increments the value of the stack top pointer
                movq %r12, (%rdx, %r11, 8)  # pushes the new score to the stack
                addq %r12, %rax # adds the recorded score to the sum and stores it in the return register 
                incq %rcx   # increments the value of i
                jmp .forloop    # looping back to the start of the forloop code block

            .c2:
                movq (%rdx, %r11, 8), %r12 # pops the score from the stack and stores it in a temporary storage register
                subq %r12, %rax # subtracts the recorded score from the sum and stores the difference in the return register
                incq %rcx   # increments the value of i
                decq %r11   # decrements the value of the stack top pointer   
                jmp .forloop    # looping back to the start of the forloop code block

            .c3:
                movq (%rdx, %r11, 8), %r12 # pops the score from the stack and stores it in a temporary storage register
                decq %r11   # decrements the value of the stack top pointer
                movq (%rdx, %r11, 8), %r13  # pops a score from the stack and stores it in a temporary storage register
                addq %r12, %r13 # adds the two popped values and stores the sum in a temporary storage register
                addq %r13, %rax # adds the recorded score to the sum and stores it in the return register
                addq $2, %r11   # adds 2 to the stack top pointer and stores the sum in the register storing the stack top pointer
                movq %r13, (%rdx, %r11, 8)  # pushes the new score to the stack
                incq %rcx   # increments the value of i
                jmp .forloop    # looping back to the start of the forloop code block
        
        .end:
            popq %r13   # popping value of r13 (calle save register)
            popq %r12   # popping back value of r12 (calle save register)
            ret # returning value in %rax