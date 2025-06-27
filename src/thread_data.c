/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:13:40 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/27 15:15:32 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static t_timing_thread_data	*new_thread_data(long int tid, long long total_time)
{
	t_timing_thread_data	*data;

	data = malloc(sizeof(t_timing_thread_data));
	data->tid = tid;
	data->called = 1;
	data->total_time = total_time;
	return (data);
}

void	add_data(t_timing_thread_data **data, long long time, long int tid)
{
	t_timing_thread_data	*cur;
	t_timing_thread_data	*used;

	cur = *data;
	used = NULL;
	while (cur)
	{
		if (cur->tid == tid)
		{
			used = cur;
			break ;
		}
		cur = cur->next;
	}
	if (!used)
	{
		used = new_thread_data(tid, time);
		used->next = *data;
		*data = used;
		return ;
	}
	used->total_time += time;
	used->called++;
}
