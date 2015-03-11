// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Resolve.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 16:06:45 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 13:06:43 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RESOLVE_HPP
# define RESOLVE_HPP

# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <cmath>
# include "CustomError.class.hpp"

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
	void						setOpt_aff(bool b);
private:
	Resolve(Resolve const &src);
	Resolve						&operator=(Resolve const &rhs);

	typedef size_t (Resolve::*t_heuristic)(size_t, size_t, std::vector<size_t>);
	t_heuristic					heuristics[3];

	size_t						heuristic_p(size_t n, size_t pos, std::vector<size_t> map);
	size_t						heuristic_w(size_t n, size_t pos, std::vector<size_t> map);
	size_t						heuristic_e(size_t n, size_t pos, std::vector<size_t> map);

	size_t						sum_heuristic(std::vector<size_t> map);
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
	bool						opt_aff;
	int							opt_heu;
};

#endif
