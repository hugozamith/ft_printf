/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:02:40 by hteixeir          #+#    #+#             */
/*   Updated: 2024/05/14 14:38:35 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_spaces(t_data *data, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (data->format.percision_value == 0)
	{
		data->format.n_spaces = data->format.width_value;
		return ;
	}
	if (s == NULL)
		len = 0;
	else
		len = ft_strlen(s);
	if (data->format.width_value > 0)
	{
		if (data->format.percision_value >= 0
			&& data->format.percision_value < len)
			len = data->format.percision_value;
		data->format.n_spaces = data->format.width_value - len;
	}
}

void	print_str(t_data *data, char *s)
{
	int	str_len;

	if (((data->format.percision_value >= 6)
			|| data->format.percision_value == -1)
		&& NULL == s)
		s = "(null)";
	else if (NULL == s)
		s = "";
	str_len = ft_strlen(s);
	if (data->format.percision_value >= 0
		&& data->format.percision_value < str_len)
		str_len = data->format.percision_value;
	put_spaces(data, s);
	if (data->format.left)
	{
		putstr_n(s, str_len, data);
		putchar_n(' ', data->format.n_spaces, data);
	}
	else
	{
		putchar_n(' ', data->format.n_spaces, data);
		putstr_n(s, str_len, data);
	}
}
