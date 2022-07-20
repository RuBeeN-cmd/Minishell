/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:33:38 by johrober          #+#    #+#             */
/*   Updated: 2022/07/14 17:42:57 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_shell *shell, int argc, char **argv)
{
	char	*pwd;

	(void)shell;
	(void)argv;
	pwd = NULL;
	if (argc == 1)
	{
		pwd = getcwd(pwd, 0);
		ft_printf("%s\n", pwd);
		free(pwd);
		exit(EXIT_SUCCESS);
	}
	else
		ft_printf_fd(2, "pwd: too many arguments\n");
}

void	cd(t_shell *shell, int argc, char **argv)
{
	int			ret;
	t_env_var	*pwd;
	t_env_var	*old_pwd;
	char		*path;

	if (argc == 2)
	{
		pwd = get_env_var(shell, "PWD");
		old_pwd = get_env_var(shell, "OLDPWD");
		path = argv[1];
		if (old_pwd && pwd)
		{
			free(old_pwd->value);
			old_pwd->value = pwd->value;
			pwd->value = NULL;
		}
		ret = chdir(path);
		if (pwd)
		{
			pwd->value = getcwd(pwd->value, 0);
			printf("New pwd: %s\n", pwd->value);
		}
		if (ret != -1)
			exit(EXIT_SUCCESS);
	}
	else
		ft_printf_fd(2, "cd: wrong number of arguments\n");
}

void	echo(t_shell *shell, int argc, char **argv)
{
	int	n_flag;
	int	i;

	(void) shell;
	n_flag = 0;
	i = 1;
	if (argc == 1)
		ft_putchar_fd('\n', 1);
	else
	{
		if (!ft_strcmp(argv[1], "-n"))
		{
			n_flag = 1;
			i++;
		}
		while (i < argc)
		{
			ft_putstr_fd(argv[i], 1);
			if (i < argc - 1)
				ft_putchar_fd(' ', 1);
			if (!n_flag && i == argc - 1)
				ft_putchar_fd('\n', 1);
			i++;
		}
	}
	exit(EXIT_SUCCESS);
}

void	exit_builtin(t_shell *shell, int argc, char **argv)
{
	int	exit_status;

	(void)argv;
	if (argc > 2)
	{
		ft_printf_fd(2, "exit: too many arguments\n");
		return ;
	}
	if (argc == 1)
		exit_status = EXIT_SUCCESS;
	else
		exit_status = ft_atoi(argv[1]);
	destroy_tshell(shell);
	exit(exit_status);
}
