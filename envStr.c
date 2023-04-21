#include "myShell.h"
/**
 * envPrint - prints environment like printenv
 *
 * Return: 0
 */
int envPrint(void)
{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, strlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}

/**
 * compStr - lexicographically compares not more than count chars
 * from two strings and returns an integer based on the result.
 * @s1: first string
 * @s2: second string to compare to first string
 * @n: count of the comparison between s1 and s2
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 * Description: Src code file like GNU C library
 */


int compStr(char *s1, char *s2, int n)
{
  return strncmp(s1, s2, n);
}



/**
 * _getenv - prints environment like getenv
 * @var: environ variable
 *
 * Return: 0
 */
#include <string.h>

char *_getenv(char *var)
{
  int i;
  for (i = 0; environ[i]; i++)
    {
      if (strcmp(environ[i], var) == 0)
	return (&environ[i][strlen(var)]);
    }
  return (NULL);
}
