/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:10:24 by jmuni-re          #+#    #+#             */
/*   Updated: 2023/02/01 13:10:39 by jmuni-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int get_string_double(t_var **shell, int i, char *cmd, char **tmp_env) {
  int start;
  t_list *tmp;

  i++;
  start = i;
  while (cmd[i] != '"') {
    if (cmd[i] == '$') {
     
    if ((*shell)->string->content)
      get_space(shell);///// erreur a modifier
        tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
        ft_lstadd_back(&(*shell)->string, tmp);
      
      i = get_variable(cmd, i, tmp_env, shell);
      start = i;
    } else
      i++;
  }
  tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->string, tmp);
  i++;
  return (i);
}

int scan_tmp_env(char **tmp_env, char *str, int j, t_var **shell) {
  t_list *tmp = NULL;
  char **tab = NULL;
  char *tmp2 = NULL;
  int n = 0;

  while (tmp_env[n]) {
    if (ft_strncmp(str, tmp_env[n], j) == 0) {
      tab = ft_split(tmp_env[n], '=');
      tmp2 = ft_strdup(tab[1]);
      tmp = ft_lstnew(tmp2);
      ft_lstadd_back(&(*shell)->string, tmp);
    }
    n++;
  }
  return (0);
}

int get_variable(char *cmd, int i, char **tmp_env, t_var **shell) 
{
  int j = 0;
  char *str = NULL;
  // char *nbr;
  int size = 0;

  i++;
  /*nbr = ft_itoa(exit_statut);
  if (cmd[i] == '?') {
    while (nbr[j])
      str[j] = nbr[j];
    j++;
  }
  i++;*/
  size = is_forbidden_char(size, cmd);
  str = malloc(sizeof(char) * size + 1);
  while (cmd[i] && cmd[i] != ' ' && cmd[i] != '|' && cmd[i] != '"' &&
         cmd[i] != '\'')
   {
    str[j] = cmd[i];
    i++;
    j++;
  }
  str[j] = '=';
  scan_tmp_env(tmp_env, str, j + 1, shell);
  free(str);
  return (i);
}

int get_string_simple(t_var **shell, int i, char *cmd) {
  int start;
  t_list *tmp;

  i++;
  start = i;
  while (cmd[i] != '\'')
    i++;
  tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->string, tmp);
  i++;
  return (i);
}

int get_string(t_var **shell, int i, char *cmd, char **tmp_env) {
  int start;
  t_list *tmp;
  (void)tmp_env;

  start = i;
  while (cmd[i] && cmd[i] != '<' && cmd[i] != '>' && cmd[i] != '\'' &&
         cmd[i] != '"' && cmd[i] != '|') {
    if (cmd[i] == ' ' && cmd[i + 1] == ' ') {
      while (cmd[i] == ' ' && cmd[i + 1] == ' ')
        i++;
      start = i;
    }
    while (cmd[i] && cmd[i] != '<' && cmd[i] != '>' && cmd[i] != '\'' &&
           cmd[i] != '"' && cmd[i] != '|' && cmd[i] != ' ') {
      if (cmd[i] == '$') {
        /* tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
         ft_lstadd_back(&(*shell)->string, tmp);*/
        // printf("test %s\n",(*shell)->string->content);
        i = get_variable(cmd, i, tmp_env, shell);
        start = i;
      }
      i++;
    }
    tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
    ft_lstadd_back(&(*shell)->string, tmp);
    start = i;
    i++;
  }
  return (i);
}
