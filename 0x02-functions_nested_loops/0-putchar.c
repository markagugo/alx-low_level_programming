#include "main.h"

/**
 * main -  prints _putchar, followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch[] = "_putchar";
	
	for (int i = 0; i < 8; i++)
	{
		_putchar(ch[i]);
	}

	_putchar('\n');

	return (0);
}
