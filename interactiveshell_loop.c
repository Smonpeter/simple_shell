#include "main.h"

/**
 * without_comment - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
    int i, up_to;

    up_to = 0;
    for (i = 0; in[i]; i++)
    {
        if (in[i] == '#')
        {
            if (i == 0)
            {
                /* If the input begins with a comment character, free the input and return NULL */
                free(in);
                return (NULL);
            }

            if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
                up_to = i;
        }
    }

    if (up_to != 0)
    {
        /* If there was a comment, modify the input string to remove the comment portion */
        in = _realloc(in, i, up_to + 1);
        in[up_to] = '\0';
    }

    return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
    int loop, i_eof;
    char *input;

    loop = 1;
    while (loop == 1)
    {
        write(STDIN_FILENO, "^-^ ", 4); /* Display the shell prompt */
        input = read_line(&i_eof); /* Read user input */
        if (i_eof != -1)
        {
            input = without_comment(input); /* Remove comments from the input */
            if (input == NULL)
                continue; /* Continue the loop if input was entirely a comment */

            if (check_syntax_error(datash, input) == 1)
            {
                datash->status = 2; /* Set status to indicate a syntax error */
                free(input);
                continue;
            }
            input = rep_var(input, datash); /* Replace variables in the input */
            loop = split_commands(datash, input); /* Split and execute commands */
            datash->counter += 1; /* Increment the command counter */
            free(input);
        }
        else
        {
            loop = 0; /* Exit the loop when end-of-file is encountered */
            free(input);
        }
    }
}

