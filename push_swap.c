/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:13 by apereira          #+#    #+#             */
/*   Updated: 2023/01/24 15:15:27 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// Loop to print all elements of a list
//
	// while (a)
	// {
	// 	printf("%i\n", *(int *)a->content);
	// 	a = a->next;
	// }
//

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_vars	var;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	vars_init(&var);
	var.i = 1;
	if (!stack_a_init(argv, a, &var, argc))
		return (0);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	ft_printf("\nNumber of moves: %d\n\n", var.count);
	return (0);
}

int	stack_a_init(char **argv, t_list *a, t_vars *var, int argc)
{
	while (var->i < argc)
	{
		ft_printf("--------------------------\n");
		ft_printf("argv is currently: %i\n", ft_atoi(argv[var->i]));
		if (!nbr_is_valid(a, argv[var->i], ft_atoi(argv[var->i]), var->i))
			return (0);
		var->tmp = ft_calloc(1, sizeof(int));
		*var->tmp = ft_atoi(argv[var->i]);
		ft_lstadd_back(&a, ft_lstnew(var->tmp));
		var->i++;
	}
	return (1);
}
