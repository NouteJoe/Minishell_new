/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:17:35 by jmuni-re          #+#    #+#             */
/*   Updated: 2023/02/17 12:41:13 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_double_quote(char *cmd)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (cmd[i])
	{
		if (cmd[i] == '"')
			nb++;
		i++;
	}
	return (nb); // si != 0 erreur
}

int	is_simple_quote(char *cmd)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
			nb++;
		i++;
	}
	return (nb);
}

int	is_forbidden_char2(int i, char *cmd)
{
	while (cmd[i] && cmd[i] == ' ' && cmd[i] != '<' && cmd[i] != '>'
		&& cmd[i] != '|')
		i++;
  /*if (cmd[i] == '>' || cmd[i] == '<') {
      printf("zsh: parse error near `%c'\n", (cmd[i]));
      /////////////////////////
      // $? zsh: command not found: 1
    }*/
	return (i);
}

int	is_forbidden_char(int i, char *cmd)
{
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '<' && cmd[i] != '>'
		&& cmd[i] != '|')
		i++;
	return (i);
}