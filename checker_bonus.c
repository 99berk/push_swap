/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:32:17 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/26 15:53:23 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line/get_next_line.h"

int	checker(t_push_swap *arrays)
{
	char	*line;
	
	line = get_next_line(0);
	if (line == NULL)
		return (free(line), 0);
	if (ft_strcmp_b(line, "sa"))
		sa_b(arrays);
	else if (ft_strcmp_b(line, "pa"))
		pa_b(arrays);
	else if (ft_strcmp_b(line, "ra"))
		ra_b(arrays);
	else if (ft_strcmp_b(line, "rra"))
		rra_b(arrays);
	else if (ft_strcmp_b(line, "sb"))
		sb_b(arrays);
	else if (ft_strcmp_b(line, "pb"))
		pb_b(arrays);
	else if (ft_strcmp_b(line, "rb"))
		rb_b(arrays);
	else if (ft_strcmp_b(line, "rrb"))
		rrb_b(arrays);
	else if (ft_strcmp_b(line, "ss"))
		ss_b(arrays);
	else if (ft_strcmp_b(line, "rr"))
		rr_b(arrays);
	else if (ft_strcmp_b(line, "rrr"))
		rrr_b(arrays);
	else
		return (write(1, "Error\n", 6), 0);
	checker(arrays);
	return (0);
}

int	push_swap(char **argv)
{
	t_push_swap	arrays;
	int			i;

	arrays.size_a = pushswap_len_b(argv);
	arrays.a = malloc(sizeof(int) * arrays.size_a);
	if (!arrays.a)
		return (0);
	arrays.b = malloc(sizeof(int) * arrays.size_a);
	if (!arrays.b)
		return (free(arrays.a), 0);
	arrays.size_b = 0;
	i = -1;
	while (++i < arrays.size_a)
		arrays.a[i] = push_swap_atoi_b(argv[i], arrays.a);
	ctrl_doubles_b(arrays.a, arrays.size_a);
	checker(&arrays);
	if (ctrl_sorted_b(arrays.a, arrays.size_a, 0))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(arrays.a);
	free(arrays.b);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split_b(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	return (0);
}
