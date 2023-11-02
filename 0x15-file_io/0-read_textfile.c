#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;/*File descriptor for the opened file*/
	ssize_t nrd;/*Number of bytes read from the file*/
	ssize_t nwr;/*Number of bytes written to standard output*/
	char *buf; /*Buffer to store file content*/

	/*Check if the filename is NULL*/
	if (!filename)
	return (0);

	/*Open the file for reading*/
	fd = open(filename, O_RDONLY);

	/*Check if the open operation failed*/
	if (fd == -1)
	return (0);

	/*Allocate memory for a buffer to store the file content*/
	buf = malloc(sizeof(char) * (letters));
	if (!buf)
	return (0);

	/*Read from the file into the buffer*/
	nrd = read(fd, buf, letters);

	/*Write the contents of the buffer to the standard output*/
	nwr = write(STDOUT_FILENO, buf, nrd);

	/*Close the file*/
	close(fd);

	/*Free the memory allocated for the buffer*/
	free(buf);

	/*Return the number of letters written to the standard output*/
	return (nwr);
}
