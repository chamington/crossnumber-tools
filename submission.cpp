//Should sum the answers to the across clues

#include <experimental/filesystem>
#include <iostream>
#include <string>

#include "parsing.h"

int main(){
	std::string path;
	std::set<unsigned int> pos;

	unsigned int sum=0;

	std::experimental::filesystem::path placements{"placements"};
	for (auto dir_entry : std::experimental::filesystem::directory_iterator{placements}){
		path=dir_entry.path().string();
		if (path.back()=='A'){
			pos=filetoset(path);
			if (pos.size()!=1)
				throw std::runtime_error("Must have 1 solution for each across");
			std::cout<<"Path: "<<path<<std::endl<<"Solution "<<*(pos.begin())<<std::endl;
			sum+=*(pos.begin());
		}
	}
	std::cout<<std::endl<<"Sum: "<<sum<<std::endl;
}
