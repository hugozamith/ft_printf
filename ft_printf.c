/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:16:32 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 12:37:03 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_format(t_data *data)
{
	t_onion	int_values;

	int_values.nint = 0;
	if ('%' == data->format.specifier)
		print_char(data, '%');
	else if ('c' == data->format.specifier)
		print_char(data, va_arg(data->ap, int));
	else if ('s' == data->format.specifier)
		print_str(data, va_arg(data->ap, char *));
	if (!ft_strchrr("dipxXu", data->format.specifier))
	{
		if (!ft_strchrr("di", data->format.specifier))
		{
			int_values.nint = (long)va_arg(data->ap, int);
			data->format.is_signed = 1;
			if (int_values.nint < 0)
				data->format.negative = 1;
		}
		else if ('p' == data->format.specifier)
			int_values.unint = (unsigned long)va_arg(data->ap, void *);
		else if (!ft_strchrr("xXu", data->format.specifier))
			int_values.unint = (unsigned long)va_arg(data->ap, unsigned int);
		print_int(data, int_values);
	}
}

static int	init_data(t_data *data, const char *frmt)
{
	data->nwr_char = 0;
	data->s = frmt;
	data->buff = malloc(BUF_SIZE * sizeof(char));
	if (data->buff == NULL)
		return (MALLOC_ERROR);
	data->buff_index = 0;
	ft_memiset(data->buff, 0, BUF_SIZE * sizeof(char));
	return (OK);
}

static int	malloc_err(t_data data)
{
	free(data.buff);
	return (MALLOC_ERROR);
}

static int	read_err(t_data data)
{
	free(data.buff);
	return (READ_ERROR);
}

int	ft_printf(const char *frmt, ...)
{
	t_data	data;

	va_start(data.ap, frmt);
	if (init_data(&data, frmt))
		return (malloc_err (data));
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (read_format (&data))
				return (read_err (data));
			write_format(&data);
		}
		else
			write_char(&data, *data.s);
		data.s++;
	}
	write_everything(&data);
	va_end(data.ap);
	free(data.buff);
	return (data.nwr_char);
}
