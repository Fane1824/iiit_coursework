.global combs
.text

combs:
    push %r12   # saves current value of r12 (calle save register)
    push %r13   # saves current value of r13 (calle save register)
    movq %rdi, %r12 # moves n value to temporary storage register (saving value for function call)
    movq %rsi, %r13 # moves r value to temporary storage register (saving value for function call)
    cmp $0, %rsi    # comparing the value of r with 0. If they are not equal, check for the next condition
    je .returner         # if equal, jump to the returner code block
    cmp %rsi, %rdi  # comparing the value of r with n. If they are not equal, continue on to the recursive case
    je .returner      # if equal, jump to the returner code block
    decq %rdi   # decrements the value of n
    decq %rsi   # decrements the value of r
    call combs   # call the combs function
    imulq %r12, %rax    # multiplying the value of n with the result of the combs function call and storing the result in the return register
    movq $0, %rdx   # setting the value of the remainder register to 0
    idivq %r13  # divides the value of rax with r13 
    pop %r13    # popping value of r13 (calle save register)                    
    pop %r12    # popping back value of r12 (calle save register)                    
    ret     # returning value in %rax

    .returner:
        pop %r13    # popping value of r13 (calle save register)
        pop %r12    # popping back value of r12 (calle save register)
        mov $1, %rax    # setting the value of return register to 1
        ret     # returning value in %rax