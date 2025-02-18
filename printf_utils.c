/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:00:06 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/10 17:21:23 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return (0);
	while(s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnmbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11) ;
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnmbr(n / 10);
	}
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;	
	if(n > 9)
	{
		count += ft_putnbr_unsigned( n / 10);
	}
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int     ft_putnbr_hexa(unsigned int n, char type)
{	
        int     count;

        count = 0;
        if(n >= 16)
        {
                count += ft_putnbr_hexa((n / 16), type);
        }
	if ((n % 16) > 9)
	{
		if (type == 'x')
        	count += ft_putchar(((n % 16) - 10) + 'a');
		else
		count += ft_putchar(((n % 16) - 10) + 'A');
	}
	else 
		count += ft_putchar((n % 16) + '0');
        return (count);
}

int     ft_putnbr_hexa_pointer(unsigned long long n)
{
        int     count;

        count = 0;
        if(n >= 16)
        {
                count += ft_putnbr_hexa_pointer(n / 16);
        }
        if ((n % 16) > 9)
        {
                count += ft_putchar(((n % 16) - 10) + 'a');
        }
        else
                count += ft_putchar((n % 16) + '0');
        return (count);
}


int	ft_print_pointer(void *ptr)
{
	int	count;
	count = 0;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_hexa_pointer((unsigned long long)ptr);
	return (count);
}
