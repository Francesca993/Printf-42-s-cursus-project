/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:09:19 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/10 17:22:48 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char str, va_list args)
{
	if (str == '%')
	{
		write(1, "%", 1);
		return(1);
	}
	if (str == 'c')
	{
		char c = (char) va_arg(args, int);
			return (ft_putchar(c));
	}
	if (str == 's')
	{
		return (ft_putstr(va_arg(args, char *)));
	}
	if (str == 'd' || str == 'i')
	{
		return (ft_putnmbr(va_arg(args, int)));
	}
	if (str == 'u')
	{
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	}
	if (str == 'x' || str == 'X')
	{
		return (ft_putnbr_hexa(va_arg(args, unsigned int), str));
	}
	if (str == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	return (0);
}

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
			count += check_type(str[i], args);
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

/*
 * // Test della funzione ft_printf
#include <stdio.h>
int main() {
	int numero = 42;
	int *ptr = &numero;
	void *null_ptr = NULL;
 printf("Puntatore valido con printf: %p\n", ptr);
    printf("Puntatore NULL con printf: %p\n", null_ptr);

      ft_printf("Puntatore valido: %p\n", ptr);
    ft_printf("Puntatore NULL: %p\n", null_ptr);

    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Number: %d\n", 12345);
    ft_printf("Percent sign: %%\n");
    ft_printf("Unsigned int: %u\n", 4294967295);
    ft_printf("Unsigned int: %u\n", 429496725);
    ft_printf("Esadecimale: %x\n", 123);
    ft_printf("Numero esadecimale minuscolo: %x\n", 255);
    printf("Numero esadecimale minuscolo con printfvero: %x\n", 255);
    ft_printf("Numero esadecimale maiuscolo: %X\n", 255);
    printf("Numero esadecimale maiuscolo con printf vero: %X\n", 255);
    ft_printf("Numero esadecimale grande: %x\n", 4294967295);
    printf("Numero esadecimale grande con printf vero: %lx\n", 4294967295);
    return 0;
}
*/
