/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:18:26 by apereira          #+#    #+#             */
/*   Updated: 2023/02/20 10:55:15 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_element3(t_moves *local, int sizea, int sizeb)
{
	if (local->ra > sizea / 2)
	{
		local->rra = sizea - local->ra;
		local->ra = 0;
	}
	if (local->rb > sizeb / 2)
	{
		local->rrb = sizeb - local->rb;
		local->rb = 0;
	}
	while (local->ra > 0 && local->rb > 0)
	{
		local->ra--;
		local->rb--;
		local->rr++;
	}
	while ((local->rra > 0 && local->rrb > 0))
	{
		local->rra--;
		local->rrb--;
		local->rrr++;
	}
}

// Split the function due to norminette, too many lines
// Checks if element is the biggest or the smallest element (in B stack).
// If it is, it counts how many times we will rotate B to put it's highest
// number on top. Else it simulates the RB function to calculate how many RB's
// we need to place element in the right place in B.
void	first_element2(t_list *node, t_list *first,
			t_list *last, t_moves *local)
{
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

// Checks if the element is bigger than the biggest element of B or smaller than
// the smallest element of B. if it is, it RB's unti the biggest/smallest is at 
// the top of B. If it's neither, it counts the RB's needed to put element in
// the correct position in the middle of the stack.
void	first_element(t_list *node, t_list *first, t_moves *moves, int sizea)
{
	t_moves	local;
	t_list	*last;
	int		sizeb;

	sizeb = ft_lstsize(first);
	moves->ra = 0;
	local.ra = 0;
	last = ft_lstlast(first);
	moves_reset(&local);
	first_element2(node, first, last, &local);
	first_element3(&local, sizea, sizeb);
	moves->ra = local.ra;
	moves->rb = local.rb;
	moves->rr = local.rr;
	moves->rrb = local.rrb;
	moves->rra = local.rra;
	moves->rrr = local.rrr;
}
