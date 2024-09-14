/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:52:05 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 16:03:27 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"
#include "./../lib/get_next_line/get_next_line.h"
#include "./../lib/ft_printf/libft/libft.h"

void	excute_wihout_here_doc(char **argv, char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_printf("Error opening input file");
		exit(-1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		ft_printf("Error duplicating file descriptor for stdout");
		close(file);
		exit(EXIT_FAILURE);
	}
	if (dup2(file, STDIN_FILENO) == -1)
	{
		ft_printf("Error duplicating file descriptor for stdin");
		close(file);
		exit(EXIT_FAILURE);
	}
	close (fd[0]);
	close (fd[1]);
	execute(argv[2], envp);
}

void	child_process_bonus(int *fd, int argc, char **argv, char **envp)
{
	int	i;

	if (check_here_doc(argv, fd, argc, envp) == 1)
		i = 3;
	else
	{
		excute_wihout_here_doc(argv, envp, fd);
		i = 3;
	}
	while (++i < argc - 2)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		close (fd[1]);
		execute(argv[i], envp);
	}
	exit(EXIT_SUCCESS);
}

void	parent_process_bonus(int *fd, int argc, char **argv, char **envp)
{
	int	file;

	file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
	{
		ft_printf("Error");
		exit(-1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close (fd[0]);
	close (fd[1]);
	execute(argv[argc - 2], envp);
	close (file);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;
	int	i;

	i = 2;
	if (argc < 4)
		return (ft_printf("./pipexfile1 cmd1 cmd2 file2"), -1);
	while (i < argc)
	{
		if (ft_strncmp(argv[i++], "", 1) == 0)
		{
			ft_printf("Empty commend!");
			exit(-1);
		}
	}
	if (pipe(fd) == -1)
		return (ft_printf("Error"), 0);
	pid = fork();
	if (pid == -1)
		return (ft_printf("Error"), 0);
	if (pid == 0)
		child_process_bonus(fd, argc, argv, envp);
	wait(NULL);
	parent_process_bonus(fd, argc, argv, envp);
	return (0);
}
