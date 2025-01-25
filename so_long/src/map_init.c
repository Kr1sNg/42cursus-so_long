/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:45:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:32 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// count lines of map to prepare for calloc
static int	ft_count_lines(int fd)
{
	int		count;
	char	buffer[BUFF_SZ];
	ssize_t	n_read;
	int		i;

	count = 0;
	while (1)
	{
		n_read = read(fd, buffer, BUFF_SZ);
		if (n_read < 0)
			return (0);
		if (n_read == 0)
			break ;
		i = 0;
		while (i < n_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	count++;
	return (count);
}

static bool	ft_map_extension(char *map)
{
	char	*ext;
	int		len;

	ext = ".ber";
	len = ft_strlen(map);
	if (len < 4)
		return (false);
	return (!ft_strcmp(&map[len - 4], ext));
}


// Open and Read <map>.ber file. Return 0 if can't open, 1 is good
int	ft_open_map(char *map, t_game *game)
{
	int	fd;

	if (!ft_map_extension(map))
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	game->map.numoflines = ft_count_lines(fd);
	// if (!game->map.numoflines || game->map.numoflines < 3)
	// {
	// 	close(fd);
	// 	ft_free_map(game);
	// 	return (0);
	// }
	if (!ft_read_map(fd, game))
	{
		close(fd);
		ft_free_map(game);
		return (0);
	}
	close(fd);
	return (1); //means OK
}

// read map from file, validate and set it in game
int	ft_read_map(int fd, t_game *game)
{
	int		i;
	char	*buffer;

	game->map.matrix = ft_calloc(game->map.numoflines + 1, sizeof(char *));
	if (!game->map.matrix)
		return (0);
	buffer = NULL;
	i = 0;
	while (i < game->map.numoflines)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game->map.matrix[i] = buffer;
		i++;
	}
	if (i < game->map.numoflines || !ft_map_dimensions(game) || !ft_valid_map(game))
	{
		ft_free_map(game);
		return (0);
	}
	return (1);
}

// int	ft_check_map(t_game *game)
// {
// 	if (game->map.matrix[0] == NULL || !ft_map_dimensions(game) || !ft_valid_map(game)) //TODO
// 	{
// 		ft_free_map(game);
// 		return (0);
// 	}
// 	return (1);
// }
