#include "../minishell.h"

t_var *ft_varnew() {
  t_var *var;

  var = malloc(sizeof(t_var));
  if (var == NULL)
    return (NULL);
  var->next = NULL;
  init_struct(&var);
  return (var);
}
