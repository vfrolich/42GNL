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

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	dst = ft_strcpy(dst, s1);
	free(s1);
	ft_putendl("FLAAAAAAAAAG");
	dst = ft_strcat(dst , s2);	
	free(s2);
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
			mstr->str = ft_strchr(mstr->str, '\n') + 1;
		return (1);
	}
	if (!ret)
	{
		ft_str_cut(tmp, line);
		mstr->flag = 0;
		free(tmp);
		return (1);
	}
	else
	{
		free(tmp);
		return (0);
	}
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
	}
	while (ret && mstr.flag)
	{
		mstr.buff = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, mstr.buff, BUFF_SIZE)) < 0)
			return (-1);
		mstr.buff[ret] = '\0';
		mstr.str = ft_strjoin_free(mstr.str, mstr.buff);
		if (!ft_strlen(mstr.str))
		{
			free(mstr.str);
			return (0);
		}
		if (return_line(line, &mstr, ret))
			return (1);
	}
	free(mstr.str);
	return (0);
}
