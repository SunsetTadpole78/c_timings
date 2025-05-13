/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:30:44 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 09:54:00 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

t_timings	*get_timings(void)
{
	static t_timings	*timings = NULL;

	if (!timings)
	{
		timings = malloc(sizeof(t_timings));
		if (!timings)
			return (NULL);
		timings->timings = NULL;
		timings->started = ft_timestamp_us();
	}
	return (timings);
}

t_session	*start_timing(char *id)
{
	t_timings	*timings;
	t_timing	*cur;
	t_timing	*timing;

	if (!is_timings_enabled())
		return (NULL);
	timings = get_timings();
	cur = timings->timings;
	timing = NULL;
	while (cur)
	{
		if (ft_strncmp(id, cur->id, ft_strlen(id) + 1) == 0)
		{
			timing = cur;
			break ;
		}
		cur = cur->next;
	}
	return (create_session(&timings->timings, id, timing));
}

static int	check_sessions(int id, t_session *cur, t_session **prev)
{
	while (cur)
	{
		if (cur->id == id)
			break ;
		*prev = cur;
		cur = cur->next;
	}
	return (cur != NULL);
}

void	stop_timing(t_session *session)
{
	t_timing	*timing;
	t_session	*prev;
	long long	time;

	time = ft_timestamp_us();
	if (session == NULL)
		return ;
	timing = session->timing;
	prev = NULL;
	if (!check_sessions(session->id, timing->sessions, &prev))
	{
		free(session);
		return ;
	}
	timing->called++;
	timing->total_time += time - session->started;
	free(session);
	if (prev)
		prev->next = prev->next->next;
	else
		timing->sessions = NULL;
}
