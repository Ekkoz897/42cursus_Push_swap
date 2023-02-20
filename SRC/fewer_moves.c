/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:15:05 by apereira          #+#    #+#             */
/*   Updated: 2023/02/20 10:51:09 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Split the function due to norminette, too many lines.
// At the end, we put rra back to it's value, since we did 
// while (RRA) RRA-- && RRR++. That's why there are ifs at the end.
void	fewer_moves3_element(t_moves *local, t_moves *moves,
	int sizea, t_list *element)
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
	if (element->next == NULL)
		local->ra = 0;
}

// Split the function due to norminette, too many lines
// Checks if element is the biggest or the smallest element (in B stack).
// If it is, it counts how many times we will rotate B to put it's highest
// number on top. Else it simulates the RB function to calculate how many RB's
// we need to place element in the right place in B.
void	fewer_moves2_element(t_moves *local,
	t_list *element, t_list *first)
{
	t_list			*last;

	last = ft_lstlast(first);
	if (smaller(element, first) || bigger(element, first))
	{
		while (*first->content != *biggest(first)->content)
		{
			local->rb++;
			first = first->next;
		}
	}
	else
	{
		while (first && (*element->content < *first->content
				|| *element->content > *last->content))
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

// Checks which A element takes fewer movements to place correctly in B.
// Every time it finds a new best number it updates the moves variable.
// all the if's are for optimization purposes, it checks if it's better,
// to RA or to RRA, for example.
void	fewer_moves_element(t_list *element, t_list *first,
		t_moves *moves, int sizea)
{
	static t_moves	local;
	int				sizeb;

	local.ra++;
	sizeb = ft_lstsize(first);
	moves_reset(&local);
	fewer_moves2_element(&local, element, first);
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
	fewer_moves3_element(&local, moves, sizea, element);
}
