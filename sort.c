/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:51:18 by apereira          #+#    #+#             */
/*   Updated: 2023/02/02 12:14:13 by apereira         ###   ########.fr       */
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
