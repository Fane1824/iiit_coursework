.global postfix
.text

postfix:
    movq $0, %rcx     # intializes variable i to 1

    .forloop:
        cmp %rcx, %rsi  # comparing the length with i. If they are are not equal, do not enter the for loop
        je .end # jumping to end code block if they are equal
        movb (%rdi, %rcx, 1), %r8b   # moves the ith element of the input array into a temporary storage register
        cmp $43, %r8b   # comparing the ith element of the input array with ASCII value of '+'. If they are not equal, check for the next condition
        je .c1  # jumping to c1 code block if they are equal
        cmp $45, %r8b   # comparing the ith element of the input array with ASCII value of '-'. If they are not equal, check for the next condition
        je .c2  # jumping to c2 code block if they are equal
        cmp $42, %r8b   # comparing the ith element of the input array with ASCII value of '*'. If they are not equal, check for the next condition
        je .c3  # jumping to c3 code block if they are equal
        cmp $47, %r8b   # comparing the ith element of the input array with ASCII value of '/'. If they are not equal, convert the value to an integer
        je .c4  # jumping to c4 code block if they are equal
        sub $48, %r8b   # converting ASCII digit to integer value
        pushq %r8   # pushes the integer value onto the system stack
        incq %rcx   # incrementing value of i
        jmp .forloop    # looping back to the start of the forloop code block

        .c1:                            
            popq %r9    # pops the top value from system stack into a temporary storage register
            popq %r10   # pops the top value from system stack into a temporary storage register
            addq %r9, %r10  # adds the two popped values and stores the sum in the second temporary storage register
            pushq %r10  # pushes the result value back onto the system stack
            incq %rcx   # incrementing value of i
            jmp .forloop    # looping back to the start of the forloop code block

        .c2:                           
            popq %r9    # pops the top value from system stack into a temporary storage register
            popq %r10   # pops the top value from system stack into a temporary storage register
            subq %r9, %r10  # adds the two popped values and stores the difference in the second temporary storage register
            pushq %r10  # pushes the result value back onto the system stack
            incq %rcx   # incrementing value of i
            jmp .forloop    # looping back to the start of the forloop code block
            
        .c3:                           
            popq %r9    # pops the top value from system stack into a temporary storage register
            popq %r10   # pops the top value from system stack into a temporary storage register
            imulq %r9, %r10 # multiplies the two popped values and stores the product in the second temporary storage register
            pushq %r10  # pushes the result value back onto the system stack
            incq %rcx   # incrementing value of i
            jmp .forloop    # looping back to the start of the forloop code block

        .c4:                          
            popq %r9    # pops the top value from system stack into a temporary storage register
            pop %r10    # pops the top value from system stack into a temporary storage register
            mov %r10, %rax  # moves the dividend value to the return register for division
            cqto # sign extending into the remainder register for division
            idivq %r9   # divides the value of the return register with r9
            pushq %rax  # pushes the result value back onto the system stack
            movq $0, %rdx # setting the value of the return register to 0
            incq %rcx   # incrementing value of i
            jmp .forloop    # looping back to the start of the forloop code block

        .end:
            popq %rax   # pops the result from the system stack into the return register
            ret # returning value in %rax
