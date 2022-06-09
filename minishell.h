/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:42 by johrober          #+#    #+#             */
/*   Updated: 2022/06/09 15:44:59 by johrober         ###   ########.fr       */
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

typedef struct s_shell {
	/* int	running; */
	/* int	pid; */
	char			*prompt;
	struct termios	termios_shell;

}				t_shell;

//////////////////////////////////////////////////
////////////		minishell		//////////////
//////////////////////////////////////////////////

/********	main.c	*******************/
int		main(void);

/********	signal_handler.c	*******/
void	set_signal_handlers(void);
void	receive(int signum);

/********	tshell.c		***********/
void	init_tshell(t_shell *shell);


#endif
