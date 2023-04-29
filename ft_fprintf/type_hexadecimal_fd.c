/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:26:50 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/29 16:30:54 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_putlhex(unsigned int num, int fd, int *count)
{
	if (num > 16)
	{
		ft_putlhex(num / 16, fd, count);
		if (*count == -1)
			return ;
	}
	if (num == 16)
		ft_putstr("10", fd, count);
	else if (num % 16 < 10)
		ft_putchar(((num % 16) + '0'), fd, count);
	else
		ft_putchar(((num % 16) - 10 + 'a'), fd, count);
}

void	ft_putuhex(unsigned int num, int fd, int *count)
{
	if (num > 16)
	{
		ft_putuhex(num / 16, fd, count);
		if (*count == -1)
			return ;
	}
	if (num == 16)
		ft_putstr("10", fd, count);
	else if (num % 16 < 10)
		ft_putchar((num % 16) + '0', fd, count);
	else
		count += ft_putchar(((num % 16) - 10 + 'A'), fd, count);
}

int	ft_putptr(unsigned long long ptr, int ptrcount, int fd, int *count)
{
	if (ptr > 16)
		ptrcount += ft_putptr(ptr / 16, ptrcount, fd, count);
	if ((ptr / 16 == 0 || ptr % 16 == 0) && ptrcount == 0)
		ptrcount += ft_putstr("0x", fd, count);
	if (*count == -1)
		return (-1);
	if (ptr == 16)
		ptrcount += ft_putstr("10", fd, count);
	else if (ptr % 16 < 10)
		ptrcount += ft_putchar(((ptr % 16) + '0'), fd, count);
	else
		ptrcount += ft_putchar(((ptr % 16) - 10 + 'a'), fd, count);
	if (*count == -1)
		return (-1);
	return (ptrcount);
}
