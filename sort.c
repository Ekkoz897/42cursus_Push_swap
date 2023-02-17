/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:51:18 by apereira          #+#    #+#             */
/*   Updated: 2023/02/17 09:19:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_or_less(t_list **a)
{
	if (*(*a)->content > *(*a)->next->content
		&& *(*a)->content < *(*a)->next->next->content)
		sa(a, 0);
	if (are_already_in_order(*a))
		return ;
	if (*(*a)->content < *(*a)->next->content)
	{
		rra(a, 0);
		if (are_already_in_order(*a))
			return ;
		sa(a, 0);
	}
	if (are_already_in_order(*a))
		return ;
	if (*(*a)->content > *(*a)->next->content)
	{
		ra(a, 0);
		if (are_already_in_order(*a))
			return ;
		sa(a, 0);
		if (are_already_in_order(*a))
			return ;
		ra(a, 0);
	}
}

void	push_highest_numbers(t_list	**a, t_list **b, int bigpos)
{
	if (bigpos == 2)
		ra(a, 0);
	if (bigpos == 3)
	{
		ra(a, 0);
		ra(a, 0);
	}
	if (bigpos == 4 && (*a)->next->next->next->next)
	{
		rra(a, 0);
		rra(a, 0);
	}
	else if (bigpos == 4)
		rra(a, 0);
	if (bigpos == 5)
		rra(a, 0);
	pb(a, b);
}

void	five_or_less(t_list **a, t_list **b)
{
	find_highest_numbers(a, b);
	find_highest_numbers(a, b);
	three_or_less(a);
	if (*(*b)->content > *(*b)->next->content)
		sb(b, 0);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	ra(a, 0);
}

// int	partition(t_list **stack_a, t_list **stack_b, int size)
// {
// 	int	pivot;
// 	int	i;
// 	int	j;

// 	pivot = *(*stack_a)->next->content;
// 	i = 1;
// 	j = size - 1;
// 	while (i < j && (*stack_a)->next)
// 	{
// 		ft_printf("a->content = %i\n", *(*stack_a)->content);
// 		ft_printf("pivot: %i\n", pivot);
// 		if (*(*stack_a)->content > pivot)
// 			pb(stack_a, stack_b);
// 		else
// 		{
// 			ra(stack_a, 0);
// 			i++;
// 		}
// 	}
// 	while (*stack_b)
// 		pa(stack_a, stack_b);
// 	return (i - 1);
// }

// void	quicksort(t_list **stack_a, t_list **stack_b, int size)
// {
// 	int	pivot;

// 	if (size <= 1)
// 		return ;
// 	pivot = partition(stack_a, stack_b, size);
// 	quicksort(stack_a, stack_b, pivot);
// 	quicksort(&((*stack_a)->next), stack_b, size - pivot - 1);
// }

void	quicksort(t_list **a, t_list **b, int size)
{
	if (size <= 1)
		return ;
	while (ft_lstsize(*a) > 1)
	{
		if (*(*a)->content < *(*a)->next->content)
			ra(a, 0);
		else
			pb(a, b);
		if (*b && (*b)->next)
		{
			if (*(*b)->content > *(*b)->next->content)
				sb(b, 0);
		}
		// print_stacks(*a, 'a');
		// print_stacks(*b, 'b');
	}
	while (*b)
	{
		pa(a, b);
		ra(a, 0);
	}
	print_stacks(*a, 'a');
	print_stacks(*b, 'b');
}
