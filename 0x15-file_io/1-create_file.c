#include "main.h"

/**
 * create_file - Create a file named filename
 * @filename: Name of the file
 * @text_content: A NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure (file cannot be created,
 *         file cannot be written, write "fails", etc...)
 */
int create_file(const char *filename, char *text_content)
{
	int _file, _write, text_len = 0;

	if (!filename)
		return (-1);

	_file = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (_file == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[text_len])
			text_len++;

		_write = write(_file, text_content, text_len);
		if (_write == -1)
		{
			close(_file);
			return (-1);
		}
	}

	close(_file);
	return (1);
}
