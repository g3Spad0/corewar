/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:38:38 by sjamie            #+#    #+#             */
/*   Updated: 2020/01/04 18:38:39 by sjamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/asm.h"

static	void	check_max_index(int i, int flag, int length)
{
	if (i < length)
		return ;
	die("Length of string too long");
}

static	void	next_line(t_read *reader, int *i, char *str)
{
	reader->i += 1;
	if (reader->i == reader->count)
	{
		error_position("Syntax error at token [TOKEN]", " END \"(null)\"",
					reader->i, reader->j);
	}	
	str[*i] = '\n';
	*i += 1;
	reader->j = 0;
}

char			*full_string(t_main *main, t_read *reader,
							int length, int flag)
{
	char	str[length + 1];
	char	*line;
	int		i;

	i = 0;
	while (reader->arr[reader->i][reader->j] != '"')
	{
		line = reader->arr[reader->i];
		if (!line[reader->j])
		{
			next_line(reader, &i, str);
			continue ;
		}
		check_max_index(i, flag, length);
		str[i] = line[reader->j];
		i += 1;
		reader->j += 1;
	}
	str[i] = 0;
	reader->j += 1;
	return (ft_strdup(str));
}
