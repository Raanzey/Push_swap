/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:45 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/15 15:43:20 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void max_number_top_b(t_stack *stk, int max_index)
{
	if (list_len(stk->b) / 2 > max_index)
	{
		while (max_index > 0)
		{
			swap_step("rb",stk);
			max_index--;
		}		
	}
	else if (list_len(stk->b) / 2 < max_index)
	{
		while (max_index < list_len(stk->b))
		{
			swap_step("rrb",stk);
			max_index++;
		}
	}
}
void	max_number_find_b(t_stack *stk, int data_b)
{
	int max;
	int max_index;
	t_node *temp_b;
	
	max = -2147483648;
	temp_b = stk->b;
	while (temp_b)
	{
		if(temp_b->data > data_b && temp_b->data > max)
			max = temp_b->data;			
		temp_b = temp_b->next;
	}
	max_index = calculate_index(stk->b, max);
	max_number_top_b(stk, max_index);	
}
int	move_count(t_stack *stk, int index_a, int index_b)
{		
	if (list_len(stk->a) / 2 > index_a && list_len(stk->b) / 2 > index_b) //+ +
	{
		if (index_a > index_b)
			return (index_a);
		return (index_b);
	}
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 >= index_b) //- +
		return (list_len(stk->a) - index_a + index_b);
	else if (list_len(stk->a) / 2 >= index_a && list_len(stk->b) / 2 <= index_b)//+ -
		return (list_len(stk->b) - index_b + index_a);
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 <= index_b) //- -
	{
		if (index_a > index_b)
			return (list_len(stk->a) - index_a);
		return (list_len(stk->b) - index_b);
	}
	return (0);
}
int	number_b(t_stack *stk, int result_move, int result_index)
{
	int	move;
	int	num_b;
	int	index_b;
	int	index_a;
	t_node *temp;
	
	temp = stk->a;
	while (temp)
	{
		num_b = number_find_b(stk, temp->data);
		index_b = calculate_index(stk->b, num_b);
		index_a = calculate_index(stk->a, temp->data);		
		move = move_count(stk, index_a, index_b);
		if (move < result_move && index_a < result_index)
		{
			result_index = index_a;
			result_move = move;			
		}	
		temp = temp->next;
	}
	return (result_index);
}
