/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:25:28 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/11 12:24:18 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (*nptr < '0' || *nptr > '9')
		exit_error();
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		check_overflow(result, sign);
		nptr++;
	}
	if (*nptr != '\0')
		exit_error();
	return (sign * result);
}

static const char	*skip_whitespace(const char *nptr)
{
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	return (nptr);
}

static const char	*parse_sign(const char *nptr, int *sign)
{
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			*sign = -1;
		nptr++;
	}
	return (nptr);
}

int	ft_atoi_safe(const char *nptr, int *result)
{
	int		sign;
	long	temp_result;

	sign = 1;
	temp_result = 0;
	nptr = skip_whitespace(nptr);
	nptr = parse_sign(nptr, &sign);
	if (*nptr < '0' || *nptr > '9')
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		temp_result = temp_result * 10 + (*nptr - '0');
		if ((sign == 1 && temp_result > INT_MAX)
			|| (sign == -1 && - temp_result < INT_MIN))
			return (0);
		nptr++;
	}
	if (*nptr != '\0')
		return (0);
	*result = sign * temp_result;
	return (1);
}
