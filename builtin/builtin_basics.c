/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:33:38 by johrober          #+#    #+#             */
/*   Updated: 2022/06/25 15:38:19 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(t_shell *shell, int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		if (!shell->pwd)
			shell->pwd = getcwd(shell->pwd, 0);
		ft_printf("%s\n", shell->pwd);
	}
	else
		printf("pwd: too many arguments\n");
}

void	cd(t_shell *shell, int argc, char **argv)
{
	int			ret;
	t_env_var	*pwd;
	t_env_var	*old_pwd;
	char		*path;

	if (argc == 1 || argc == 2)
	{
		pwd = get_env_var(shell, "PWD");
		old_pwd = get_env_var(shell, "OLDPWD");
		if (argc == 1)
			path = "~";
		else
			path = argv[1];
		if (old_pwd && pwd)
			old_pwd->value = pwd->value;
		ret = chdir(path);
		shell->pwd = getcwd(shell->pwd, 0);
		if (pwd)
			pwd->value = shell->pwd;
		if (ret == -1)
			perror("Error ");
	}
	else
		printf("cd: too many arguments");
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
}