/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:28 by apereira          #+#    #+#             */
/*   Updated: 2023/01/24 14:42:18 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nbr_is_valid(t_list *a, char *str, int nbr, int index)
{
	if (str[0] < '0' || str[0] > '9')
	{
		ft_printf("\nError\nThe %ith input isn't valid\n\n", index);
		return (1);
	}
	while (a)
	{
		if (*a->content == nbr)
		{
			ft_printf("\nError\n%i is present more than once", nbr);
			ft_printf(" in the stack of numbers you provided\n\n");
			return (1);
		}
		ft_printf("Comparing %i to: %i\n", nbr, *a->content);
		a = a->next;
	}
	return (0);
}
