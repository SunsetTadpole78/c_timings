/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:27 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/25 13:23:25 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_timings.h"

static int	create_log_file(char *dir_path)
{
	char	*value;
	char	*name;
	char	*path;
	int		fd;

	value = ft_ltoa(ft_timestamp());
	name = ft_strjoin("timing-", value);
	path = ft_pathjoin(dir_path, name);
	free(name);
	fd = open(path, O_CREAT | O_WRONLY, 0644);
	free(path);
	return (fd);
}

static void	write_timing_data(t_timing *timing, int fd)
{
	write(fd, timing->id, ft_strlen(timing->id));
	write(fd, "\t", 1);
	ft_putnbr_fd(timing->total_time, 1);
	write(fd, "\t", 1);
	ft_putnbr_fd(timing->called, 1);
	write(fd, "\n", 1);
}

static void	write_timings(t_timing *cur, long long time, int fd)
{
	t_timing	*tmp;

	ft_putnbr_fd(time, 1);
	write(1, "\n", 1);
	while (cur)
	{
		while (cur->sessions)
			stop_timing(cur->sessions);
		write_timing_data(cur, fd);
		tmp = cur;
		cur = cur->next;
		free(tmp->id);
		free(tmp);
	}
}

void	report_timings(char *dir_path)
{
	t_timings	*timings;
	int			fd;

	if (!is_timings_enabled())
		return ;
	fd = 0;
	if (dir_path)
		fd = create_log_file(dir_path);
	timings = get_timings();
	write_timings(timings->timings, ft_timestamp_us() - timings->started, fd);
	free(timings);
	if (fd > 0)
		close(fd);
}
