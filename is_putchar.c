#include <unistd.h>

/**
 * is_putchar - writes the character c to stdout
 * also returns an integer
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int is_putchar(char c)
{
	return (write(1, &c, 1));
}
