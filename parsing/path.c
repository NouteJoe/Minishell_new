/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:23:15 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/06 12:33:01 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_find_line_env(char **env, char *cmd)
{
	int		i;
	char	*line;
	char	**path;

	i = -1;
	line = NULL;
	if (!cmd)
		return NULL;//TODO
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	if (!env[i])
		return NULL; // TODO;
	line = &(env[i][5]);
	path = ft_split(line, ':');
	return (path);
}

char	*ft_find_path(char **env, char *cmd)
{
	int		i;
	char	*line;
	char	**path;

	path = ft_find_line_env(env, cmd);
	i = -1;
	while (path[++i])
	{
		line = path[i];
		path[i] = ft_strjoin(ft_strjoin(path[i], "/"), cmd);
		free(line);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
	}
	// ft_error(5); // TODO 
	return (NULL);
}
