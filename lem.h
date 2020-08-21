/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:31:07 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/17 20:21:13 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft.h"

typedef struct		s_room {
	char			*name;
	int				coord_x;
	int				coord_y;
	int				steps;
	int				ant;
}					t_room;

typedef struct		s_lst {
	char			*cont;
	char			a;
	char			s;
	char			r;
	char			e;
	char			l;
	char			c;
	char			o;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_path {
	int				len;
	t_room			**rooms;
	int				ants_num;
}					t_path;

typedef struct		s_lst_paths {
	t_path				*path;
	struct s_lst_paths	*next;
}					t_lst_paths;

typedef struct		s_lem {
	int				number_of_ants;
	int				number_of_rooms;
	t_room			**rooms;
	int				**matrix;
	t_lst_paths		*paths;
	t_lst			*list;
}					t_lem;

typedef struct		s_valid_info {
	int				s;
	int				e;
	int				l;
	int				c;
	int				o;
	int				rs;
	int				re;
}					t_valid_info;
/*
** init
*/
t_lst				*newlst(char *cont);
t_lem				*newlem();
t_room				**newarr(int len);
t_room				*newroom(char *info);
int					**newmatrix(int size);
/*
** parser
*/
t_lem				*parse();
t_lst				*preparse();
char				*parsename(char *s);
void				markup(t_lst *list);
void				parseroom(t_room *room, char *info);
t_room				**get_rooms(t_lst *list, int len);
/*
** validation
*/
int					is_room(char *s);
int					is_link(char *s);
int					is_number_of_ants(char *s);
int					check_rooms(char *a, char *b, t_lem *lem);
int					postvalid(t_lst *list);
/*
** free
*/
void				rmlst(t_lst *list);
void				rmlem(t_lem *lem);
void				rmpath(t_path *path);
void				rmpaths(t_lst_paths *paths);
/*
** alg
*/
int					bfs(t_lem *lem);
t_path				*get_path(t_lem *lem);
void				step(t_path **ants, int number_of_ants, int *finished,
															t_room *end);
void				run_ants(int number_of_ants, t_lst_paths *paths);
/*
** print
*/
void				print_info(t_lst *list);
void				print_step(int id, char *name);
void				error();
/*
** matrix
*/
int					fill_matrix(t_lem *lem, t_lst *list);
/*
** paths
*/
t_path				*get_path(t_lem *lem);
void				restore_path(t_lem *lem, t_path *path);
t_lst_paths			*get_paths(t_lem *lem);
/*
** queue interface
*/
t_room				**newqueue(int size);
int					qin(t_room **queue, int size, t_room *room);
void				qrm(t_room **queue, int size);
void				qfree(t_room **queue, int size);

#endif
