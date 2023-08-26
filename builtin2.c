#include "SHLIB-H"

/**
 * _jmshhistory - to display the history list
 * @info: Structure containing content arguments.)
 *Return: (0) success
 */
int _jmshhistory(strinput_array_gen*info)
{
	PrintList(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to str
 * @info: parameter
 * @str:  str alias
 *
 * Return: ( 0 )on success, (1) on error
 */
int unset_alias(strinput_array_gen*info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = DeleteNodeAtIndex(&(info->alias),
		getNodeIndex(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

int set_alias(strinput_array_gen*info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - printsalias string
 * @node:alias node
 *
 * Return:(0) on success,(1)error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _jmshalias - immitates the alias builtin.
 * @info: Structure containing content arguments.
 *  Return: Always 0
 */
int _jmshalias(strinput_array_gen*info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
