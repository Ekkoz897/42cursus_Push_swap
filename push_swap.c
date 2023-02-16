/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:31:13 by apereira          #+#    #+#             */
/*   Updated: 2023/02/15 12:41:22 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to print stacks ( will delete later)
void	print_stacks(t_list *a, char c)
{
	int	i;

	i = 1;
	while (a->next)
	{
		if (c == 'a')
			ft_printf("a: %i  ", *a->content);
		if (c == 'b')
			ft_printf("b: %i  ", *a->content);
		a = a->next;
		i++;
	}
	if (c == 'a')
		ft_printf("a: %i  ", *a->content);
	if (c == 'b')
		ft_printf("b: %i  ", *a->content);
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_vars	var;
	int		size;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	vars_init(&var);
	stack_a_init(argv, &a, &var, argc);
	size = ft_lstsize(a);
	if (are_already_in_order(a))
	{
		clear_stacks(&a, &b);
		return (0);
	}
	if (argc <= 4)
		three_or_less(&a);
	else if (argc <= 6)
		five_or_less(&a, &b);
	else
		quicksort(&a, &b, size);
	clear_stacks(&a, &b);
	return (0);
}

void	stack_a_init(char **argv, t_list **a, t_vars *var, int argc)
{
	while (var->i < argc)
	{
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
		a = a->next;
	}
	return (1);
}
