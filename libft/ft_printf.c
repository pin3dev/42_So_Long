/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:42:25 by ivbatist          #+#    #+#             */
/*   Updated: 2022/12/23 22:43:51 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, char specification)
{
	int	x;

	x = 0;
	if (specification == 'i' || specification == 'd')
		x = ft_putnbr(va_arg(args, int), 1);
	else if (specification == 'c')
		x = ft_putchar(va_arg(args, int));
	else if (specification == 's')
		x = ft_putstr(va_arg(args, char *));
	else if (specification == 'u')
		x = ft_print_unsig(va_arg(args, unsigned int), 1);
	else if (specification == 'p')
		x = ft_print_pointer(va_arg(args, unsigned long long));
	else if (specification == 'x')
		x = ft_print_hex(va_arg(args, unsigned int), specification);
	else if (specification == 'X')
		x = ft_print_hex(va_arg(args, unsigned int), specification);
	else if (specification == '%')
		x = ft_putchar('%');
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/*int main(void)
{
	//int d = 364;
	//int c;
	//char l = 'L';
	//char *str = "era uma vez";
	// printf("\n\n printf\n");
	// c = printf(" char         = %c\n str          = %s\n 
	pointer      = %p\n dec          = %d\n int          = %i\n 
	unsigned int = %u\n hexmin       = %x\n hexhigh      = %X\n 
	percent      = %%\n ", l, str, str, d, d, d, d, d);
	// printf("\n\n o meu\n");
	// ft_printf(" char         = %c\n str          = %s\n 
	pointer      = %p\n dec          = %d\n int          = %i\n 
	unsigned int = %u\n hexmin       = %x\n hexhigh      = %X\n 
	percent      = %%\n", l, str, str, d, d, d, d, d);

	// c = printf(" gdfgdfgdfgdgdr %d\n",d);
	// ft_printf(" gdfgdfgdfgdgdr %d\n",d);
	// printf(" printf len = %d\n", c);

	ft_printf("ft_printf Hex: %x\n", 55555);
	printf("printf Hex: %x\n", 55555);
	return (0);
}
*/
