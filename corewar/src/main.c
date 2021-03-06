/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:05:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/18 00:22:12 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int		cor_close(void *main)
{
	(void)main;
	exit(EXIT_SUCCESS);
}

int				init_mlx(t_main *main)
{
	if (!(main->mlx = mlx_init()) ||
		!(main->win = mlx_new_window(main->mlx, WIDTH, HEIGHT, "COREWAR")) ||
		!(main->img = mlx_new_image(main->mlx, WIDTH, HEIGHT)))
		return (0);
	main->data_addr = mlx_get_data_addr(main->img, &main->bits_per_pixel,
										&main->size_line, &main->endian);
	return (1);
}

static	void	start_game(t_main *main)
{
	int		i;

	ft_putstr("Introducing contestants...\n");
	i = -1;
	while (++i < main->players)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		i + 1, main->player[i].code_size,
		main->player[i].name,
		main->player[i].comment);
	while (main->cursor && main->cycle_to_die > 0)
	{
		game_exec(main);
		if (main->dump && main->cycles_count == main->dump)
		{
			print_memory(main->area, MEM_SIZE);
			exit(0);
		}
	}
	if (main->cursor)
		game_exec(main);
	print_winner(main);
}

int				main(int ac, char *av[])
{
	t_main	*main;

	main = init();
	insert_params(main, ac, av);
	sort_p_index(main);
	if (main->starter)
	{
		main->speed = 1;
		main->pause = 1;
	}
	if (main->flag_v)
		init_mlx(main);
	init_cursors(main);
	init_area(main);
	if (main->flag_v)
	{
		mlx_key_hook(main->win, lem_hook_keydown, main);
		mlx_hook(main->win, 17, 0, cor_close, main);
		mlx_loop_hook(main->mlx, lem_loop_key_hook, main);
		mlx_loop(main->mlx);
	}
	else
		start_game(main);
	exit(0);
	return (0);
}
