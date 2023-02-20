#include "../minishell.h"

int here_doc(t_var **shell, int i, char *cmd) {
  int start;

  t_list *tmp;

  i = i + 2;
  i = is_forbidden_char2(i, cmd);
  start = i;
  i = is_forbidden_char(i, cmd);
  tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->redir_hdoc, tmp);
  return (i);
}

int input_file(t_var **shell, int i, char *cmd) {
  int start;

  i++;
  i = is_forbidden_char2(i, cmd);
  start = i;
  i = is_forbidden_char(i, cmd);
  t_list *tmp;

  tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->redir_input, tmp);
  return (i);
}

int output_file(t_var **shell, int i, char *cmd) {
  int start;

  i = i + 1;
  start = i;
  t_list *tmp;

  if (cmd[i] == '>' || cmd[i] == '<') {
    printf("zsh: parse error near `%c'\n", (cmd[i]));
    g_exit_statut = 127;
  } else
    g_exit_statut = 0;

  i = is_forbidden_char2(i, cmd);
  start = i;
  i = is_forbidden_char(i, cmd);
  tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->redir_output, tmp);
  return (i);
}

int append(t_var **shell, int i, char *cmd) {
  int start;

  i = i + 2;
  start = i;
  t_list *tmp;

  i = is_forbidden_char2(i, cmd);
  start = i;
  i = is_forbidden_char(i, cmd);
  
  tmp = ft_lstnew((char *)ft_substr(cmd, start, i - start));
  ft_lstadd_back(&(*shell)->redir_append, tmp);
  return (i);
}
