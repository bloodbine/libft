/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:50:12 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/29 16:32:10 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	ft_check_params(const char ch, va_list argsp, int fd, int *count)
{
	if (ch == 'c')
		ft_putchar(va_arg(argsp, int), fd, count);
	else if (ch == 's')
		ft_putstr(va_arg(argsp, char *), fd, count);
	else if (ch == 'd' || ch == 'i')
		ft_putdec(va_arg(argsp, int), fd, count);
	else if (ch == 'u')
		ft_putunsdec(va_arg(argsp, unsigned int), fd, count);
	else if (ch == 'x')
		ft_putlhex(va_arg(argsp, unsigned int), fd, count);
	else if (ch == 'X')
		ft_putuhex(va_arg(argsp, unsigned int), fd, count);
	else if (ch == 'p')
		ft_putptr(va_arg(argsp, unsigned long long), 0, fd, count);
	else if (ch == '%')
		ft_putchar('%', fd, count);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list	argsp;
	int		count;
	int		i;

	i = -1;
	count = 0;
	va_start(argsp, str);
	while (str[++i])
	{
		if (str[i] == '%')
			ft_check_params(str[++i], argsp, fd, &count);
		else
			ft_putchar(str[i], fd, &count);
		if (count < 0)
			return (va_end(argsp), -1);
	}
	return (va_end(argsp), count);
}
