/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:20:45 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/12 20:17:04 by yozlu            ###   ########.fr       */
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

int	move_count(t_stack *stk, int index_a, int index_b)
{
	if (list_len(stk->a) / 2 > index_a && list_len(stk->b) / 2 > index_b)
	{
		if (index_a > index_b)
			return (index_a);
		return (index_b);
	}
	else if (list_len(stk->a) / 2 < index_a && list_len(stk->b) / 2 > index_b)
		return (index_a + index_b);
	else if (list_len(stk->a) / 2 > index_a && list_len(stk->b) / 2 < index_b)
		return (index_a + index_b);
	else if (list_len(stk->a) / 2 < index_a && list_len(stk->b) / 2 < index_b)
	{
		if (index_a > index_b)
			return (index_a);
		return (index_b);
	}
	return (0);
}
int	number_find_a(t_stack *stk)
{
	int temp;
	while (stk->a)
	{
		temp = number_find_b(stk, stk->a->data);
		stk->a = stk->a->next;
	}
	return (temp);
}