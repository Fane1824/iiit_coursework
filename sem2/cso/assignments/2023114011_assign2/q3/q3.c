#include <stdio.h>
#include <stdlib.h>

// typedef struct Stack{
//     long long int top, size, capacity;
//     long long int* arr;
// } Stack;

// Stack* createstack(long long int capacity){
//     Stack* new = (Stack*)malloc(sizeof(Stack));
//     new->top = -1;
//     new->size = 0;
//     new->capacity = capacity;
//     new->arr = (long long int*)malloc(sizeof(long long int) * capacity);
//     return new;
// }

// long long int isFull(Stack* st){
//     if (st->capacity - 1 == st->top){
//         return 1;
//     }
//     return 0;
// }

// long long int isEmpty(Stack* st){
//     if (st->size == 0){
//         return 1;
//     }
//     return 0;
// }

// void push(Stack* st, long long int element){
//     if (isFull(st)){
//         return;
//     }
//     else{
//         st->top++;
//         st->arr[st->top] = element;
//         st->size++;
//     }
// }

// long long int pop(Stack* st){
//     if (isEmpty(st)){
//         return NULL;
//     }
//     else{
//         long long int temp = st->arr[st->top];
//         st->top--;
//         st->size--;
//         return temp;
//     }
// }

long long int postfix(char input[], long long int n);
// {
//     stack* st = createstack(n);
//     for (int i = 0 ; i <n; i++){
//         if (input[i] == 43){
//             long long int temp1 = pop(st);
//             long long int temp2 = pop(st);
//             temp2 += temp1;
//             push(st, temp2);
//             continue;
//         }
//         if (input[i] == 45){
//             long long int temp1 = pop(st);
//             long long int temp2 = pop(st);
//             temp1 -= temp2;
//             push(st, temp1);
//             continue;
//         }
//         if (input[i] == 42){
//             long long int temp1 = pop(st);
//             long long int temp2 = pop(st);
//             temp2 *= temp1;
//             push(st, temp2);
//             continue;
//         }
//         if (input[i] == 47){
//             long long int temp1 = pop(st);
//             long long int temp2 = pop(st);
//             temp1 /= temp2;
//             push(st, temp1);
//             continue;
//         }
//         push(st, (int)input[i] - 48);
//     }
//     return st->arr[st->top];
// }

int main (){
    long long int n;
    scanf("%lld", &n);

    long long int size = n/2 + 1;
    char input[size];

    char buffer;
    scanf("%c", &buffer);

    for (int i = 0;i < size;i++){
        scanf("%c", &input[i]);
        char white_space;
        scanf("%c", &white_space);
    }

    long long int result = postfix(input, size);

    printf("%lld", result);
    return 0;
}