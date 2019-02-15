#ifndef T_VAR_H
# define T_VAR_H

# define INT 0
# define CHAR 1
# define FLOAT 2
# define INT_PTR 3
# define CHAR_PTR 4
# define VOID 5

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_var
{
	int	type;
	char	v_name[11];
	int	i;
	char	c;
	float	f;
	int	*i_ptr;
	char	*c_ptr;
	void	*v_ptr;
	struct s_var	*next;
}		t_var;

#endif
