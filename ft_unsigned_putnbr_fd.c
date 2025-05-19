/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:23:37 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/19 18:48:37 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the unsigned integer ’n’ to the specified file
descriptor.*/

#include "ft_printf.h"

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	int	r;

	r = 0;
	if (n > 9)
		r += ft_putnbr_fd(n / 10, fd);
	r += ft_putchar_fd((n % 10) + '0', fd);
	return (r);
}
