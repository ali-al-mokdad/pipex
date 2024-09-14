/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:02:53 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 16:09:33 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"
#include "./../lib/get_next_line/get_next_line.h"
#include "./../lib/ft_printf/libft/libft.h"

void	print_terminal(int dd)
{
	dup2(dd, STDOUT_FILENO);
	ft_printf("pipe heredoc> ");
}

void	print_file(int file, char *str)
{
	dup2(file, STDOUT_FILENO);
	ft_printf("%s", str);
}

int	create_here_doc(char *terminate)
{
	int		terminal;
	int		heredoc_file;
	char	*str;

	str = NULL;
	heredoc_file = open("here_doc.temp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	terminal = open("/dev/tty", O_WRONLY);
	print_terminal(terminal);
	str = get_next_line(0);
	print_file(heredoc_file, str);
	while (ft_strncmp(str, terminate, ft_strlen(terminate)))
	{
		dup2(terminal, STDOUT_FILENO);
		ft_printf("pipe heredoc> ");
		dup2(heredoc_file, STDOUT_FILENO);
		free(str);
		str = get_next_line(0);
		ft_printf("%s", str);
	}
	free(str);
	close (terminal);
	close(heredoc_file);
	return (open("here_doc.temp", O_RDONLY));
}

void	excute_befor_while(char **argv, int heredoc_file, int *fd, char **envp)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(heredoc_file, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execute(argv[3], envp);
}

int	check_here_doc(char **argv, int *fd, int argc, char **envp)
{
	int	heredoc_file;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
		{
			ft_printf("Usage: ./pipex here_doc LIMITER cmd1 cmd2 ... file2\n");
			exit(-1);
		}
		heredoc_file = create_here_doc(argv[2]);
		excute_befor_while(argv, heredoc_file, fd, envp);
		close (heredoc_file);
		return (1);
	}
	else
		return (0);
}
