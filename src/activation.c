/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:47:35 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/12 20:47:55 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static int	enabled(int v, int replace)
{
	static int	timings_enabled = 0;

	if (replace)
		timings_enabled = v;
	return (timings_enabled);
}

void	enable_timings(void)
{
	enabled(1, 1);
	get_timings();
}

int	is_timings_enabled(void)
{
	return (enabled(0, 0));
}
