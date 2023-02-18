/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:01:24 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/09 15:56:12 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(t_var *shell)
{
	while (shell->string)
	{
		printf("%s", shell->string->content);	
		shell->string = shell->string->next;
	}
	//if (shell->flag->content == NULL)
	printf("\n");
}
