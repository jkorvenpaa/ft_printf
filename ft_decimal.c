/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:23:37 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/20 13:07:41 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_putnbr_fd(int n, int fd)
{
	int	r;

	r = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		r = ft_putchar_fd('-', fd);
		n = -1 * n;
	}
	if (n > 9)
		r += ft_putnbr_fd(n / 10, fd);
	r += ft_putchar_fd((n % 10) + '0', fd);
	return (r);
}

int	ft_decimal(va_list *list)
{
	int	count;
	int	d;

	d = va_arg(*list, int);
	count = ft_putnbr_fd(d, 1);
	return (count);
}
