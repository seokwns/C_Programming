#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *gates, *fxor, *steve;
    gates = fopen("gates.txt", "rb");
    fxor = fopen("xor.txt", "rb"); // = gates ^ steve
    steve = fopen("steve.txt", "wb"); // = gates ^ (gates ^ steve) = steve
    
    char n, b1, b2;
    while (fread(&b1, sizeof(char), 1, gates) == 1) {
    	fread(&b2, sizeof(char), 1, fxor);
    	n = b1 ^ b2;
    	fwrite(&n, sizeof(char), 1, steve);
	}

    fclose(gates);
    fclose(fxor);
    fclose(steve);

    return 0;
}