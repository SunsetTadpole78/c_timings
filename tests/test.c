/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:02:06 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/27 11:57:51 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NUM_THREADS 5

#include "c_timings.h"

typedef struct s_thread_args
{
	int	thread_id;
}	t_thread_args;

void* thread_function(void* arg)
{
	t_thread_args	*args;
	t_session	*session;

	args = (t_thread_args*)arg;
	session = start_timing("thread");
	usleep(1000 * args->thread_id);
	stop_timing(session);

	return NULL;
}

int main(void)
{
	t_session	*session;
	pthread_t	threads[NUM_THREADS];
	t_thread_args	thread_args[NUM_THREADS];

	enable_timings();
	usleep(50000);
	session = start_timing("a");
	usleep(50000);
	stop_timing(session);
	usleep(10000);
	session = start_timing("b");
	usleep(20000);
	stop_timing(session);
	for (int i = 0; i < NUM_THREADS; i++)
	{
		thread_args[i].thread_id = i + 1;
		pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
	}
	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
	report_timings(NULL);
	return (0);
}

