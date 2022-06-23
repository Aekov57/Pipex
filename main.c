/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:40:08 by misimon           #+#    #+#             */
/*   Updated: 2022/06/23 18:53:42 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*main_var;

	main_var = define_var(argc, argv, envp);
	if (main_var->error == -1)
	{
		write(2, "an_error_occured\n", 18);
		free(main_var);
		return (-1);
	}
	pipe(main_var->fd_pipe);
	main_var->id = fork();
	if (main_var-> id == 0)
		child_cmd(main_var, envp);
	if (main_var-> id > 0)
		parent_cmd(main_var, envp, argv);
	free(main_var);
	return (0);
}
