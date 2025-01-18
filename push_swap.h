/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:29 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/17 16:36:41 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Push_swap/libft/libft.h"

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


#endif