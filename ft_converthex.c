/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:42:30 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/19 18:49:49 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int  ft_converthex(unsigned long nb, const char type)
{
    int count;
    int mod;
    
    count = 0;
    if (nb >= 16)
        count += ft_converthex(nb / 16, type);
    mod = nb % 16;
    if (mod > 9 && mod < 16)
    {
        if (type == 'X')
            mod = mod - 10 + 65;
        else
            mod = mod - 10 + 97;
    }
    else 
        mod += '0';
    count += ft_putchar_fd(mod, 1);
    
    return (count);
}