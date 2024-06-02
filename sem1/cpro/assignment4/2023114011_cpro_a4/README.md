# Introduction

This file contains details regarding the functions called and data structures used, alongside any assumptions made, in the 3 Non-OJ questions given as part of Computer Programming Assignment 4.

# Question 1

## Purpose of the Code

This program represents a basic bank account database management system (DBMS). It includes features for creating accounts, displaying account information, deleting accounts, listing low-balance accounts, and conducting transactions.

## Data Structures Used

**1. enum `acc_type`**: An enum used to store whether the account is a savings account (`savings` or 0) or a current account (`current` or 1).

**2. struct `AccountInfo`**: A structure to store account information, including account number (an integer `acc_no`), account type (acc_type enum `type`), account holder's name (a string of up to 49 characters, excluding the newline character, `name[50]`), and account balance (a float `bal`).

**3. struct `Node`**: A linked list node that contains an AccountInfo structure `data` and a pointer to the next node in the linked list.

**4. Node\* `LinkedList`**: A pointer to the first node of a linked list.

## Functions 

**1. `display()`**: Displays all details (account number, name, account type, and balance) of all bank accounts in the system by iterating through a linked list.

**2. `find_num():`** Finds the next available account number to assign to a new account by iterating through a linked list. 

**3. `repeated(char Name[], int accountType)`**: Checks if an account with the given name and type already exists by iterating through a linked list and then comparing the name and type contained in the data of that node with the name and type being checked.

**4. `createAccount(int accountType, char Name[], float Amount)`**: Creates a new bank account with the specified account type, account holder's name, and initial balance of the account.

**5. `deleteAccount(int accountType, char Name[])`**: Deletes a bank account based on the account type and account holder's name.

**6. `lowBalanceAccounts()`**: Lists the account number, account holder's name, and account balance of all accounts with a balance below Rs 100.

**7. `transaction(int accountNumber, float amount, int code)`**: Conducts a transaction (withdrawal or deposit) on a specific account by modifying the balance, and then printing the next balance, after checking if sufficient funds are available.

## Assumptions
1. The program assumes that the input is provided in the predefined format. If the input does not follow the predefined format, the program may behave irregularly and/or incorrectly.
2. The program assumes that account numbers start at 100.
3. The program assumes that account numbers increase sequentially.
4. The program assumes that account numbers can be reused.
5. The program assumes that when an account is created, the account number it is assigned is the lowest available account number.
6. The program assumes that all accounts under Rs 100 are low-balance accounts.
7. The program assumes that two account holders cannot have the same name.
8. The program assumes that the user will enter "EXIT" to signal the end of the input. If the user does not provide an "EXIT" signal, the program will continue in an infinite loop.
9. The program assumes that the name of the account holder will be a maximum of 49 characters.

# Question 2

## Purpose of the Code

This program is designed to perform various mathematical operations on two n-dimensional complex numbers. The operations include addition, subtraction, dot product, and cosine similarity. The complex numbers are represented by two linked lists. 

## Data Structures Used

**1. struct `Node`**: A linked list node that contains a float data type `num` and a pointer to the next node in the linked list.

**2. Node\* `LinkedList`**: A pointer to the first node of a linked list.

## Functions

**1. `printer(LinkedList l):`** This function prints the elements of a linked list.

**2. `append(int x, LinkedList l):`** This function appends a new node with the value x to the end of the linked list l.

**3. `mod(LinkedList l):`** Calculates the mod of a complex number represented by the linked list.

**4. `dot(LinkedList l1, LinkedList l2):`** Calculates the dot product between two complex numbers, which are represented by linked lists.

**5. `cosineSimilarity(LinkedList l1, LinkedList l2):`** Calculates the cosine similarity between two complex numbers, which are represented by linked lists.

**6. `sub(LinkedList l1, LinkedList l2):`** Subtracts two complex numbers represented by linked lists.

**7. `add(LinkedList l1, LinkedList l2):`** Adds two complex numbers represented by linked lists.

## Assumptions
1. The program assumes that the input is provided in the predefined format. If the input does not follow the predefined format, the program may behave irregularly and/or incorrectly.
2. The program assumes that the floating-point terms are correctly separated by spaces.
3. The program assumes that the user will only input `n` elements for each linked list; not more, not less.
4. The program assumes that the user will enter -1 to signal the end of the input. If the user does not provide a -1, the program will continue in an infinite loop.
5. The program assumes that it can perform division and square root operations without explicitly verifying whether division by zero or taking the square root of a negative number might occur (this is important for the cosine similarity and mod calculaions).


# Question 3

## Purpose of the Code

This program is designed to take a list of colors as input and remove duplicate colors from the list. It represents the list of colors as a linked list. It takes the number of colors and the number of each color as input. Meanwhile, the output is a modified linked list containing only unique colors. 

## Data Structures Used

**1. struct `Node`**: A linked list node containing an integer data type `num` and a pointer to the next node.

**2. Node\* `LinkedList`**: Represents the main linked list of the program, storing the list of colors. It is modified via functions in the program to remove repeated colors.

## Functions Used

**1. `display(LinkedList l)`**: Displays the linked list l used as a parameter in the function in the format "Modified Linked List: color1 -> color2 -> ... -> colorN"
3
**2. `removeDuplicates(LinkedList l):`**: Removes duplicate colors from the linked list, ensuring each color appears only once.

**3. `append(int x, LinkedList l)`**: Appends a new color to the end of the linked list.

## Assumptions

1. The program assumes the user inputs only integers for each color.
2. The program assumes the user inputs only `n` colors.
3. The program assumes the user inputs colors in non-decreasing order.
4. The program assumes that the linked list is null (ie. no colors were contained before data was inputted).



