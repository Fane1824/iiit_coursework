#include <stdio.h>
#include <stdlib.h>

long long int maxcount = 0;
long long int maxval = 0;

typedef struct Node {
    int count;
    long long int val;
    struct Node* next;
} Node;

typedef struct head {
    long long int min;
    long long int max;
    Node* next;
} head;

Node* createNode(long long int n) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->count = 1;
    new->val = n;
    new->next = NULL;
    return new;
}

long long int findmin(Node* finder) {
    if (finder == NULL) {
        return 0;
    }
    int newmin = finder->val;
    while (finder != NULL) {
        if (finder->val < newmin) {
            newmin = finder->val;
        }
        finder = finder->next;
    }
    return newmin;
}

long long int findmax(Node* finder) {
    int newmax = 0;
    while (finder != NULL) {
        if (finder->val > newmax){
            newmax = finder->val;
        }
        finder = finder->next;
    }
    return newmax;
}

void inserterfunc(head* inserted, Node* updatenode, long long int n) {
    updatenode->next = inserted->next;
    inserted->next = updatenode;
    if (updatenode->count > maxcount) {
        maxcount = updatenode->count;
        maxval = updatenode->val;
    }
    if (inserted->min == 0) {
        inserted->min = n;
    } else if (inserted->min > n) {
        inserted->min = n;
    }
    if (inserted->max < n) {
        inserted->max = n;
    }
}

void insertNode(head* hash[], long long int n) {
    int x = (n % 200000 + 200000) % 200000;
    int inserter;
    if (x != 199999) {
        inserter = x + 1;
    } else {
        inserter = 0;
    }
    int flag = 0;
    if (hash[x]->next == NULL || n > hash[x]->max + 1 || n - 1 < hash[x]->min) {
        inserterfunc(hash[inserter], createNode(n), n);
    } else {
        int flag2 = 0;
        while (hash[x]->next->val == n-1) {
            Node* temp = hash[x]->next;
            hash[x]->next = hash[x]->next->next;
            temp->count++;
            temp->val = n;
            inserterfunc(hash[inserter], temp, n);
            flag2 = 1;
            if (hash[x]->next == NULL) {
                break;
            }
        }
        Node* temp2 = hash[x]->next;
        while (temp2 != NULL && temp2->next != NULL) {
            if (temp2->next->val == n-1) {
                flag2 = 1;
                Node* updaternode = temp2->next;
                temp2->next = temp2->next->next;
                updaternode->count++;
                updaternode->val = n;
                inserterfunc(hash[inserter], updaternode, n);
            }
            temp2 = temp2->next;
        }
        if (flag2 == 1) {
            hash[x]->max = findmax(hash[x]->next);
            hash[x]->min = findmin(hash[x]->next);
        }
        if (flag2 == 0) {
            inserterfunc(hash[inserter], createNode(n), n);  
        }
    
    }
    return; 
}


int main() {
    int n;
    scanf("%d", &n);
    long long int arr[n];
    head* hash[200000];
    for (int i = 0; i < 200000; i++) {
        hash[i] = (head*)malloc(sizeof(head));
        hash[i]->min = 0;
        hash[i]->max = 0;
        hash[i]->next = NULL;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);      
        insertNode(hash, arr[i]);
    }
    long long int start = maxval-maxcount+1;
    long long int countvar = 0;
    printf("%lld\n", maxcount);
    for (int i = 0; i < n; i++) {
        if (countvar == maxcount) {
            break;
        }
        if (arr[i] == start) {
            printf("%d ", i);
            start++;
            countvar++;
        }
    }
    return 0;
}
