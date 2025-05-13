/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:45:16 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 10:51:48 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*res;
	size_t	i;

	slen = ft_strlen(s);
	if (start >= slen || len == 0)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_pathjoin(char const *path1, char const *path2)
{
	char	*result;
	int		have_slash1;
	int		have_slash2;
	int		len;
	char	*temp;

	len = ft_strlen(path1);
	have_slash1 = path1[len - 1] == '/';
	have_slash2 = path2[0] == '/';
	if (have_slash1 && have_slash2)
		temp = ft_substr(path1, 0, len - 1);
	else if (have_slash1 || have_slash2)
		return (ft_strjoin(path1, path2));
	else
		temp = ft_strjoin(path1, "/");
	result = ft_strjoin(temp, path2);
	free(temp);
	return (result);
}
