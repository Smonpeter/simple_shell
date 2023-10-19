#include "main.h"

/**
 * exit_shell - Exits the shell with the specified exit status.
 *
 * @datash: Data relevant (status and arguments).
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
    unsigned int ustatus;
    int is_digit;
    int str_len;
    int big_number;

    if (datash->args[1] != NULL)
    {
        ustatus = _atoi(datash->args[1]);
        is_digit = _isdigit(datash->args[1]);
        str_len = _strlen(datash->args[1]);
        big_number = ustatus > (unsigned int)INT_MAX;

        /* Check if the argument is not a digit or if it exceeds integer limits */
        if (!is_digit || str_len > 10 || big_number)
        {
            get_error(datash, 2); /* Call the error handling function for exit command */
            datash->status = 2; /* Set the shell's status to 2 (error) */
            return (1);
        }

        datash->status = (ustatus % 256); /* Set the shell's status to the specified exit status */
    }

    return (0); /* Return 0 (success) */
}

