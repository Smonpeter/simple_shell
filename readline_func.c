#include "main.h"

/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
    char *input = NULL;  /* Initialize a pointer to the input string */
    size_t bufsize = 0;   /* Initialize the buffer size */

    *i_eof = getline(&input, &bufsize, stdin);  /* Read a line from the standard input and store it in 'input' */

    return (input);  /* Return the input string */
}

