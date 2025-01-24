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

bool	ft_map_valid(t_data **game)
{
	ft_init_count(game);
	if (!init_sum_count(game))
		return (false);
	if ((*game)->count.exit != 1 || (*game)->count.player != 1 || (*game)->count.coin < 1)
		return (false);
	if (!check_border_walls(game))
		return (false);
	if (!check_rectangular(game))
		return (false);
	if (!valid_path(game))
		return (false);
	return (true);
}

int	ft_open_fd(t_data **game, char **argv)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (free(*game), 0);
	ft_init_data(game);
	(*game)->map = (char **)malloc(sizeof(char *) * (HEIGHT + 1));
	if (!(*game)->map)
		close (fd);
	i = 0;
	while (1)
	{
		(*game)->map[i] = get_next_line(fd);
		if (!(*game)->map[i])
			break;
		i++;
	}
	close(fd);
	if (i == 0 || !ft_map_valid)
		return (ft_free_map((*game)->map), free(*game), 0); //TODO ft_free_map
	return (1);
}

int	ft_draw_map(t_data **game)
{
	int	row_index;
	int column_index;

	row_index = 0;
	if (!ft_init_img(game)) //TODO
		return (ft_printf("Error image\n"), 0);
	row_index = 0;
	while ((*game)->map[row_index])
	{
		column_index = 0;
		while ((*game)->map[row_index][column_index])
		{
			ft_put_image(row_index, column_index, game);
			ft_change_wall(row_index, column_index, game);
			column_index++;
		}
		row_index++;
	}
	return (0);
}

void	ft_put_image(int row_index, int column_index, t_data **game)
{
	void	*img;

	img = NULL;
	if ((*game)->map[row_index][column_index] == WALL)
		img = (*game)->img.wall;
	else if ((*game)->map[row_index][column_index] == FLOOR)
		img = (*game)->img.floor;
	else if ((*game)->map[row_index][column_index] == PLAYER)
		img = (*game)->img.down;
	else if ((*game)->map[row_index][column_index] == EXIT)
		img = (*game)->img.exit;
	else if ((*game)->map[row_index][column_index] == COIN)
		img = (*game)->img.coin;
	if (img)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, img, column_index * SZ, row_index * SZ);
}
