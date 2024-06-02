#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pair {
    long long int depth;
    long long int time;
} Pair;

typedef struct Node {
    long long int dist;
    long long int time;
    struct Node* next;
} Node;

typedef struct Heap {
    long long int capacity;
    Node** arr;
    long long int size;
} Heap;

Node* createNode(long long int d, long long int t) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->dist = d;
    new->time = t;
    new->next = NULL;
    return new;
}

typedef Node* LinkedList;

Node* insertLL(LinkedList l, long long int d, long long int t) {
    if (l == NULL) {
        return createNode(d, t);
    }
    Node* new = createNode(d, t);
    LinkedList temp = l;
    if (temp->dist > d) {
        new->next = temp;
        return new;
    }
    while (temp->next != NULL && temp->next->dist < d) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        temp->next = new;
        return l;
    } 
    new->next = temp->next;
    temp->next = new;
    return l;
}

void printLL(LinkedList l) {
    LinkedList temp = l;
    while (temp != NULL) {
        printf("%lld ", temp->dist);
        temp = temp->next;
    }
    printf("\n");
}

Heap* create(long long int c) {
    Heap* new = (Heap*)malloc(sizeof(Heap));
    new->capacity = c;
    new->size = 0;
    new->arr = (Node**)malloc(sizeof(Node*) * c);
    return new;
}

void heapify(Heap* h, long long int i) {
    long long int smallest = i;
    long long int left = 2 * i + 1;
    long long int right = 2 * i + 2;
    
    if (left < h->size && h->arr[left]->time < h->arr[smallest]->time) {
        smallest = left;
    }
    if (right < h->size && h->arr[right]->time < h->arr[smallest]->time) {
        smallest = right;
    }
    if (smallest != i) {
        Node* temp = h->arr[i];
        h->arr[i] = h->arr[smallest];
        h->arr[smallest] = temp;
        heapify(h, smallest);
    }
}

// void build(Heap* heap, int* arr, int n){
//     if(n > heap->capacity){
//         return;
//     }
//     heap->size = n;
//     for(int i = 0; i < n; i++){
//         heap->arr[i] = arr[i];
//     }
//     for(int i = (n-1)/2; i >= 0; i--){
//         heapify(heap, i);
//     }
// }

void printHeap(Heap* heap) {
    printf("Min Heap: ");
    for (long long int i = 0; i < heap->size; i++) {
        printf("%lld ", heap->arr[i]->time);
    }
    printf("\n");
}

void insert(Heap* heap, Node* x) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->size++;
    long long int i = heap->size - 1;
    heap->arr[i] = x;
    while (i != 0 && heap->arr[i]->time < heap->arr[(i-1)/2]->time) {
        Node* temp = heap->arr[i];
        heap->arr[i] = heap->arr[(i-1)/2];
        heap->arr[(i-1)/2] = temp;
        i = (i-1)/2;
    }
    // printHeap(heap);
}

Node* delete(Heap* heap){
    if(heap->size == 0){
        return NULL;
    }
    Node* r = heap->arr[0];
    if (heap->size == 1) {
        heap->size--;
        return r;
    }
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return r;
}

LinkedList heapBuilder(LinkedList l, Heap* heap, long long int k) {
    if (l == NULL) {
        return NULL;
    }
    while (l != NULL && l->dist <= k) {
        insert(heap, l);
        l = l->next;
    }
    return l;
}

int compare(const void* a, const void* b) {
    Pair ax = *(Pair*)a;
    Pair bx = *(Pair*)b;
    return bx.depth - ax.depth;
}

int main() {
    long long int n, k, p, d;
    scanf("%lld %lld %lld %lld", &n, &k, &d, &p);
    Pair a[n];
    // long long int depths[n];
    // long long int times[n];
    long long int max_depth = k;
    long long int time = 0;
    LinkedList l = NULL;
    Heap* heap = create(n);
    for (long long int i = 0; i <n; i++) {
        scanf("%lld", &a[i].depth);
    }
    for (long long int i = 0; i < n; i++) {
        scanf("%lld", &a[i].time);
        // l =insertLL(l, depths[i], times[i]);
    }
    qsort(a, n, sizeof(Pair), compare);
    for(long long int i = 0; i < n; i++) {
        l = insertLL(l, a[i].depth, a[i].time);
    }
    if (k >= d) {
        printf("0\n");
        return 0;
    }
    // for (int i = 0; i< n;i++) {
    //     printf("%lld %lld\n", a[i].depth, a[i].time);
    // }
    // printf("\n");
    while (true) {
        l = heapBuilder(l, heap, k);
        // printLL(l);
        // printHeap(heap);
        Node* x = delete(heap);
        if (x == NULL) {
            printf("-1 %lld\n", max_depth);
            break;
        }
        max_depth += p;
        time += x->time;
        k += p;
        // printf("%d %d %d %d\n", x->dist, x->time, max_depth, time);
        if (k >= d) {
            printf("%lld\n", time);
            break;
        } 
    }

    

    return 0;
}