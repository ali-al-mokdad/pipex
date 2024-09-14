/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:47:11 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 16:04:53 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define    PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./lib/ft_printf/ft_printf.h"

void	execute(char *argv, char **envp);
void	error(void);
void	child_process_bonus(int *fd, int argc, char **argv, char **envp);
void	parent_process_bonus(int *fd, int argc, char **argv, char **envp);
void	print_terminal(int dd);
void	print_file(int file, char *str);
int		create_here_doc(char *terminate);
void	excute_befor_while(char **argv, int heredoc_file, int *fd, char **envp);
int		check_here_doc(char **argv, int *fd, int argc, char **envp);

#endif
