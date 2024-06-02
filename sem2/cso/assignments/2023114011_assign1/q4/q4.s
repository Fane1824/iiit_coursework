.global sum
.text

# purpose of function is to first find the smallest element in the array and the greatest element of the array and add it. This is done by setting sammlest and largest to some initial values and then iterating throught the array and updating the value of smallest and largest as the smallest and largest elements come along respectively.

sum:
    mov (%rdi), %r8     # storing value of first element of array for finding greatest integer
    mov (%rdi), %r9     # storing value of first element of array for finding smallest integer
    mov $1, %rdx        # setting value of i to 1
    
    .loop:
        cmp %rdx, %rsi  # compares value of i with n. if they are not equal, we want to continue loop
        je .end         # if they are equal, switching to end code to return the sum of smallest and greatest integers.
        cmp (%rdi, %rdx, 8), %r8 # compares value of the ith element of the array with the value stored as smallest integer.
        jl .greatest    # if the value of the ith index is greater than the greatest integer, it switches to greatest code to change the value of the greatest integer.
        cmp (%rdi, %rdx, 8), %r9 # compares value of the ith element of the array with the value stored as largest integer.
        jge .smallest   # if the value of the ith index is less than the smallest integer, it switches to smallest code to change the value of the smallest integer.
        add $1, %rdx    # incrementing value of i in the loop
        jmp .loop       # looping back to start of function

        .greatest:
            mov (%rdi, %rdx, 8), %r8    # change value of the greatest integer to the ith element of the array
            add $1, %rdx                # incrementing value of i in the loop
            jmp .loop                   # looping back to start of function

        .smallest:
            mov (%rdi, %rdx, 8), %r9    # change value of the smallest integer to the ith element of the array
            add $1, %rdx                # incrementing value of i in the loop
            jmp .loop                   # looping back to start of function

            .end:
                mov %r8, %rax   # adding value of greatest integer with value of return register and storing in return register
                add %r9, %rax   # adding value of smallest integer with value of return register and storing in return register
                ret             # calling end of function
                