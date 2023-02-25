/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:07:03 by jmuni-re          #+#    #+#             */
/*   Updated: 2023/02/24 15:56:11 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	here_doc(t_var **shell, int i, char *cmd)
{
	int		start;
	t_list	*tmp;

	i = i + 2;
	i = is_forbidden_char2(i, cmd);
	start = i;
	i = is_forbidden_char(i, cmd);
	tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
	ft_lstadd_back(&(*shell)->redir_hdoc, tmp);
	return (i);
}

int	input_file(t_var **shell, int i, char *cmd)
{
	int		start;
	t_list	*tmp;

	i++;
	i = is_forbidden_char2(i, cmd);
	start = i;
	i = is_forbidden_char(i, cmd);
	tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
	ft_lstadd_back(&(*shell)->redir_input, tmp);
	return (i);
}

int	output_file(t_var **shell, int i, char *cmd)
{
	int		start;
	t_list	*tmp;

	i = i + 1;
	start = i;
	i = is_forbidden_char2(i, cmd);
	start = i;
	i = is_forbidden_char(i, cmd);
	tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
	ft_lstadd_back(&(*shell)->redir_output, tmp);
	return (i);
}

int	append(t_var **shell, int i, char *cmd)
{
	int		start;
	t_list	*tmp;

	i = i + 2;
	start = i;
	i = is_forbidden_char2(i, cmd);
	start = i;
	i = is_forbidden_char(i, cmd);
	tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
	ft_lstadd_back(&(*shell)->redir_append, tmp);
	return (i);
}
