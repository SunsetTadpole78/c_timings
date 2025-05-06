/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:30:44 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/06 16:09:40 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static t_timings	*get_timings(void)
{
	static t_timings	*timings = NULL;

	if (!timings)
	{
		timings = malloc(sizeof(t_timings));
		if (!timings)
			return (NULL);
		timings->timings = NULL;
	}
	return (timings);
}

static t_timing	*init_timing(t_timing **timings, char *id)
{
	t_timing	*timing;

	timing = malloc(sizeof(t_timing));
	if (!timing)
		return (NULL);
	timing->id = ft_strdup(id);
	timing->total_time = 0l;
	timing->called = 0;
	if (*timings)
		timing->next = *timings;
	*timings = timing;
	return (timing);
}

static t_session	*create_session(t_timing **timings, char *id,
	t_timing *timing)
{
	t_session	*session;

	if (!timing)
	{
		timing = init_timing(timings, id);
		if (!timing)
			return (NULL);
	}
	session = malloc(sizeof(t_session));
	if (!session)
		return (NULL);
	session->started = ft_timestamp();
	session->timing = timing;
	session->next = timing->sessions;
	if (!session->next)
		session->id = 0;
	else
		session->id = session->next->id + 1;
	timing->sessions = session;
	return (session);
}

t_session	*start_timings(char *id)
{
	t_timings	*timings;
	t_timing	*cur;
	t_timing	*timing;

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
	}
	return (create_session(&timings->timings, id, timing));
}

void	stop_timings(char *id)
{
	(void)id;
}
