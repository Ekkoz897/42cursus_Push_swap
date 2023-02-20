/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:05:27 by apereira          #+#    #+#             */
/*   Updated: 2023/02/20 12:44:58 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_list **b, t_list **a)
{
	rra(a);
	rrb(b);
}

int	are_already_in_order(t_list *a)
{
	while (a->next)
	{
		if (*a->content > *a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
