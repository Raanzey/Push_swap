/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/11 18:56:44 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void turk_sorter(t_stack *stk)
{
	int num_a;
	
    swap_step("pb", stk); 
	if (list_len(stk->a) > 3)
		swap_step("pb", stk);
	while (list_len(stk->a) > 3)
	{
		
		num_b=movie_count_b(stk);	
	}
	
	
}
int	movie_count_b(t_stack *stk)//-----> a sayısının kendinden küçük en büyük b sayısı
{
	
	int temp;
	while (stk->b)
	{
		if (stk->b->data < stk->a->data && stk->b->data > temp)
			temp = stk->b->data;	
		stk->b = stk->b->next;
	} 
	return temp;                             
}

int num_find_a(t_stack *stk)
{
	
}