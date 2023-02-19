/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_no_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:29:40 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/17 16:27:51 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	builtin_no_fork(t_var *shell, char **tmp_env)
{
	if (!shell->cmd_arg)
		return (1);
	if (ft_strcmp(shell->cmd_arg, "cd") == 0)
		cd(shell, tmp_env);
	else if (ft_strcmp(shell->cmd_arg, "env") == 0)
		env(tmp_env);
	else if (ft_strcmp(shell->cmd_arg, "export") == 0)
		g_exit_statut = export(shell, tmp_env);
	else if (ft_strcmp(shell->cmd_arg, "exit") == 0)
		lexit(shell);
	return (1);
}
