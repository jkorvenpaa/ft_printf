/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:38:58 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/20 13:08:12 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	r;

	i = 0;
	if (!s)
	{
		r = write (1, "(null)", 6);
		return (r);
	}
	while (s[i])
	{
		r = ft_putchar_fd(s[i], fd);
		if (r != 1)
			return (-1);
		i++;
	}
	return (i);
}
