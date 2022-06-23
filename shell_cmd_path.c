/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misimon <misimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:57:27 by misimon           #+#    #+#             */
/*   Updated: 2022/06/23 15:24:03 by misimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envvar)
{
	int		i;
	char	**pathsplit;

	i = 0;
	while (envvar[i++])
	{
		if (ft_strncmp(envvar[i], "PATH=", 5) == 0)
		{
			pathsplit = ft_split(envvar[i], '=');
			return (ft_split(pathsplit[1], ':'));
		}
	}
	return (0);
}

char	*command_path(char *cmd, char **pathenv)
{
	int		verif;
	int		i;
	char	**excmd;

	i = -1;
	while (pathenv[++i])
	{
		excmd = ft_split(cmd, ' ');
		pathenv[i] = ft_strjoin(ft_strjoin(pathenv[i], "/"), excmd[0]);
		verif = access(pathenv[i], F_OK);
		if (verif == 0)
			return (pathenv[i]);
	}
	return (0);
}
