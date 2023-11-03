/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:02:24 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/03 11:50:03 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libraries/Libft/libft.h"
#include <unistd.h>

void	ft_error(int *arrays)
{
	free(arrays);
	write(2, "Error\n", 6);
	exit (1);
}

int	push_swap_atoi(char *str, int *arrays)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i]  < '0' && str[i] > '9')
			ft_error(arrays);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		ft_error(arrays);
	return (num * sign);
}

int	pushswap_len(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

void	ctrl_doubles(int *array, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;	
		while (j < size)
		{
			if (array[i] == array[j])
				ft_error(array);
			j++;
		}
		i++;
	}
}

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
		arrays.a[i] = push_swap_atoi(argv[i], arrays.a);
	ctrl_doubles(arrays.a, arrays.size_a);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		push_swap(argv);
		return (0);
	}
	return (0);
}