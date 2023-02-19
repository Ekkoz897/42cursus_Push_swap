/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:15:05 by apereira          #+#    #+#             */
/*   Updated: 2023/02/18 21:17:05 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Split the function due to norminette, too many lines
// 
void	fewer_moves3_element(t_moves *local, t_moves *moves,
	int sizea, t_list *node)
{
	while (local->rra > 0 && local->rrb > 0)
	{
		local->rra--;
		local->rrb--;
		local->rrr++;
	}
	if (local->ra + local->rb + local->rr + local->rra + local->rrb + local->rrr
		< moves->ra + moves->rb + moves->rr + moves->rra + moves->rrb
		+ moves->rrr)
	{
		moves->ra = local->ra;
		moves->rb = local->rb;
		moves->rr = local->rr;
		moves->rrb = local->rrb;
		moves->rra = local->rra;
		moves->rrr = local->rrr;
	}
	if (local->rrr != 0)
		local->rra = local->rra + local->rrr;
	if (local->rra != 0)
		local->ra = sizea - local->rra;
	if (local->rr != 0)
		local->ra = local->ra + local->rr;
	if (node->next == NULL)
		local->ra = 0;
}

// Split the function due to norminette, too many lines
// 
void	fewer_moves2_element(t_moves *local,
	t_list *node, t_list *first)
{
	t_list			*last;

	last = ft_lstlast(first);
	if (smaller(node, first) || bigger(node, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local->rb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*node->content < *first->content
				|| *node->content > *last->content))
		{
			local->rb++;
			if (last->next == NULL)
				last = first;
			else
				last = last->next;
			first = first->next;
		}
	}

}

// checks which A element takes fewer movements to place correctly in B
// Every time it finds a new best number it updates the moves.ra
void	fewer_moves_element(t_list *node, t_list *first,
		t_moves *moves, int sizea)
{
	static t_moves	local;
	int				sizeb;

	local.ra++;
	sizeb = ft_lstsize(first);
	moves_reset(&local);
	fewer_moves2_element(&local, node, first);
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
	fewer_moves3_element(&local, moves, sizea, node);
}
