/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/10 18:31:44 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter_2(t_stack *stk)
{
	if (stk->a->data > stk->a->next->data)
		swap_step("sa", stk);
}
void	sorter_3(t_stack *stk)
{
	int	a;
	int	b;
	int	c;

	a = stk->a->data;
	b = stk->a->next->data;
	c = stk->a->next->next->data;
	if (a > b && b < c && a < c) // 2 1 3
		swap_step("sa", stk);
	else if (a > b && b > c) // 3 2 1
	{
		swap_step("sa", stk);
		swap_step("rra", stk);
	}
	else if (a > b && b < c && a > c) // 3 1 2
		swap_step("ra", stk);
	else if (a < b && b > c && a < c) // 1 3 2
	{
		swap_step("sa", stk);
		swap_step("ra", stk);
	}
	else if (a < b && b > c && a > c) // 2 3 1
		swap_step("rra", stk);
}

void	movie_count(t_stack *stk)
{
	int temp;
	while (stk->b)
	{
		if (stk->b->data < stk->a->data && stk->b->data > temp)
			temp = stk->b->data;
		stk->b = stk->b->next;
	}                              
}
