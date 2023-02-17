/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:46:08 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/16 19:20:25 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	verif_num_args(char **string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

int	verif_exit_1(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (1);
		i++;
	}
	return (0);
}

int	lexit(t_var *shell)
{
	char **args;

	if (shell->string)
	{
		args = ft_split(shell->string->content, ' ');
		if (verif_exit_1(shell->string->content))
			printf("letter(s) in the argument\n");
		else if (verif_num_args(args) > 1)
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		ft_putstr_fd("exit\n", 1);
		exit(ft_atoi(args[0]));
	}
	ft_putstr_fd("exit\n", 1);
	exit(0);
}
