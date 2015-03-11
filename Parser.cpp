// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/26 10:20:09 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 11:38:18 by mbar             ###   ########.fr       //
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

	if (!file)
	{
		throw CustomError::UnknownFile();
	}
	while (std::getline(file, line))
		this->check_line(line, i++);
}

void							Parser::check_line(std::string line, size_t i)
{
	size_t						c = 0;
	std::vector<std::string>	array;
	std::regex					map_comment("^#.*");
	std::regex					map_value("\\s*\\d+\\s*");

	(void)i;
	if (std::regex_match(line, map_comment))
		return ;
	if (!this->size && std::regex_match(line, map_value))
	{
		if (atoi(line.data()) < 2)
		{
			throw CustomError::WrongSize();
		}
		this->size = atoi(line.data());
		return ;
	}
	if (!this->size)
	{
		throw CustomError::SizeNotSpecified();
	}
	array = this->split(line, " ");
	for (auto elem : array)
	{
		if (std::regex_match(elem, map_value))
		{
			if (this->map.size() >= (this->size * this->size))
			{
				throw CustomError::TooMuchValues();
			}
			this->map.push_back(atoi(elem.data()));
			c++;
		}
		else if (std::regex_match(elem, map_comment))
			break ;
		else
		{
			throw CustomError::SyntaxError();
		}
	}
	if (c != this->size)
	{
		throw CustomError::NumberOfValuesError();
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

std::vector<size_t>				Parser::getMap(void)
{
	return (this->map);
}

size_t							Parser::getSize(void)
{
	return (this->size);
}
