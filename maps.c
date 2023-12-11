/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:17:09 by tbihoues          #+#    #+#             */
/*   Updated: 2023/12/11 16:35:30 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
// #include <stdlib.h>
// #include <stddef.h>
// #include <stdio.h>

// char	*get_map(int fd)
// {
// 	char	*line_map;
// 	char	*buff;
// 	int		char_count;
// 	char	*tmp_buff;

// 	line_map = ft_strdup("");
// 	buff = ft_strdup("");
// 	char_count = gnl(fd, &line_map);
// 	if (char_count > 0)
// 	{
// 		tmp_buff = buff;
// 		while (char_count > 0)
// 		{
// 			buff = ft_strjoin(buff, line_map);
// 			free(tmp_buff);
// 			free(line_map);
// 			line_map = ft_strdup("");
// 			char_count = gnl(fd, &line_map);
// 			tmp_buff = buff;
// 		}
// 		return (buff);
// 	}
//     printf("Dommage\n");
// 	return (NULL);
// }
