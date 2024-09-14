/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:50:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/31 18:17:09 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	child_process(int *fd, char **argv, char **envp)
{
	int	file;

	file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
	{
		perror("Error");
		exit(-1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
	{
		perror("Error");
		exit(-1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
		return (perror("execute as follow: ./pipexfile1 cmd1 cmd2 file2"), -1);
	if (ft_strncmp(argv[3], "", 1) == 0 || ft_strncmp(argv[2], "", 1) == 0)
	{
		perror("Empty commend!");
		exit(-1);
	}
	else
	{
		if (pipe(fd) == -1)
			return (perror("Error"), 0);
		pid = fork();
		if (pid == -1)
			return (perror("Error"), 0);
		if (pid == 0)
			child_process(fd, argv, envp);
		wait(NULL);
		parent_process(fd, argv, envp);
	}
	return (0);
}
