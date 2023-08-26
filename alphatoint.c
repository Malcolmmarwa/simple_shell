#include "SHLIB_H"

/**
 * interarguement_counttive - (true) interarguement_counttive.
 * @info: structaddress.
 *
 * Return: (1)interarguement_counttive , (0) otherwise
 */
int interarguement_counttive(strinput_array_gen*info)
{
	return (isatty(STDIN_FILENO) && info->readfile_descriptor <= 2);
}

/**
 * is_delim - check if char arguement_countter is  delimeter
 * @c: char check
 * @delim: string delimeter
 * Return: (1) true, (0)  false
 */
int check_if_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_checkalphabet - check alphabetic chararguement_countter
 *@c: char arguement_countter to input
 *Return: (1)alphabetic, (0) otherwise
 */

int _checkalphabet(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_alphatoint - convert string to  integer.
 *@s: the string to convert
 *Return: (0) no numbers in string, converted number otherwise
 */

int _alphatoint(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
