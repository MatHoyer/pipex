/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:51:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/30 08:05:24 by mhoyer           ###   ########.fr       */
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
	int		**fd_pipe;
	pid_t	*pid;
	char	**all_path;
	char	*infile;
	char	*outfile;
	int		if_here_doc;
	char	*limiter;
	int		nb_cmd;
}	t_pipex;

int		msg_error(char *str);
void	free_all(t_pipex *pipe, char *msg);
void	free_mat(char **mat);

void	wait_all(t_pipex *pip);

void	one_more(t_pipex *pip, int fd_prec[2], int fd_pipe[2]);
void	first(t_pipex *pip, int fd_pipe[2], int infile);

void	do_first(t_pipex *pip, int i);
void	do_one_more(t_pipex *pip, int i);

int		cmp_str(char *str_to_cmp, char *str_model);
char	*get_cmd(t_pipex *pip);
void	pipex(t_pipex *pip);
char	**get_path(t_pipex *pip, char **env);

#endif