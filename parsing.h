//Here we read the files into sets and write the sets into files
#ifndef PARSING_H
#define PARSING_H

#include <set>
#include <fstream>
#include <iostream>
#include <iterator>

void printset(std::set<unsigned int> myset){
	for (std::set<unsigned int>::iterator it = myset.begin(); it != myset.end(); it++)
		std::cout << *it << std::endl;
}

void prot(std::set<unsigned int> &seti, std::string where=""){
	if (seti.size()==1)
		throw std::runtime_error("About to erase a set of size 1\n"+where);
}

std::set<unsigned int> filetoset(std::string path){
	std::ifstream placement(path);
	if(!placement.is_open()) throw std::runtime_error("Could not open file");
	
	std::string line;
	std::set<unsigned int> setinit;
	while (std::getline(placement,line)){
		setinit.insert(atoi(line.c_str()));
	}
	return setinit;
}

void settofile(std::string path, std::set<unsigned int> possibilities){
	std::ofstream output_file(path);
	std::ostream_iterator<unsigned int> output_iterator(output_file, "\n");
	std::copy(possibilities.begin(), possibilities.end(), output_iterator);
}
#endif
