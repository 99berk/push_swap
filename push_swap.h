/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakgun <bakgun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:55:48 by bakgun            #+#    #+#             */
/*   Updated: 2023/12/13 11:27:32 by bakgun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_push_swap
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_push_swap;

char	**ft_split(char const *s, char c);
char	**ft_allfree(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		quicksort_array_a(t_push_swap *arrays, int len, int count_rotate);
int		quicksort_array_b(t_push_swap *arrays, int len, int count_rotate);
int		push_array(t_push_swap *arrays, int len, char array_ab);
int		start_sort(t_push_swap *arrays, int size);
int		push_swap_atoi(char *str, t_push_swap arrays, char **argv);
int		pushswap_len(char **argv);
int		ctrl_sorted(int *array, int size, int order_way);
void	ctrl_doubles(t_push_swap arrays, int size, char **argv);
void	ft_error(t_push_swap arrays, char **argv);
void	sa(t_push_swap *arrays);
void	pa(t_push_swap *arrays);
void	ra(t_push_swap *arrays);
void	rra(t_push_swap *arrays);
void	sb(t_push_swap *arrays);
void	pb(t_push_swap *arrays);
void	rb(t_push_swap *arrays);
void	rrb(t_push_swap *arrays);
void	ss(t_push_swap *arrays);
void	rr(t_push_swap *arrays);
void	rrr(t_push_swap *arrays);
void	case_of_has_three_element_in_a(t_push_swap *arrays);
void	tmp_array_sort(int *tmp_array, int size);

#endif