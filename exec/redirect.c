/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:13:08 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/10 16:54:38 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirection_heredocs(t_var *shell)
{
	char	*str;
	int		fd;

	fd = open(shell->redir_hdoc->content, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	str = readline("> ");
	while (str != NULL)
	{
		if (str[0])
		{
			str = ft_strjoin(str, "\n");
			ft_putstr_fd(str, fd);
		}
		str = readline("> ");
	}
	close (fd);
	shell->infile = open(".heredoc", O_RDONLY);
	dup2(shell->infile, STDIN_FILENO);
}

void	redirection_infile(t_var *shell)
{
	shell->infile = open(shell->redir_input->content, O_RDONLY);
	if (shell->infile < 0)
		return (ft_putstr_fd("error infile\n", 2));
	dup2(shell->infile, STDIN_FILENO);
}

void	redirection_outfile(t_var *shell)
{
	shell->outfile = open(shell->redir_output->content, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (shell->outfile < 0)
		return (ft_putstr_fd("error outfile\n", 2));
	dup2(shell->outfile, STDOUT_FILENO);
}

void	redirection_append(t_var *shell)
{
	shell->outfile = open(shell->redir_append->content, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (shell->outfile < 0)
		return (ft_putstr_fd("error append\n", 2));
	dup2(shell->outfile, STDOUT_FILENO);	
}

void	redirect(t_var *shell)
{
	if (shell->redir_hdoc)
		redirection_heredocs(shell);
	else if (shell->redir_input)
		redirection_infile(shell);
	else if (shell->redir_append)
		redirection_append(shell);
	else if (shell->redir_output)
		redirection_outfile(shell);
}
