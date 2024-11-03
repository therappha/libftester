/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:46:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/02 15:46:04 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TESTS_H
# define TESTS_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"

int	*ft_atoi_test(void);
int	*ft_isalpha_test(void);
int	*ft_isdigit_test(void);
int	*ft_isalnum_test(void);
int	*ft_isascii_test(void);
int	*ft_isprint_test(void);
int	*ft_strlen_test(void);
int	*ft_toupper_test(void);
int	*ft_tolower_test(void);
int	*ft_strchr_test(void);
int	*ft_strrchr_test(void);
int	*ft_strncmp_test(void);
int	*ft_memset_test(void);
int	*ft_bzero_test(void);
int *ft_memcmp_test(void);
int	*ft_memcpy_test(void);

#endif
