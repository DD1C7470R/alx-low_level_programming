#include "main.h"
/**
 * main - Print "_putchar" followed by a new line.
 * Description: You are not allowed to include standard libraries.
 * Return: 0
 */
int main(void)
{
	char school_printer[] = "_putchar";
	int i = 0;

	while (school_printer[i] != '\0')
	{
		_putchar(school_printer[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}

