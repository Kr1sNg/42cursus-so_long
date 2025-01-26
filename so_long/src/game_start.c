/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:39:36 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:02:59 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// set up game window, key and draw map
void	ft_game_start(t_game *game)
{
	mlx_hook(game->win_ptr,
		DestroyNotify, StructureNotifyMask, ft_game_exit, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_keypress, game);
	mlx_loop_hook(game->mlx_ptr, ft_game_draw, game);
}

static void	ft_drawing_plus(t_game *game, int col, int row)
{
	if (game->map.matrix[row][col] == EXIT && game->count.coin == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit_open, col * SZ, row * SZ);
	else if (game->map.matrix[row][col] == EXIT && game->count.coin != 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit_close, col * SZ, row * SZ);
	return ;
}

int	ft_game_draw(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (game->map.matrix[++row])
	{
		col = -1;
		while (game->map.matrix[row][++col])
		{
			if (game->map.matrix[row][col] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.wall, col * SZ, row * SZ);
			else if (game->map.matrix[row][col] == FLOOR)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.floor, col * SZ, row * SZ);
			else if (game->map.matrix[row][col] == PLAYER)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.player, col * SZ, row * SZ);
			else if (game->map.matrix[row][col] == COIN)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img.coin, col * SZ, row * SZ);
			ft_drawing_plus(game, col, row);
		}
	}
	return (0);
}
