// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/26 10:16:23 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 11:19:33 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <cstring>
# include <cstdlib>
# include <regex>
# include <string>

# define COMMENT_CHAR	'#'

class Parser
{
public:
	Parser(void);
	virtual ~Parser(void);
	void						check_input(std::string input);
	std::vector<size_t>			getMap(void);
	size_t						getSize(void);
private:
	Parser(Parser const &src);
	Parser						&operator=(Parser const &rhs);
	void						check_line(std::string line, size_t i);
	std::vector<std::string>	split(std::string line, const char *delimiter);
	size_t						size;
	std::vector<size_t>			map;
};

#endif
