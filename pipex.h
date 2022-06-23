/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:32:50 by misimon           #+#    #+#             */
/*   Updated: 2022/06/23 19:14:36 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		fd_pipe[2];
	int		id;
	int		file_read;
	int		error;
	char	**cmd1;
	char	*path_cmd1;
	int		file_write;
	char	**cmd2;
	char	*path_cmd2;
}	t_pipex;

t_pipex	*define_var(int argc, char **argv, char **envp);

void	child_cmd(t_pipex *main_var, char **envp);
void	parent_cmd(t_pipex *main_var, char **envp, char **argv);

char	**split_path(char **envvar);
char	*command_path(char *cmd, char **pathenv);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif