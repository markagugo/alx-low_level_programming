#include "main.h"
/**
* append_text_to_file- function
* @filename: file to create
* @text_content: null term str to write to file
*
* Descripton: function to append text at end of file
* Return: 1 success, -1 fail
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, sz = 0, wr;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND, S_IRGRP | S_IWGRP | S_IROTH);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";
	while (text_content[sz] != '\0')
		sz++;

	wr = write(fd, text_content, sz);

	if (wr == -1)
	return (-1);

	close(fd);
	return (1);

}
