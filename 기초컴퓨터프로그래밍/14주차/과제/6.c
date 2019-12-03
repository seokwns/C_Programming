#include <stdio.h> 
int main(void)
{
	char strA[128] = "Steven Paul \"Steve\" Jobs was an American businessman, inventor, and industrial designer.\n";
	char strB[128] = "He was the co-founder, chairman, and chief executive officer (CEO) of Apple, CEO and majority shareholder of Pixar.\n";
	char strAXB[128];
	char strAXBXA[128];
	char strAXBXB[128];

	int i;

	for (i=0; i<128; i++) 
		strAXB[i] = strA[i]^strB[i];

	for (i=0; i<128; i++) 
		strAXBXA[i] = strAXB[i]^strA[i];

	for (i=0; i<128; i++) 
		strAXBXB[i] = strAXB[i]^strB[i];

	printf("> A\n%s> B\n%s",strA,strB);
	printf("\n===== Results of XOR Operations =====\n");
	printf("> A XOR B\n%s\n",strAXB);
	printf("> (A XOR B) XOR A\n%s",strAXBXA);
	printf("> (A XOR B) XOR B\n%s",strAXBXB);

	return 0;
}