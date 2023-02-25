/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:52:57 by jmuni-re          #+#    #+#             */
/*   Updated: 2023/02/24 16:35:15 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_var	*ft_varnew(void)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (var == NULL)
		return (NULL);
	var->next = NULL;
	init_struct(&var);
	return (var);
}
