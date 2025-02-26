/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:45 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/26 13:14:56 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_number_top_b(t_stack *stk, int max_index)
{
	if (list_len(stk->b) / 2 > max_index)
	{
		while (max_index > 0)
		{
			swap_step("rb", stk);
			max_index--;
		}
	}
	else if (list_len(stk->b) / 2 < max_index)
	{
		while (max_index < list_len(stk->b))
		{
			swap_step("rrb", stk);
			max_index++;
		}
	}
}

void	max_number_find_b(t_stack *stk, int data_b)
{
	int		max;
	int		max_index;
	t_node	*temp_b;

	max = -2147483648;
	temp_b = stk->b;
	while (temp_b)
	{
		if (temp_b->data > data_b && temp_b->data > max)
			max = temp_b->data;
		temp_b = temp_b->next;
	}
	max_index = calculate_index(stk->b, max);
	max_number_top_b(stk, max_index);
}

int	move_count(t_stack *stk, int index_a, int index_b, int len_a)
{
	int	len_b;

	len_b = list_len(stk->b);
	if (list_len(stk->a) % 2 == 1)
		len_a = list_len(stk->a) + 1;
	if (list_len(stk->b) % 2 == 1)
		len_b = list_len(stk->b) + 1;
	if (len_a / 2 > index_a && len_b / 2 > index_b)
	{
		if (index_a >= index_b)
			return (index_a);
		return (index_b);
	}
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)
		return (((index_a - list_len(stk->a)) * -1) + index_b);
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)
		return (((index_b - list_len(stk->b)) * -1) + index_a);
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)
	{
		if (list_len(stk->a) - index_a > list_len(stk->b) - index_b)
			return ((index_a - list_len(stk->a)) * -1);
		return ((index_b - list_len(stk->b)) * -1);
	}
	return (0);
}
