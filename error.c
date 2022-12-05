/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:33:11 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/31 15:56:52 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *error, int errnum)
{
	if (error)
	{
		ft_putstr_fd(error, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd(strerror(errnum), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(errnum);
}
