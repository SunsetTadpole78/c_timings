/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:35:47 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/12 20:45:42 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

void	fix_time(char **time)
{
	int	i;
	int	j;

	i = 0;
	while ((*time)[i] && (*time)[i] != '.')
		i++;
	if ((*time)[i] != '.')
		return ;
	j = 1;
	while ((*time)[i + j] && j != 3)
		j++;
	if ((*time)[i + j])
		(*time)[i + j] = '\0';
}

static char	*apply_time(double *res, double diviser, char *unit)
{
	(*res) /= diviser;
	return (unit);
}

char	*execution_time(long long value)
{
	double	res;
	char	*temp;
	char	*str;
	char	*unit;

	res = (double)value;
	if (res > 86400000000.0)
		unit = apply_time(&res, 86400000000.0, "d");
	if (res > 3600000000.0)
		unit = apply_time(&res, 3600000000.0, "h");
	else if (res > 60000000.0)
		unit = apply_time(&res, 60000000.0, "m");
	else if (res > 1000000.0)
		unit = apply_time(&res, 1000000.0, "s");
	else if (res > 1000.0)
		unit = apply_time(&res, 1000.0, "ms");
	else
		unit = "μs";
	temp = ft_ftoa(ft_round(res, 2));
	fix_time(&temp);
	str = ft_strjoin(temp, unit);
	free(temp);
	return (str);
}
