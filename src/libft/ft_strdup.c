/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:01:03 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 10:19:19 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
