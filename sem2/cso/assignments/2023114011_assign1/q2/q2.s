.global rotate
.text

# purpose of the function is to move the i+1th elemnt of an input array to the ith position in another output array. After looping, we also have to move the 0th element of the input array to the n-1 index position in the output array

rotate:
    mov $0, %r8     # setting value of i to 0
    sub $1, %rsi    # getting the value of n-1 and storing it for future refernce
    mov $1, %r9     # storing intial value of i+1 for keeping track of index of output array

    .perform_rotation:
        cmp %r8, %rsi           # compares value of i with n-1. if they are not equal, we want to continue performing rotation function
        je .end             # if they are equal, switching to end code to move first element of array to last index of output array
        mov (%rdi, %r9, 8), %rcx       # moving arr[i+1] to temp register to move to output array later on (for some reaseon, cannot move elents directly to another array)
        mov %rcx, (%rdx, %r8, 8)        # moving temp array value to mult[i] i.e. the output array
        add $1, %r8         # incrementing value of i in the loop
        add $1, %r9         # incrementing value of i + 1 in the loop
        jmp .perform_rotation   # looping back to start of fucntion

        .end:
            mov $0, %r8             # making value of i=0 to access the zero index element of input array
            mov (%rdi, %r8, 8), %rcx    # moving value of arr[0] to temporary register
            mov %rcx, (%rdx, %rsi, 8)   # moving temporary register value to n-1 index of output array
            ret         # calling end of function
            