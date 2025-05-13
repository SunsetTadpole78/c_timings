/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:58:03 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 09:58:11 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_round(float v, int precision)
{
	int	temp;
	int	i;
	int	res;

	i = 0;
	while (i++ <= precision)
		v *= 10;
	res = (int)v % 10;
	if (res >= 5)
		v += 10;
	temp = (int)v - res;
	v = (float)temp;
	while (--i > 0)
		v /= 10;
	return (v);
}
