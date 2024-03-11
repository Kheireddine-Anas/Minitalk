#include <stdio.h>

// Function to print the binary representation of a character with exactly 8 bits
void printCharBinary(char *str) {
    // Print exactly 8 bits
	while (*str){
		int i = 7;
		while (i >= 0){
			// Check if the i-th bit is set (1) or unset (0)
			if ((*str >> i) & 1) {
				printf("1");
			} else {
				printf("0");
			}
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
