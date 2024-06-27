/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:20:58 by hteixeir          #+#    #+#             */
/*   Updated: 2024/06/25 16:44:35 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUF_SIZE 4096
# define FLAGS "+ 0-#"
# define NUMBERS "1234567890"
# define SPECIFIERS "cspdiuxX%"
# define UPSYMBOLS "0123456789ABCDEF"
# define SYMBOLS "0123456789abcdef"

typedef enum e_ret
{
	OK = 0,
	MALLOC_ERROR = -9,
	READ_ERROR = -12,
}	t_ret;

typedef enum e_bases
{
	DEC = 10,
	HEX = 16,
}	t_bases;

typedef union u_onion
{
	unsigned long	unint;
	long			nint;
}	t_onion;

typedef struct s_format
{
	int		left;
	int		plus;
	int		space;
	int		hash;
	int		zero_pad;
	int		uppercase;
	char	specifier;
	char	tmp[64];
	int		nbl;
	int		width_value;
	int		percision_value;
	int		n_spaces;
	int		n_zeros;
	t_bases	base;

	int		is_coverted;
	int		is_signed;
	int		negative;
}	t_format;

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int			nwr_char;
	char		*buff;
	int			buff_index;
	int			nciclo;
	t_format	format;
}	t_data;

void	ft_memiset(void *b, int c, size_t len);

int		ft_strchrr(const char *str, int c);
int		ft_printf(const char *frmt, ...);
int		read_format(t_data *data);

void	write_char(t_data *data, char c);
void	write_everything(t_data *data);
void	print_char(t_data *data, char c);
void	putchar_n(char c, int n, t_data *data);
void	putstr_n(char *str, int precision, t_data *data);
void	print_str(t_data *data, char *s);
void	print_int(t_data *data, t_onion int_values);
void	itoa_base(t_data *data, t_onion int_values);
void	padding_spaces(t_data *data);
void	padding_zeros(t_data *data);

size_t	ft_strlen(const char *str);

#endif

/*# define RST "\033[0m"
# define O   "\033[1;33m"  // BOLD Yellow
# define R   "\033[1;31m"  // BOLD Red
# define G   "\033[1;32m"  // BOLD Green
# define Y   "\033[1;33m"  // BOLD Yellow
# define B   "\033[1;34m"  // BOLD Blue
# define M   "\033[1;35m"  // BOLD Magenta
*/