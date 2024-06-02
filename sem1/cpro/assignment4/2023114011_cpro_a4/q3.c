#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void display(LinkedList l) {
    printf("Modified Linked List: ");
    while (l -> next != NULL) {
        printf("%d -> ", l -> num);
        l = l -> next; 
    }
    printf("%d", l -> num);
}

LinkedList removeDuplicates(LinkedList l) {
    LinkedList head = l;
    if (l == NULL || l -> next == NULL) {
        return l;
    } 
    while (l -> next != NULL) {
        if (l -> num == l -> next -> num) {
            l -> next = l -> next -> next;
            continue;
        }
        l = l -> next;
    }
    return head;

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

int main() {

    int n;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("Modified Linked List: ");
        return 0;
    }
    LinkedList l = NULL;
    printf("Enter the colors: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        l = append(x, l);
    }
    l = removeDuplicates(l);
    display(l);

    return 0;
}