/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:02:24 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/13 11:29:30 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	push_swap(char **argv)
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
		arrays.a[i] = push_swap_atoi(argv[i], arrays, argv);
	ctrl_doubles(arrays, arrays.size_a, argv);
	start_sort(&arrays, arrays.size_a);
	free(arrays.a);
	free(arrays.b);
	ft_allfree(argv);
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
			str = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
	}
	str2 = ft_split(str, ' ');
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
