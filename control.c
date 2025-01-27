/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:06 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/27 19:18:54 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void check(char **data)
{
    int i;
    int j;
    
    i = 1;
    while (data[i])
    {
        j = 0;
        if (data[i][j] == '+' || data[i][j] == '-')
            j++;
        while (data[i][j])
        {
            if (data[i][j] < '0' || data[i][j] > '9')
            {
                write(1, "Eerror\n", 6);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        if (ft_atoi(data[i]) > 2147483647 /* && ft_atoi(data[i]) < -2147483648 MİN DEĞER OLMALIMI*/) 
        {
            write(1, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        i++;    
    }
}
