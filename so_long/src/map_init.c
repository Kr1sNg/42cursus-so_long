/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:45:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/09/11 10:12:04 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	ft_map_extension(char *path)
{
	char	*ext;
	int		len;

	ext = ".ber";
	len = ft_strlen(path);
	if (len < 4)
		return (false);
	return (!ft_strcmp(&path[len - 4], ext));
}

// read map from file, validate and set it in game
static int	ft_read_map(int fd, t_game *game)
{
	int		i;
	char	*buffer;

	game->map.matrix = ft_calloc(MAX_LINES, sizeof(char *));
	if (!game->map.matrix)
	{
		ft_free_map(game);
		return (ft_error_map(24), 0);
	}
	buffer = NULL;
	i = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game->map.matrix[i] = buffer;
		i++;
	}
	game->map.numoflines = i;
	if (!ft_map_dimensions(game) || !ft_valid_map(game))
		return (ft_free_map(game), 0);
	return (1);
}

// Open and Read <map>.ber file. Return 0 if can't read!
int	ft_open_map(char *path, t_game *game)
{
	int		fd;

	if (!ft_map_extension(path))
		ft_error_map(23);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_map(22);
	if (!ft_read_map(fd, game) || !game->map.numoflines)
	{
		close(fd);
		ft_free_map(game);
		return (0);
	}
	close(fd);
	return (1);
}
