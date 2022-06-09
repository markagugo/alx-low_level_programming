#include "main.h"

/**
 * print_most_numbers - Print numbers from 0-9 except 2&4
 * Return: nothing
 */

void print_most_numbers(void)
{
	int num = 0;

	while (num <= 9)
	{
		if (num != 2 && num != 4)
			_putchar(num + '0');
		num++;
	}
	_putchar('\n');
}
