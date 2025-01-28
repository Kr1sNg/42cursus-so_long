/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:13:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:03:41 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// check and set up dimension for map
int	ft_map_dimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.matrix[0][i] != '\n' && game->map.matrix[0][i] != '\0')
		i++;
	if (i < 3)
		return (0);
	game->map.numofcols = i;
	if (!game->map.numoflines || game->map.numoflines < 3)
		return (0);
	game->map.size_matrix = game->map.numoflines * game->map.numofcols;
	return (game->map.size_matrix);
}

static bool	ft_map_shape(t_game *game)
{
	int	numofcols;
	int	row;
	int	col;

	numofcols = game->map.numofcols;
	row = -1;
	while (game->map.matrix[++row])
	{
		col = 0;
		while (game->map.matrix[row][col] && game->map.matrix[row][col] != '\n')
			col++;
		if (col != numofcols)
			return (false);
	}
	return (true);
}

static bool	ft_map_border(t_game *game)
{
	int	row;
	int	col;

	col = game->map.numofcols;
	row = -1;
	while (++row < game->map.numoflines)
	{
		if ((game->map.matrix[row][0] != WALL)
			|| (game->map.matrix[row][col - 1] != WALL))
			return (false);
	}
	col = -1;
	while (++col < game->map.numofcols)
	{
		if ((game->map.matrix[0][col] != WALL)
			|| (game->map.matrix[row - 1][col] != WALL))
			return (false);
	}
	return (true);
}

static bool	ft_map_objs(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map.numoflines)
	{
		col = -1;
		while (++col < game->map.numofcols)
		{
			if (game->map.matrix[row][col] == PLAYER)
				game->count.player++;
			else if (game->map.matrix[row][col] == EXIT)
				game->count.exit++;
			else if (game->map.matrix[row][col] == COIN)
				game->count.coin++;
			else if (game->map.matrix[row][col] == WALL)
				game->count.wall++;
			else if (game->map.matrix[row][col] == FLOOR)
				game->count.floor++;
			else if (game->map.matrix[row][col] == ENEMY)
				game->count.enemy++;
			else
				return (false);
		}
	}
	return ((game->count.player == 1) && (game->count.exit == 1)
		&& (game->count.coin > 0));
}

bool	ft_valid_map(t_game *game)
{
	if (!(ft_map_objs(game)))
		return (false);
	if (!(ft_map_shape(game)))
		return (false);
	if (!(ft_map_border(game)))
		return (false);
	return (true);
}
