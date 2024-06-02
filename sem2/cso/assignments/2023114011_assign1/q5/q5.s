.global products
.text

# purpose of function is to set an array of n elements to 1. Then based on the current index of the input array and the output array, multiply both the elements and store it in the output array for furthur calculations. Then return the output array (implpemented using a void function in c where address of putput array is passed)

products:
    mov $0, %rcx # setting value of i to 0

    .setting_output_array:
        cmp %rcx, %rsi # compares value of i with n. if they are not equal, we want to continue loop
        je .mult_elements # if they are equal, switching to mult_elements code to find the products and fill the products array
        movq $1, (%rdx, %rcx, 8) # setting value of the ith element to 1
        add $1, %rcx # incrementing value of i in the loop
        jmp .setting_output_array # looping back to start of function


        .mult_elements:
            mov $0, %rcx    # setting value of i to 0
            mov $0, %r8     # setting value of j to 0

            .mult_loop:
                cmp %rcx, %rsi # compares value of i with n. if they are not equal, we want to continue loop
                je .end # if they are equal, switching to end code
                cmp %r8, %rsi # compares value of j with n. if they are not equal, we want to continue loop
                je .increment_i # if they are equal, switching to increment_i code to increment the value of i
                cmp %rcx, %r8 # compares the value of i with j.
                jne .multiplication # if they are not equal, switching to multiplication code to multiply the ith value of the sums array with the jth value of inputs array
                add $1, %r8 # incrementing value of j in the loop
                jmp .mult_loop   # looping back to start of function            

                .multiplication:
                    mov (%rdx, %rcx, 8), %r9    # storing value of the ith element of the sums array in a temporary register
                    imul (%rdi, %r8, 8), %r9    # multiplying value of the temporary register with the ith value of the input array, storing the result in the same temporary register
                    mov %r9, (%rdx, %rcx, 8)    # storing value of temporary register in the ith index of the sums array
                    add $1, %r8     # incrementing value of j in the loop
                    jmp .mult_loop  # looping back to start of function

                    .increment_i:
                        mov $0, %r8     # setting value of j to 0
                        add $1, %rcx    # incrementing value of i in the loop
                        jmp .mult_loop  # looping back to start of function

                        .end:
                            ret # calling end of function
                            