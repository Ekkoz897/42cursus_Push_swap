/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:51:18 by apereira          #+#    #+#             */
/*   Updated: 2023/02/08 18:43:23 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_or_less(t_list **a)
{
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

void	push_highest_numbers(t_list	**a, t_list **b)
{
	int		bigpos;
	t_list	*temp;
	int		nbr;
	int		i;

	bigpos = 0;
	temp = *a;
	nbr = *(*a)->content;
	i = 0;
	while (temp->content)
	{
		if (nbr < *temp->content)
		{
			nbr = *temp->content;
			bigpos = i;
		}
		i++;
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	while (bigpos-- > 0)
		ra(a, 0);
	pb(a, b);
}

void	five_or_less(t_list **a, t_list **b)
{
	push_highest_numbers(a, b);
	push_highest_numbers(a, b);
	three_or_less(a);
	if (*(*b)->content > *(*b)->next->content)
		sb(b, 0);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	ra(a, 0);
}

// void	big_stack(t_list **a, t_list **b, t_vars vars)
// {
	// implement algo for big lists
// }
