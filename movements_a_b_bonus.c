/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a_b_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:17:15 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/06 15:16:58 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss_b(t_push_swap *arrays)
{
	int	tmp;

	if (arrays->size_a <= 1 || arrays->size_b <= 1)
		return ;
	tmp = arrays->a[0];
	arrays->a[0] = arrays->a[1];
	arrays->a[1] = tmp;
	tmp = arrays->b[0];
	arrays->b[0] = arrays->b[1];
	arrays->b[1] = tmp;
}

void	rr_b(t_push_swap *arrays)
{
	int	i;
	int	tmp;

	if (arrays->size_a <= 1 || arrays->size_b <= 1)
		return ;
	tmp = arrays->a[0];
	i = 0;
	while (++i < arrays->size_a)
		arrays->a[i - 1] = arrays->a[i];
	arrays->a[i - 1] = tmp;
	tmp = arrays->a[0];
	i = 0;
	while (++i < arrays->size_b)
		arrays->b[i - 1] = arrays->b[i];
	arrays->b[i - 1] = tmp;
}

void	rrr_b(t_push_swap *arrays)
{
	int	i;
	int	tmp;

	if (arrays->size_a <= 1 || arrays->size_b <= 1)
		return ;
	i = arrays->size_a;
	tmp = arrays->a[i - 1];
	while (--i > 0)
		arrays->a[i] = arrays->a[i - 1];
	arrays->a[i] = tmp;
	i = arrays->size_b;
	tmp = arrays->b[i - 1];
	while (--i > 0)
		arrays->b[i] = arrays->b[i - 1];
	arrays->b[i] = tmp;
}
