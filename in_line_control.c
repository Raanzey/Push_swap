/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_line_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:33:28 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/16 12:40:56 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stk)
{
	t_node	*temp;

	temp = stk->a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str2 == '0')
		str2++;
	while (*str1 == '0')
		str1++;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
