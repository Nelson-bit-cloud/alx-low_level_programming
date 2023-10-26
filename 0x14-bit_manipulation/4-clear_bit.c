#include "main.h"
#include <stdlib.h>
/**
 * clear_bit - This prog sets the value of a bit to 0 at a given index
 * @n: parameter
 * @index: index
 * Return: 1 if success, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/*Check if the index is out of bounds*/
	if (index > sizeof(n) * 8)
		return (-1);
	/*Use bitwise AND with a negated set bit to clear the bit*/
	*n &= ~(1 << index);
	/*Return 1 to indicate successful bit clearing*/
	return (1);
}
