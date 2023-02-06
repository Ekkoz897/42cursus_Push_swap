/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:26:58 by apereira          #+#    #+#             */
/*   Updated: 2023/02/06 15:14:20 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_list **b, t_list **a)
{
	rra(a, 1);
	rrb(b, 1);
	ft_printf("rrr");
}

int	are_already_in_order(t_list *a)
{
	go_back(&a);
	while (a->next)
	{
		if (*a->content > *a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
