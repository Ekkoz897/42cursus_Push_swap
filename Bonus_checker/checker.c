/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:03:20 by apereira          #+#    #+#             */
/*   Updated: 2023/02/20 13:19:30 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	replicate2(t_list **a, t_list **b, char *line)
{
	if (line[2] != '\n' && line[3] != '\n')
		return (0);
	if (line[0] == 'p' && line[1] == 'a')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b')
		pb(a, b);
	else if (line[0] == 's' && line[1] == 'a')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b')
		sb(b);
	else if (line[0] == 'r' && line[1] == 'a')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b')
		rb(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(a);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	replicate(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (replicate2(a, b, line))
			write(1, "", 1);
		else if (line[0] == 'r' && line[1] == 'r')
			rr(a, b);
		else if (line[0] == 's' && line[1] == 's')
			ss(a, b);
		else
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_vars	var;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	vars_init(&var);
	stack_a_init(argv, &a, &var, argc);
	if (!(replicate(&a, &b)) || (!are_already_in_order(a) && !b))
	{
		ft_printf("KO\n");
		return (0);
	}
	else
		ft_printf("OK\n");
	clear_stacks(&a, &b);
	return (0);
}
