/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 08:07:55 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/29 16:32:32 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_fprintf(int fd, const char *input, ...);
//character type
int		ft_putchar(char ch, int fd, int *count);
int		ft_putstr(char *str, int fd, int *count);
//decimal type
void	ft_putdec(long int num, int fd, int *count);
void	ft_putunsdec(unsigned int num, int fd, int *count);
//hexadecimal type
void	ft_putlhex(unsigned int num, int fd, int *count);
void	ft_putuhex(unsigned int num, int fd, int *count);
int		ft_putptr(unsigned long long ptr, int ptrcount, int fd, int *count);

#endif
