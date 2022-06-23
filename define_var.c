/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:49:50 by misimon           #+#    #+#             */
/*   Updated: 2022/06/23 19:20:03 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*define_var(char **argv, char **envp)
{
	t_pipex	*def_var;

	def_var = malloc(sizeof(t_pipex));
	if (!def_var)
		def_var->error = -1;
	def_var->file_read = open(argv[1], O_RDONLY);
	def_var->path_cmd1 = command_path(argv[2], split_path(envp));
	def_var->cmd1 = ft_split(argv[2], ' ');
	def_var->file_write = open(argv[4], O_CREAT | O_WRONLY, 0644);
	def_var->path_cmd2 = command_path(argv[3], split_path(envp));
	def_var->cmd2 = ft_split(argv[3], ' ');
	if (!def_var->path_cmd1 || !def_var->path_cmd2 || def_var->file_read < 0
		|| def_var->file_write < 0)
		def_var->error = -1;
	close (def_var->file_write);
	return (def_var);
}
