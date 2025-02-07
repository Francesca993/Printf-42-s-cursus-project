/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:09:19 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/07 16:17:07 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list	args;
	int	i;

	i = 0;
	count = 0;
	va_start(args, str);

	while (str[i] != '\0')
	{
		if ((str[i] == '%') && (str[i+ 1]))
		{
			i++;
			count += ft_check_format(str[i], args);
		}
		else
		{

			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
