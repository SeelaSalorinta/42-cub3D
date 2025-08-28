/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_positive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalorin <ssalorin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:32:35 by ssalorin          #+#    #+#             */
/*   Updated: 2025/08/28 12:33:34 by ssalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	error_found(int *error)
{
	*error = 1;
	return (1);
}

static int	skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] && (str[i] >= 9 && str[i] <= 13))
		|| str[i] == 32)
		i++;
	return (i);
}

static long	process_digits(char *str, int *i, int *has_digit, int *error)
{
	long	nbr;

	nbr = 0;
	while (str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		*has_digit = 1;
		nbr = nbr * 10 + (str[*i] - '0');
		if (nbr > INT_MAX)
			return (error_found(error));
		(*i)++;
	}
	return (nbr);
}

int	atoi_positive(char *str, int *error)
{
	int		i;
	int		has_digit;
	long	nbr;
	int		sign;

	has_digit = 0;
	nbr = 0;
	sign = 1;
	if (!str || str[0] == '\0')
	{
		*error = 1;
		return (0);
	}
	i = skip_whitespace(str);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			return (error_found(error));
		i++;
	}
	nbr = process_digits(str, &i, &has_digit, error);
	if (!has_digit || *error)
		return (error_found(error));
	return (sign * nbr);
}
