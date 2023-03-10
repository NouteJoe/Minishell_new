/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:01:24 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/24 16:07:49 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	dollar(void)
{
	printf("%d\n", g_exit_statut);
	return (0);
}

int	echo(t_var *shell)
{
	if (ft_strcmp(shell->string->content, "$") == 0)
	{
		dollar();
		return (0);
	}
	while (shell->string)
	{
		printf("%s", shell->string->content);
		shell->string = shell->string->next;
	}
	if (!shell->flag || !shell->flag->content
		|| ft_strcmp(shell->flag->content, "-n") != 0)
		printf("\n");
	return (0);
}
