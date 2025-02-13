/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:45 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/13 19:34:51 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_find_b(t_stack *stk, int data_a)//-----> a sayısının kendinden küçük en büyük b sayısı
{
	int temp;
	t_node *temp_b;
	
	temp = 0;
	temp_b = stk->b;
	while (temp_b)
	{
		if (temp_b->data < data_a && temp_b->data > temp)
			temp = temp_b->data;
		temp_b = temp_b->next;
	}
	return (temp);
}

int max_value_b(t_stack *stk)
{
	int result;
	t_node *temp_b;
	t_node *temp_x;
	
	result = 0;
	temp_b = stk->b;
	temp_x = stk->b;
	while (temp_x)
	{
		temp_b = stk->b;
		while (temp_b->next)
		{
			if (temp_x->data > temp_b->next->data)
				result = temp_x->data;
			temp_b = temp_b->next;				
		}
		temp_x = temp_x->next;
	}
	printf("%d",result);
	return (result);
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
		return (list_len(stk->a)-index_a + index_b);
	else if (list_len(stk->a) / 2 >= index_a && list_len(stk->b) / 2 <= index_b)//+ -
		return (index_a + list_len(stk->b)-index_b);
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 <= index_b) //- -
	{
		if (index_a > index_b)
			return (list_len(stk->a)-index_a);
		return (list_len(stk->b)-index_b);
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
	// if (result_index == -1)
	// {
	// 	num_b = max_value_b(stk); max value işlemde kendinden küçük en büyük sayı yoksa bu fonksiyon.
	// }
	return (result_index);
}