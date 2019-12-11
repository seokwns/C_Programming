#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N 3

typedef int mat_type[N][N];

// Load the 3x3 matrix stored in the given file into the variable 'mt'.
int load(const char* fname, mat_type mt) {
    FILE* ifp;
    int r,c;
    
    ifp = fopen(fname, "r");
    assert(ifp);

    for (r = 0; r < N; ++r) {
        for (c = 0; c < N; ++c) {
            if(fscanf(ifp, "%d ", &mt[r][c]) != 1) return -1; // input fail
        }
    }
    
    fclose(ifp);
    return 0; // input success
}

// Store the 3x3 matrix stored in the variable 'mt' in the given file.
void save(const char* fname, const mat_type mt) {
    FILE* ofp;
    int r,c;
    
    ofp = fopen(fname, "w");
    assert(ofp);
    for (r = 0; r < N; ++r) {
        for (c = 0; c < N; ++c) {
            fprintf(ofp, "%d ", mt[r][c]);
        }
        fprintf(ofp,"\n");
    }

    fclose(ofp);
}

// Add the 3x3 matrix stored in 'src1' and 'src2' and store it in 'dst'.
void add_mat(mat_type dst, const mat_type src1, const mat_type src2) {
    int r,c;
    
    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            dst[r][c] = src1[r][c] + src2[r][c];
        }
    }
}

int main(void) {
    char file_name1[260];
    char file_name2[260];
    char file_name3[260];
    mat_type mat1, mat2, mat3;
    
    printf("first matrix file: ");
    gets(file_name1);
    printf("second matrix file: ");
    gets(file_name2);
    printf("result file: ");
    gets(file_name3);
    
    if(load(file_name1, mat1) == -1) {
        printf("first file error\n");
    }
    if(load(file_name2, mat2) == -1) {
        printf("second file error\n");
    }

    add_mat(mat3, mat1, mat2);
    save(file_name3, mat3);

    return 0;
}