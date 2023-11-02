#include "main.h"

/**
 *  * append_text_to_file - appends text at the end of a file
 *   * @filename: filename.
 *    * @text_content: added content.
 *     *
 *      * Return: 1 if the file exists. -1 if the fails does not exist
 *       * or if it fails.
 *        */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;/*File descriptor for the file to append to*/
	int nletters;/*Number of letters in text_content*/
	int rwr;/*Number of letters written to the file*/

	/*Check if the filename is NULL*/
	if (!filename)
	return (-1);

	/*Open the file for appending with write-only access*/
	fd = open(filename, O_WRONLY | O_APPEND);

	/*Check if the file open operation failed*/
	if (fd == -1)
	return (-1);

	/*If text_content is not NULL, append its content to the file*/
	if (text_content)
		{
			for (nletters = 0; text_content[nletters]; nletters++)
			;

			rwr = write(fd, text_content, nletters);

			/*Check if the write operation failed*/
			if (rwr == -1)
			return (-1);
		}

			/* Close the file */
			close(fd);

			/*Return 1 to indicate success*/
			return (1);
}
