/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacikar <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:06:16 by hsacikar          #+#    #+#             */
/*   Updated: 2021/12/04 23:08:59 by hsacikar         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	get_values(int *set, char *str);
int		check(int ac, char **av);
int		check_case(int table[4][4], int position, const int set[16]);

#endif
