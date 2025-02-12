/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/12 20:19:01 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void turk_sorter(t_stack *stk)
{
    swap_step("pb", stk);
    //swap_step("pb", stk);
	//list_print(stk->b);
	if (list_len(stk->a) > 3)
		swap_step("pb", stk);
	//list_print(stk->b);
	if (list_len(stk->a) > 3)
	{
		number_b(stk);
	}
}
int	number_b(t_stack *stk)
{
	int move;
	int num_b;
	int index_b;
	int index_a;
	// while (stk->a)
	// {
		num_b = number_find_b(stk, stk->a->data);
		//printf("%p\n", stk->b);
		printf("%d\n", num_b);
		index_b = calculate_index(stk->b, num_b);//------>YANLIŞ ÇALIŞIYOR
		printf("%d\n", index_b);
		index_a = calculate_index(stk->a, stk->a->data);
		printf("%d\n", index_a);
		move = move_count(stk, index_a, index_b);
		//printf("%d", move);
		return(move);
		//stk->a = stk->a->next;
	//}
}
// int number_a(t_stack *stk)
// {
// }