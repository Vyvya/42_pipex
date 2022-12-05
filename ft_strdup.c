/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:52:22 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/30 19:54:24 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	len;

	len = 0;
	dst = (char *)malloc(sizeof(char) * ((ft_strlen(str) + 1)));
	if (!dst || !str)
		return (NULL);
	while (str[len])
	{
		dst[len] = str[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
