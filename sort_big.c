/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:09:48 by apereira          #+#    #+#             */
/*   Updated: 2023/02/17 18:58:29 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks which A element takes fewer movements to place correctly in B
// Every time it finds a new best number it updates the moves.ra
void	fewer_moves_element(t_list *node, t_list *first, t_moves *moves, int sizeb, int sizea)
{
	static t_moves	local;
	t_list			*last;

	local.ra++;
	last = ft_lstlast(first);
	moves_reset(&local);
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local.rb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content
				|| *node->content > *last->content))
		{
			local.rb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}
	if (local.ra > sizea / 2)
	{
		local.rra = sizea - local.ra;
		local.ra = 0;
	}
	if (local.rb > sizeb / 2)
	{
		local.rrb = sizeb - local.rb;
		local.rb = 0;
	}
	while (local.ra > 0 && local.rb > 0)
	{
		local.ra--;
		local.rb--;
		local.rr++;
	}
	while (local.rra > 0 && local.rrb > 0)
	{
		local.rra--;
		local.rrb--;
		local.rrr++;
	}
	if (local.ra + local.rb + local.rr + local.rra + local.rrb + local.rrr
		< moves->ra + moves->rb + moves->rr + moves->rra + moves->rrb
		+ moves->rrr)
	{
		moves->ra = local.ra;
		moves->rb = local.rb;
		moves->rr = local.rr;
		moves->rrb = local.rrb;
		moves->rra = local.rra;
		moves->rrr = local.rrr;
	}
	if (local.rrr != 0)
		local.rra = local.rra + local.rrr;
	if (local.rra != 0)
		local.ra = sizea - local.rra;
	if (local.rr != 0)
		local.ra = local.ra + local.rr;
	if (node->next == NULL)
		local.ra = 0;
}

// Checks if the element is bigger than the biggest element of B or smaller than
// the smallest element of B. if it is, it RB's unti the biggest/smallest is at 
// the top of B. If it's neither, it counts the RB's needed to put element in
// the correct position in the middle of the stack.
void	first_element(t_list *node, t_list *first,
	t_moves *moves, int sizeb, int sizea)
{
	t_moves	local;
	t_list	*last;

	moves->ra = 0;
	local.ra = 0;
	last = ft_lstlast(first);
	moves_reset(&local);
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local.rb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content
				|| *node->content > *last->content))
		{
			local.rb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}
	if (local.ra > sizea / 2)
	{
		local.rra = sizea - local.ra;
		local.ra = 0;
	}
	if (local.rb > sizeb / 2)
	{
		local.rrb = sizeb - local.rb;
		local.rb = 0;
	}
	while (local.ra > 0 && local.rb > 0)
	{
		local.ra--;
		local.rb--;
		local.rr++;
	}
	while ((local.rra > 0 && local.rrb > 0))
	{
		local.rra--;
		local.rrb--;
		local.rrr++;
	}
	moves->ra = local.ra;
	moves->rb = local.rb;
	moves->rr = local.rr;
	moves->rrb = local.rrb;
	moves->rra = local.rra;
	moves->rrr = local.rrr;
}

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
		first_element(node, *b, &moves, ft_lstsize(*b), ft_lstsize(*a));
		node = node->next;
		while (node)
		{
			fewer_moves_element(node, *b, &moves,
				ft_lstsize(*b), ft_lstsize(*a));
			node = node->next;
		}
		sort_big2(a, b, &moves);
		while (moves.rrb-- > 0)
			rrb(b, 0);
		pb(a, b);
	}
	sort_big3(a, b);
}
