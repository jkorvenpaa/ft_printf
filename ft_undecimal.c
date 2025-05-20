/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:23:37 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/20 13:07:55 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	int	r;

	r = 0;
	if (n > 9)
		r += ft_unsigned_putnbr_fd(n / 10, fd);
	r += ft_putchar_fd((n % 10) + '0', fd);
	return (r);
}

int	ft_undecimal(va_list *list)
{
	int				count;
	unsigned int	u;

	u = va_arg(*list, unsigned int);
	count = ft_unsigned_putnbr_fd(u, 1);
	return (count);
}
