/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:32:52 by bakgun            #+#    #+#             */
/*   Updated: 2023/11/29 13:42:43 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

typedef struct s_push_swap
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_push_swap;

char	**ft_split_b(char const *s, char c);
int		ft_strcmp_b(const char *s1, const char *s2);
int		push_swap_atoi_b(char *str, int *arrays);
int		pushswap_len_b(char **argv);
int		ctrl_sorted_b(int *array, int size, int order_way);
void	ctrl_doubles_b(int *array, int size);
void	ft_error_b(int *arrays);
void	sa_b(t_push_swap *arrays);
void	pa_b(t_push_swap *arrays);
void	ra_b(t_push_swap *arrays);
void	rra_b(t_push_swap *arrays);
void	sb_b(t_push_swap *arrays);
void	pb_b(t_push_swap *arrays);
void	rb_b(t_push_swap *arrays);
void	rrb_b(t_push_swap *arrays);
void	ss_b(t_push_swap *arrays);
void	rr_b(t_push_swap *arrays);
void	rrr_b(t_push_swap *arrays);

#endif