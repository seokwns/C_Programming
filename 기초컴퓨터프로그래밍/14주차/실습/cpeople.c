#include <stdio.h>
#include <stdlib.h>
#define LEN 20

typedef struct PERSON_DATA {
    int id;
    char name[20];
    int birth;
    int death;
} PersonData;

void swap(PersonData *p1, PersonData *p2) {
    PersonData tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(void) {
    FILE *PeopleData = fopen("cpeople.csv", "r");
    FILE *output = fopen("cpeople_birth.csv", "w");
    PersonData *pData = (PersonData*)malloc(sizeof(PersonData) * LEN);
    
    int i, j;
    for (i = 0; fscanf(PeopleData, "%d,%[^,],%d,%d\n", &pData[i].id, &pData[i].name, &pData[i].birth, &pData[i].death) != EOF; i++) ;
    
    for (i = 0; i < LEN; i++) {
        for (j = i; j < LEN; j++) {
            if (pData[i].birth > pData[j].birth) swap(&pData[i], &pData[j]);
        }
    }

    for (i = 0; i < LEN; i++) {
        fprintf(output, "%d,%s,%d,%d\n", pData[i].id, pData[i].name, pData[i].birth, pData[i].death);
    }

    fclose(PeopleData);
    fclose(output);

    return 0;
}
