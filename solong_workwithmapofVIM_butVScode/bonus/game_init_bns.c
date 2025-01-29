/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:00:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:02:36 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_check_img(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (!(*image))
	{
		ft_error_init(13);
		ft_game_exit(game);
	}
}

// load img from xmp files
static void	ft_img_init(t_game *game)
{
	ft_check_img(game, &game->img.coin, "assets/coin.xpm");
	ft_check_img(game, &game->img.wall, "assets/wall.xpm");
	ft_check_img(game, &game->img.exit_close, "assets/exit_close.xpm");
	ft_check_img(game, &game->img.exit_open, "assets/exit_open.xpm");
	ft_check_img(game, &game->img.floor, "assets/floor.xpm");
	ft_check_img(game, &game->img.down, "assets/down.xpm");
	ft_check_img(game, &game->img.up, "assets/up.xpm");
	ft_check_img(game, &game->img.left, "assets/left.xpm");
	ft_check_img(game, &game->img.right, "assets/right.xpm");
	ft_check_img(game, &game->img.enemy, "assets/enemy.xpm");
}

// initialize window and set properties of the game
void	ft_game_init(t_game	*game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_init(11);
	game->count.moves = 0;
	ft_img_init(game);
	game->img.player = game->img.down;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.numofcols * SZ,
			game->map.numoflines * SZ, "so_long_bonus");
	if (!game->win_ptr)
		ft_error_init(12);
}
