/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:15:28 by apereira          #+#    #+#             */
/*   Updated: 2023/02/17 18:35:06 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*biggest(t_list *b)
{
	while (b->next)
	{
		if (bigger(b, b))
			return (b);
		b = b->next;
	}
	return (b);
}

int	bigger(t_list *element, t_list *b)
{
	while (b)
	{
		if (*element->content < *b->content)
			return (0);
		b = b->next;
	}
	return (1);
}

int	smaller(t_list *element, t_list *b)
{
	while (b)
	{
		if (*element->content > *b->content)
			return (0);
		b = b->next;
	}
	return (1);
}


// Resets the "moves" struct
void	moves_reset(t_moves *moves)
{
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
}
