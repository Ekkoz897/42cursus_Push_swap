/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:09:48 by apereira          #+#    #+#             */
/*   Updated: 2023/02/18 21:29:31 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Had to split the main sort_big due to too many lines (norminette)
// This part RB's until the biggest element is at the top, so that the numbers
// are pushed back to stack A in ascending order
// Checks if it's better to RB or RRB, based on highest element position
void	sort_big3(t_list **a, t_list **b)
{
	if (ft_lstsize(*b) - ft_lstsize(biggest(*b)) <= ft_lstsize(*b) / 2)
		while (*(*b)->content != *biggest(*b)->content)
			rb(b, 0);
	else
		while (*(*b)->content != *biggest(*b)->content)
			rrb(b, 0);
	while (*b)
		pa(a, b);
}

// Had to split the main sort_big due to too many lines (norminette)
void	sort_big2(t_list **a, t_list **b, t_moves *moves)
{
	while (moves->rr > 0)
	{
		rr(a, b);
		moves->rr--;
	}
	while (moves->rrr > 0)
	{
		rrr(a, b);
		moves->rrr--;
	}
	while (moves->ra > 0)
	{
		ra(a, 0);
		moves->ra--;
	}
	while (moves->rb > 0)
	{
		rb(b, 0);
		moves->rb--;
	}
	while (moves->rra > 0)
	{
		rra(a, 0);
		moves->rra--;
	}
}

void	sort_big(t_list **a, t_list **b)
{
	t_moves	moves;
	t_list	*node;

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		node = *a;
		moves.ra = 0;
		moves_reset(&moves);
		first_element(node, *b, &moves, ft_lstsize(*a));
		node = node->next;
		while (node)
		{
			fewer_moves_element(node, *b, &moves, ft_lstsize(*a));
			node = node->next;
		}
		sort_big2(a, b, &moves);
		while (moves.rrb-- > 0)
			rrb(b, 0);
		pb(a, b);
	}
	sort_big3(a, b);
}
