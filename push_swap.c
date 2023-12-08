/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:02:24 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/08 12:15:48 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	push_swap(char **argv, int k)
{
	t_push_swap	arrays;
	int			i;

	arrays.size_a = pushswap_len(argv);
	arrays.a = malloc(sizeof(int) * arrays.size_a);
	if (!arrays.a)
		return (0);
	arrays.b = malloc(sizeof(int) * arrays.size_a);
	if (!arrays.b)
		return (free(arrays.a), 0);
	arrays.size_b = 0;
	i = -1;
	while (++i < arrays.size_a)
		arrays.a[i] = push_swap_atoi(argv[i], arrays, k, argv);
	ctrl_doubles(arrays, arrays.size_a, k, argv);
	start_sort(&arrays, arrays.size_a);
	free(arrays.a);
	free(arrays.b);
	if (k == 1)
		ft_allfree(argv);
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
			argv = ft_split(*argv, ' ');
			push_swap(argv, k);
		}
		else
			push_swap(argv, k);
		return (0);
	}
	return (0);
}
