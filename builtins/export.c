/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:07:21 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/16 15:41:57 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**new_env(t_var *shell, char ***tmp_env)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc((ft_strlen_tab(*tmp_env) + 2) * sizeof(char *));
	while ((*tmp_env)[i])
	{
		tmp[i] = ft_strdup((*tmp_env)[i]);
		free((*tmp_env)[i]);
		i++;
	}
	tmp[i] = shell->string->content;
	i++;
	tmp[i] = NULL;
	*tmp_env = tmp;
	return (NULL);
}

int	var_in_env(char **tmp_env, char *string)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (string[len] != '=')
		len++;
	while (tmp_env[i])
	{
		if (ft_strncmp(tmp_env[i], string, len) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	change_variable_in_env(char **tmp_env, char *string)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (string[len] != '=')
		len++;
	while (tmp_env[i])
	{
		if (!ft_strncmp(tmp_env[i], string, len + 1))
		{
			free(tmp_env[i]);
			tmp_env[i] = ft_strdup(string);
		}
		i++;
	}
}

int	export(t_var *shell, char **tmp_env)
{
	g_exit_statut = 0;
	if (!ft_strchr(shell->string->content, '='))
		return (printf("error no sign =\n"));
	if (shell->string->content == NULL)
		return (printf("no argument with export\n"));
	if (shell->string->content)
	{
		if (var_in_env(tmp_env, shell->string->content) == 0)
			change_variable_in_env(tmp_env, shell->string->content);
		else
		{
			new_env(shell, &tmp_env);
			env(tmp_env);
		}
	}
	return (0);
}
