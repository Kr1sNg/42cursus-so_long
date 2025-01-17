/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:34:33 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/17 15:00:29 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>


typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	on_destroy(t_data *data, void *img)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, img);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;
	void	*img;
	char	*filename;
	int		img_width = 50;
	int		img_height = 50;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 720, "window");
	if (!data.win_ptr)
	{	
		free(data.mlx_ptr);
		return (EXIT_FAILURE);
	}
	filename = "11zon_fish.xpm";
	img = mlx_xpm_file_to_image(data.mlx_ptr, filename, &img_width, &img_height);
	// if (!img)
	// {
	// 	perror("Error image\n");
	// 	on_destroy(&data, img);
	// 	return (EXIT_FAILURE);
	// }
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 100, 100);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);


}