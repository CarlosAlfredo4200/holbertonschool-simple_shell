#include "myShell.h"

/**
 **_strcat(char *dest, char *src)- a function that concatenates two strings.
 *@dest: Char input
 *@src: Char input
 *
 * Return: Always 0.
 */

 
/**
 * *_strdup - copies the input string
 * @string: input string
 *
 * Return: *ptr to the copied string or  NULL (if Error)
 */
char *_strdup(char *string)
{
	char *dup;
	unsigned int i = 0, length = 0;

	if (string == NULL)
		return (NULL);

	while (string[length])
		length++;

	dup = malloc(sizeof(char) * (length + 1));

	if (dup == NULL)
		return (NULL);

	while ((dup[i] = string[i]) != '\0')
		i++;

	return (dup);
}
