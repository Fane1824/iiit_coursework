.global lonely
.text

# purpose of the function is to xor all the elements of the inputed array with each other and return the output of all those operations

lonely:
    mov (%rdi), %rax   # moves the value of the first element of the array to output register
    mov $1, %rdx       # intializes variable i to 1

    .xorloop:          # loop for performing xor function
        cmp %rsi, %rdx      # comparing the value of i with the size of the array. If they are not equal, we want the loop to keep iterating
        je .end             # jumping to end function if they are equal
        xor (%rdi, %rdx, 8), %rax   # if not equal, performing xor between arr[i] and value in rax and updating rax with the resultant value
        add $1, %rdx        # incrementing value of i in the loop
        jmp .xorloop        # looping back to the start of the function
        
        .end:
            ret             # returning value in %rax
            