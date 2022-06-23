/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:14:38 by misimon           #+#    #+#             */
/*   Updated: 2022/06/23 19:43:01 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_cmd(t_pipex *main_var, char **envp)
{
	dup2(main_var->file_read, 0);
	dup2(main_var->fd_pipe[1], 1);
	close(main_var->fd_pipe[0]);
	close(main_var->file_read);
	execve(main_var->path_cmd1, main_var->cmd1, envp);
}

void	parent_cmd(t_pipex *main_var, char **envp, char **argv)
{
	wait(&main_var->id);
	main_var->file_write = open(argv[4], O_WRONLY | O_TRUNC);
	dup2(main_var->file_write, 1);
	dup2(main_var->fd_pipe[0], 0);
	close(main_var->fd_pipe[1]);
	close(main_var->file_write);
	execve(main_var->path_cmd2, main_var->cmd2, envp);
}
