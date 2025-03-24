/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knavarre <knavarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:18 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/23 19:17:02 by knavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void	*str, size_t	n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	*ft_memmove(void *destination, const void *source, size_t size);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *str);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*free_tab(char **tab);
char	**ft_split(char const *s, char c);
int		ft_tolower(int c);
int		ft_toupper(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int		ft_strcmp(char *s1, char *s2);
int		ft_counttab(char **av);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);
char	*ft_strcpy(char *dest, const char *src);
void	free_list(t_list *lst);
char	*ft_strcopy_until(char *line, char stop_char);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strndup(char *src, int size);

/* get_next_line.c */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*extract_new_stash(char *stash);
char	*read_line(int fd, char *stash);
char	*extract_line(char *stash);
/* get_next_line_utils.c*/
size_t	ft_strlen2(char *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *str, int c);
/* ft_printf */
void	ft_putnbr_base_fd(int n, int base, int fd);
char	*ft_itoa_base(int n, int base);
int		ft_printf(const char *format, ...);
char	*ft_itoa_base_u(unsigned int n, unsigned int base);
void	ft_putnbr_base_u_fd(unsigned int n, unsigned int base, int fd);
int		ft_printp(unsigned long long nb);
void	handlestring(va_list ap, int *count);
void	handlechar(va_list ap, int *count);
void	handlepointer(va_list ap, int *count);
void	handlepercent(int *count);
void	handlehex(va_list ap, char c, int *count);
void	handleunsignedint(va_list ap, int *count);
void	handleinteger(va_list ap, int *count);

#endif