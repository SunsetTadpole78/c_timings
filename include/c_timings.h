/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_timings.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:31:04 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/13 10:00:22 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TIMINGS_H
# define C_TIMINGS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define TIMINGS_HEADER \
	"=============================== Timings ===============================\n"
# define TIMINGS_FOOTER \
	"================================================================~Sunset\n"

typedef struct s_session
{
	int					id;
	long long			started;
	struct s_timing		*timing;
	struct s_session	*next;
}	t_session;

typedef struct s_timing
{
	char			*id;
	long long		total_time;
	int				called;
	t_session		*sessions;
	struct s_timing	*next;
}	t_timing;

typedef struct s_timings
{
	long long	started;
	t_timing	*timings;
}	t_timings;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long long	ft_timestamp_us(void);
size_t		ft_log(int nb, int base);
float		ft_round(float v, int precision);
char		*ft_ftoa(float v);
char		*ft_strjoin(const char *s1, const char *s2);
void		ft_putnbr_fd(int n, int fd);

void		enable_timings(void);
int			is_timings_enabled(void);

t_session	*start_timing(char *id);
void		stop_timing(t_session *session);

t_timings	*get_timings(void);

void		report_timings(char *filename);

void		fix_time(char **time);
char		*execution_time(long long value);

t_session	*create_session(t_timing **timings, char *id, t_timing *timing);

#endif
