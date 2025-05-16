/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:54:42 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/05/16 14:33:07 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int ft_printf(const char *str, ...);
int ft_helper(const char type, va_list *list);
int ft_putchar_fd(char c, int fd);
int ft_putstr_fd(char *s, int fd);
int ft_putnbr_fd(int n, int fd);

#endif