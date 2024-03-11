#include <stdio.h>


void printCharBinary(char *str)
{
	while (*str)
	{
		int i = 7;
		while (i >= 0)
		{
			if ((*str << i) & 128)
				printf("1");
			else
				printf("0");
			i--;
		}
		printf(" ");
		str++;
	}
    printf("\n");
}

int main() {
    char ch[] = "A";

    // printf("Enter a character: ");
    // scanf("%s", ch);

    printf("Binary representation (8 bits) of '%s': ", ch);
    printCharBinary(ch);

    return 0;
}
