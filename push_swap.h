/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:29 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/20 17:08:51 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Push_swap/libft/libft.h"
# include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}t_node;

typedef struct stack
{
    t_node *a;
    t_node *b;
}t_stack;

int	ft_atoi(const char *str);
t_node *addValue(t_node *node, int data);
void display(t_node *node);
char	**ft_split(char const *s, char c);

#endif