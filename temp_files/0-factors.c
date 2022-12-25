#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX1 4096
#define MAX2 1024

/**
 * _atoll - a helper function that converts a string to a long double
 * @str: the string to be converted
 * Return: returns the converted integer
 */
long double _atoll(char *str)
{
	int i;

	long double result = 0;

	if (str == NULL || *str == '\0')
		return (0);
	for (i = 0; str[i] != '\0' && str[i] != ' ' && isdigit(str[i]); i++)
	{
		result = (result * 10) + (str[i] - '0');
	}
	return (result);
}

/**
 * print_factors - a helper function that prints factors of a number
 * @num: the number to be computed
 * Return: returns void
 */

void print_factors(long double num)
{
	long double i, temp;

	if (num <= 1)
	{
		dprintf(2, "<num> must be greater than 1\n");
		return;
	}
	for (i = 2; i < num; i++)
	{
		if ((long int)num % (int)i == 0)
		{
			temp = num / i;
			printf("%.0Lf=%.0Lf*%.0Lf\n", num, temp, i);
			return;
		}
	}
	printf("%.0Lf has no factors\n", num);
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
	int fd, i, j;
	char buf[MAX1], temp[MAX2];

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
	n = read(fd, buf, MAX1 - 2);
	if (n == -1)
	{
		perror("Failed to read");
		exit(3);
	}
	buf[MAX1 - 1] = '\0';
	for (i = 0, j = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] != '\n')
		{
			temp[j++] = buf[i];
			continue;
		}
		temp[j] = '\0';
		j = 0;
		num = _atoll(temp);
		printf("%0.Lf\n", _atoll(temp));
		if (num == 0)  /* atoll returns zero on failure */
			break;
		print_factors(num);
	}
	close(fd);
	return (0);
}
