// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Resolve.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 16:06:45 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 10:18:25 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RESOLVE_HPP
# define RESOLVE_HPP

# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <unistd.h>

# define MAX	500

typedef struct		s_node
{
	std::vector<size_t>		cur_map;
	int						i_prev;
	int						j_prev;
	size_t					g;
	size_t					h;
	size_t					f;
}					t_node;

class Resolve
{
public:
	Resolve(std::vector<size_t> initial_map, size_t size);
	virtual ~Resolve(void);

	void						launch(void);
private:
	Resolve(Resolve const &src);
	Resolve						&operator=(Resolve const &rhs);

	size_t						heuristic_m(size_t n, size_t pos, std::vector<size_t> map);
	size_t						sum_heuristic_m(std::vector<size_t> map);
	bool						is_solvable(void);
	bool						is_final(t_node current);
	bool						is_exist(std::vector<t_node> list, t_node item);
	void						add_to_opened(std::vector<t_node> &opened, t_node current, std::map<int, std::vector<t_node> > &closed, size_t g);
	t_node						find_current(std::vector<t_node> &opened);
	void						aff_map(std::vector<size_t> map);
	void						aff_sequence(t_node current, std::map<int, std::vector<t_node> > closed);
	void						aff_nb_moves(t_node current, std::map<int, std::vector<t_node> > closed);
	void						aff_nb_opened(size_t n);
	void						aff_nb_max(size_t n);

	std::vector<size_t>			initial_map;
	size_t						size;
};

#endif
