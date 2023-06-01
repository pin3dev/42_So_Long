/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: xxxx/xx/xx xx:xx:xx by ivbatist          #+#    #+#             */
/*   Updated: xxxx/xx/xx xx:xx:xx by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	dest = malloc(sizeof(*dest) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include<string.h>
#include<stdio.h>
int main()
{  
    char str[] = "dale maluco";
    printf("string original: %s \n", str);
    char *copy = ft_strdup(str);
    int size = strlen(copy);
    printf("string copiada pelo ft: %s \n", copy);
    printf("tamanho da string copiada pelo ft: %d \n", size);

    free(copy);

    copy = strdup(str);
    size = strlen(copy);
    printf("string copiada pela função: %s \n", copy);
    printf("tamanho da string copiada pela função: %d \n", size);

    return 0;
}*/