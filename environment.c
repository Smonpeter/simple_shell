#include "main.h"

/**
 * cmp_env_name - Compares environment variable names with the name passed.
 * @nenv: Name of the environment variable
 * @name: Name passed for comparison
 *
 * Return: 0 if they are not equal, otherwise, returns the position of inequality.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0); /* Return 0 if the names are not equal. */
		}
	}

	return (i + 1); /* Return the position of inequality if they are not equal. */
}

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Name of the environment variable to retrieve.
 * @_environ: Array of environment variables.
 *
 * Return: Value of the environment variable if found, NULL if not found.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env to NULL and mov to 0. */
	ptr_env = NULL;
	mov = 0;

	/* Compare the name with all environment variables. */
	for (i = 0; _environ[i]; i++)
	{
		/* Check if name and env are equal. */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov); /* Return the value of the environment variable or NULL. */
}

/**
 * _env - Prints the environment variables.
 *
 * @datash: Data relevant (contains environment variables).
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{
		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j); /* Write the environment variable to stdout. */
		write(STDOUT_FILENO, "\n", 1); /* Write a newline character. */
	}
	datash->status = 0;

	return (1); /* Return 1 (success). */
}

