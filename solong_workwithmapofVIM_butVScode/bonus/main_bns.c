/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:05:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/26 21:03:21 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_struct_init(&game);
	if (argc != 2)
		ft_error_map(20);
	if (ft_open_map(argv[1], &game))
	{
		ft_game_init(&game);
		ft_game_start(&game);
		mlx_loop(game.mlx_ptr);
	}
	else
		ft_error_map(21);
	ft_game_exit(&game);
	return (0);
}

void	ft_struct_init(t_game *game)
{
	t_img	*image;

	*game = (t_game){0};
	game->map.matrix = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	image = ft_calloc(1, sizeof(t_img));
	if (!image)
		ft_error_map(12);
	game->img = *image;
	free(image);
	return ;
}
