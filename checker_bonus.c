/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:32:17 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/13 11:42:47 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>

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
		arrays.a[i] = push_swap_atoi_b(argv[i], arrays, argv);
	ctrl_doubles_b(arrays, arrays.size_a, argv);
	if (checker(&arrays) == 1 && !ctrl_sorted_b(arrays.a, arrays.size_a, 0))
		write(1, "KO\n", 3);
	else if (ctrl_sorted_b(arrays.a, arrays.size_a, 0))
		write(1, "OK\n", 3);
	free(arrays.a);
	free(arrays.b);
	ft_allfree_b(argv);
	return (0);
}

char	**arg_converter(char **argv)
{
	char	*str;
	char	*tmp;
	char	**str2;
	int		i;

	str = NULL;
	i = -1;
	while (argv[++i])
	{
		if (!str)
			str = ft_strdup_b(argv[i]);
		else
		{
			tmp = ft_strjoin_b(str, " ");
			free(str);
			str = ft_strjoin_b(tmp, argv[i]);
			free(tmp);
		}
	}
	str2 = ft_split_b(str, ' ');
	free(str);
	return (str2);
}

int	main(int argc, char **argv)
{
	char	**str;

	if (argc > 1)
	{
		argv++;
		str = arg_converter(argv);
		push_swap(str);
		return (0);
	}
	return (0);
}
