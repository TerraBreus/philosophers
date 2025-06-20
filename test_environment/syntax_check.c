#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define USAGE " \
Usage: ./philo n time2die time2eat time2sleep [max_iter] \n \
Where\n \
n: the amount of philosophers at the table (max of 200)\n \
time2die: the maximum time (in ms) a philosopher can not eat before dying\n \
time2eat: the maximum time (in ms) a philosopher will eat for\n \
time2sleep: the maximum (in ms) time a philosopher will sleep for\n \
[max_iter]: OPTIONAL! Program will stop when all philosophers \
have at least eaten [max_iter] times (or a philosopher has died)\n"

#define NONNUMERICAL " \
NB: Nonnumerical character found. Use only numbers (no +/- signs)\n"

#define TOOMANYPHILO " \
A maximum of 200 philosophers is allowed\n"

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

void	ft_usage(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	write(2, str, length);
	exit(EXIT_FAILURE);
}

void	syntax_check(int argc, char *argv[])
{
	int	i;
	int	j;

	if (!(argc == 5 || argc == 6))
		ft_usage(USAGE);
	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				ft_usage(NONNUMERICAL);
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		ft_usage(TOOMANYPHILO);
}

int	main(int argc, char *argv[])
{
	syntax_check(argc, argv);
}
