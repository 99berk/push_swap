
#include "push_swap.h"

void    sb(t_push_swap *arrays)
{
	int	tmp;

	if (arrays->size_b <= 1)
		return ;
	tmp = arrays->b[0];
	arrays->b[0] = arrays->b[1];
	arrays->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_push_swap *arrays)
{
	int	i;

	if (arrays->size_a)
	{
		arrays->size_b++;
		i = arrays->size_b;
		while (--i > 0)
			arrays->b[1] = arrays->b[i - 1];
		arrays->b[0] = arrays->a[0];
		i = -1;
		while (++i < arrays->size_a)
			arrays->a[i] = arrays->a[i + 1];
		write(1, "pb\n", 3);
	}
}

void	rb(t_push_swap *arrays)
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
	write(1, "rb\n", 3);
}

void	rrb(t_push_swap *arrays)
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
	write(1, "rrb\n", 4);
}
