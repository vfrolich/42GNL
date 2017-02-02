/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:55:30 by vfrolich          #+#    #+#             */
/*   Updated: 2017/01/30 20:14:28 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_str_cut(char *str, char **line)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
	{
		str[i + 1] = '\0';
		*line = str;
		return ;
	}
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			*line = str;
			return ;
		}
		i++;
	}
	*line = str;
}

char	*ft_strjoin_free(t_mstr mstr)
{
	char	*dst;

	if (!mstr.str || !mstr.buff)
		return (NULL);
	dst = ft_strnew(ft_strlen(mstr.str) + ft_strlen(mstr.buff));
	if (!dst)
		return (NULL);
	dst = ft_strcpy(dst, mstr.str);
	free(mstr.str - mstr.diff);
	dst = ft_strcat(dst , mstr.buff);	
	free(mstr.buff);
	return (dst);
}

int		return_line(char **line, t_mstr *mstr, int ret)
{
	char *tmp;

	if (!(tmp = ft_strdup(mstr->str)))
		return (-1);
	if (ft_strchr(tmp, '\n'))
	{
		ft_str_cut(tmp, line);
		free(tmp);
		if ((ft_strchr(mstr->str, '\n') + 1))
		{
			mstr->diff = (ft_strchr(mstr->str, '\n') + 1) - mstr->str;
			mstr->str = ft_strchr(mstr->str, '\n') + 1;
		}
		return (1);
	}
	if (!ret)
	{
		ft_str_cut(tmp, line);
		mstr->flag = 0;
		free(tmp);
		return (1);
	}
	mstr->diff = 0;
	free(tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	t_mstr	mstr;
	int 			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	ret = 1;
	if (!mstr.str)
	{
		mstr.str = ft_strnew(0);
		mstr.flag = 1;
		mstr.diff = 0;
	}
	while (ret && mstr.flag)
	{
		mstr.buff = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, mstr.buff, BUFF_SIZE)) < 0)
			return (-1);
		mstr.buff[ret] = '\0';
		mstr.str = ft_strjoin_free(mstr);
		if (!ft_strlen(mstr.str))
			return (0);
		if (return_line(line, &mstr, ret))
			return (1);
	}
	return (0);
}
