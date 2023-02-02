/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:13 by apereira          #+#    #+#             */
/*   Updated: 2023/02/02 12:19:11 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Loop to print all elements of a list
//
	// while (a)
	// {
	// 	printf("%i\n", *a->content);
	// 	a = a->next;
	// }
//

// To print an element of the list
//
// ft_printf("%i", *(*a)->content);
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
	stack_a_init(argv, &a, &var, argc);
	if (are_already_in_order(a))
	{
		clear_stacks(&a, &b);
		return (0);
	}
	go_back(&a);
	if (argc <= 4)
		three_or_less(&a);
	while (a->content)
	{
		ft_printf("---%i---   \n", *a->content);
		// if (b->content)
		// 	ft_printf("---%i---", *b->content);
		if (!a->next)
			break ;
		a = a->next;
		// if (b->next)
		// 	b = b->next;
	}
	clear_stacks(&a, &b);
	return (0);
}

void	stack_a_init(char **argv, t_list **a, t_vars *var, int argc)
{
	while (var->i < argc)
	{
		ft_printf("--------------------------\n");
		ft_printf("argv is currently: %i\n\n", ft_atoi(argv[var->i]));
		if (!nbr_is_valid(*a, argv[var->i], ft_atoi(argv[var->i]), var->i))
		{
			clear_stacks(a, a);
			exit (0);
		}
		var->tmp = ft_calloc(1, sizeof(int));
		*var->tmp = ft_atoi(argv[var->i]);
		ft_lstadd_back(a, ft_lstnew(var->tmp));
		var->i++;
	}
}

//
// To avoid 25 lines, just delete the line 95 ft_printf
//
int	nbr_is_valid(t_list *a, char *str, int nbr, int index)
{
	if ((str[0] == '-' && str - "-2147483648" > 0 && ft_strlen(str) >= 11)
		|| (str - "2147483647" > 0 && ft_strlen(str) >= 10))
	{
		ft_printf("\nError\nThe %i input isn't valid\n\n", index);
		return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_printf("\nError\nThe %i input isn't valid\n\n", index);
			return (0);
		}
		str++;
	}
	while (a)
	{
		if (*a->content == nbr)
		{
			ft_printf("\nError\n%i is present more than once", nbr);
			return (0);
		}
		ft_printf("Comparing %i to: %i\n", nbr, *a->content);
		a = a->next;
	}
	return (1);
}
