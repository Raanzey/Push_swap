/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:45 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/14 17:55:16 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_find_b(t_stack *stk, int data_a)//-----> a sayısının kendinden küçük en büyük b sayısı
{
	int min;
	int max;
	int count;
	t_node *temp_b;
	
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
		else if(temp_b->data > data_a && temp_b->data > max)
			max = temp_b->data;			
		temp_b = temp_b->next;
	}
	if (count > 0)
		return(min);	
	return (max);
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
		printf("%d -> %d\n",temp->data,num_b);
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
void turk_sorter_push(t_stack *stk, int num_a, int num_b)
{
	int index_a;
	int index_b;
	index_a = calculate_index(stk->a, num_a);
	index_b = calculate_index(stk->b, num_b);
	
	if (list_len(stk->a) / 2 > index_a && list_len(stk->b) / 2 > index_b) //+ +
		plus_plus(stk, index_a, index_b);
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
}
