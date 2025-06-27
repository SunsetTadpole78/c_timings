/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:56:59 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/27 11:56:50 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putllnbr_fd(long long n, int fd)
{
	char	c[2];

	if (n == LLONG_MIN)
	{
		write(fd, "-9223372036854775808", 20);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putllnbr_fd((n / 10ll), fd);
	c[0] = (n % 10ll) + '0';
	c[1] = '\0';
	write(fd, c, 1);
}
