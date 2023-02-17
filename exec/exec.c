/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:28:30 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/16 17:43:56 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

// TODO cat
// TODO redirection
// buildin

char	**ft_create_tab(t_var *shell)
{
	char	**tmp;
	int		i;
	t_list	*flag;

	flag = shell->flag;
	i = 0;
	while (flag)
	{
		flag = flag->next;
		i++;
	}
	tmp = malloc(sizeof(char *) * i + 2);
	tmp[0] = shell->cmd_arg;
	i = 1;
	while (shell->flag)
	{
		tmp[i] = shell->flag->content;
		shell->flag = shell->flag->next;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	builtin_fork(t_var *shell, char **tmp_env)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(shell->cmd_arg, "echo") == 0)
		echo(shell);
	else if (ft_strcmp(shell->cmd_arg, "pwd") == 0)
		printf("%s\n", pwd(tmp_env));
	else
		execve(ft_find_path(tmp_env, shell->cmd_arg), ft_create_tab(shell),
			tmp_env);
	if (flag == -1)
		return ;
}

void	child_process(t_var *shell, char **tmp_env)
{
	close(shell->pipe[0]);
	builtin_fork(shell, tmp_env);
	exit(1);
}

int	process(t_var *shell, char **tmp_env, int tmp)
{
	pid_t	pid;
	int		status;

	status = 0;
	pipe(shell->pipe);
	// TODO process open file and redirection
	pid = fork();

	if (pid == 0)
	{
		dup2(tmp, STDIN_FILENO);
		if (shell->next)
			dup2(shell->pipe[1], STDOUT_FILENO);
		child_process(shell, tmp_env);
	}
	else
	{
		dup2(shell->pipe[0], tmp);
		close(shell->pipe[1]);
		wait(NULL);
	}
	return (status);
}

void	exec(t_var *shell, char **tmp_env)
{
	int	tmp;

	tmp = dup(STDIN_FILENO);
	if (!builtin_no_fork(shell, tmp_env))
		return ;
	else
	{
		while (shell)
		{
			redirect(shell);
			process(shell, tmp_env, tmp);
			shell = shell->next;
		}
	}
}
