/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:54:09 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/19 18:45:03 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
*/

# include"ft_printf.h"

static int ft_char (va_list *list)
{
    int count;
    int c = va_arg(*list, int);
    char ch = (char)c;

    count = ft_putchar_fd(ch,1);
    return (count);
}

static int ft_string(va_list *list)
{
    int count;
    char *str = va_arg(*list, char *);
    count = ft_putstr_fd(str,1);
    return (count);
}

static int ft_decimal(va_list *list)
{
    int count;
    int d = va_arg(*list, int);
    count = ft_putnbr_fd(d, 1);
    return (count);
}
static int ft_undecimal(va_list *list)
{
    int count;
    unsigned int u = va_arg(*list, unsigned int);
    
    count = ft_unsigned_putnbr_fd(u, 1);
    return (count);
}

static int  ft_hex(va_list *list, const char type)
{
    int count;
    unsigned long nb = va_arg(*list, unsigned long);
    
    count = ft_converthex(nb, type);
    return (count);
}  

static int ft_pointer(va_list *list, const char type)
{
    int count;
    void *vp = va_arg(*list, void*);
    uintptr_t nb;
    nb = (uintptr_t)vp;

    count = ft_putstr_fd("0x", 1);
    count += ft_converthex(nb, type);
    return (count);
}
int ft_helper(const char type, va_list *list)
{
    int count;
    
    count = 0;
    if (type == '%')
        count = ft_putchar_fd(type, 1);
    if (type == 'c')
        count = ft_char(list);
    if (type == 's')
        count = ft_string(list);
    if (type == 'd' || type == 'i')
        count = ft_decimal(list);
    if (type == 'u')
        count = ft_undecimal(list);
    if (type == 'p')
        count = ft_pointer(list, type);
    if (type == 'x' || type == 'X')
        count = ft_hex(list, type);
    return (count);
}
