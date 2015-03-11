// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/26 10:20:09 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 10:30:57 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"

Parser::Parser(void) : size(0)
{
	return ;
}

Parser::Parser(Parser const &src)
{
	*this = src;
	return ;
}

Parser::~Parser(void)
{
	return ;
}

Parser							&Parser::operator=(Parser const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

void							Parser::check_input(std::string input)
{
	size_t				i = 1;
	std::ifstream		file(input);
	std::string			line;

	while (std::getline(file, line))
		this->check_line(line, i++);
	if (this->map.size() != (size * size))
	{
		std::cerr << "Number (" << this->map.size() << ") of elements: Error" << std::endl;
		exit(-1);
	}
}

void							Parser::check_line(std::string line, size_t i)
{
	bool						first = false;
	size_t						c = 0;
	std::vector<std::string>	array;
	std::regex					comment("^#.*");

	array = this->split(line, " ");
	for (auto elem : array)
	{
		if (elem[0] == COMMENT_CHAR)
			break ;
		else if (this->is_number(elem))
		{
			if (first)
			{
				std::cerr << "Line " << i << ": Error" << std::endl;
				exit(-1);
			}
			if (!size)
			{
				this->size = atoi(elem.data());
				first = true;
			}
			else
			{
				this->map.push_back(atoi(elem.data()));
				c++;
			}
		}
		else
		{
			std::cerr << "Line " << i << ": Error" << std::endl;
			exit(-1);
		}
	}
	if (c > 0)
	{
		if (c != this->size)
		{
			std::cerr << "Line " << i << ": Error" << std::endl;
			exit(-1);
		}
	}
}

std::vector<std::string>		Parser::split(std::string line, const char *delimiter)
{
	char						*pch;
	char						*temp;
	std::vector<std::string>	array;

	temp = const_cast<char *>(line.c_str());
	pch = strtok(temp, delimiter);
	while (pch != NULL)
	{
		array.push_back(pch);
		pch = strtok(NULL, delimiter);
	}
	return (array);
}

bool							Parser::is_number(std::string number)
{
	int							i = 0;
	while (number[i])
	{
		if (!isdigit(number[i]))
			return (false);
		i++;
	}
	return (true);
}

std::vector<size_t>				Parser::getMap(void)
{
	return (this->map);
}

size_t							Parser::getSize(void)
{
	return (this->size);
}
