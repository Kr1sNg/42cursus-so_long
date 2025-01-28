/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:14:53 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:01:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game || !game->map.matrix)
		return ;
	i = 0;
	while (game->map.matrix[i])
	{
		free(game->map.matrix[i]);
		game->map.matrix[i] = NULL;
		i++;
	}
	free(game->map.matrix);
	game->map.matrix = NULL;
}

void	ft_free_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img.coin);
	mlx_destroy_image(game->mlx_ptr, game->img.down);
	mlx_destroy_image(game->mlx_ptr, game->img.exit_close);
	mlx_destroy_image(game->mlx_ptr, game->img.exit_open);
	mlx_destroy_image(game->mlx_ptr, game->img.floor);
	mlx_destroy_image(game->mlx_ptr, game->img.left);
	mlx_destroy_image(game->mlx_ptr, game->img.right);
	mlx_destroy_image(game->mlx_ptr, game->img.up);
	mlx_destroy_image(game->mlx_ptr, game->img.wall);
	mlx_destroy_image(game->mlx_ptr, game->img.enemy);
	game->img = (t_img){0};
}
