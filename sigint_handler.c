#include "main.h"

/**
 * get_sigint - Signal handler for Ctrl+C (SIGINT)
 *
 * @sig: Signal number (unused in this function)
 */
void get_sigint(int sig)
{
    (void)sig;  /* Suppress the unused parameter warning*/

    /* Write a message to the standard output to indicate Ctrl+C has been received.*/
    write(STDOUT_FILENO, "\n^-^ ", 5);
}
