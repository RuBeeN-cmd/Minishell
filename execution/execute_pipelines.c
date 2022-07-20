/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipelines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:39:08 by johrober          #+#    #+#             */
/*   Updated: 2022/07/13 17:19:51 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	execute(t_shell *shell, t_cmd **list)
{
	int		nb_pipe;
	int		input[2];
	int		output[2];
	int		count;
	int		status;
	pid_t	pid;

	nb_pipe = ft_tablen((const void **)list) - 1;
	count = -1;
	while (++count <= nb_pipe)
	{
		pipe(output);
		if (nb_pipe == 0)
			pid = fork_cmd(shell, list[count], NULL, NULL);
		else if (count == 0)
			pid = fork_cmd(shell, list[count], NULL, (int *)output);
		else if (count == nb_pipe)
			pid = fork_cmd(shell, list[count], (int *)input, NULL);
		else
			pid = fork_cmd(shell, list[count], (int *)input, (int *)output);
		if (count > 0)
			close(input[0]);
		close(output[1]);
		input[0] = output[0];
		input[1] = output[1];
	}
	if (count <= nb_pipe)
		close(input[0]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		return (0);
	return (WEXITSTATUS(status));
}

pid_t	fork_cmd(t_shell *shell, t_cmd *cmd, int *input, int *output)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (!pid)
	{
		if (input)
			dup2(input[0], STDIN_FILENO);
		if (input)
			close_pipe(input);
		if (output)
			dup2(output[1], STDOUT_FILENO);
		if (output)
			close_pipe(output);
		execute_cmd(shell, cmd);
	}
	return (pid);
}

void	close_pipe(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
}

int	execute_cmd(t_shell *shell, t_cmd *cmd)
{
	char	*exec_path;

	cmd->env = env_to_string_array(shell);
	if (!ft_str_contains(cmd->argv[0], '/'))
	{
		if (!call_builtin_if_exists(shell, cmd))
		{	
			exec_path = search_executable_path(shell, cmd->argv[0]);
			if (!exec_path)
			{
				ft_printf_fd(2, "%s: command not found.\n", cmd->argv[0]);
				exit(127);
			}
			free(cmd->argv[0]);
			cmd->argv[0] = exec_path;
		}
	}
	execve(cmd->argv[0], cmd->argv, cmd->env);
	perror(cmd->argv[0]);
	exit(EXIT_FAILURE);
}

char	*search_executable_path(t_shell *shell, char *exec)
{
	t_env_var	*path;
	char		**path_tab;
	char		*exec_path;
	int			count;

	exec_path = NULL;
	if (!ft_str_contains(exec, '/'))
	{
		path = get_env_var(shell, "PATH");
		if (path)
		{
			path_tab = ft_split(path->value, ':');
			count = -1;
			while (path_tab[++count] && !exec_path)
				exec_path = try_path(path_tab[count], exec);
			ft_free_tab((void **)path_tab);
		}
	}
	return (exec_path);
}

char	*try_path(char *path, char *exec)
{
	char *exec_path;

	exec_path = NULL;
	if (ft_strlen(path))
		exec_path = ft_strnjoin(exec_path, path, ft_strlen(path));
	if (ft_strlen(exec_path) && exec_path[ft_strlen(exec_path) - 1] != '/')
		exec_path = ft_strnjoin(exec_path, "/", 1);
	exec_path = ft_strjoin(exec_path, exec);
	if (!access(exec_path, F_OK))
		return (exec_path);
	else
		free(exec_path);
	return (NULL);
}

/* int	handle_redirections(t_shell *shell, t_cmd_element *list) */
/* { */
	
/* } */

int	count_pipes(t_cmd_element *list)
{
	int				pipes;
	t_cmd_element	*current;

	pipes = 0;
	current = list;
	while (current)
	{
		if (current->type == PIPE)
			pipes++;
		current = current->next;
	}
	return (pipes);
}
