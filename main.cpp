// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 11:40:04 by mbar              #+#    #+#             //
//   Updated: 2015/03/11 13:08:44 by mbar             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"
#include "Resolve.hpp"

int						main(int argc, char **argv)
{
	Parser				Parser;

	if (argc != 2 && argc != 3)
	{
		std::cout << "usage : " << argv[0] << " [-t] [map]" << std::endl;
		return (-1);
	}
	if (argc == 3 && strcmp(argv[1], "-t"))
	{
		std::cout << "usage : " << argv[0] << " [-t] [map]" << std::endl;
		return (-1);
	}

	Parser.check_input(argv[argc - 1]);

	Resolve				Resolve(Parser.getMap(), Parser.getSize());
//	ManhattanHeuristic  man;

//	Resolve.addHeuristic(man);
	if (argc == 3)
		Resolve.setOpt_aff(false);
	Resolve.launch();

	return (0);
}
