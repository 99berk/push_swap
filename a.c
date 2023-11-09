/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:58:08 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/04 18:35:24 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *arrays)
{
	int	tmp;

	if (arrays->size_a <= 1)
		return ;
	tmp = arrays->a[0];
	arrays->a[0] = arrays->a[1];
	arrays->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	pa(t_push_swap *arrays)
{
	int	i;

	if (arrays->size_b)
	{
		arrays->size_a++;
		i = arrays->size_a;
		while (--i > 0)
			arrays->a[1] = arrays->a[i - 1];
		arrays->a[0] = arrays->b[0];
		i = -1;
		while (++i < arrays->size_b)
			arrays->b[i] = arrays->b[i + 1];
		write(1, "pa\n", 3);
	}
}

void	ra(t_push_swap *arrays)
{
	int	i;
	int	tmp;

	if (arrays->size_a <= 1)
		return ;
	tmp = arrays->a[0];
	i = 0;
	while (++i < arrays->size_a)
		arrays->a[i - 1] = arrays->a[i];
	arrays->a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_push_swap *arrays)
{
	int	i;
	int	tmp;

	if (arrays->size_a <= 1)
		return ;
	i = arrays->size_a;
	tmp = arrays->a[i - 1];
	while (--i > 0)
		arrays->a[i] = arrays->a[i - 1];
	arrays->a[i] = tmp;
	write(1, "rra\n", 4);
}
