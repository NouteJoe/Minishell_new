/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:25:32 by mfusil            #+#    #+#             */
/*   Updated: 2023/01/24 19:28:39 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(char **tmp_env)
{
	int	i;

	i = 0;
	while (tmp_env[i])
	{
		ft_putstr(tmp_env[i]);
		printf("\n");
		i++;
	}
}
