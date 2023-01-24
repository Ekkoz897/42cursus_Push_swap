/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:28 by apereira          #+#    #+#             */
/*   Updated: 2023/01/24 13:17:40 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_is_present(t_list *a, int i)
{
	while (a)
	{
		if (*a->content == i)
		{
			ft_printf("\nError\n%i is present more than once", i);
			ft_printf(" in the stack of numbers you provided\n\n");
			return (1);
		}
		ft_printf("Comparing %i to: %i\n", i, *a->content);
		a = a->next;
	}
	return (0);
}
