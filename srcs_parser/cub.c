/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:18:00 by abibi             #+#    #+#             */
/*   Updated: 2020/09/26 16:20:12 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		parse_line(char **line, t_game *el)
{
	if (id_num(line) == 1)
		return (get_res(el, *line));
	if (id_num(line) > 1 && id_num(line) < 7)
		return (get_tex(el, *line, id_num(line)));
	if (id_num(line) > 6 && id_num(line) < 9)
		return (get_color(el, *line, id_num(line)));
	return (id_num(line));
}

int		parse_inp(int fd, t_game *el)
{
	char	*buf;
	char	*rem;
	int		i;
	int		gnl_r;

	i = 9;
	while (i > 0 && (gnl_r = get_next_line(fd, &buf, 0)) > 0)
	{
		rem = buf;
		i = parse_line(&buf, el);
		free(rem);
		if (check_fields(*el) == 1)
			break ;
	}
	if (gnl_r == 0)
		free(buf);
	if (gnl_r == 1 && check_fields(*el) == 0)
		get_next_line(0, NULL, 1);
	if (gnl_r == 0 || check_fields(*el) == 0 || gnl_r == -1)
		free_tex_paths(el);
	if (i < 0)
		return (i);
	if (gnl_r == -1)
		return (-7);
	return (1);
}

int		validate_mapname(char *f_path)
{
	char *dot;

	if (!f_path)
		return (0);
	if (*f_path == '.')
		return (0);
	dot = ft_strchr(f_path, '.');
	if (dot == NULL)
		return (0);
	if (ft_strncmp(dot, ".cub", 4) != 0)
		return (0);
	return (1);
}

int		parse_input(char *f_path, t_game *el)
{
	int		fd;
	int		error;

	tgame_init(el);
	if (!validate_mapname(f_path))
		return (-1);
	fd = open(f_path, O_RDONLY | O_RDWR);
	if (fd < 0)
		return (-100);
	if ((error = parse_inp(fd, el)) != 1)
	{
		close(fd);
		return (error);
	}
	if (!check_fields(*el))
	{
		close(fd);
		return (-9);
	}
	return (get_map(el, fd));
}
