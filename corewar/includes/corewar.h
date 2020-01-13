/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:06:53 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/11 21:32:38 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../libft/includes/libft.h"
# include "../../includes/op.h"
# include <stdio.h>
# define COUNT_TOKENS 16
# define MAX_INT 2147483647
# define MAX_SHORT 32767

# define DUMP "dump"
# define DUMP_LEN 4
# define HEADER_VAR 16
# define MIN_PLAYERS 2

# define T_REG_CODE 1
# define T_DIR_CODE 2
# define T_IND_CODE 3

extern t_op g_instr[];

typedef struct		s_player
{
	char			*content;
	int				file_size;
	int				code_size;
	int				id;
	char			*name;
	char			*comment;
}					t_player;

typedef struct		s_main
{
	struct s_player	player[MAX_PLAYERS];
	int				players;
	struct s_cursor	*cursor;
	struct s_cursor	*last_cursor;
	char			*area;
	int				dump;
}					t_main;

typedef struct		s_cursor
{
	int				registers[REG_NUMBER];
	int				pos;
	int				command;
	int				cycles;
	char			types[3];
	int				carry;
	struct s_cursor	*next;
}					t_cursor;

typedef void	(*t_op_func) (t_main *main, t_cursor *cursor, char *area);

void				*init();
void				die(const char *reason);

void				init_player(t_main *main, int ch, int n);
void				calc_ids(t_main *main);

void				insert_params(t_main *main, int count_args, char *params[]);
int					valid_number(char *str);
int					is_number(int count_args, char *params[], int i);
void				help(void);
void				valid_filename(char *filename);
void				valid_file_size(char *str, int size);

void				memory_read(char *area, int pos, void *dst, int size);
void				memory_write(char *area, int pos, void *src, int size);
void				rev_endian(void *val, int size);
void				get_arg_types(char *typesarr, char *area, int pos);
int					check_arg_types(char *types, char command);






void				check_file_content(t_main *main, t_read *reader);
void				init_area(t_main *main);
void				init_cursors(t_main *main);
# define START_NAME 4
# define START_COMMENT (4 + PROG_NAME_LENGTH + 8)
# define CODE_SIZE_FILE 4
# define NULL_SIZE 4

void p(void);
#endif
