#include <stdio.h>

struct account {
    char accountNumber[12];
    char owner[20];
    unsigned int balance;
};

void input(struct account *p, int num) {
    if (num > 0) {
        p -> balance += num;
    }
}

void output(struct account *p, int num) {
    if (num < 0) {
        if (p -> balance + num >= 0) {
            p -> balance += num;
        }
    }
}

void ACprint(struct account *p) {
    printf("Account Number : %s\n", p -> accountNumber);
    printf("Owner : %s\n", p -> owner);
    printf("Balance: %d\n\n", p -> balance);
}

int main(void) {
    struct account a1 = {"123-4567", "Hong_Gil_Dong", 0};
    ACprint(&a1);
    input(&a1, 5000);
    ACprint(&a1);
    output(&a1, -2500);
    ACprint(&a1);

    return 0;
}