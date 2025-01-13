/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:00:14 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/13 10:00:40 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello");
	if (!win_ptr)
	{
		free(win_ptr);
		return (MLX_ERROR);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}