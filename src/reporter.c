/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:27 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/12 20:36:20 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static void	write_timing_data(t_timing *timing, long long time, int fd)
{
	char	*formated;

	write(fd, timing->id, ft_strlen(timing->id));
	write(fd, "\t", 1);
	formated = ft_ftoa(ft_round((float)timing->total_time * 100.0f
				/ (float)time, 2));
	fix_time(&formated);
	write(fd, formated, ft_strlen(formated));
	free(formated);
	write(fd, "\t", 1);
	formated = execution_time(timing->total_time / timing->called);
	write(fd, formated, ft_strlen(formated));
	free(formated);
	write(fd, "\t", 1);
	ft_putnbr_fd(timing->called, fd);
	write(fd, "\n", 1);
}

static void	write_sample_time(long long time, int fd)
{
	char		*formated;

	formated = execution_time(time);
	write(fd, formated, ft_strlen(formated));
	free(formated);
	write(fd, "\n", 1);
}

void	report_timings(char *filename)
{
	t_timings	*timings;
	long long	time;
	t_timing	*cur;
	int			fd;
	t_timing	*tmp;

	if (!is_timings_enabled())
		return ;
	(void)filename;
	fd = 0;
	timings = get_timings();
	time = ft_timestamp_us() - timings->started;
	write_sample_time(time, fd);
	cur = timings->timings;
	while (cur)
	{
		while (cur->sessions)
			stop_timing(cur->sessions);
		write_timing_data(cur, time, fd);
		tmp = cur;
		cur = cur->next;
		free(tmp->id);
		free(tmp);
	}
	free(timings);
}
