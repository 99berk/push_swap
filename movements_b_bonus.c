/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:17:34 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/26 14:21:44 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <unistd.h>

void	sb_b(t_push_swap *arrays)
{
	int	tmp;

	if (arrays->size_b <= 1)
		return ;
	tmp = arrays->b[0];
	arrays->b[0] = arrays->b[1];
	arrays->b[1] = tmp;
}

void	pb_b(t_push_swap *arrays)
{
	int	i;

	if (arrays->size_a)
	{
		arrays->size_b++;
		i = arrays->size_b;
		while (--i > 0)
			arrays->b[i] = arrays->b[i - 1];
		arrays->b[0] = arrays->a[0];
		arrays->size_a--;
		i = -1;
		while (++i < arrays->size_a)
			arrays->a[i] = arrays->a[i + 1];
	}
}

void	rb_b(t_push_swap *arrays)
{
	int	i;
	int	tmp;

	if (arrays->size_b <= 1)
		return ;
	tmp = arrays->b[0];
	i = 0;
	while (++i < arrays->size_b)
		arrays->b[i - 1] = arrays->b[i];
	arrays->b[i - 1] = tmp;
}

void	rrb_b(t_push_swap *arrays)
{
	int	i;
	int	tmp;

	if (arrays->size_b <= 1)
		return ;
	i = arrays->size_b;
	tmp = arrays->b[i - 1];
	while (--i > 0)
		arrays->b[i] = arrays->b[i - 1];
	arrays->b[i] = tmp;
}