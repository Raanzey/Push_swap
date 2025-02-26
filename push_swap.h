/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:29 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/26 16:59:06 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Push_swap/libft/libft.h"
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stack;

t_node				*push_b(t_stack *stk);
t_node				*push_a(t_stack *stk);
t_node				*rotate_ab(t_node *node);
t_node				*rev_rotate_ab(t_node *node);
t_node				*step_ss(t_node *node);
t_node				*add_value(t_node *node, int data);

int					list_op_add(t_stack *stk, char **av);
int					is_sorted(t_stack *stk);
int					min_number_a(t_stack *stk);
int					move_count(t_stack *stk, int index_a, int index_b,
						int len_a);
int					calculate_index(t_node *node, int data);
int					number_find_a(t_stack *stk, int data_b);
int					list_len(t_node *node);
int					ft_strcmp(const char *str1, const char *str2);
long				ft_atol(const char *str);
char				**split_check(int argc, char **argv);

void				first_min_number_a(t_stack *stk, int data_a);
void				max_number_find_b(t_stack *stk, int data_a);
void				minus_minus(t_stack *stk, int num_a, int num_b,
						char push_list);
void				plus_minus(t_stack *stk, int num_a, int num_b,
						char push_list);
void				minus_plus(t_stack *stk, int num_a, int num_b,
						char push_list);
void				plus_plus(t_stack *stk, int num_a, int num_b,
						char push_list);
void				turk_sorter(t_stack *stk, int num_a, int num_b);
void				sorter_3(t_stack *stk);
void				swap_step(char *str, t_stack *stk);
void				free_argv(char **argv);
void				free_list(t_node *node);
void				check(char **data);
void				error(char **data, char *temp_free);
void				error_av(char **data);
#endif