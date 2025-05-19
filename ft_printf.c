/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:54:57 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/19 18:45:42 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list list;
    va_start(list, str);
    int i;
    int count;
    
    i = 0;
    count = 0;
    while(str[i])
    {
        if(str[i] == '%')
        {
            if (str[i+1] == '\0')
                break;
            i++;
            count = count + ft_helper(str[i], &list);
        }
        else
        {
            ft_putchar_fd(str[i], 1);
            count++;
        }
        i++;
    }
    va_end(list);
    return (count);
}
# include<stdio.h>

int main(void)
{
   int count;
   int count2;

   char str[] = "hey";
   void *pointer;
   pointer = &str;

   count = ft_printf("hello %x hello %u\n", -2147483647, -2147483647);
   count2 = printf("hello %x hello %u\n", -2147483647, -2147483647);
   printf("%d\n", count);
   printf("%d\n", count2);

    return (0);
}
