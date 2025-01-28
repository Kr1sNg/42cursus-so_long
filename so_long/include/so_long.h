/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:57:06 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/28 15:50:07 by tat-nguy         ###   ########.fr       */
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
** 	-I /usr/X11/include(to find X11/X.h and keysym.h)
**	-L../minilibx -lmlx -L/usr/X11/lib -lX11 -lXext    
**	(-framework OpenGL -framework AppKit)
**
*/

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** :::::::::::::::::::::::::::::::::* HEADERS *:::::::::::::::::::::::::::::: **
*/

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

/*
** :::::::::::::::::::::::::::* DEFINE DECLARATION *::::::::::::::::::::::::: **
*/

# define SZ 32

# define FLOOR '0'
# define WALL '1'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'

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
	void	*player;
	void	*left;
	void	*right;
	void	*down;
	void	*up;
	void	*coin;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
}	t_img;

/*
** ...:::*** Positions of Player ***:::...
*/

typedef struct s_pos
{
	int	p_row;
	int	p_col;
}	t_pos;

/*
** ...:::*** Data Counting ***:::...
*/

typedef struct s_count
{
	int	player;
	int	exit;
	int	coin;
	int	wall;
	int	floor;
	int	moves;
}	t_count;

/*
** ...:::*** Matrix and Maps ***:::...
*/

typedef struct s_map
{
	int			numoflines;
	int			numofcols;
	int			size_matrix;
	char		**matrix;
}	t_map;

/*
** ...:::*** Main Controller ***:::...
*/

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_pos	position;
	t_count	count;
	t_map	map;
	int		path_exit;
	int		path_coin;
}	t_game;

/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
** ...:::*** Main ***:::...
*/

void	ft_struct_init(t_game *game);

/*
** ...:::*** Errors ***:::...
*/

void	ft_error_init(int n);
void	ft_error_map(int n);

/*
** ...:::*** Maps ***:::...
*/

// map_init
int		ft_open_map(char *path, t_game *game);

// map_check
int		ft_map_dimensions(t_game *game);
bool	ft_valid_map(t_game *game);

// map_check_floodfill
bool	ft_map_path(t_game *game);

/*
** ...:::*** Free ***:::...
*/

void	ft_free_map(t_game *game);
void	ft_free_img(t_game *game);

/*
** ...:::*** Game ***:::...
*/

// game init
void	ft_game_init(t_game	*game);

// game start
void	ft_game_start(t_game *game);
int		ft_game_draw(t_game *game);

// game event
void	ft_locate_player(t_game *game);
int		ft_handle_keypress(int keysym, t_game *game);

// game exit
int		ft_game_exit(t_game *game);

#endif
