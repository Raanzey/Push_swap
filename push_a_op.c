/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:44:17 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/23 16:28:42 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_find_a(t_stack *stk, int data_b)
{
	int		max;
	int		min;
	t_node	*temp_a;
	int		count;

	temp_a = stk->a;
	count = 0;
	max = 2147483647;
	min = 2147483647;
	while (temp_a)
	{
		if (temp_a->data > data_b && temp_a->data < max)
		{
			max = temp_a->data;
			count++;
		}
		else if (temp_a->data < data_b && temp_a->data < min)
			min = temp_a->data;
		temp_a = temp_a->next;
	}
	if (count > 0)
		return (max);
	return (min);
}

int	min_number_a(t_stack *stk)
{
	int		min;
	t_node	*temp;

	temp = stk->a;
	min = 2147483647;
	while (temp)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	first_min_number_a(t_stack *stk, int data_a)
{
	int	index_a;

	index_a = calculate_index(stk->a, data_a);
	if (list_len(stk->a) / 2 >= index_a)
	{
		while (index_a > 0)
		{
			swap_step("ra", stk);
			index_a--;
		}
	}
	index_a = calculate_index(stk->a, data_a);
	if (list_len(stk->a) / 2 < index_a)
	{
		while (index_a < list_len(stk->a))
		{
			swap_step("rra", stk);
			index_a++;
		}
	}
}
