/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:02:40 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 11:59:11 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	put_0x(t_data *data)
{
	if (*(data->format.tmp) == 0 && data->format.specifier == 'p')
	{
		putstr_n ("(nil)", 5, data);
		return ;
	}
	if ((!ft_strchrr("xX", data->format.specifier)
			&& data->format.hash
			&& data->format.tmp[0] != '0')
		|| data->format.specifier == 'p')
	{
		if (data->format.uppercase)
			putstr_n("0X", 2, data);
		else
			putstr_n("0x", 2, data);
	}
}

static	void	put_sign(t_data *data)
{
	if (data->format.base == HEX)
		put_0x(data);
	else if (data->format.is_signed)
	{
		if (data->format.negative)
			putchar_n('-', 1, data);
		else if (!data->format.negative)
		{
			if (data->format.plus)
				putchar_n('+', 1, data);
			else if (!data->format.plus
				&& data->format.space)
				putchar_n(' ', 1, data);
		}
	}
}

int	nill(t_data *data, t_onion int_values)
{
	if ((data->format.specifier == 'p' && int_values.unint == 0))
	{
		if (data->format.left)
		{
			putstr_n("(nil)", 5, data);
			putchar_n(' ', data->format.n_spaces - 2, data);
			return (1);
		}
		else
		{
			putchar_n(' ', data->format.n_spaces - 2, data);
			putstr_n("(nil)", 5, data);
			return (1);
		}
	}
	return (0);
}

void	print_int(t_data *data, t_onion int_values)
{
	if (!(data->format.percision_value == 0 && int_values.unint == 0)
		|| (data->format.specifier == 'p'))
		itoa_base(data, int_values);
	if (data->format.percision_value > 0)
		data->format.zero_pad = 0;
	padding_zeros(data);
	padding_spaces(data);
	if (nill (data, int_values))
		return ;
	if (data->format.left)
	{
		put_sign(data);
		putchar_n('0', data->format.n_zeros, data);
		putstr_n(data->format.tmp, data->format.nbl, data);
		putchar_n(' ', data->format.n_spaces, data);
	}
	else
	{
		putchar_n(' ', data->format.n_spaces, data);
		put_sign(data);
		putchar_n('0', data->format.n_zeros, data);
		putstr_n(data->format.tmp, data->format.nbl, data);
	}
}
