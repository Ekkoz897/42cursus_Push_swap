/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:36:52 by apereira          #+#    #+#             */
/*   Updated: 2023/02/01 15:26:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a, int flag)
{
	(*a)->next->prev = NULL;
	ft_lstadd_back(a, *a);
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_list **b, int flag)
{
	(*b)->next->prev = NULL;
	ft_lstadd_back(b, *b);
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr");
}

void	rra(t_list **a, int flag)
{
	ft_lstadd_front(a, ft_lstlast(*a));
	ft_lstlast(*a)->next = NULL;
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int flag)
{
	ft_lstadd_front(b, ft_lstlast(*b));
	ft_lstlast(*b)->next = NULL;
	if (flag == 0)
		ft_printf("rrb\n");
}
