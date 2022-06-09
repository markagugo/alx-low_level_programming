#include "main.h"

/**
 * more_numbers - Prints 0-14
 * Return: nothing
 */

void more_numbers(void)
{
	int a, b;

	b = 0;
	while (b < 10)
	{
		a = 0;
		while (a < 15)
		{
			if (a > 9)
				_putchar(a / 10 + '0');
			_putchar(a % 10 + '0');
			a++;
		}
		_putchar('\n');
		b++;
	}
}

