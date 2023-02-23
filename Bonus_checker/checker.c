/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:03:20 by apereira          #+#    #+#             */
/*   Updated: 2023/02/23 11:55:25 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	replicate2(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
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
			write(1, "", 0);
		else if (!ft_strncmp(line, "rr\n", 3))
			rr(a, b);
		else if (!ft_strncmp(line, "ss\n", 3))
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
	if (!(replicate(&a, &b)))
		ft_printf("Error\n");
	else if ((are_already_in_order(a) && !b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stacks(&a, &b);
	return (0);
}