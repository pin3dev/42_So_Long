#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx_win);
}

// para compilar no terminal sem makefile: cc -Wall -Wextra -Werror -I/usr/include -Imlx_linux so_long.c -o so_long
