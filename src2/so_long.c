/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:00:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/15 20:11:09 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int	main(void)
{
	void	*mlx_connection;
	void	*win_ptr;

	mlx_connection = mlx_init();
	if (!mlx_connection)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_connection, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello");
	if (!win_ptr)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (MLX_ERROR);
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection, win_ptr);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	return (0);
}


