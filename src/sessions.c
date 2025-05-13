/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sessions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:53:10 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 09:55:10 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static t_timing	*init_timing(t_timing **timings, char *id)
{
	t_timing	*timing;

	timing = malloc(sizeof(t_timing));
	if (!timing)
		return (NULL);
	timing->id = ft_strdup(id);
	timing->total_time = 0l;
	timing->called = 0;
	timing->sessions = NULL;
	timing->next = *timings;
	*timings = timing;
	return (timing);
}

t_session	*create_session(t_timing **timings, char *id, t_timing *timing)
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
	session->timing = timing;
	session->next = timing->sessions;
	if (!session->next)
		session->id = 0;
	else
		session->id = session->next->id + 1;
	timing->sessions = session;
	session->started = ft_timestamp_us();
	return (session);
}
