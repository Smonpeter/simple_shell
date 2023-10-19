#include "main.h"

/**
 * get_help - Retrieve help messages according to the built-in command.
 *
 * @datash: Data structure containing arguments and input.
 * Return: Return 0 (success).
 */
int get_help(data_shell *datash)
{
    /* Check if no arguments are provided, and display general help */
    if (datash->args[1] == 0)
        aux_help_general();
    /* Check if the 'setenv' command is provided and display help for 'setenv' */
    else if (_strcmp(datash->args[1], "setenv") == 0)
        aux_help_setenv();
    /* Check if the 'env' command is provided and display help for 'env' */
    else if (_strcmp(datash->args[1], "env") == 0)
        aux_help_env();
    /* Check if the 'unsetenv' command is provided and display help for 'unsetenv' */
    else if (_strcmp(datash->args[1], "unsetenv") == 0)
        aux_help_unsetenv();
    /* Check if the 'help' command is provided and display help for 'help' */
    else if (_strcmp(datash->args[1], "help") == 0)
        aux_help();
    /* Check if the 'exit' command is provided and display help for 'exit' */
    else if (_strcmp(datash->args[1], "exit") == 0)
        aux_help_exit();
    /* Check if the 'cd' command is provided and display help for 'cd' */
    else if (_strcmp(datash->args[1], "cd") == 0)
        aux_help_cd();
    /* Check if the 'alias' command is provided and display help for 'alias' */
    else if (_strcmp(datash->args[1], "alias") == 0)
        aux_help_alias();
    else
    {
        /* Display an error message if the command is not recognized */
        write(STDERR_FILENO, datash->args[0], _strlen(datash->args[0]));
    }

    datash->status = 0; /* Set the status to 0 (success) */
    return (1); /* Return 1 to continue executing the shell */
}

