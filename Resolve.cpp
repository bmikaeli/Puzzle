// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Resolve.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 16:07:47 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 17:29:38 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Resolve.hpp"

Resolve::Resolve(std::vector<size_t> initial_map, size_t size) : initial_map(initial_map), size(size), opt_aff(true), opt_heu(0)
{
	this->heuristics[0] = &Resolve::heuristic_p;
	this->heuristics[1] = &Resolve::heuristic_w;
	this->heuristics[2] = &Resolve::heuristic_e;
	this->generate_final_map();
	return ;
}

Resolve::Resolve(Resolve const &src)
{
	*this = src;
	return ;
}

Resolve::~Resolve(void)
{
	return ;
}

Resolve							&Resolve::operator=(Resolve const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

void							Resolve::generate_final_map(void)
{
	size_t						i = 0;
	size_t						n = 1;

	while (i < this->initial_map.size())
	{
		this->final_map.push_back(0);
		i++;
	}
	i = 0;
	while (n < this->final_map.size())
	{
		while ((i % this->size != this->size - 1) && !this->final_map[i + 1] && n < this->final_map.size())
		{
			this->final_map[i] = n;
			i += 1;
			n++;
		}
		while ((i / this->size < this->size - 1) && !this->final_map[i + this->size] && n < this->final_map.size())
		{
			this->final_map[i] = n;
			i += this->size;
			n++;
		}
		while ((i % this->size != 0) && !this->final_map[i - 1] && n < this->final_map.size())
		{
			this->final_map[i] = n;
			i -= 1;
			n++;
		}
		while ((i / this->size > 0) && !this->final_map[i - this->size] && n < this->final_map.size())
		{
			this->final_map[i] = n;
			i -= this->size;
			n++;
		}
	}
}

size_t							Resolve::pos_value(size_t n, std::vector<size_t> map)
{
	size_t						i = 0;

	while (map[i] != n)
		i++;
	return (i);
}

void							Resolve::setOpt_aff(bool b)
{
	this->opt_aff = b;
}

bool							Resolve::is_final(t_node current)
{
	size_t						i = 0;

//	while (i < this->initial_map.size() - 1)
//	{
//		if (current.cur_map[i] != (i + 1))
//			return (false);
//		i++;
//	}
//	return (true);
	while (i < this->final_map.size())
	{
		if (this->pos_value(i, current.cur_map) != this->pos_value(i, this->final_map))
			return (false);
		i++;
	}
	return (true);
}

void							Resolve::add_to_opened(std::vector<t_node> &opened, t_node current, std::map<int, std::vector<t_node> > &closed, size_t g)
{
	t_node						temp;
	size_t						i = 0;

//	while (current.cur_map[i] != 0)
//		i++;
	i = this->pos_value(0, current.cur_map);
	if ((i % this->size) != (this->size - 1))
	{
		temp.cur_map = current.cur_map;
		temp.cur_map[i] = temp.cur_map[i + 1];
		temp.cur_map[i + 1] = 0;
		temp.g = g;
		temp.h = this->sum_heuristic(temp.cur_map);
		temp.f = temp.g + temp.h;
		temp.i_prev = closed[current.h % MAX].size() - 1;
		temp.j_prev = current.h % MAX;
//		if (!this->is_exist(closed[temp.h % MAX], temp) && !this->is_exist(opened, temp))
		if (!this->is_exist(closed[temp.h % MAX], temp))
			opened.push_back(temp);
	}
	if ((i % this->size) != 0)
	{
		temp.cur_map = current.cur_map;
		temp.cur_map[i] = temp.cur_map[i - 1];
		temp.cur_map[i - 1] = 0;
		temp.g = g;
		temp.h = this->sum_heuristic(temp.cur_map);
		temp.f = temp.g + temp.h;
		temp.i_prev = closed[current.h % MAX].size() - 1;
		temp.j_prev = current.h % MAX;
//		if (!this->is_exist(closed[temp.h % MAX], temp) && !this->is_exist(opened, temp))
		if (!this->is_exist(closed[temp.h % MAX], temp))
			opened.push_back(temp);
	}
	if ((i / this->size) != (this->size - 1))
	{
		temp.cur_map = current.cur_map;
		temp.cur_map[i] = temp.cur_map[i + this->size];
		temp.cur_map[i + this->size] = 0;
		temp.g = g;
		temp.h = this->sum_heuristic(temp.cur_map);
		temp.f = temp.g + temp.h;
		temp.i_prev = closed[current.h % MAX].size() - 1;
		temp.j_prev = current.h % MAX;
//		if (!this->is_exist(closed[temp.h % MAX], temp) && !this->is_exist(opened, temp))
		if (!this->is_exist(closed[temp.h % MAX], temp))
			opened.push_back(temp);
	}
	if ((i / this->size) != 0)
	{
		temp.cur_map = current.cur_map;
		temp.cur_map[i] = temp.cur_map[i - this->size];
		temp.cur_map[i - this->size] = 0;
		temp.g = g;
		temp.h = this->sum_heuristic(temp.cur_map);
		temp.f = temp.g + temp.h;
		temp.i_prev = closed[current.h % MAX].size() - 1;
		temp.j_prev = current.h % MAX;
//		if (!this->is_exist(closed[temp.h % MAX], temp) && !this->is_exist(opened, temp))
		if (!this->is_exist(closed[temp.h % MAX], temp))
			opened.push_back(temp);
	}
}

bool							Resolve::is_exist(std::vector<t_node> list, t_node item)
{
	size_t						i = 0;

	while (i < list.size())
	{
		if (item.cur_map == list[i].cur_map)
			return (true);
		i++;
	}
	return (false);
}

t_node							Resolve::find_current(std::vector<t_node> &opened)
{
	std::vector<t_node>::iterator	it;
	std::vector<t_node>::iterator	tmp;
	t_node							ret;

	tmp = opened.begin();
	for (it = opened.begin(); it != opened.end(); ++it)
	{
		if ((*it).h < (*tmp).h)
			tmp = it;
		else if ((*it).h == (*tmp).h)
		{
			if ((*it).f < (*tmp).f)
				tmp = it;
		}
	}
	ret = *tmp;
	opened.erase(tmp);
	return (ret);
}

void									Resolve::launch(void)
{
	if (!this->is_solvable())
	{
		throw CustomError::Unsolvable();
	}

	std::vector<t_node>					opened;
	std::map<int, std::vector<t_node> >	closed;
	t_node								current;
	size_t								g = 0;
	size_t								s = 0;
	bool								succes = false;

	current.cur_map = this->initial_map;
	current.i_prev = -1;
	current.j_prev = -1;
	current.g = 0;
	current.h = 0;
	current.f = 0;
	opened.push_back(current);
	while (opened.size() > 0 && !succes)
	{
		if (opened.size() > s)
			s = opened.size();
		current = this->find_current(opened);
		closed[current.h % MAX].push_back(current);
		if (this->is_final(current))
			succes = true;
		else
		{
			g += 1;
			add_to_opened(opened, current, closed, g);
		}
	}
	if (succes && this->opt_aff)
	{
		this->aff_sequence(current, closed);
		this->aff_nb_moves(current, closed);
		this->aff_nb_opened(g + 1);
		this->aff_nb_max(s);
	}
}

void							Resolve::aff_nb_max(size_t n)
{
	printf("%-38s %5ld\n", "Maximum number of states represented:", n);
}

void							Resolve::aff_nb_opened(size_t n)
{
	printf("%-38s %5ld\n", "Number of states selected:", n);
}

void							Resolve::aff_nb_moves(t_node current, std::map<int, std::vector<t_node> > closed)
{
	size_t						i = 0;
	t_node						temp;

	temp = current;
	while (temp.i_prev != -1)
	{
		temp = closed[temp.j_prev][temp.i_prev];
		i++;
	}
	std::cout << std::endl;
	printf("%-38s %5ld\n", "Number of moves:", i);
}

void							Resolve::aff_sequence(t_node current, std::map<int, std::vector<t_node> > closed)
{
	if (current.i_prev != -1)
		this->aff_sequence(closed[current.j_prev][current.i_prev], closed);
	aff_map(current.cur_map);
	if (!this->is_final(current))
		std::cout << std::endl;
}

void							Resolve::aff_map(std::vector<size_t> map)
{
	size_t						i = 0;

	while (i < map.size())
	{
		std::cout << map[i];
		if ((i % this->size) != (this->size - 1))
			std::cout << " ";
		else
			std::cout << std::endl;
		i++;
	}
}

size_t                          Resolve::sum_heuristic(std::vector<size_t> map)
{
    size_t                      r = 0;
    size_t                      i = 0;

    while (i < map.size() - 1)
    {
//        r += (this->*heuristics[this->opt_heu])(i + 1, i, map);
		r += (this->*heuristics[this->opt_heu])(i + 1, this->pos_value(i + 1, this->final_map), map);
        i++;
    }
    return (r);
}

size_t							Resolve::heuristic_p(size_t n, size_t pos, std::vector<size_t> map)
{
	size_t						p = 0;
	size_t						i = 0;

	while (map[i] != n)
		i++;
	if ((i % this->size) > (pos % this->size))
		p += (i % this->size) - (pos % this->size);
	else
		p += (pos % this->size) - (i % this->size);
	if ((i / this->size) > (pos / this->size))
		p += (i / this->size) - (pos / this->size);
	else
		p += (pos / this->size) - (i / this->size);
	return (p);
}

size_t							Resolve::heuristic_w(size_t n, size_t pos, std::vector<size_t> map)
{
	if (map[pos] != n)
		return (1);
	return (0);
}

size_t							Resolve::heuristic_e(size_t n, size_t pos, std::vector<size_t> map)
{
	size_t						i = 0;
	size_t						t;

	while (map[i] != n)
		i++;
	t = sqrt(pow((i % this->size + 1) - (i / this->size + 1), 2) + pow((pos % this->size + 1) - (pos / this->size + 1), 2));
//	std::cout << t << std::endl;
	return (t);
}

bool							Resolve::is_solvable(void)
{
	std::vector<size_t>			cpy;
	size_t						i = 0;
	size_t						j = 0;
	size_t						p = 0;
	size_t						temp;

	cpy = this->initial_map;
//	while (cpy[i] != 0)
//		i++;
//	if (i != (cpy.size() - 1))
//	{
//		p++;
//		cpy[i] = cpy[cpy.size() - 1];
//		cpy[cpy.size() - 1] = 0;
//	}
//	i = 0;
//	while (i < (cpy.size() - 1))
//	{
//		if (cpy[i] != i + 1)
//		{
//			p++;
//			j = 0;
//			while (cpy[j] != (i + 1))
//				j++;
//			temp = cpy[i];
//			cpy[i] = cpy[j];
//			cpy[j] = temp;
//		}
//		i++;
//	}
	while (i < cpy.size())
	{
		if (cpy[i] != this->final_map[i])
		{
			p++;
			j = this->pos_value(this->final_map[i], cpy);
			temp = cpy[i];
			cpy[i] = cpy[j];
			cpy[j] = temp;
		}
		i++;
	}

//	if ((this->heuristic_p(0, this->initial_map.size() - 1, this->initial_map) % 2) != (p % 2))
	if ((this->heuristic_p(0, this->pos_value(0, this->final_map), this->initial_map) % 2) != (p % 2))
		return (false);
	return (true);
}
