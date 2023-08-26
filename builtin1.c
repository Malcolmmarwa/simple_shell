#include "SHLIB_H"

/**
 * _jmshexit - exit shell
 * @info: Structure containing content arguments.
 *  Return: exits with exit status
 *         (0) if info.argv[0] != "exit"
 */
int _jmshexit(strinput_array_gen*info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _errorAlphaToInterger(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			PrintError(info, "Illegal number: ");
			_inputStrPrint(info->argv[1]);
			_writechar('\n');
			return (1);
		}
		info->err_num = _errorAlphaToInterger(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _jmshcd - changes current directory of the process
 * @info: Structure containing content arguments.
 *  Return: Always 0
 */
int _jmshcd(strinput_array_gen*info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcomparision(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		PrintError(info, "can't cd to ");
		_inputStrPrint(info->argv[1]), _writechar('\n');
	}
	else
	{
		_setEnvironment(info, "OLDPWD", _getenv(info, "PWD="));
		_setEnvironment(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _jmshhelp(strinput_array_gen*info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
