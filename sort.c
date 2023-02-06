/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:51:18 by apereira          #+#    #+#             */
/*   Updated: 2023/02/06 16:20:51 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_or_less(t_list **a)
{
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

void	five_or_less(t_list **a, t_list **b)
{
	pb(a, b);
	pb(a, b);
	three_or_less(a);
	pa(a, b);
	// add a way to add elements in correct position
}

// void	big_stack(t_list **a, t_list **b, t_vars vars)
// {
	// implement algo for big lists
// }
