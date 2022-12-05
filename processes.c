/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:37:22 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/31 15:37:59 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	execute(char *argv, char **envp)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(argv, ' ');
	if (execve(get_path(cmd_args[0], envp), cmd_args, envp) == -1)
		msg_error(ft_strjoin(cmd_args[0], " : command not found\n"), 127);
}

char	*get_path(char *cmd, char **envp)
{
	char	**path_array;
	char	*path;
	int		i;
	char	*tmp;

	i = 0;
	path = find_path(envp);
	path_array = ft_split(path, ':');
	i = 0;
	while (path_array[i])
	{
		tmp = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(tmp, cmd);
		ft_free_ptr((void **)&tmp);
		if (!access(path, F_OK))
			return (path);
		i++;
	}
	return (0);
}

/*char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free (tmp);
		if (!access(command, F_OK))
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}*/
