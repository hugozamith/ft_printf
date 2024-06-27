/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:48:06 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 11:58:31 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_zeros(t_data *data)
{
	if ((data->format.percision_value >= 0)
		&& (data->format.percision_value > data->format.nbl))
	{
		data->format.n_zeros = data->format.percision_value - \
		data->format.nbl;
		return ;
	}
	if (data->format.zero_pad && !data->format.left)
	{
		if (data->format.width_value > data->format.nbl)
			data->format.n_zeros = data->format.width_value - \
			data->format.nbl;
		if (data->format.specifier == 'u')
			return ;
		else if ((!ft_strchrr ("Xx", data->format.specifier)
				&& data->format.hash && data->format.tmp[0] != '0')
			|| data->format.specifier == 'p')
			data->format.n_zeros -= 2;
		else if (data->format.negative
			|| (!data->format.negative
				&& (data->format.plus || data->format.space)))
			data->format.n_zeros--;
	}
	if (data->format.n_zeros < 0)
		data->format.n_zeros = 0;
}

void	padding_spaces(t_data *data)
{
	data->format.n_spaces = data->format.width_value - \
								data->format.n_zeros - \
								data->format.nbl;
	if (!ft_strchrr("uxXp", data->format.specifier))
	{
		if ((!ft_strchrr("xX", data->format.specifier)
				&& data->format.hash
				&& data->format.tmp[0] != '0')
			|| data->format.specifier == 'p')
			data->format.n_spaces -= 2;
		return ;
	}
	if (data->format.negative)
	{
		data->format.n_spaces--;
		return ;
	}
	if (!data->format.negative && data->format.plus)
	{
		data->format.n_spaces--;
		return ;
	}
	if (!data->format.negative && data->format.space)
		data->format.n_spaces--;
}
