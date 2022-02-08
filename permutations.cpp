#include <experimental/filesystem>
#include <iostream>
#include <string>

#include "parsing.h"

int main(){
	unsigned int permutations=1;
	std::string path;
	std::experimental::filesystem::path placements{"placements"};
	for (auto dir_entry : std::experimental::filesystem::directory_iterator{placements}) 
	{
		std::cout<<"Permutations: "<<permutations<<std::endl;
		path=dir_entry.path().string();
		unsigned int possibilities=filetoset(path).size();
		std::cout<<"Possibilities in "<<dir_entry<<": "<<filetoset(path).size()<<std::endl;
		permutations = permutations * possibilities;
	}
}
