/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:50 by apereira          #+#    #+#             */
/*   Updated: 2023/02/03 12:00:18 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

int			ft_tolower(int c);
int			ft_toupper(int c);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	int				*content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
/**
 * It creates a new list element.
 * 
 * @param content The content to put in the new element.
 * 
 * @return A pointer to a new list element.
 */
t_list		*ft_lstnew(void *content);
/**
 * Adds a new element to the beginning of the list.
 * 
 * @param lst A pointer to a pointer to a linked list.
 * @param new the new element to add to the list
 */
void		ft_lstadd_front(t_list **lst, t_list *new);
/**
 * It counts the number of elements in a linked list.
 * 
 * @param lst The list to be counted.
 * 
 * @return The number of elements in the linked list.
 */
int			ft_lstsize(t_list *lst);
/**
 * It returns the last element of a list.
 * 
 * @param lst A pointer to the first link of a list.
 * 
 * @return The last element of the list.
 */
t_list		*ft_lstlast(t_list *lst);
/**
 * Adds a new element to the end of a linked list
 * 
 * @param lst a pointer to a pointer to a linked list
 * @param new the new element to add to the list
 */
void		ft_lstadd_back(t_list **lst, t_list *newx);
/**
 * It calls the function on the content of the linked list
 * 
 * @param lst The list to be deleted.
 * @param del pointer to a function
 */
void		ft_lstdelone(t_list *lst, void (*del)(void*));
/**
 * Iterate through the list, deleting each node's content 
 * and freeing the node itself
 * 
 * @param lst a pointer to the first element of a linked list
 * @param del a pointer to a function that takes a single 
 * void pointer argument and returns nothing.
 * 
 * @return A pointer to the first element of the list.
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * Iterate through a linked list and apply a function to each element
 * 
 * @param lst a pointer to the first element of a linked list
 * @param f a function that takes a void pointer and returns nothing
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

#endif