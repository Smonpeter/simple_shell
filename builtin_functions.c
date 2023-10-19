#include "main.h"

/**
 * get_builtin - Retrieves the appropriate function pointer for a built-in command.
 *
 * @cmd: Command name.
 * Return: Function pointer for the built-in command.
 */
int (*get_builtin(char *cmd))(data_shell *)
{
    /* Array of structures that map command names to their corresponding functions */
    builtin_t builtin[] = {
        { "env", _env },
        { "exit", exit_shell },
        { "setenv", _setenv },
        { "unsetenv", _unsetenv },
        { "cd", cd_shell },
        { "help", get_help },
        { NULL, NULL } /* Sentinel element for the end of the array */
    };
    int i;

    for (i = 0; builtin[i].name; i++)
    {
        /* Compare the provided command name with entries in the 'builtin' array */
        if (_strcmp(builtin[i].name, cmd) == 0)
            break;
    }

    return (builtin[i].f); /* Return the function pointer for the specified built-in command */
}

