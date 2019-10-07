/*
Complete the source code below to make a program that meets the following requirements.

The value of the variable n is the number of valid elements in the array a.
The program is going to remove one element from the array a 
    and replace it with the last (valid) element of the array. 
    
After the replacement, the number of valid elements of the array will be decreased by 1.

If the element to be removed is the last element, 
    no replacement takes place, 
    but just the number of valid elements needs to be decreased by 1.

The order of the element to be removed is read from user input into the variable j. 
If the input value is larger than the number of valid elements or less than 1, 
    it will be set to the number of valid elements.

The program should print out all valid elements in sequence after removing  
The followings are some example execution results

Execution Result #1
2  
11 55 33 44 
Execution Result #2
3  
11 22 55 44 
Execution Result #3
6  
11 22 33 44 
*/


#include <stdio.h>

int main(void) {
    int a[10] = {11, 22, 33, 44, 55};
    int i, j, n = 5;
    
    scanf("%d", &j);

    if (j < 1 || j >= 5) {
        a[4] = 55;
    } else {
        a[j - 1] = 55;
    }
    n--;

    for(i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
	
    return 0;
}