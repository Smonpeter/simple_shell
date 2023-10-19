#include "main.h"

/**
 * exec_line - Executes built-in commands or external commands.
 *
 * @datash: Data relevant (arguments).
 * Return: 1 on success.
 */
int exec_line(data_shell *datash)
{
    int (*builtin)(data_shell *datash);

    if (datash->args[0] == NULL)
        return (1); /* Return 1 (success) if there are no arguments provided */

    builtin = get_builtin(datash->args[0]); /* Get the function pointer for the specified command */

    if (builtin != NULL)
        return (builtin(datash)); /* Execute the built-in command and return its result */

    return (cmd_exec(datash)); /* Execute external commands using cmd_exec function */
}

