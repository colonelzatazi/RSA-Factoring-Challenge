#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 100

/**
 * print_factors - a helper function that prints factors of a number
 * @num: the number to be computed
 * Return: returns void
 */
void print_factors(long double num)
{
	long double i, temp;

	for (i = 2; i < num; i++)
	{
		if ((long int)num % (int)i == 0)
		{
			temp = num / i;
			printf("%.0Lf=%.0Lf*%.0Lf\n", num, temp, i);
			return;
		}
	}
}

/**
 * main - the entry point of the program
 * @argc: command line argument count
 * @argv: an array of strings containing arguments
 * Description: a program that factorizes a number
 * Return: always 0 (SUCCESS)
 */
int main(int argc, char *argv[])
{
	int fd;
	char temp[MAX];

	long double n, num;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open");
		exit(2);
	}
	n = read(fd, temp, MAX - 1);
	if (n == -1)
	{
		perror("Failed to read");
		exit(2);
	}

	num = atoll(temp);

	print_factors(num);

	close(fd);
	return (0);
}
