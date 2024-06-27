/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:03:35 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 12:31:45 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	mini_atoi(t_data *data)
{
	int	value;

	value = 0;
	if ((ft_strchrr(NUMBERS, *data->s))
		&& *(data->s - 1) == '.')
		return (0);
	while (!ft_strchrr(NUMBERS, *data->s))
		value = (value * 10) + (*data->s++ - '0');
	return (value);
}

static void	read_flags(t_data *data)
{
	char	flag;

	while (!ft_strchrr(FLAGS, *data->s))
	{
		flag = *data->s;
		if ('0' == flag)
			data->format.zero_pad = 1;
		else if ('+' == flag)
			data->format.plus = 1;
		else if (' ' == flag)
			data->format.space = 1;
		else if ('#' == flag)
			data->format.hash = 1;
		else if ('-' == flag)
			data->format.left = 1;
		++data->s;
	}
}

static void	get_value(t_data *data, int *value, int iswidth)
{
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		if (*value <= 0)
		{
			if (iswidth && (*value < 0))
			{
				data->format.left = 1;
				*value *= -1;
			}
			if (!(iswidth) && *(data->s + 1) == 'd' && (*value < 0))
				*value = -1;
		}
		++data->s;
		return ;
	}
	*value = mini_atoi(data);
}

int	read_format(t_data *data)
{
	ft_memiset(&data->format, 0, sizeof(t_format));
	data->format.percision_value = -1;
	read_flags(data);
	get_value(data, &data->format.width_value, 1);
	if (*data->s == '.' && *(data->s++))
		get_value(data, &data->format.percision_value, 0);
	if (ft_strchrr(SPECIFIERS, *data->s))
		return (READ_ERROR);
	else
	{
		data->format.specifier = *data->s;
		if (!ft_strchrr("diu", data->format.specifier))
			data->format.base = DEC;
		else if (!ft_strchrr("xXp", data->format.specifier))
		{
			data->format.base = HEX;
			if ('X' == data->format.specifier)
				data->format.uppercase = 1;
		}
	}
	return (OK);
}
