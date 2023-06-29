/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:51:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/29 10:20:04 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define TMP_FILE "/tmp/here_doc.tmp"

typedef struct pipex
{
	t_list	*cmd;
	t_list	*first_cmd;
	char	**all_path;
	char	*infile;
	char	*outfile;
	int		if_here_doc;
	int		nb_cmd;
}	t_pipex;

int		msg_error(char *str);
void	free_all(t_pipex *pipe, char *msg);
void	free_mat(char **mat);

void	wait_all(t_pipex *pip);

char	*get_cmd(t_pipex *pip);
void	pipex(t_pipex *pip);
char	**get_path(char **env);

#endif