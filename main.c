/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:25:56 by vfrolich          #+#    #+#             */
/*   Updated: 2017/01/30 20:29:43 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char 	*line;
	int		ret;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while((ret = get_next_line(fd, &line)))
		ft_putstr(line);
	return (0);
}