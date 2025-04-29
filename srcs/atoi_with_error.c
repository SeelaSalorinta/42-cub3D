#include "../includes/cub3d.h"

static int	error_found(int *error)
{
	*error = 1;
	return (1);
}

static int	skip_whitespace(char *str)
{
	int	i = 0;
	while ((str[i] && (str[i] >= 9 && str[i] <= 13))
		|| str[i] == 32)
		i++;
	return (i);
}

static int	check_overflow(long nbr, int digit, int sign)
{
	if (sign == 1 && nbr > (INT_MAX - digit) / 10)
		return (1);
	if (sign == -1 && -nbr < (INT_MIN + digit) / 10)
		return (1);
	return (0);
}

static long	build_number(char *str, int *i, int sign, int *error)
{
	long	nbr;
	int		has_digit;
	int		digit;

	nbr = 0;
	has_digit = 0;
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		has_digit = 1;
		digit = str[*i] - '0';
		if (check_overflow(nbr, digit, sign))
			return (error_found(error));
		nbr = nbr * 10 + digit;
		(*i)++;
	}
	if (!has_digit)
		return (error_found(error));
	return (nbr);
}

int	atoi_with_error(char *str, int *error)
{
	int		i;
	long	nbr;
	int		sign;

	sign = 1;
	i = skip_whitespace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr = build_number(str, &i, sign, error);
	if (*error)
		return (error_found(error));
	return (sign * nbr);
}
