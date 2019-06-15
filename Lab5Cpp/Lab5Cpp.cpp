#include "pch.h"
#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *f1, *f2, *h;
	char s[1000];

	f1 = fopen("f1.txt", "r");
	f2 = fopen("f2.txt", "r");
	if (f1 == NULL || f2 == NULL)
	{
		printf("File(s) not found\n");
		return 1;
	}
	h = fopen("h.txt", "w");
	while (fgets(s, 1000, f1) != NULL)
		fprintf(h, "%s", s);
	f1 = fopen("f1.txt", "w");
	while (fgets(s, 1000, f2) != NULL)
		fprintf(f1, "%s", s);
	f2 = fopen("f2.txt", "w");
	fclose(h);
	h = fopen("h.txt", "r");
	while (fgets(s, 1000, h) != NULL)
		fprintf(f2, "%s", s);
	printf("Done\n");
	fclose(f1);
	fclose(f2);
	fclose(h);
	getch();
}