#include <stdio.h>
#include <stdlib.h>

int to_int(char *str)
{
	int num;
	while (*str == 9 || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str - 48);
	return (num);
}