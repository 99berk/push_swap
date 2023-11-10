/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:59:13 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/10 15:12:07 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ss(t_push_swap *arrays)
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
	write(1, "ss\n", 3);
}

void	rr(t_push_swap *arrays)
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
	write(1, "rr\n", 3);
}

void	rrr(t_push_swap *arrays)
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
	write(1, "rrr\n", 4);
}
