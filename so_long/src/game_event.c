/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:25:25 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:01:51 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_locate_player(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (game->map.matrix[row])
	{
		col = 0;
		while (game->map.matrix[row][col])
		{
			if (game->map.matrix[row][col] == PLAYER)
			{
				game->position.p_row = row;
				game->position.p_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

static void	ft_moving(t_game *game, int move_row, int move_col)
{
	int	new_row;
	int	new_col;
	int	curr_pos;

	ft_locate_player(game);
	new_row = game->position.p_row + move_row;
	new_col = game->position.p_col + move_col;
	curr_pos = game->map.matrix[new_row][new_col];
	if (curr_pos == FLOOR || curr_pos == COIN)
	{
		game->map.matrix[new_row][new_col] = PLAYER;
		game->map.matrix[game->position.p_row][game->position.p_col] = FLOOR;
		game->position.p_row = new_row;
		game->position.p_col = new_col;
		if (curr_pos == COIN && game->count.coin > 0)
			game->count.coin--;
		game->count.moves++;
		ft_printf("Number of movements: %i \n", game->count.moves);
	}
	else if (curr_pos == EXIT && game->count.coin == 0)
	{
		game->map.matrix[game->position.p_row][game->position.p_col] = FLOOR;
		ft_printf("👑 You WIN in %i movements!\n", (game->count.moves + 1));
		ft_game_exit(game);
	}
}

int	ft_handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_game_exit(game);
	else if (keysym == XK_w || keysym == XK_Up)
	{
		game->img.player = game->img.up;
		ft_moving(game, -1, 0);
	}
	else if (keysym == XK_a || keysym == XK_Left)
	{
		game->img.player = game->img.left;
		ft_moving(game, 0, -1);
	}
	else if (keysym == XK_s || keysym == XK_Down)
	{
		game->img.player = game->img.down;
		ft_moving(game, +1, 0);
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		game->img.player = game->img.right;
		ft_moving(game, 0, +1);
	}
	return (0);
}
