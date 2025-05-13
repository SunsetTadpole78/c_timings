/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:11:34 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/12 18:13:44 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static void	on_negative(char **result, int *v)
{
	(*result)[0] = '-';
	(*v) *= -1;
}

static char	*int_value(int v)
{
	int		size;
	char	*result;
	int		neg;

	size = 3;
	if (v != 0)
		size = ft_log(v, 10) + 2 + (v < 0);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	result[size--] = '0';
	result[size--] = '.';
	neg = v < 0;
	if (neg)
		on_negative(&result, &v);
	while (size >= neg)
	{
		result[size--] = (v % 10) + '0';
		v /= 10;
	}
	return (result);
}

static char	*init_values(float *v, int *size, int *dot_position)
{
	int		i;
	char	*result;

	if (*v == (int)(*v))
		return (int_value(*v));
	i = 0;
	while (*v != ((int)(*v)))
	{
		i++;
		(*v) *= 10;
	}
	*size = ft_log(*v, 10) + 1 + (*v < 0);
	*dot_position = (*size) - i - 1;
	result = malloc(sizeof(char) * ((*size) + 1));
	result[0] = '\0';
	return (result);
}

char	*ft_ftoa(float v)
{
	int		size;
	int		dot_position;
	int		nb;
	char	*result;

	result = init_values(&v, &size, &dot_position);
	if (!result)
		return (NULL);
	if (result[0])
		return (result);
	nb = (int)v;
	if (nb < 0)
		on_negative(&result, &nb);
	result[size--] = '\0';
	while (nb > 0)
	{
		if (size == dot_position)
			result[size--] = '.';
		else
		{
			result[size--] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (result);
}
