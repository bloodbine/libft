/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:24:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/29 16:30:20 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_putdec(long int num, int fd, int *count)
{
	if (num < 0)
	{
		ft_putchar('-', fd, count);
		if (*count == -1)
			return ;
		ft_putdec(num * -1, fd, count);
		return ;
	}
	if (num > 9)
	{
		ft_putdec(num / 10, fd, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(((num % 10) + '0'), fd, count);
}

void	ft_putunsdec(unsigned int num, int fd, int *count)
{
	if (num > 9)
	{
		ft_putdec(num / 10, fd, count);
		if (*count == -1)
			return ;
	}
	ft_putchar(((num % 10) + '0'), fd, count);
}
