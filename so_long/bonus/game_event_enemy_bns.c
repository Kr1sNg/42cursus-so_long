/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event_enemy_bns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:25:25 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/28 16:53:23 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	ft_is_wce(char c)
{
	if (c == WALL)
		return (1);
	else if (c == COIN)
		return (1);
	else if (c == EXIT)
		return (1);
	else
		return (0);
}

static void	ft_enemy_right(t_game *game, int *direction)
{
	int	col;
	int	row;

	row = -1;
	while (++row < game->map.numoflines)
	{
		col = -1;
		while (++col < game->map.numofcols)
		{
			if (game->map.matrix[row][col] == ENEMY)
			{
				if (game->map.matrix[row][col + 1] == FLOOR)
				{
					game->map.matrix[row][col] = FLOOR;
					game->map.matrix[row][col + 1] = ENEMY;
					col++;
				}
				else if (col + 1 > game->map.numofcols
					|| ft_is_wce(game->map.matrix[row][col + 1]))
					*direction = 1;
			}
		}
	}
}

static void	ft_enemy_left(t_game *game, int *direction)
{
	int	col;
	int	row;

	row = game->map.numoflines;
	while (--row > 0)
	{
		col = game->map.numofcols;
		while (--col > 0)
		{
			if (game->map.matrix[row][col] == ENEMY)
			{
				if (game->map.matrix[row][col - 1] == FLOOR)
				{
					game->map.matrix[row][col] = FLOOR;
					game->map.matrix[row][col - 1] = ENEMY;
					col--;
				}
				else if (col < 1 || ft_is_wce(game->map.matrix[row][col - 1]))
					*direction = 0;
			}
		}
	}
}

void	ft_enemy_moving(t_game *game)
{
	static int	direction;

	if (direction == 0)
		ft_enemy_right(game, &direction);
	else if (direction == 1)
		ft_enemy_left(game, &direction);
}
