/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:30:10 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/06 15:48:13 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	find_mediane(int *pivot, int *array, int size)
{
	int	i;
	int	*tmp_array;

	tmp_array = (int *)malloc(size * sizeof(int));
	if (!tmp_array)
		return (0);
	i = -1;
	while (++i < size)
		tmp_array[i] = array[i];
	tmp_array_sort(tmp_array, size);
	*pivot = tmp_array[size / 2];
	free(tmp_array);
	return (1);
}

void	quicksort_three_element_in_b(t_push_swap *arrays, int len)
{
	if (len == 1)
		pa(arrays);
	else if (len == 2)
	{
		if (arrays->b[0] < arrays->b[1])
			sb(arrays);
		while (len--)
			pa(arrays);
	}
	else if (len == 3)
	{
		while (len || !(arrays->a[0] < arrays->a[1]
				&& arrays->a[1] < arrays->a[2]))
		{
			if (len == 1 && (arrays->a[0] > arrays->a[1]))
				sa(arrays);
			else if (len == 1 || (len >= 2 && arrays->b[0] > arrays->b[1])
				|| (len == 3 && (arrays->b[0] > arrays->b[2])))
				len = push_array(arrays, len, 'a');
			else
				sb(arrays);
		}
	}
}

void	quicksort_three_element_in_a_b(t_push_swap *arrays, int len)
{
	if (len == 3 && arrays->size_a == 3)
		case_of_has_three_element_in_a(arrays);
	else if (len == 2)
	{
		if (arrays->a[0] > arrays->a[1])
			sa(arrays);
	}
	else if (len == 3)
	{
		while (len != 3 || !(arrays->a[0] < arrays->a[1]
				&& arrays->a[1] < arrays->a[2]))
		{
			if (len == 3 && arrays->a[0] > arrays->a[1] && arrays->a[2])
				sa(arrays);
			else if (len == 3 && !(arrays->a[2] > arrays->a[0]
					&& arrays->a[2] > arrays->a[1]))
				len = push_array(arrays, len, 'b');
			else if (arrays->a[0] > arrays->a[1])
				sa(arrays);
			else if (len++)
				pa(arrays);
		}
	}
}

int	quicksort_array_a(t_push_swap *arrays, int len, int count_rotate)
{
	int	pivot;
	int	num;

	if (ctrl_sorted(arrays->a, len, 0))
		return (1);
	num = len;
	if (len <= 3)
		return (quicksort_three_element_in_a_b(arrays, len), 1);
	if (!find_mediane(&pivot, arrays->a, len))
		return (0);
	while (len != ((num / 2) + (num % 2)))
	{
		if (arrays->a[0] < pivot && (len--))
			pb(arrays);
		else if (++count_rotate)
			ra(arrays);
	}
	while ((arrays->size_a != ((num / 2) + (num % 2))) && count_rotate--)
		rra(arrays);
	return (quicksort_array_a(arrays, ((num / 2) + (num % 2)), 0)
		&& quicksort_array_b(arrays, (num / 2), 0));
}

int	quicksort_array_b(t_push_swap *arrays, int len, int count_rotate)
{
	int	pivot;
	int	num;

	if (ctrl_sorted(arrays->b, len, 1))
		while (len--)
			pa(arrays);
	if (len <= 3)
		return (quicksort_three_element_in_b(arrays, len), 1);
	num = len;
	if (!find_mediane(&pivot, arrays->b, len))
		return (0);
	while (len != num / 2)
	{
		if ((arrays->b[0] >= pivot) && len--)
			pa(arrays);
		else if (++count_rotate)
			rb(arrays);
	}
	while ((arrays->size_b != num / 2) && count_rotate--)
		rrb(arrays);
	return (quicksort_array_a(arrays, ((num / 2) + (num % 2)), 0)
		&& quicksort_array_b(arrays, (num / 2), 0));
}
