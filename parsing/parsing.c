
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:17:12 by jmuni-re          #+#    #+#             */
/*   Updated: 2023/02/04 21:36:02 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

int get_flag_cmd(t_var **shell, int i, char *cmd)
{
  int start;

  start = i;
  t_list *tmp;
  i = is_forbidden_char(i, cmd);
  tmp = ft_lstnew(ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->flag, tmp);
  return (i);
}

int get_cmd(t_var **shell, int i, char *cmd)
{
  int start;

  start = i;
  i = is_forbidden_char(i, cmd);
  (*shell)->cmd_arg = ft_substr(cmd, start, i - start);
  return (i);
}

int get_space(t_var **tmp)
{
  char *c;
   t_list *space;

  c = ft_substr(" ", 0, 1);
  space = ft_lstnew(c);
  ft_lstadd_back(&(*tmp)->string, space);
return(0);
}

int read_cmd_user(t_var **shell, char **tmp_env, char *cmd)
 {
  int i = 0;
  int flag = 0;
  int flag_space = 0;

  t_var *tmp = ft_varnew();
  if (is_double_quote(cmd) % 2 == 0 && is_simple_quote(cmd) % 2 == 0)
  {
    while (cmd && cmd[i]) 
    {
      //////////////////////////////////
    while (cmd[i] == ' ')
      i++;
    if (ft_strncmp(&cmd[i], "<<", 2) == 0) 
      i = here_doc(&tmp, i, cmd);
    else if (cmd[i] == '<') 
       i = input_file(&tmp, i, cmd);
    else if (ft_strncmp(&cmd[i], ">>", 2) == 0) 
    {
     /*if((*tmp).redir_output)   
        printf("outfile or append, make your choice\n");
      else*/
      i = append(&tmp, i, cmd);
    } 
    else if (cmd[i] == '>') 
        i = output_file(&tmp, i, cmd);
        ////////////////////////////////////////////
    else if (cmd[i] == '$')
    {
      i = get_variable(cmd, i, tmp_env, &tmp);
      if (cmd[i] == ' ')
        flag_space = 1;
    }
    else if (cmd[i] != ' ' && !flag)
     {
      flag = 1;
      i = get_cmd(&tmp, i, cmd);
    } 
    else if (cmd && cmd[i] == '-' && cmd[i - 1] == ' ') //////// segfault?
      i = get_flag_cmd(&tmp, i, cmd);
    else if (cmd[i] == '\"')
     {
      i = get_string_double(&tmp, i, cmd, tmp_env);
      flag_space = 1;
    } 
    else if (cmd[i] == '\'') 
    {
      i = get_string_simple(&tmp, i, cmd);
      flag_space = 1;
    } 
    else if (cmd[i] == '|') 
    {
      flag = 0;
      ft_varadd_back(shell, tmp);
      tmp = ft_varnew();
      i++;
    } 
    else
    {
      i = get_string(&tmp, i, cmd, tmp_env);
      printf("ici : %d\n", cmd[i]);
      printf("number: %d\n", i);
      if (cmd && cmd[i] == ' ')
        flag_space = 1; /////////// a verifier
    }

    if (cmd[i] == ' ' && flag_space) 
      flag_space = get_space(&tmp);
  }
  ft_varadd_back(shell, tmp);
  }
  else
  {
    printf("Error: missing quote\n");
    return(1);
  }
  return (0);
}