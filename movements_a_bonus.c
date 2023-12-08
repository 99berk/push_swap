/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:17:21 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/06 15:16:52 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa_b(t_push_swap *arrays)
{
	int	tmp;

	if (arrays->size_a <= 1)
		return ;
	tmp = arrays->a[0];
	arrays->a[0] = arrays->a[1];
	arrays->a[1] = tmp;
}

void	pa_b(t_push_swap *arrays)
{
	int	i;

	if (arrays->size_b)
	{
		arrays->size_a++;
		i = arrays->size_a;
		while (--i > 0)
			arrays->a[i] = arrays->a[i - 1];
		arrays->a[0] = arrays->b[0];
		arrays->size_b--;
		i = -1;
		while (++i < arrays->size_b)
			arrays->b[i] = arrays->b[i + 1];
	}
}

void	ra_b(t_push_swap *arrays)
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
}

void	rra_b(t_push_swap *arrays)
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
}
