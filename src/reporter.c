/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reporter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:10:27 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/27 13:31:14 by lroussel         ###   ########.fr       */
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
	name = ft_strjoin(value, ".ctmg");
	path = ft_pathjoin(dir_path, name);
	free(name);
	fd = open(path, O_CREAT | O_WRONLY, 0644);
	free(path);
	return (fd);
}

static void	write_threads_data(t_timing_thread_data *data, int fd)
{
	while (data)
	{
		ft_putllnbr_fd(data->tid, fd);
		write(fd, ";", 1);
		ft_putllnbr_fd(data->total_time, fd);
		write(fd, ";", 1);
		ft_putllnbr_fd(data->called, fd);
		write(fd, "\n", 1);
		data = data->next;
	}
}

static void	write_timing_data(t_timing *timing, int fd)
{
	t_timing_thread_data	*cur;
	long long				time;
	long long				called;
	int						i;

	cur = timing->tdata;
	time = 0;
	called = 0;
	i = 0;
	while (cur)
	{
		time += cur->total_time;
		called += cur->called;
		cur = cur->next;
		i++;
	}
	time /= i;
	ft_putllnbr_fd(time, fd);
	write(fd, ",", 1);
	ft_putllnbr_fd(called, fd);
	write(fd, ",", 1);
	ft_putllnbr_fd(called / i, fd);
	write(fd, "\n", 1);
	if (i != 1 && i == 1)
		write_threads_data(timing->tdata, fd);
}

static void	write_timings(t_timing *cur, long long time, int fd)
{
	t_timing				*tmp;
	t_timing_thread_data	*tmp_data;

	ft_putnbr_fd(time, fd);
	write(fd, "\n", 1);
	while (cur)
	{
		while (cur->sessions)
			stop_timing(cur->sessions);
		write(fd, cur->id, ft_strlen(cur->id));
		write(fd, ",", 1);
		write_timing_data(cur, fd);
		while (cur->tdata)
		{
			tmp_data = cur->tdata;
			cur->tdata = cur->tdata->next;
			free(tmp_data);
		}
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
