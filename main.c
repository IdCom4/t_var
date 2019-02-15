#include "t_var.h"

t_var	*new_var(t_var *head, int type, char *var_name)
{
	t_var	*new;
	t_var	*cursor;

	if (!(new = (t_var *)malloc(sizeof(t_var) * 1)))
		return (NULL);
	new->type = type;
	strncpy(new->v_name, var_name, 10);
	new->next = NULL;
	if (!head)
		return (new);
	cursor = head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
	return (head);
}

t_var	*get_var(t_var *head, int type, char *v_name)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->type == type && strcmp(head->v_name, v_name) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	free_var(t_var *head, int free_content)
{
	t_var *cursor;
	t_var *tmp;

	cursor = head;
	while (cursor)
	{
		tmp = cursor->next;
		if (cursor->type == CHAR_PTR && free_content)
			free(cursor->c_ptr);
		if (cursor->type == INT_PTR && free_content)
			free(cursor->i_ptr);
		if (cursor->type == VOID && free_content)
			free(cursor->v_ptr);
		free(cursor);
		cursor = tmp;
	}
}

int	main()
{
	t_var *vars;

	vars = new_var(vars, INT, "i");
	get_var(vars, INT, "i")->i = 0;
	printf("i = %d\n", get_var(vars, INT, "i")->i);
	get_var(vars, INT, "i")->i = 42;
	printf("i = %d\n", get_var(vars, INT, "i")->i);
	free_var(vars, 0);
	return (0);
}
