#include "philo.h"

static size_t	ft_get_length(const char *input)
{
	size_t	length;

	length = 0;
	if (*input >= '0' && *input <= '9')
	{
		length = 1;
		input++;
	}
	while (*input >= '0' && *input <= '9')
	{
		input++;
		length *= 10;
	}
	return (length);
}

static int	ft_calc_int(const char *str, size_t length, int conv_int)
{
	while (length)
	{
		conv_int += (*str - '0') * length;
		length /= 10;
		str++;
	}
	return (conv_int);
}

int	ft_atoi(const char *nptr)
{
	int			conv_int;
	int			is_minus;

	is_minus = 1;
	conv_int = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_minus *= -1;
		nptr++;
	}
	while (*nptr == '0')
		nptr++;
	conv_int = ft_calc_int(nptr, ft_get_length(nptr), conv_int);
	conv_int *= is_minus;
	return (conv_int);
}
