/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:13:19 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// set up dimension for map
int	ft_map_dimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.matrix[0][i] != '\n')
		i++;
	if (i == 0)
		return (0);
	game->map.numofcols = i;
	game->map.size_matrix = game->map.numoflines * game->map.numofcols;
	return (1);
}

bool	ft_valid_map(t_game *game)
{
	if (!(ft_map_objects(game)))
		return (false);
	if (!(ft_map_shape(game)))
		return (false);
	if (!(ft_map_border(game)))
		return (false);
	return (true);
}

bool	ft_map_shape(t_game *game)
{
	int numofcols;
	int row; // y: row index
	int col; // x: column index

	if (!game->map.numoflines || game->map.numoflines < 3)
		return (false);
	numofcols = game->map.numofcols;
	row = 0;
	while (game->map.matrix[row])
	{
		col = 0;
		while (game->map.matrix[row][col] && game->map.matrix[row][col] != '\n')
			col++;
		if (col != numofcols)
			return (false);
		row++;
	}
	return (true);
}

bool	ft_map_border(t_game *game)
{
	int	row; //y: row index
	int col; //x: column index

	// check left and right walls
	row = 0;
	col = game->map.numofcols;
	while (row < game->map.numoflines)
	{
		if ((game->map.matrix[row][0] != WALL) || (game->map.matrix[row][col - 1] != WALL))
			return (false);
		row++;
	}
	// check first and last row is walls
	col = 0;
	while (col < game->map.numofcols)
	{
		if ((game->map.matrix[0][col] != WALL) || (game->map.matrix[row - 1][col] != WALL))
			return (false);
		col++;
	}
	return (true);
}



