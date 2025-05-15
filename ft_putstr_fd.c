/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:38:58 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/15 16:23:39 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Outputs the string ’s’ to the specified file descriptor.*/

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	r;

	i = 0;
	while (s[i])
	{
		r = ft_putchar_fd(s[i], fd);
		if (r != 1)
			return (-1);
		i++;
	}
	return (i);
}
