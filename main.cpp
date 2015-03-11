// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 11:40:04 by mbar              #+#    #+#             //
//   Updated: 2015/03/09 16:35:31 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"
#include "Resolve.hpp"

int						main(int argc, char **argv)
{
	Parser				Parser;

	if (argc != 2)
		return (-1);
	Parser.check_input(argv[1]);

	Resolve				Resolve(Parser.getMap(), Parser.getSize());

	Resolve.launch();

	return (0);
}
