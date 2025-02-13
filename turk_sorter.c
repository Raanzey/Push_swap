/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/13 19:33:27 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sorter(t_stack *stk)
{
	int num_a;
	swap_step("pb", stk);
	if (list_len(stk->a) > 3)
		swap_step("pb", stk);	
	if (list_len(stk->a) > 3)
	{	
		
		num_a = calculate_num(stk);
		printf("A---->%d",num_a);		
	}
}
int calculate_num(t_stack *stk)
{
	int a;
	t_node *temp;

	temp = stk->a;
	while (temp)
	{
		if (number_b(stk,2147483647,-1) == calculate_index(stk->a, temp->data))
			a = temp->data;
		temp = temp->next;
	}
	return a;	
}
// int number_a(t_stack *stk)
// {
// }