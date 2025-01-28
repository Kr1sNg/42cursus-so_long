/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:13:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/28 17:17:45 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// check and set up dimension for map

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

static int	ft_map_objs_count(t_game *game, int row, int col)
{
	if (game->map.matrix[row][col] == PLAYER)
		return (game->count.player++, 1);
	else if (game->map.matrix[row][col] == EXIT)
		return (game->count.exit++, 1);
	else if (game->map.matrix[row][col] == COIN)
		return (game->count.coin++, 1);
	else if (game->map.matrix[row][col] == WALL)
		return (game->count.wall++, 1);
	else if (game->map.matrix[row][col] == FLOOR)
		return (game->count.floor++, 1);
	else if (game->map.matrix[row][col] == ENEMY)
		return (game->count.enemy++, 1);
	else
		return (0);
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
			if (ft_map_objs_count(game, row, col) == 0)
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
	if (!(ft_map_path(game)))
		return (false);
	return (true);
}
