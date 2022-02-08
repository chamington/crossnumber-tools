#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <set>

#include <stdlib.h>
#include <math.h>
//Parses board.csv and creates csv's for all possible answers for all placements

std::string remws(std::string str)//removes whitespace that is from csv shit
{
	std::string remstr="";
	for (unsigned int i=0; str[i]!='\0'; i++){
		if(str[i]>='0' && str[i]<='~')
			remstr.push_back(str[i]);
	}
	return remstr;
}

std::set<unsigned int> setinit(unsigned int digits) //creates a set of initial possibilities with the digits
	//for example with 2 digits you get a set from 10-99, 3 digits 100-999, yknow
{
	std::set<unsigned int> initset;
	for (unsigned int i=pow(10,digits-1); i<pow(10,digits); i++){
		initset.insert(i);
	}
	return initset;
}

void create_csv(std::string line)
{
	std::stringstream ss(line);
	std::string substr;
	getline(ss,substr, ',');
	std::string filename = remws(substr);
	getline(ss,substr, ',');
	unsigned int digits = std::stoi(remws(substr));
	
	std::set<unsigned int> possibilities = setinit(digits);
	std::ofstream output_file("./placements/"+filename);
	std::ostream_iterator<unsigned int> output_iterator(output_file, "\n");
	std::copy(possibilities.begin(), possibilities.end(), output_iterator);
}
int main( int argc, char* argv[] )
{
	std::ifstream board("board.csv");
	if(!board.is_open()) throw std::runtime_error("Could not open file");
	std::string line;
	while (std::getline(board,line)){
		create_csv(line);
	}
}
