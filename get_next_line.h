/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:07:15 by vfrolich          #+#    #+#             */
/*   Updated: 2017/01/30 19:11:45 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct			s_mstr
{
		char 			*str;
		char			*buff;
		int				flag;
		int				diff;
}						t_mstr;

int				get_next_line(const int fd, char **line);

#endif
