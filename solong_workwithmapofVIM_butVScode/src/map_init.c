/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:45:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/31 15:00:57 by tat-nguy         ###   ########.fr       */
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

static int	ft_count_lines(int fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

	count = 0;
	while ((n_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (i <= n_read)
		{
			if (buffer[i] == '\n' || buffer[i] == '\0')
				count++;
			i++;
		}
	}
	if (n_read < 0)
		return (0);
	return (count);
}

/*


char* buffer = "1111111 \n 1C11111 \n 1E11111 \n 1P110C1\n1111111";

char **buffer { [0] ->	[1111111]
			[1] ->	,[1C11111]
			[2] ->	,[1E11111]
			[3] ->	,[1P110C1]
			[4] ->	,[1111111]
			}
char [0]
char* buffer = "1111111 \n 1C11111 \n 1E11111 \n 1P110C1\n1111111";

*/


// int	ft_count_lines(int fd)
// {
// 	int count = 0;
// 	char *line;
	
// 	while (true)
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 			count++;
// 		else
// 			break;
// 	}
// 	return (count);
// }

static int	ft_get_lines(char *map)
{
	int	fd;
	int	lines;

	lines = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	lines = ft_count_lines(fd);
	if (close(fd) == -1)
		return (0);
	return (lines);
}

// read map from file, validate and set it in game
static int	ft_read_map(int fd, t_game *game)
{
	int		i;
	char	*buffer;

	game->map.matrix = ft_calloc(game->map.numoflines + 1, sizeof(char *));
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
	game->map.matrix[i] = NULL;
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
	game->map.numoflines = ft_get_lines(path);
	if (!game->map.numoflines || !ft_read_map(fd, game))
	{
		close(fd);
		ft_free_map(game);
		return (0);
	}
	close(fd);
	return (1);
}
