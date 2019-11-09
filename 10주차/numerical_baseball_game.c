#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_different_digits(int num);
int generate_target_number();
int guess_number();
int get_match_result(int target, int guessed);
void receive_match_result(int result, int guessed);

int main(void) {
    int max_try_time = 10;
    printf("최대 시도 횟수 입력 : ");
    scanf("%d", &max_try_time);

    int looping = 1, target, guessed, count = 0;
    target = generate_target_number();

    printf("target : %d\n", target);

    while(looping && count < max_try_time) {
        guessed = guess_number();
        receive_match_result(get_match_result(target, guessed), guessed);
        
        if(get_match_result(target, guessed) == 30) {
             looping = 0;
        }

        count++;
    }

    return 0;
}

int generate_a_digit() {
	return (rand()%10);
}

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

int guess_number() {
	int num;

	while (1) {
		printf("Enter your guess : ");
		scanf("%d",&num);

		if (num < 1000 && is_different_digits(num)) break;

		printf("Input Error !!! ? Wrong number format\n");
	}
	return num;
}

int get_match_result(int target, int guessed) {
    int n_strike = 0, n_ball = 0;

	int target_arr[3], guessed_arr[3];
    int i, j;

    for (i = 0; i < 3; i++, target /= 10, guessed /= 10) {
        target_arr[i] = target % 10;
        guessed_arr[i] = guessed % 10;

        if (target_arr[i] == guessed_arr[i]) n_strike++;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (target_arr[i] == guessed_arr[j] && i != j) n_ball++;
        }
    }

	return (n_strike * 10 + n_ball);
}

void receive_match_result(int result, int guessed) {
	int n_strike = result / 10, n_ball = result % 10;
	switch (result) {
		case 30: 
            printf("Congratulation !!!\n");
			break;
		case 0: 
            printf("Oops !!!\n");
			break;
		default: 
            printf("Nice try !!!\n");
	}

	printf("Your guess %d is [%d] strikes and [%d] balls\n", 
		guessed, n_strike, n_ball);
}
