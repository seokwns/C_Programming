#include <stdio.h> 
// print a Square Matrix M of order n
void print_nxn(int n, double M[n][n]) {
    int row, col;
    for (row=0; row<n; row++) {
	printf("    [ ");
	for (col=0; col<n; col++)
	    printf("%6.2lf ", M[row][col]);
	printf("]\n");
    }
}

// Compute the determinant of a Square Matrix M of order n
double determinant(int n, double M[n][n]) {
    double ratio, det;
    int i, j, k;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (j > i){
                ratio = M[j][i] / M[i][i];
                for(k = 0; k < n; k++){
                    M[j][k] -= ratio * M[i][k];
                }
            }
        }
    }

    det = 1; //storage for determinant
    for(i = 0; i < n; i++)
        det *= M[i][i];
    
    return det;
}

int main(void) {
    double M1[3][3] = { {1.7, 3.2, 2.5},
			{2.3, 4.1, 0.7},
			{1.0, 2.0, 3.0} };
    double M2[4][4] = { {2.0, 1.0, 2.0, 1.0},
    		        {1.7, 3.2, 2.5, 3.0},
			{2.3, 4.1, 0.7, 2.0},
			{1.0, 2.0, 3.0, 4.0} };

    printf("Matrix M1 = \n");
    print_nxn(3, M1);
    printf("det(M1) = %lf\n", determinant(3, M1));
    
    printf("Matrix M2 = \n");
    print_nxn(4, M2);
    printf("det(M2) = %lf\n", determinant(4, M2));
    
    return 0;
}