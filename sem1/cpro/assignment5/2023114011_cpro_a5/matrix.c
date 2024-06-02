#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix(int r, int c) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int**) calloc(r, sizeof(long long int*));
    for (int i =0; i < r; i++) {
        m->data[i] = (long long int*) calloc(c, sizeof(long long int));
    }   
    return m;
}

Matrix* matrix_creator(int mode) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (mode == 0) {
        int n, m;
        scanf("%d %d", &n, &m);
        mat = create_matrix(n, m);
        for (int ic1 = 0; ic1 < n; ic1++) {
            for (int ic2 = 0; ic2 < m; ic2++) {
                scanf("%lld", &mat->data[ic1][ic2]);
            }
        }
    } else {
        char* f1 = (char*)malloc(sizeof(char)*5000);
        scanf("%s", f1);
        mat = read_matrix_from_file(f1);
    }
    return mat;
}

void destroy_matrix(Matrix* m) {
    int r = m->num_rows;
    int c = m->num_cols;
    for (int i = 0; i < r; i++) {
            free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix* add_matrix(Matrix* A, Matrix* B) {
    int r = A->num_rows;
    int c = A->num_cols;
    Matrix* m = create_matrix(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
    return m;
}

Matrix* mult_matrix(Matrix* A, Matrix* B) {
    int r = A->num_rows;
    int c = B->num_cols;
    Matrix* m = create_matrix(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m->data[i][j] = 0;
            for (int z = 0; z < A->num_cols; z++) {
                m->data[i][j] += (A->data[i][z] * B->data[z][j]);
            }
        }
    }
    return m;
}

Matrix* scalar_mult_matrix(long long int s, Matrix* M) {
    Matrix* m1 = create_matrix(M->num_rows, M->num_cols);
    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m1->num_cols; j++) {
            m1->data[i][j] = s * M->data[i][j];
        }
    }
    return m1;
}

Matrix* transpose_matrix(Matrix* A) {
    Matrix* m1 = create_matrix(A->num_cols, A->num_rows);
    int r = A->num_rows;
    int c = A->num_cols;    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m1->data[j][i] = A->data[i][j];
        }
    }
    return m1;
}
long long int determinant(Matrix* M) {
    if (M->num_rows == 1) {
        return M->data[0][0];
    }
    long long int res = 0;
    int multiplier = 1;
    for (int i = 0; i < M->num_rows; i++) {
        Matrix* m1 = create_matrix(M->num_rows-1, M->num_cols-1);
        for (int z = 1; z < M->num_rows; z++) {
            int c = 0;
            for (int j = 0; j < M->num_cols; j++) {
                if (j == i) {
                    continue;
                }
                m1->data[z-1][c] = M->data[z][j];
                c++;
            }
        }
        res += (determinant(m1) * M->data[0][i] * multiplier);
        multiplier = (-1) * multiplier;
        destroy_matrix(m1);
    }
    return res;
    
// 6: Write code here to calculate the determinant of the given matrix M (if not a square matrix, return -1).
// Return the determinant value.
}

// DO NOT MODIFY THE OUTPUT FORMAT of this function. Will be used for grading

void print_matrix(Matrix* m) {
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
    printf("\n");
    }
}

Matrix* defaultac(char instruct[100], int mode) {
    if ((int)instruct[1] == 97) {
        Matrix* a = matrix_creator(mode);
        Matrix* b = matrix_creator(mode);
        if (a == NULL || b == NULL) {
            return NULL;
        } else {
            if ((a->num_cols != b->num_cols) || (b->num_rows != a->num_rows)) {
                return NULL;                
            } else {
                Matrix* result = add_matrix(a, b);
                destroy_matrix(a);
                destroy_matrix(b);
                return result; 
            }
        }
    }
    if ((int)instruct[1] == 109) {
        Matrix* a = matrix_creator(mode);
        Matrix* b = matrix_creator(mode);
        if (a == NULL || b == NULL) {
            return NULL;
        } else {
            if (a->num_cols != b->num_rows) {
                return NULL;                
            } else {
                Matrix* result = mult_matrix(a, b);
                destroy_matrix(a);
                destroy_matrix(b);
                return result;    
            }
        }
    }
    if ((int)instruct[1] == 115) {
        int s;
        scanf("%d", &s);
        Matrix* a = matrix_creator(mode);
        if (a == NULL) {
            return NULL;
        } else {
            Matrix* result = scalar_mult_matrix(s, a);
            destroy_matrix(a);
            return result;  
        }
    }
    if ((int)instruct[1] == 116) {
        Matrix* a = matrix_creator(mode);
        if (a == NULL) {
            return NULL;
        } else {
            Matrix* result = transpose_matrix(a);
            destroy_matrix(a);
            return result; 
        }             
    }
    if ((int)instruct[1] == 100) {
        Matrix* a = matrix_creator(mode);
        if (a == NULL) {
            return NULL;
        } else {
            if (a->num_cols != a->num_rows) {
                return NULL;
            } else {
                int ans = determinant(a);
                destroy_matrix(a);
                Matrix* result = create_matrix(1, 1);
                result->data[0][0] = ans;
                return result; 
            }
        }
    }
    return NULL;
}

Matrix* read_matrix_from_file(char* name) {
    FILE* ptr = fopen(name, "r");
    if (ptr == NULL) {
        return NULL;
    }
    int r, c;
    fscanf(ptr, "%d %d", &r, &c);
    Matrix* m = create_matrix(r, c);
    for (int ic1 = 0; ic1 < r; ic1++) {
        for (int ic2 = 0; ic2 < c; ic2++) {
            fscanf(ptr, "%lld", &m->data[ic1][ic2]);
        }
    }
    fclose(ptr);
    return m;
}

void write_matrix_to_file(char* name, Matrix* m) {
    FILE* ptr; 
    ptr = fopen(name, "w");
    fprintf(ptr, "%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            fprintf(ptr, "%lld ", m->data[i][j]);
        }
        fprintf(ptr, "\n");
    }
    fclose(ptr);
}

void readHistory() {
    FILE *ptr;
    ptr = fopen("mx_history", "r");
    while (1) {
        char c = fgetc(ptr);
        if (c == EOF) {
            break;
        } else {
            printf("%c", c);
        }
    }
    fclose(ptr);
}
