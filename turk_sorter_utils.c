/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:45 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/21 17:50:12 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_number_top_b(t_stack *stk, int max_index)
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
	// printf("MAX B İNDEX SAYISI----> %d\n", max_index);
	max_number_top_b(stk, max_index);
}
int	move_count(t_stack *stk, int index_a, int index_b, int len_a)
{
	int	len_b;

	len_b = list_len(stk->b);
	if (len_a / 2 > index_a && len_b / 2 > index_b) //+ +
	{
		if (index_a > index_b)
			return (index_a);
		return (index_b);
	}
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)//- +
	{

		return (((  index_a - list_len(stk->a))*-1) + index_b);
	}
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)//+ -
	{
		
		return ((( index_b-list_len(stk->b) )*-1) + index_a);}
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)	//- -
	{
		if (index_a > index_b)
		{
			return (( index_a-list_len(stk->a) )*-1);
		}
		
		return (( index_b-list_len(stk->b))*-1);
	}
	
	return (0);
}

int	number_b(t_stack *stk, int result_move, int result_index)
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
		move = move_count(stk, index_a, index_b,list_len(temp));
		if (move < result_move)
		{
			result_move = move;
			result_index = temp->data;
		}
		temp = temp->next;
	}			 
	// printf("hamle=%d ",result_move);
	// printf("%d\n",result_index);
	return (result_index);
}
