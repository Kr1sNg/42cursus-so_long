/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:57:06 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/21 16:45:17 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Linux:
**	make && ./configure
**	flag needed to add to compile
**	-L../minilibx-linux -lmlx -lX11 -lXext
**	
**	MacOS:
**	make && ./configure (have to install mlx first)
** 	-I /usr/X11/include(to find X11/X.h and keysym.h) -L../minilibx-linux -lmlx -L/usr/X11/lib -lX11 -lXext    
**	(-framework OpenGL -framework AppKit)
**
**	https://github.com/rbourgeat/so_long
*/

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** :::::::::::::::::::::::::::::::::* HEADERS *:::::::::::::::::::::::::::::: **
*/

#include "../libft/includes/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h> //perror
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>

/*
** :::::::::::::::::::::::::::* DEFINE DECLARATION *::::::::::::::::::::::::: **
*/

#define BUFF_SZ 1042
#define SZ 32

#define FLOOR '0'
#define WALL '1'
#define COIN 'C'
#define EXIT 'E'
#define PLAYER 'P'

// #define ESC 65307
// #define W 119
// #define S 115
// #define A 97
// #define D 100



/*
** :::::::::::::::::::::::::::* STRUCT DECLARATION *::::::::::::::::::::::::: **
*/

/*
** ...:::*** Images ***:::...
*/

typedef struct s_img
{
	void	*left;
	void	*right;
	void	*down;
	void	*up;
	void	*coin;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
	int		img_width;
	int		img_height;
}	t_img;

/*
** ...:::*** Positions of Player and Exit ***:::...
*/

typedef struct s_pos
{
	int	p_row; //player row
	int	p_col; //player col
	int	e_row; // exit row
	int	e_col; //exit col
}	t_pos;

/*
** ...:::*** Count and Data ***:::...
*/

typedef struct s_count
{
	int	count_player;
	int	count_exit;
	int	count_coin;
	int	count_wall;
	int	count_floor;
	int	count_moves;
	int	endgame; //for what???
}	t_count;

/*
** ...:::*** Resolutions ***:::...
*/

typedef struct s_resolu
{
	int	map_width; //useless
	int	map_height;
}	t_resolu;

/*
** ...:::*** Matrix and Maps ***:::...
*/

typedef struct s_map
{
	int			numoflines; //used
	int			numofcols; //used
	int			rows; //useless
	int			size_matrix;
	char		**matrix; //used
	t_pos		positions;
	t_resolu	resolution; //useless
}	t_map;

/*
** ...:::*** Main Controller ***:::...
*/

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			argc_tmp;
	char		**argv_tmp;
	t_img		game_img;
	t_pos		position;
	t_count		game_count;
	t_resolu	resolution;
	t_map		map;
}	t_game;


/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
** ...:::*** Errors ***:::...
*/

void	ft_error_init(int n);
void	ft_error_map(int n);

/*
** ...:::*** Maps ***:::...
*/

int	ft_open_map(char *map, t_game *game);
int	ft_read_map(int fd, t_game *game);

bool	ft_map_extension(char *map);


/*
** ...:::*** Free ***:::...
*/

void	ft_free_map(t_game *game);


#endif