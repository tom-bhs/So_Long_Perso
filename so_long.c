/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:46:23 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/08 15:37:27 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game)
{
	char	*gnl;
	int		i;

	i = 0;
	gnl = get_next_line(game->map.fd);
	game->map.map_size = malloc(len_map(gnl) * sizeof(char *));
	game->map.map_width = len_map(gnl);
	while (gnl != NULL)
	{
		game->map.map_size[i] = gnl;
		gnl = get_next_line(game->map.fd);
		i++;
	}
	game->map.map_size[i] = '\0';
	game->map.map_height = i;
}