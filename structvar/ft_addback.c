#include "../minishell.h"

int ft_varsize(t_var *var) {
  int len;

  len = 0;
  if (var == NULL)
    return (0);
  while (var) {
    var = var->next;
    len++;
  }
  return (len);
}

t_var *ft_varlast(t_var *var) {
  int len;

  len = ft_varsize(var);
  while (len-- && len)
    var = var->next;
  return (var);
}

void ft_varadd_back(t_var **var, t_var *n) {
  if (var && n) {
    if (*var)
      ft_varlast(*var)->next = n;
    else
      *var = n;
  }
}