# 🎮 &nbsp; so longgggg
# &emsp; &emsp; &emsp; *and thanks to all the fish* &nbsp; 🐟
*A 42's project to create a small 2D game with **minilibx**.*

---

<p align="center">
  <img src="https://github.com/Kr1sNg/42cursus-so_long/blob/main/so_long.gif" />
</p>

---

## 🎴 Requirement

Objective of this project is to improve skills in the following areas: window management, event handling, colors, textures, etc

By using the [MiniLibX](https://github.com/42Paris/minilibx-linux) graphical library, we can open a window, create images and deal with keyboard and mouse events.

### Mandatory part

| **Program name** | so_long |
|-------------|-------------| 
| **Turn in files** | Makefile, *.h, *.c, maps, textures |
| **Makefile** | NAME, all, clean, fclean, re |
| **Arguments** | A map in format *.ber |
| **External functs** | + open, close, read, write, malloc, free, perror, strerror, exit + All functions of math library + All functions of MiniLibX + ft_printf |
| **Libft authorized** | Yes
| **Description** | You mus create a basic 2D game in which a dolphin escapes Earth atfer eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want. |	

### Bonus part
- Make player lose when they touch an enemy patrol
- Add some sprite animation
- Display the movement count directly on screen instead of writing it in the shell


---
## 📍 Using MiniLibX
The MiniLibX, or MLX, is a framework built by Olivier Crouzet on top of X11, a window system developed back in 1984. The MLX is a beginner-friendly C API to interact with the X11 system behind it.

#### 1 - Including file
Header file `mlx.h` should be included for a correct use of the MiniLibX API.

#### 2 - Initiation
#### `mlx_init`
function will create connection between software and the display. It must be called before using any other functions.
```
void	*mlx_init()
```
No parameters are needed, and it will return a `void *` identifier, used for further calls to the library routines.

#### `mlx_destroy_display`
Free MLX

#### 3 - Managing windows
#### `mlx_new_window`
Create a new windlow on the screen
```
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
```
- `mlx_prt`	: connection identifier returned by `mlx_init()`
- `size_x`	: WINDOW_WIDTH
- `size_y`	: WINDOW_HEIGHT
- `title`	: the text that should be displayed in the window's title bar

It returns a `void *` window identifier that can be used by other MLX calls.
Note that the MLX can handle an arbitrary number of separate windows.

If it fails to create a new window (for whatever reason), it will return `NULL`,
otherwise a non-null poiter is returned as a window identifier.

#### `mlx_clear_window` and `mlx_destroy_window`
Respectively clear (in black) and destroy (`free()`) the given window.
```
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
```
They both use the same parameters:
- `mlx_ptr` : the screen connection identifier
- `win_ptr` : the window identifier

#### 4 - Drawing inside windows
#### `mlx_pixel_put` and `mlx_string_put`
This function draws a defined pixel or `string` in the window `win_ptr` using the (`x`, `y`) coordinates, and the specified `color`.
```
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
```
The `color` parameter has an integer type, using RGB color mode.

#### 5 - Manipulating images
#### `mlx_new_image`
creates a new image in memory
```
void	*mlx_new_image(void *mlx_ptr, int width, int height);
```
It returns a `void *` identifier needed to manipulate this image later, or `NULL` if an error occurs. It only needs the size of the image to be created, using the `width` and `height` parameters, and the `mlx_ptr` connection identifier.

User can draw inside the image, and can dump the image inside a specified window at any time to display it on the screen...

...by using the function below:

#### `mlx_put_image_to_window`
Three identifiers are needed here, for the connection to the display `mlx_ptr`, the window to use `win_ptr`, and the image `img_ptr`
```
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
```
- `x` : vertical location
- `y` : horizontal location where the image should be placed in the window.

#### `mlx_get_data_addr`
This function returns information about the created image, allowing user to modify it later.
```
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
```
- `img_ptr` : the identifier to specify the image to use
- `bits_per_pixel` : pointer to integer which is filled with the number of bits needed to represent a pixel color (also called the depth of the image)
- `size_line` : pointer to integer which is the number of bytes used to store one line of the image in memory.
- `endian` : pointer to integer which tells us whether the pixel color in the image needs to be stored in little endian (`endian == 0`), or big endian (`endian == 1`).

It returns a `char *` address that represents the beginning of the memory area where the image is stored. From this address, the first `bits_per_pixel` bits represent the color of the first pixel in the first line of the image. The second group of `bits_per_pixel` bits represent the second pixel of the first line, and so on. Add `size_line` to the address to get the beginning of the second line. We can reach any pixels of the image that way. 

#### `mlx_destroy_image`
Frees the given image
```
int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
```

#### 6 - Storing color inside images
Depending on the display, the number of bits used to store a pixel color can change.
#### `mlx_get_color_value`
It takes a standard RGB `color` parameter, and returns an `unsigned int` value.
```
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
```

#### 7 - XPM Images
#### `mlx_xpm_to_image` and `mlx_xpm_file_to_image`
These functions will create a new image in the same way. They will fill it using the specified `xpm_data` or `filename`, depending on which function is used.

```
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
```
Note that MLX does not use the standard Xpm library to deal with xpm images. We may not be able to read all types of xpm images. It however handles transparency.

#### 8 - Handle events
The X-Window (and MacOSX graphical) system is bi-directionnal. On one hand, it sends orders to the screen to display pixels, images,... On the other hand, it can get information from the keyboard and mouse associated to the screen, those recieves call "events".

#### `mlx_loop`
This function never returns. It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event.
```
int	mlx_loop(void *mlx_ptr);
```
A single parameter is needed, the connection identifier `mlx_ptr`.

We can assign different functions to the three following events:
- A key pressed
- The mouse button is pressed
- A part of the window should be re-drawn (this is called an "expose" event, and it is a job of program to handle)

Each window can define a different function for the same event.

#### `mlx_key_hook`, `mlx_mouse_hook`, `mlx_expose_hook` and `mlx_loop_hook` or `mlx_hook`

Three functions `mlx_key_hook`, `mlx_mouse_hook`, `mlx_expose_hook` work exactly in the same way.
```
int	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
```
They take the parameters:
- `win_ptr` : the specific identifier window
- `funct_ptr` : a pointer to the function that will be called when an event occurs.
- `param` : The address will be passed to the function everytime it is called, and should be used to store the parmeters is might need.

The function `mlx_loop_hook` will be called when no event occurs.
```
int	mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
```

*see `keycode` in `X11/keysymdef.h` to know which key is pressed*


#### 9 - Linking MiniLibX
To use MiniLibX functions, we need to link software with several libraries, include the MiniLibX library itself.

To do this, simply add the following arguments at linking time:
```
-lmlx -lXext -lX11
```
We may need to specify the path to these libraries, using the `-L`

In MacOS, we need to add link to include for headers of X11 with:
```
-I /usr/X11/include
```

---

<p align="center">
  <img src="https://github.com/user-attachments/assets/66ee7d99-89e2-4807-820c-af4fe4747fcc" />
</p>

---
## ▶️ Play the game

### 1 - Map Mandatory
In the folder **so_long**, run the command to compile program `so_long`
```
make re
```
Run `so_long` by choosing the valid map you want
```
./so_long map/valid/<name_of_map>.ber
```
Try to collect all coins and finish the game by going through the exit!
You can **quit** the game anytime by using `esc` or by clicking on the cross on the window.

### 2 - Map Bonus
In the folder **so_long**, run the command to compile program `so_long`
```
make fclean && make bonus
```
Run `so_long_bonus` by choosing the valid map you want
```
./so_long_bonus map/bonus/<name_of_map>.ber
```
Try to avoid touching the enemy patrol, collect all coins, finish the game by going through the exit!
You can **quit** the game anytime by using `esc` or by clicking on the cross on the window.

### 3 - Create New Map
Create new map `.ber` file with:
- `1` for Wall
- `0` for Floor
- `C` for Coin
- `E` for Exit
- `I` for EnemIes (works only with `so_long_bonus`)
- `P` fot Player

> If you use Vim to create the map, make sure to use `:set binary` or `:set noeol` before quit
> (because VIM always adds an unwanted `\n` at eof)

#### **Then enjoy the game!**

---
## 🐛 Issues and Bugs
Please feel free to create a new issue with its title and description on the `issues` page of this [42cursus-so_long](https://github.com/Kr1sNg/42cursus-so_long/) repository. If you have already found the solution to the problem, I would love to review your `pull request`!

---
#### Reference
- [Game asset](https://itch.io/game-assets)
- [MiniLibX Introduction](https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx)
- [MiniLibX Install Linux](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)
- [MiniLibX Install MacOs](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)
