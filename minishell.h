/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:42 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 16:49:10 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>

typedef struct s_env_var
{
	char	*name;
	char	*value;
}				t_env_var;

typedef struct s_shell {
	/* int	running; */
	/* int	pid; */
	char			*prompt;
	struct termios	termios_shell;
	t_env_var		**env;
}				t_shell;

//////////////////////////////////////////////////
////////////		minishell		//////////////
//////////////////////////////////////////////////

/********	main.c	*******************/
int		main(int argc, char **argv, char **env);

/********	signal_handler.c	*******/
void	set_signal_handlers(void);
void	receive(int signum);

/********	tshell.c		***********/
void	init_tshell(t_shell *shell, char **env);


//////////////////////////////////////////////////
////////////		tenv			//////////////
//////////////////////////////////////////////////

/********	tenv_init.c		***********/
t_env_var	*init_env_var(char *name, char *value);
t_env_var	*parse_env_var(char *env_str);
t_env_var	**init_env(char **env_str);

/********	tenv_destroy.c		***********/
void	destroy_env_var(t_env_var *var);
void	destroy_env(t_env_var **env);

#endif
