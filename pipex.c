/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:31:02 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/31 16:13:36 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char *argv[], char *envp[], int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		msg_error(NULL, errno);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent(char *argv[], char *envp[], int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		msg_error(NULL, errno);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	pipex(int argc, char *argv[], char *envp[])
{
	int		pipe_fds[2];
	pid_t	child_pid;

	if (argc != 5)
		msg_error("Invalid number of arguments\n", 1);
	if (pipe(pipe_fds) == -1)
		msg_error("Pipe error\n", errno);
	child_pid = fork();
	if (child_pid < 0)
		msg_error("Fork error\n", errno);
	if (child_pid == 0)
		child(argv, envp, pipe_fds);
	waitpid(child_pid, NULL, 0);
	parent(argv, envp, pipe_fds);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	return (pipex(argc, argv, envp));
}
