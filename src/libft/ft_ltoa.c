/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:41:26 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 10:59:00 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"
#include <limits.h>

char	*ft_ltoa(long n)
{
	unsigned int	size;
	char			*res;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	size = ft_llog(n, 10);
	if (n < 0)
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[size--] = '\0';
	while (n > 9)
	{
		res[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	res[size] = n + '0';
	return (res);
}
