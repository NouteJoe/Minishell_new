/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:01:24 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/21 16:00:51 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo(t_var *shell)
{
	while (shell->string)
	{
		printf("%s", shell->string->content);
		shell->string = shell->string->next;
	}
	printf("\n");
	return (0);
}
