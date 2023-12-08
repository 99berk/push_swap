/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:15:00 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/06 15:03:33 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_of_has_three_element_in_a(t_push_swap *arrays)
{
	if (arrays->a[0] > arrays->a[1] && arrays->a[0] < arrays->a[2]
		&& arrays->a[1] < arrays->a[2])
		sa(arrays);
	if (arrays->a[0] > arrays->a[1] && arrays->a[0] > arrays->a[2]
		&& arrays->a[1] > arrays->a[2])
	{
		sa(arrays);
		rra(arrays);
	}
	if (arrays->a[0] > arrays->a[1] && arrays->a[0] > arrays->a[2]
		&& arrays->a[1] < arrays->a[2])
		ra(arrays);
	if (arrays->a[0] < arrays->a[1] && arrays->a[0] < arrays->a[2]
		&& arrays->a[1] > arrays->a[2])
	{
		sa(arrays);
		ra(arrays);
	}
	if (arrays->a[0] < arrays->a[1] && arrays->a[0] > arrays->a[2]
		&& arrays->a[1] > arrays->a[2])
		rra(arrays);
}

int	start_sort(t_push_swap *arrays, int size)
{
	if (!ctrl_sorted(arrays->a, arrays->size_a, 0))
	{
		if (size == 2)
			sa(arrays);
		else if (size == 3)
			case_of_has_three_element_in_a(arrays);
		else
			quicksort_array_a(arrays, size, 0);
	}
	return (0);
}

int	push_array(t_push_swap *arrays, int len, char array_ab)
{
	if (array_ab == 'b')
		pb(arrays);
	else if (array_ab == 'a')
		pa(arrays);
	if (len > 0)
		len--;
	return (len);
}

void	tmp_array_sort(int *tmp_array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tmp_array[i] > tmp_array[j])
			{
				tmp = tmp_array[i];
				tmp_array[i] = tmp_array[j];
				tmp_array[j] = tmp;
			}
		}
	}
}
