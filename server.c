#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void	show_num(int num)
{
	if (num > 9)
		show_num(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}
int	main(void)
{
	write(1, "PID : ", 7);
	show_num(getpid());
	write(1, "\n", 1);

}