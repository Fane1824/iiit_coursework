.global palindrome
.text

# purpose of the function is to iterate from both the front and the rear of the string array and if any character is encountered int the front itereation which is not equal to its corresponding value in the rear iteration, string is not a palindrome and so we return 0. If not a single unequal character is encountered, the  the string is a palindrome and we return 1

palindrome:
    mov %rsi, %rdx  # storing value of length for comparison with i
    shr $1, %rdx    # dividing the value of length by 2 via logical right shift (since string length cannot be negative)
    mov $0, %rcx    # setting value of i to 0
    sub $1, %rsi    # subtracting 1 from length and storing the answer in the register which stores the length
    mov %rsi, %r11  # storing the value of length - 1 in a temporary register

    .compare:
        cmp %rcx, %rdx  # compares value of i with length/2. if they are not equal, we want to continue performing compare function
        je .is_palindrome   # if they are equal, switching to is_palindrome code to return 1
        sub %rcx, %rsi      # subtracting the value of i from length - 1, then storing the result in the register which stores the length vlaue
        movb (%rdi, %rsi, 1), %r8b  # setting the value of a temporary register to the n-i-1th element of the string
        cmp %r8b, (%rdi, %rcx, 1)   # compares value of the ith element of the string with the length-i-1th element of the string. if they are equal, we want to continue performing compare function
        jne .not_palindrome # if they are not equal, switching to not_palindrome code to return 0
        add $1, %rcx    # incrementing value of i in the loop
        mov %r11, %rsi  # setting the value in the register storing the length to the value stored in the register storing the value of length-1
        jmp .compare        # looping back to start of function

            .is_palindrome:
                mov $1, %rax    # setting the value of return register to 1
                ret             # calling end of function
            
            .not_palindrome:
                mov $0, %rax    # setting the value of return register to 0
                ret             # calling end of function
