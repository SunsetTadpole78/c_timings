/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp_us.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:58:46 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 10:17:22 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>

long long	ft_timestamp_us(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((long long)t.tv_sec * 1000000LL + t.tv_usec);
}
