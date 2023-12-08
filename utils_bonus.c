/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:02:37 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/08 11:59:14 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_error_b(t_push_swap arrays, int k, char **argv)
{
	free(arrays.a);
	free(arrays.b);
	if (k == 1)
		ft_allfree_b(argv);
	write(2, "Error\n", 6);
	exit (1);
}

int	push_swap_atoi_b(char *str, t_push_swap arrays, int k, char **argv)
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
	if (str[i] == '\0')
		ft_error_b(arrays, k, argv);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error_b(arrays, k, argv);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		ft_error_b(arrays, k, argv);
	return (num * sign);
}

int	pushswap_len_b(char **argv)
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

void	ctrl_doubles_b(t_push_swap arrays, int size, int k, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arrays.a[i] == arrays.a[j])
				ft_error_b(arrays, k, argv);
			j++;
		}
		i++;
	}
}

int	ctrl_sorted_b(int *array, int size, int order_way)
{
	int	i;

	if (order_way == 0)
	{
		i = 0;
		while (++i < size)
			if (array[i - 1] > array[i])
				return (0);
		return (1);
	}
	else
	{
		i = 0;
		while (++i < size)
			if (array[i - 1] < array[i])
				return (0);
		return (1);
	}
}
