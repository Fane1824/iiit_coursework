#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    float num;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void printer(LinkedList l) {
    while (l != NULL) {
        printf("%0.2f ", l -> num);
        l = l -> next;
    }
    printf("\n");
}

LinkedList append(int x, LinkedList l) {
    Node* D = (Node*)malloc(sizeof(Node));
    D -> num = x;
    D -> next = NULL;  
    if (l == NULL) {
        l = D;
    } else {
        LinkedList t = l;
        while (t->next != NULL) {
            t = t -> next;
        }
        t -> next = D;
    }

    return l;
}

float mod(LinkedList l) {
    float result = 0;
    while (l != NULL) {
        result += ((l -> num) * (l -> num));
        l = l -> next;
    }
    result = (float)sqrt(result);
    return result;
}

float dot(LinkedList l1, LinkedList l2) {

    if (l1 == NULL) {
        return 0;
    } 
    float x = 0;
    while (l1 != NULL) {
        x += (l1 -> num) * (l2 -> num);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    return x;
}

float cosineSimilarity(LinkedList l1, LinkedList l2) {

    if (l1 == NULL) {
        return 0;
    } 
    float result = dot(l1, l2)/(mod(l1) * mod(l2));
    return result; 
}

LinkedList sub(LinkedList l1, LinkedList l2) {

    if (l1 == NULL) {
        return NULL;
    } 
    LinkedList head = NULL;
    if (head == NULL) {
        float y = (l1 -> num) - (l2 -> num);
        head = append(y, head);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    LinkedList diff = head;
    while (l1 != NULL) {
        float y = (l1 -> num) - (l2 -> num);
        diff = append(y, diff);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    return head;
}

LinkedList add(LinkedList l1, LinkedList l2) {

    if (l1 == NULL) {
        return NULL;
    } 
    LinkedList head = NULL;
    if (head == NULL) {
        float y = (l1 -> num) + (l2 -> num);
        head = append(y, head);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    LinkedList sum = head;
    while (l1 != NULL) {
        float y = (l1 -> num) + (l2 -> num);
        sum = append(y, sum);
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    return head;
}

int main() {

    bool source = true;
    while (source == true) {
        char s[10];
        for (int i = 0; i < 100; i++) {
            scanf("%c", &s[i]);
            if (i == 0 && (s[i] == 10 || s[i] == 32)) {
                scanf("%c", &s[i]);
            }
            if ((int)s[i] == 32 || (int)s[i] == 10) {
                break;
            }
            if ((int)s[i] == 45) {
                return 0;
            }
        }
        int n;
        scanf("%d", &n);
        LinkedList l1 = NULL;
        LinkedList l2 = NULL;
        for (int i = 0; i < n; i++) {
            float x;
            scanf("%f", &x);
            l1 = append(x, l1);
        }
        for (int j = 0; j < n; j++) {
            float x;
            scanf("%f", &x);
            l2 = append(x, l2);
        }
        printf("Result: ");
        if ((int)s[0] == 65) {
            LinkedList sum = add(l1, l2);
            printer(sum);
        } 
        if ((int)s[0] == 83) {
            LinkedList diff = sub(l1, l2);
            printer(diff);  
        }
        if ((int)s[0] == 68) {
            printf("%0.2f\n", dot(l1, l2));
        }
        if ((int)s[0] == 67) {
            printf("%0.2f\n", cosineSimilarity(l1, l2));
        } 
    }
    
    return 0;
}