/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/26 13:27:31 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorter_push(t_stack *stk, int num_a, int num_b, char push_list)
{
	int	index_a;
	int	index_b;
	int	len_a;
	int	len_b;

	len_a = list_len(stk->a);
	len_b = list_len(stk->b);
	if (list_len(stk->a) % 2 == 1)
		len_a = list_len(stk->a) + 1;
	if (list_len(stk->b) % 2 == 1)
		len_b = list_len(stk->b) + 1;
	index_a = calculate_index(stk->a, num_a);
	index_b = calculate_index(stk->b, num_b);
	if (len_a / 2 > index_a && len_b / 2 > index_b)
		plus_plus(stk, num_a, num_b, push_list);
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)
		minus_plus(stk, num_a, num_b, push_list);
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)
		plus_minus(stk, num_a, num_b, push_list);
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)
		minus_minus(stk, num_a, num_b, push_list);
}

static int	number_find_b(t_stack *stk, int data_a)
{
	int		min;
	int		max;
	int		count;
	t_node	*temp_b;

	count = 0;
	min = -2147483648;
	max = -2147483648;
	temp_b = stk->b;
	while (temp_b)
	{
		if (temp_b->data < data_a && temp_b->data > min)
		{
			min = temp_b->data;
			count++;
		}
		else if (temp_b->data > data_a && temp_b->data > max)
			max = temp_b->data;
		temp_b = temp_b->next;
	}
	if (count > 0)
		return (min);
	return (max);
}

static int	number_a(t_stack *stk, int result_move, int result_num)
{
	int		move;
	int		num_b;
	int		index_b;
	int		index_a;
	t_node	*temp;

	temp = stk->a;
	while (temp)
	{
		num_b = number_find_b(stk, temp->data);
		index_b = calculate_index(stk->b, num_b);
		index_a = calculate_index(stk->a, temp->data);
		move = move_count(stk, index_a, index_b, list_len(stk->a));
		if (move < result_move)
		{
			result_move = move;
			result_num = temp->data;
		}
		temp = temp->next;
	}
	return (result_num);
}

void	turk_sorter(t_stack *stk, int num_a, int num_b)
{
	swap_step("pb", stk);
	if (list_len(stk->a) > 3)
	{
		swap_step("pb", stk);
		while (list_len(stk->a) > 3)
		{
			num_a = number_a(stk, 2147483647, 2147483647);
			num_b = number_find_b(stk, num_a);
			sorter_push(stk, num_a, num_b, 'b');
		}
		max_number_find_b(stk, stk->b->data);
	}
	sorter_3(stk);
	while (stk->b)
	{
		num_a = number_find_a(stk, stk->b->data);
		sorter_push(stk, num_a, stk->b->data, 'a');
	}
	if (is_sorted(stk) == 0)
		first_min_number_a(stk, min_number_a(stk));
}
