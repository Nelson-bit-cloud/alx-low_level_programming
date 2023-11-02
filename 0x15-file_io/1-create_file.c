#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd; /*File descriptor for the created file*/
	int nletters; /*Number of letters in text_content*/
	int rwr; /*Number of letters written to the file*/

	/*Check if the filename is NULL*/
	if (!filename)
	return (-1);

	/*Create the file with write-only access and truncate it if it exists*/
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	/*Check if the file creation failed*/
	if (fd == -1)
	return (-1);

	/*If text_content is NULL, set it to an empty string*/
	if (!text_content)
	text_content = "";

	/*Count the number of letters in the text_content*/
	for (nletters = 0; text_content[nletters]; nletters++)
	;
	/*Write the text content to the file*/
	rwr = write(fd, text_content, nletters);

	/*Check if the write operation failed*/
	if (rwr == -1)
	return (-1);

	/* Close the file */
	close(fd);

	/* Return 1 to indicate success */
	return (1);
}
