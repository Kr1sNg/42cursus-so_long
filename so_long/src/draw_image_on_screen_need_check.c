/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image_on_screen_need_check.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:39:36 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/17 17:38:11 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://github.com/aurelien-brabant/minilibx-posts-code/blob/master/drawing-with-minilibx.c
//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define	WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300

#define GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;


int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

// index = line_line * y + x * (bpp / 8)
// to put a pixel at (x, y) of the image

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char *pixel;
	
// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(int *)pixel = color;
// }

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        /* big endian, MSB is the leftmost bit */
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        /* little endian, LSB is the leftmost bit */
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}

void	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		i++;
	}
}


// change background
void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

int	render(t_data *data)
{
	if (!data->win_ptr)
		return (-42);
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	
	return (0);
}



int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "green window");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		return (EXIT_FAILURE);
	}
	
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
