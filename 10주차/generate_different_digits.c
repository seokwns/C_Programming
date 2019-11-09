#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
/**
* @brief : generate and return a random digit in 0~9
* @return : a digit in 0~9
* @param	 : none
*/
int generate_a_digit() {
	return (rand()%10);
}

/**
* @brief : check digit duplication
* @return : return true if all digits of the number are different, false otherwise.
* @param	 : 	num - a 3-digits number to be checked for digit duplication.
*/
int is_different_digits(int num) {
	int digits[3];
	int is_different = 1; 

	digits[0] = num % 10;
	digits[1] = (num/10) % 10;
	digits[2] = (num/100) % 10;
	if ((digits[0] == digits[1]) ||
		(digits[0] == digits[2]) ||
		(digits[1] == digits[2]) )
		is_different = 0;

	return is_different;
}

int generate_target_number() {
	int nums[3] = {generate_a_digit(), -1, -1};
    int i = 1, j, tmp, looping;
    int result = 0;
    
    while (i < 3) {
        looping = 1;
        while(looping == 1) {
            tmp = generate_a_digit();
            for (j = 0; j < i; j++) {
                if (nums[j] == tmp) {
                    j = -1;
                    break;
                }
            }
            if (j != -1) {
                nums[i] = tmp;
                looping = 0;
            }
        }
        i++;
    }

    for (i = 0; i < 3; i++) {
        result = result * 10 + nums[i];
    }

    return result;
}

int main(void) {
    int n = generate_target_number();
    printf("%d, %d\n", n, is_different_digits(n));
    return 0;
}