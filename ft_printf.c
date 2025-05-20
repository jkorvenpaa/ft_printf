/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:54:57 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/20 13:05:58 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	list;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
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
