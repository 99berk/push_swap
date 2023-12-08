/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:32:17 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/08 12:16:00 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>

int	ft_strcmp_b(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (1);
}

int	checker2(t_push_swap *arrays, char *line)
{
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
	return (1);
}

int	checker(t_push_swap *arrays)
{
	char	*line;

	line = get_next_line(0);
	if (line == NULL)
		return (free(line), 1);
	if (checker2(arrays, line) == 0)
		return (free(line), 0);
	checker(arrays);
	return (free(line), 1);
}

int	push_swap(char **argv, int k)
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
		arrays.a[i] = push_swap_atoi_b(argv[i], arrays, k, argv);
	ctrl_doubles_b(arrays, arrays.size_a, k, argv);
	if (checker(&arrays) == 1 && !ctrl_sorted_b(arrays.a, arrays.size_a, 0))
		write(1, "KO\n", 3);
	else if (ctrl_sorted_b(arrays.a, arrays.size_a, 0))
		write(1, "OK\n", 3);
	free(arrays.a);
	free(arrays.b);
	if (k == 1)
		ft_allfree_b(argv);
	return (0);
}

int	main(int argc, char **argv)
{
	int	k;

	k = 0;
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			k = 1;
			argv = ft_split_b(*argv, ' ');
			push_swap(argv, k);
		}
		else
			push_swap(argv, k);
		return (0);
	}
	return (0);
}
