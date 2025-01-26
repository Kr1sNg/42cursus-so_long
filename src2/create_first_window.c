/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:14:53 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/17 16:22:32 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define	WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	main(void)
{
	t_data	data;
	void	*win2;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "First window");
	win2 = mlx_new_window(data.mlx_ptr, 1080, 720, "Window 2");
	while (1)
		;
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_window(data.mlx_ptr, win2);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
