/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:05:49 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/21 17:41:30 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PSEUDOCODE
1 - read map
	- read file (gnl)
	
	
2 - draw map
3 - move
4 - exit

*/

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_struct_init(game);
	if (argc != 2)
		ft_error_map(22);
	game->argc_tmp = argc;
	game->argv_tmp = argv;
	if (ft_open_map(argv[1], game)) //TODO
	{
		ft_game_init(game); //ft_initialize_game - TODO
		ft_game_start(game); //ft_gameplay_start -TODO
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_error_map(61);
	ft_game_exit(game); //ft_exit_program - TODO
	return (0);
}

void	ft_struct_init(t_game *game)
{
	t_img	*img;

	*game = (t_game){0};
	game->map.matrix = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	img = malloc(sizeof(t_img));
	if (!img)
		ft_error_map(12);
	game->game_img = *img;
	free(img);
	return ;
}

int	ft_read_map(int fd, t_game *game)



// int	handle_keypress(int keysym, t_data *game)
// {
// 	int move;

// 	if (keysym == XK_Escape)
// 	{
// 		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 		game->win_ptr = NULL;
// 	}
// 	else if (keysym == XK_w || keysym == XK_Up)
// 		move_up(&game);
// 	else if (keysym == XK_s || keysym == XK_Down)
// 		move_down(&game);
// 	else if (keysym == XK_a || keysym == XK_Left)
// 		move_left(&game);
// 	else if (keysym == XK_d || keysym == XK_Right)
// 		move_right(&game);
// 	move = game->count.moves;
// 	ft_printf("Keypress: %d\n", keysym);
// 	ft_printf("Moves: %d\n", move);
// 	return (0);
// }

// int	handle_keyrelease(int keysym, t_data *game)
// {
// 	printf("Keyrelease: %d\n", keysym);
// 	return (0);
// }

// int	handle_no_event(t_data *game)
// {
// 	/* This function needs to exist, but it is useless for the moment */
// 	return (0);
// }

// int handle_close(t_data *game)
// {
// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 	game->win_ptr = NULL;
// 	return (EXIT_SUCCESS);
// }

// int	close_win(t_data *game)
// {
// 	if (game->mlx_ptr)
// 		mlx_loop_end(game->mlx_ptr);
// 	return (0);
// }



