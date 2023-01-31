/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:28 by apereira          #+#    #+#             */
/*   Updated: 2023/01/31 17:57:24 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, int flag)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	(*a)->prev = temp->prev;
	temp->next = *a;
	temp->prev = (*a)->prev;
	*a = (*a)->prev;
	if (flag == 0)
		ft_printf("sa\n");
}

void	sb(t_list **b, int flag)
{
	t_list	*temp;

	temp = (*b)->next;
	(*b)->next = temp->next;
	(*b)->prev = temp->prev;
	temp->next = *b;
	temp->prev = (*b)->prev;
	*b = (*b)->prev;
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	if (*b)
		sb(b, 1);
}
