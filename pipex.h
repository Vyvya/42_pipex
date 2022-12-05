/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:02:03 by vgejno            #+#    #+#             */
/*   Updated: 2022/05/31 15:38:43 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

int			pipex(int argc, char *argv[], char *envp[]);
void		child(char *argv[], char *envp[], int *fd);
void		parent(char *argv[], char *envp[], int *fd);
void		execute(char *argv, char **envp);
void		msg_error(char *error, int errnum);
char		*get_path(char *cmd, char **envp);
void		ft_free_ptr(void **ptr);
//char		*get_cmd(char **path, char *cmd);
char		*find_path(char **envp);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

#endif