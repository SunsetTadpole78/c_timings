/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_timings.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:31:04 by lroussel          #+#    #+#             */
/*   Updated: 2025/06/27 15:14:28 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TIMINGS_H
# define C_TIMINGS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct s_timing_thread_data
{
	long int					tid;
	long long					total_time;
	long long					called;
	struct s_timing_thread_data	*next;
}	t_timing_thread_data;

typedef struct s_session
{
	int					id;
	long int			tid;
	long long			started;
	struct s_timing		*timing;
	struct s_session	*next;
}	t_session;

typedef struct s_timing
{
	char					*id;
	t_timing_thread_data	*tdata;
	t_session				*sessions;
	struct s_timing			*next;
}	t_timing;

typedef struct s_timings
{
	long long		started;
	t_timing		*timings;
	pthread_mutex_t	mutex;
}	t_timings;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long long	ft_timestamp(void);
long long	ft_timestamp_us(void);
size_t		ft_log(int nb, int base);
size_t		ft_llog(long nb, int base);
float		ft_round(float v, int precision);
char		*ft_ftoa(float v);
char		*ft_ltoa(long v);
char		*ft_strjoin(const char *s1, const char *s2);
void		ft_putnbr_fd(int n, int fd);
void		ft_putllnbr_fd(long long n, int fd);
char		*ft_pathjoin(char const *path1, char const *path2);

void		enable_timings(void);
int			is_timings_enabled(void);

t_session	*start_timing(char *id);
void		stop_timing(t_session *session);

t_timings	*get_timings(void);

void		report_timings(char *dir_path);

void		fix_time(char **time);
char		*execution_time(long long value);

t_session	*create_session(t_timing **timings, char *id, t_timing *timing);

void		add_data(t_timing_thread_data **data, long long time, long int tid);

#endif
