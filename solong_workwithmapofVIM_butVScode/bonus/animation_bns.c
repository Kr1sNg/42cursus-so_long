/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:05:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/28 16:12:42 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_animation(t_game *game)
{
	if (game->count.animation > 3)
		game->count.animation = 0;
	mlx_destroy_image(game->mlx_ptr, game->img.coin);
	if (game->count.animation == 0)
		game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
				"assets/coin.xpm", &game->img.img_width, &game->img.img_height);
	else if (game->count.animation == 1)
		game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
				"assets/coin_mid.xpm", &game->img.img_width,
				&game->img.img_height);
	else if (game->count.animation == 2)
		game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
				"assets/coin_up.xpm", &game->img.img_width,
				&game->img.img_height);
	else if (game->count.animation == 3)
		game->img.coin = mlx_xpm_file_to_image(game->mlx_ptr,
				"assets/coin_mid.xpm", &game->img.img_width,
				&game->img.img_height);
	game->count.animation++;
	ft_game_draw(game);
	return (0);
}
