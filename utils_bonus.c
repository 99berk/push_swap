/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:02:37 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/29 13:46:05 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_error_b(int *arrays)
{
	free(arrays);
	write(2, "Error\n", 6);
	exit (1);
}

int	push_swap_atoi_b(char *str, int *arrays)
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
		ft_error_b(arrays);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error_b(arrays);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		ft_error_b(arrays);
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

void	ctrl_doubles_b(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				ft_error_b(array);
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
