/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:59:05 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 11:07:01 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_llog(long nb, int base)
{
	if (nb < 0)
		nb = -nb;
	if (nb < base)
		return (1);
	return (1 + ft_llog(nb / base, base));
}
