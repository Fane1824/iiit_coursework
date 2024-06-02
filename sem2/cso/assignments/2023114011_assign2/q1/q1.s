.global maxsum
.text

maxsum:
    movq %rsp, %r9  # saving current value of stack pointer
    movq $2, %r15   # intializes variable i to 1
    cmp $1, %rdi    # comparing the value of n with 1. If they are not equal, continue to the prefixloop code block
    je .sdq # jumping to sdq code block if n is equal to 1

    .prefixloop:
        movq %r15, %r14 # moves the value of i to a temporary storage register
        decq %r14 # decrements the value of i stored in temporary storage register
        movq (%rcx, %r15,8), %r13   # moves the value of the ith element of an array to a temporary storage register
        movq (%rcx, %r14,8), %r12   # moves the value of the i-1th element of an array to a temporary storage register
        addq %r12, %r13     # adds the value of arr[i] and arr[i-1], storing the sum in a temporary storage register
        movq %r13, (%rcx, %r15, 8)  # stores the value of the sum in the ith element of the array 
        incq %r15   # increments the value of i 
        cmp %rdi, %r15  # comparing the value of n with i. If i is greater than n, continue to the sdq code block 
        jle .prefixloop  # looping back to the start of the prefixloop code block if i is less than or equal to n

    .sdq:
        movq %rsp, %r8  # saves the stack pointer to a temporary storage register
        movq $-10000000000000, %rax # setting the value of return register to an arbitrary low value
        movq %rsi, %r15  # initializse i to l

    .forloop:
        .whileloop:
            cmp %rsp, %r8   # compares the value of the stack pointer with the value of stack pointer stored in temporary storage register. If they are not equal, check for the next condition
            je .endwhileloop  # jumping to endwhileloop code block if the value of the stack pointer with the value of stack pointer stored in temporary storage register
            movq %r15, %r14 # moves i to a temporary storage register
            subq %rsi, %r14 # subtracts l from i and stores the difference in a temporary storage register
            movq (%rcx, %r14, 8), %r13 # stores the value of the i-lth element of the array in a temporary storage register 
            movq (%rsp),%r12 # stores the last element of the deque in a temporary storage register
            cmp %r12, %r13  # compares the value of the last element of the deque with the i-lth element of the array. If the first value is greater than or equal to the second value, then jump to the endwhileloop code block
            jge .endwhileloop  # jumping to endwhileloop code block if the i-lth element of the array is greater than or equal to the last element of the deque
            addq $8, %rsp # pops the last element of the array by adding 8 to the stack pointer
            jmp .whileloop  # looping back to the start of the whileloop code block
        
            .endwhileloop:
                movq %r15, %r14 # moves the value of i to a temporary storage register
                subq %rsi, %r14 # subtracts the value of l from value of i and stores the difference in a temporary storage register
                pushq %r14  # pushes the value of i-l onto the system stack  
                movq -8(%r8), %r13 # stores the value of element at front of deque
                movq %r15, %r14 # moves the value of i to a temporary storage register
                subq %rdx, %r14 # subtracts the value of r from the value of i and stores the difference in a temporary storage register 
                cmp %r14, %r13  # comparing the value of i-r with the the value of the element at the front of the deque. If the former value is greater than the latter, enter the if statement
                jge .endif    # jumping to the endif code block if the value of element at the front of the deque is greater than or equal to i-r
                subq $8, %r8    # subtracts 8 from temporary storage register storing the value of the stack pointer
                .endif:
                    movq (%rcx, %r15, 8), %r14  # stores the ith element of the array to a temporary storage register
                    movq -8(%r8), %r13  # stores the index of the element at the front of the deque in a temporary storage register
                    movq (%rcx, %r13, 8), %r12  # stores the front element of the array in a temporary storage register                 
                    subq %r12, %r14 # subtracts the front element of the array from the ith element of the array and stores it in a temporary storage register 
                    cmp %r14, %rax  # comparing the value of a[i] - a[front element] with the value stored in the return register.   
                    cmovl %r14, %rax    # setting the value of return register to a[i] - a[front element] if the latter value is greater than the former.
 
        incq %r15   # incrementing value of i
        cmp %rdi, %r15  # comparing the value of n with i. If they are not equal, exit the for loop
        jle .forloop    # looping back to the start of the forloop code block if i is less than or equal to n
        mov %r9, %rsp    # restoring original value of stack pointer to avoid segmentation fault
        ret # returning value in %rax