/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wwriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:02:40 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 16:44:53 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoa_base(t_data *data, t_onion int_values)
{
	t_onion	ttmp;

	if (data->format.base < 2 || data->format.base > 16)
		return ;
	if (data->format.negative && !data->format.is_coverted)
	{
		int_values.nint = -(int_values.nint);
		data->format.is_coverted = 1;
		itoa_base(data, int_values);
	}
	else if (int_values.unint < data->format.base)
	{
		if (data->format.uppercase)
			data->format.tmp[data->format.nbl++] = UPSYMBOLS[int_values.unint];
		else
			data->format.tmp[data->format.nbl++] = SYMBOLS[int_values.unint];
	}
	else
	{
		ttmp.unint = int_values.unint / data->format.base;
		itoa_base(data, ttmp);
		ttmp.unint = int_values.unint % data->format.base;
		itoa_base(data, ttmp);
	}
}

void	write_everything(t_data *data)
{
	data->nwr_char += write(STDOUT_FILENO, data->buff, data->buff_index);
	ft_memiset(data->buff, 0, BUF_SIZE);
	data->buff_index = 0;
}

void	write_char(t_data *data, char c)
{
	if (data->buff_index == BUF_SIZE)
	{
		write_everything(data);
	}
	data->buff[data->buff_index++] = c;
}

void	putchar_n(char c, int n, t_data *data)
{
	if (n <= 0)
		return ;
	while (n--)
		write_char(data, c);
}

void	putstr_n(char *str, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision-- && *str)
		write_char(data, *str++);
}
