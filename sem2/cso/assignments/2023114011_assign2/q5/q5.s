.global binary_search
.text

binary_search:
    movq $0, %r8    # intializes variable left to 0
    movq $31, %r9   # intializes variable right to 31
    
    .whileloop:
        cmp %r9, %r8    # comparing the value of left with right. If left is less than or equal to right, we want the loop to keep iterating
        jg .end     # jumping to end code block if left is greater than right
        movq %r9, %r10  # moves the value of right to a temporary storage register
        movq %r8, %r11  # moves the value of left to a temporary storage register
        addq %r10, %r11 # adds the value of left to right and stores the sum in a temporary storage register
        sarq $1, %r11   # divides the value of the sum of left and right by 2 (this register now stores the value for mid)
        movq (%rdi, %r11, 8), %r10  # stores the value of the mid-th element of L in a temporary storage register 
        cmp %r10, %rsi  #   compares L[mid] with the key value.  
        je .equal   # jumping to equal code block if L[mid] equals to key
        jg .lessthan    # jumping to lessthan code block if L[mid] is less than key
        movq %r11, %r9  # stores the value of mid in a temporary storage register
        decq %r9    # decrements the value of the temporary storage register (ie. mid - 1)
        incq (%rdx) # increments the counter of the number of iterations
        jmp .whileloop  # looping back to the start of the whileloop code block

        .equal:
            cmp $0, %r11    # comparing the value of mid with 0. If mid is less than or equal to zero, do not check for the next condition and do not enter the loop
            jg .l2  # jumping to l2 code block if mid is greater than zero 
            incq (%rdx)     # increments the counter of the number of iterations 
            movq %r11, %rax # setting the value of return register to mid
            ret     # returning value in %rax
            .l2:
                decq %r11   # increments the value of mid 
                movq (%rdi, %r11, 8), %r8   # stores the value of the mid-1th element of L in a temporary storage register
                incq %r11   # decrements the value of mid
                cmp %r8, %rsi   # compares the value of the mid-1th element of L with the key value. If they are not equal, do not enter the loop
                je .l3  # jumping to l3 code block if L[mid - 1] is equal to the key
                incq (%rdx) # increments the counter of the number of iterations
                movq %r11, %rax # setting the value of return register to mid
                ret     # returning value in %rax                
                .l3:
                    decq %r11   # decrements the value of mid
                    jmp .equal  # looping back to the start of the equal code block
            
        .lessthan:
        movq %r11, %r8  # moves the value of mid to a temporary storage register  
        incq %r8    # increments the value of mid stored in the temporary storage register
        incq (%rdx) # increments the counter of the number of iterations       
        jmp .whileloop  # looping back to the start of the whileloop code block     

        .end:
            movq $-1, %rax  # setting the value of return register to -1
            ret     # returning value in %rax