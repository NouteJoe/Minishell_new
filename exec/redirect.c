/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:13:08 by mfusil            #+#    #+#             */
/*   Updated: 2023/02/20 11:45:07 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int redirection_infile(t_var **shell) {
  int fileDescriptor;
  fileDescriptor = open((*shell)->redir_input->content, O_RDONLY);
  if (fileDescriptor < 0) {
    ft_putstr_fd("error infile\n", 2);
    return 0;
  }
  return fileDescriptor;
}


void redirection_outfile(t_var **shell, int **files) {
  t_var tmp2 = **shell;
  t_list *tmp;
  int i;
  int filesDescriptor;
  char *str;

  i = 0;
  
  while ((tmp2).redir_output) {
    filesDescriptor =
        open((tmp2).redir_output->content, O_WRONLY | O_TRUNC | O_CREAT, 0664);
    if (filesDescriptor < 0)
      return ft_putstr_fd("error outfile\n", 2);
    (*files)[i] = filesDescriptor;
    i++;
    tmp2.redir_output = tmp2.redir_output->next;
  }
  
  while ((tmp2).redir_append) {
    filesDescriptor =
        open((tmp2).redir_append->content, O_CREAT | O_WRONLY | O_APPEND, 0664);
    if (filesDescriptor < 0)
      return ft_putstr_fd("error outfile\n", 2);
    (*files)[i] = filesDescriptor;
    i++;
    tmp2.redir_append = tmp2.redir_append->next;
  }
  if ((*shell)->redir_output && (*shell)->redir_output->content) {
    str =
        malloc(sizeof(char) * (ft_strlen((*shell)->redir_output->content) + 1));
    ft_strlcpy(str, (*shell)->redir_output->content,
               ft_strlen((*shell)->redir_output->content) + 1);
  }

  else {
    str =
        malloc(sizeof(char) * (ft_strlen((*shell)->redir_append->content) + 1));
    ft_strlcpy(str, (*shell)->redir_append->content,
               ft_strlen((*shell)->redir_append->content) + 1);
  }
  tmp = ft_lstnew(str);
  if ((*shell)->next)
    ft_lstadd_back(&(*shell)->next->redir_input, tmp);
}

