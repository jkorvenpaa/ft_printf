/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:54:09 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/16 16:48:12 by jkorvenp         ###   ########.fr       */
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
// add negative numbers rule

static int  converthex(int nb)
{
    int count;
    int mod;

    count = 0;
    if (nb >= 16)
        count += converthex(nb / 16);
    mod = nb % 16;
    if (mod > 9 && mod < 16)
        mod = mod - 10 + 97;
    else 
        mod += '0';
    count += ft_putchar_fd(mod, 1);
    
    return(count);
}
static int  ft_hex(va_list *list)
{
    int count;
    int nb = va_arg(*list, int);
    
    count = converthex(nb);
    return(count);
} 

/*static int ft_pointer(va_list *list, const char *str)
{
    int count;
    void *vp = va_arg(*list, void *);
    vp = &str;
    count = ft_putstr_fd("0x", 1);
    count += converthex()
    return(count);
}*/
static int ft_decimal(va_list *list)
{
    int count;
    int c = va_arg(*list, int);
    count = ft_putnbr_fd(c, 1);
    return (count);
}
int ft_helper(const char type, va_list *list)
{
    int count;

//    if (type == '%')
//        count =

    count = 0;
    if (type == 'c')
        count = ft_char(list);
    if (type == 's')
        count = ft_string(list);
    if (type == 'd' || type == 'i')
        count = ft_decimal(list);
    if (type == 'x')
        count = ft_hex(list);
    return (count);
}
        //    if (type == 'p')
  //      count = ft_pointer(type, list, str);
   /* if (type == 'u')
        count = ft_undesimal();
   
    if (type == 'X')
        count = ft_hexupp();
 */
