#include "main.h"

/* free_data - Frees data structure */
void free_data(data_shell *datash)
{
    unsigned int i;

    /* Free memory associated with environment variables */
    for (i = 0; datash->_environ[i]; i++)
    {
        free(datash->_environ[i]);
    }

    free(datash->_environ); /* Free the array of environment variable strings */
    free(datash->pid); /* Free the process ID string */
}

/* set_data - Initializes the data structure */
void set_data(data_shell *datash, char **av)
{
    unsigned int i;

    datash->av = av; /* Set the argument vector */
    datash->input = NULL; /* Initialize input to NULL */
    datash->args = NULL; /* Initialize args to NULL */
    datash->status = 0; /* Initialize status to 0 */
    datash->counter = 1; /* Initialize counter to 1 */

    /* Count the number of environment variables in the 'environ' array */
    for (i = 0; environ[i]; i++)
        ;

    /* Allocate memory for the _environ array to store environment variables */
    datash->_environ = malloc(sizeof(char *) * (i + 1));

    /* Copy environment variable strings into _environ */
    for (i = 0; environ[i]; i++)
    {
        datash->_environ[i] = _strdup(environ[i]);
    }

    datash->_environ[i] = NULL; /* Terminate the _environ array with NULL */
    datash->pid = aux_itoa(getpid()); /* Convert the process ID to a string and store it */
}

/* main - Entry point for the shell program */
int main(int ac, char **av)
{
    data_shell datash;
    (void) ac; /* Suppress unused parameter warning */

    signal(SIGINT, get_sigint); /* Set up a signal handler for SIGINT (Ctrl+C) */
    set_data(&datash, av); /* Initialize the data structure with arguments and environment variables */
    shell_loop(&datash); /* Start the shell loop */
    free_data(&datash); /* Free memory associated with the data structure */

    if (datash.status < 0)
        return (255); /* Return 255 if status is less than 0 */
    return (datash.status); /* Return the status of the shell */
}

