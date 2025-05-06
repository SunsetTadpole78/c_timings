/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_timings.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:31:04 by lroussel          #+#    #+#             */
/*   Updated: 2025/05/06 16:10:30 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TIMINGS_H
# define C_TIMINGS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_session
{
	int					id;
	long				started;
	struct s_timing		*timing;
	struct s_session	*next;
}	t_session;

typedef struct s_timing
{
	char			*id;
	long			total_time;
	int				called;
	t_session		*sessions;
	struct s_timing	*next;
}	t_timing;

typedef struct s_timings
{
	long		started;
	t_timing	*timings;
}	t_timings;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_timestamp(void);

#endif
