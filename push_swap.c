/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:13 by apereira          #+#    #+#             */
/*   Updated: 2023/01/24 12:22:58 by apereira         ###   ########.fr       */
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
	while (argv[var.i])
	{
		var.tmp = ft_calloc(1, sizeof(int));
		*var.tmp = ft_atoi(argv[var.i]);
		ft_lstadd_back(&a, ft_lstnew(var.tmp));
		var.i++;
	}
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	ft_printf("Number of moves: %d\n\n", var.count);
	return (0);
}
