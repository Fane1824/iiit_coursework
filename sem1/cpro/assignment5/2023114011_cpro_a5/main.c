#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main() {

    int q;
    scanf("%d", &q);
    char instruct[q][25];
    for (int ic = 0; ic < q; ic++) {
        FILE* ptr1;
        ptr1 = fopen("mx_history", "a");
        fprintf(ptr1, "LOG::");
        for (int ia = 0; ia < 25; ia++) {
            scanf("%c", &instruct[ic][ia]);
            if ((int)instruct[ic][ia] == 13) {
                scanf("%c", &instruct[ic][ia]);
            }
            if ((int)instruct[ic][ia] == 10) {
                continue;
            }
            fprintf(ptr1, "%c", instruct[ic][ia]);
            if (((int)instruct[ic][ia] == 32) || (int)instruct[ic][ia] == 121) {
                fclose(ptr1);
                break;
            }
        } 
        instruct[ic][0] = (char)58;
        if ((int)instruct[ic][1] == 104) {
            FILE* ptr;
            ptr = fopen("mx_history", "a");
            fprintf(ptr, "\n");
            fclose(ptr);
            readHistory();
            continue;
        }
        int mode;
        scanf("%d", &mode);
        FILE* ptr;
        ptr = fopen("mx_history", "a");
        fprintf(ptr, "%d\n", mode);
        fclose(ptr);
        Matrix* ansmat;
        ansmat = defaultac(instruct[ic], mode);
        if ((mode == 1) && ((long int)instruct[ic][1] != 100)) {
            char* ofile = (char*)malloc(sizeof(char) * 5000);
            scanf("%s", ofile); 
            if (ansmat != NULL) {
                write_matrix_to_file(ofile, ansmat);  
            }
        }
        if (ansmat == NULL) {
            printf("ERROR: INVALID ARGUMENT\n");
            continue;
        }
        if ((int)instruct[ic][1] == 100) {
            printf("%lld\n", ansmat->data[0][0]);
            destroy_matrix(ansmat);
            continue;
        } 
        if (mode == 0) {
            print_matrix(ansmat);
        }
        destroy_matrix(ansmat);
    }

    return 0;
}
