/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:52:51 by hteixeir          #+#    #+#             */
/*   Updated: 2024/05/14 15:41:16 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_data *data, char c)
{
	int	width;

	width = data->format.width_value;
	if (data->format.specifier == '%')
	{
		putchar_n(c, 1, data);
		return ;
	}
	if (width > 1)
	{
		if (data->format.left)
		{
			putchar_n(c, 1, data);
			putchar_n(' ', width - 1, data);
		}
		else
		{
			putchar_n(' ', width - 1, data);
			putchar_n(c, 1, data);
		}
	}
	else
		putchar_n(c, 1, data);
}
