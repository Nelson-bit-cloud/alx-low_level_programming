#include"main.h"

/**
 * get_bit - prog returns the value of a bit at a given index.
 * @n: number to check bits in
 * @index: index at which to check bit
 *
 * Return: value of the bit, or -1 if there is an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divisor, check;
	/* Check if the index is out of bounds*/
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	/*Create a divisor with a single bit set at the specified index*/
	divisor = 1 << index;
	/*Use bitwise AND to check if the bit at the specified index is set*/
	check = n & divisor;
	/*If the bit is set, return 1; otherwise, return 0*/
	if (check == divisor)
		return (1);
	return (0);
}
