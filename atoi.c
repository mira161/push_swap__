/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:25:28 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/01 10:36:13 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_overflow(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX)
		|| (sign == -1 && - result < INT_MIN))
		exit_error();
}

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
