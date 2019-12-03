#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[10], tel[20];
    int save;
};

typedef struct person PERSON;

int main(void) {
    int i;
    PERSON per;

    FILE *in, *out;

    out = fopen("12_6.dat", "wb");

    for (i = 0; i < 3; i++) {
        printf("%d번째 고객 이름: ", i + 1);
        scanf("%s", per.name);

        printf("연락처: ");
        scanf("%s", per.tel);

        printf("저축액: ");
        scanf("%d", &per.save);

        fwrite(&per, sizeof(PERSON), 1, out);
    }

    fclose(out);

    in = fopen("12_6.dat", "rb");

    if (in == NULL) {
        printf("해당 파일이 없음\n");
        exit(1);
    }
    printf("================================\n");
    printf("    고객명      연락처      저축액\n");
    printf("================================\n");

    while(fread(&per, sizeof(PERSON), 1, in) == 1) {
        printf("%10s %10s %5d\n", per.name, per.tel, per.save);
    }

    fclose(in);

    return 0;
}