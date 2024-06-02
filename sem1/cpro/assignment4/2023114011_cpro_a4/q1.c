#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum acc_type {
    savings,
    current
} acc_type;

typedef struct AccountInfo {
    int acc_no;
    acc_type type;
    char name[50];
    float bal;
} AccountInfo;

typedef struct Node {
    AccountInfo data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

LinkedList l = NULL;

void display() {
    int flag = 0;
    if (l == NULL) {
        printf("No Accounts to display\n");
        flag = 1;
    }
    if (flag == 0) {
        LinkedList j = l;
        printf("Account Number\t\tAccount Type \t Name \t Balance\n"
        "-----------------------------------------------------------\n");
        
        while (j!= NULL) {
            char status[8];
            if (j->data.type == 0) {
                strcpy(status, "savings");
            } else {
                strcpy(status, "current");
            }
            printf("%d\t\t\t%s \t %s \t %0.2f\n", j -> data.acc_no, status, j -> data.name, j ->data.bal);
            j = j-> next;
        }
    }
}

int find_num() {
    LinkedList t = l;
    if (t == NULL) {
        return 100;
    }
    if (t->data.acc_no != 100) {
        return 100;
    }
    while (t -> next != NULL) {
        if (t->next->data.acc_no - t->data.acc_no > 1) {
            break;
        }
        t = t -> next;
    }
    return t->data.acc_no + 1;
}

int repeated(char Name[], int accountType) {
    LinkedList j = l;
    int flag = 0;
    while (j != NULL) {
        if (strcmp(j -> data.name, Name) == 0 && j -> data.type == accountType) {
            flag = 1;
            break;
        }
        j = j -> next;
    }
    return flag;
}

LinkedList createAccount(int accountType, char Name[], float Amount){
    if (repeated(Name, accountType) == 1) {
        printf("Invalid: User already exists!\n");
        return l;
    } else {
        AccountInfo* new_acct = (AccountInfo* ) malloc(sizeof(AccountInfo));
        char status[][8] = {
            "savings",
            "current"
        };
        int x = find_num();
        printf("Account Number: %d\n", x);
        printf("Account Holder: %s\n", Name);
        printf("Account Type: %s\n", status[accountType]);
        printf("Balance: Rs %0.2f\n", Amount);
        new_acct -> acc_no = x;
        new_acct -> type = accountType;
        strcpy(new_acct -> name, Name);
        new_acct -> bal = Amount;
        Node* D = (Node *) malloc(sizeof(Node));
        D -> data = *new_acct;
        D -> next = NULL;
        if (l == NULL) {
            l = D;
            return D;
        } 
        if (x == 100) {
            LinkedList temp = l;
            D -> next = temp;
            l = D;
            return l;
        }
        LinkedList t = l;
        while (t != NULL) {
            if (t->data.acc_no != x-1) {
                t = t->next;
            } else {
                break;
            }
        }
        LinkedList temp = t -> next;
        t->next = D;
        D -> next = temp;
        return l;
    }
}

LinkedList deleteAccount(int accountType, char Name[]) {
    if (repeated(Name, accountType) == 0) {
        printf("Invalid: User does not exist\n");
        return l;
    } 
    printf("Account deleted successfully\n");
    if (strcmp(Name, l->data.name) == 0 & accountType == l->data.type) {
        LinkedList f = l->next;
        free(l);
        l = f;
        return l;
    }
    LinkedList j = l;
    while (j->next != NULL) {
        if (strcmp(Name, j->next->data.name) == 0 && accountType == j->next->data.type) {
            LinkedList t = j -> next -> next;
            LinkedList next = j -> next;
            free(next);
            j -> next = t; 
            break;
        }
    }
    return l;
}

void lowBalanceAccounts(){
    LinkedList y = l;
    while (y != NULL) {
        if (y->data.bal < 100) {
            printf("Account Number: %d, Name: %s, Balance: %0.0f\n", y->data.acc_no, y->data.name, y->data.bal);
        }
        y = y -> next;
    }
}

void transaction(int accountNumber, float amount, int code) {
    LinkedList t = l;
    int flag = 0;
    while (t != NULL) {
        if (t -> data.acc_no == accountNumber) {
            flag = 1;
            break;
        }
        t = t -> next;
    }
    if (flag == 0) {
        printf("Invalid: User does not exist\n");
    } else {
        if (code == 0 && (t -> data.bal - amount) < 100) {
            printf("The balance is insufficient for the specified withdrawal.\n");
        } else {
            int x;
            if (code == 0) {
                t -> data.bal = (t -> data.bal - amount);
            } else if (code == 1) {
                t -> data.bal = (t -> data.bal + amount);
            }
            printf("Updated Balance is %0.2f\n", t -> data.bal);
        }
    }
}

int main() {
    bool source = true;
    while (source == true) {
        char s[100];
        for (int i = 0; i < 100; i++) {
            scanf("%c", &s[i]);
            if ((int)s[i] == 32 || (int)s[i] == 10) {
                break;
            }
        }
        if ((int)s[0] == 67) {
            char type[50], name[50];
            float amt;
            scanf("%s %s %f", type, name, &amt);
            int code = 1; 
            if ((int)type[0] == 115) {
                code = 0;
            } 
            createAccount(code, name, amt);
        } else if ((int)s[0] == 68 && (int)s[1] == 73) {
            display();
        } else if ((int)s[0] == 69) {
            break;
        } else if ((int)s[0] == 68) {
            char type[50], name[50];
            scanf("%s %s", type, name);
            int code = 1; 
            if ((int)type[0] == 115) {
                code = 0;
            }
            deleteAccount(code, name);
        } else if ((int)s[0] == 76) {
            lowBalanceAccounts();
        } else if ((int)s[0] == 84) {
            int code, accno;
            float amt;
            scanf("%d %f %d", &accno, &amt, &code);
            transaction(accno, amt, code);
        }  
    }    
    return 0;
}