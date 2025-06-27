/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:30:44 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/27 15:13:29 by lroussel         ###   ########.fr       */
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
		pthread_mutex_init(&timings->mutex, NULL);
	}
	return (timings);
}

t_session	*start_timing(char *id)
{
	t_timings	*timings;
	t_timing	*cur;
	t_timing	*timing;
	t_session	*session;

	if (!is_timings_enabled())
		return (NULL);
	pthread_mutex_lock(&get_timings()->mutex);
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
	session = create_session(&timings->timings, id, timing);
	pthread_mutex_unlock(&get_timings()->mutex);
	return (session);
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
	pthread_mutex_lock(&get_timings()->mutex);
	timing = session->timing;
	prev = NULL;
	if (!check_sessions(session->id, timing->sessions, &prev))
	{
		free(session);
		pthread_mutex_unlock(&get_timings()->mutex);
		return ;
	}
	add_data(&timing->tdata, time - session->started, session->tid);
	if (prev)
		prev->next = session->next;
	else
		timing->sessions = session->next;
	free(session);
	pthread_mutex_unlock(&get_timings()->mutex);
}
