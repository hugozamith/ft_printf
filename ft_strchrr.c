/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:48:07 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 12:35:47 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchrr(const char *str, int c)
{
	if (NULL == str)
		return (READ_ERROR);
	while (*str)
	{
		if (*str == c)
			return (OK);
		str++;
	}
	return (READ_ERROR);
}
