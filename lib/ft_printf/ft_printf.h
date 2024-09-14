/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftwrite.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:29:34 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/06/26 17:01:17 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	"libft/libft.h"
# include	<stdarg.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdlib.h>
# include	<stdint.h>

int				ft_printf(const char *format, ...);
int				print_c(char c);
int				print_s(char *str);
int				print_d(int num);
int				print_p(void *str);
void			check_print(char format, va_list args, int *count);
int				print_i(int num);
int				print_u(unsigned int n);
int				print_x(unsigned int str);
int				print_x2(unsigned int str);
int				p_helper(unsigned long value);

#endif
