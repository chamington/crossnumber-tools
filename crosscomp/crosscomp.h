#ifndef CROSSCOMP_H
#define CROSSCOMP_H

#include <string>
#include "../parsing.h"
unsigned int crosscomp(std::string path1, unsigned int digit1, std::string path2, unsigned int digit2){
	//reads possibilities from path, eliminates those that cannot share a digit where crossed
	//returns possibilities eliminated
	unsigned int remPos=0;
	std::set<unsigned int> possibilities1 = filetoset(path1);
	std::set<unsigned int> possibilities2 = filetoset(path2);
	
	bool comp;
	std::set<unsigned int>::iterator itr1=possibilities1.begin();
	std::set<unsigned int>::iterator itr2;
	while (itr1!=possibilities1.end()){
		comp=false;
		itr2=possibilities2.begin();
		while (itr2!=possibilities2.end()){
			if (std::to_string(*itr1)[digit1]==std::to_string(*itr2)[digit2]){
				comp=true;
				itr2=possibilities2.end();
			}
			if (!comp){
				itr2++;
			}
		}
		if (!comp){
			prot(possibilities1,"Almost removed "+std::to_string(*itr1)+" from "+path1);
			possibilities1.erase(itr1);
			std::cout<<"Removed "<<*itr1<<" from "<<path1<<std::endl;
			remPos++;
		}
		itr1++;
	}
	itr2=possibilities2.begin();
	while (itr2!=possibilities2.end()){
		comp=false;
		itr1=possibilities1.begin();
		while (itr1!=possibilities1.end()){
			if (std::to_string(*itr1)[digit1]==std::to_string(*itr2)[digit2]){
				comp=true;
				itr1=possibilities1.end();
			}
			if (!comp){
				itr1++;
			}
		}
		if (!comp){
			prot(possibilities2,"Almost removed "+std::to_string(*itr2)+" from "+path2);
			possibilities2.erase(itr2);
			std::cout<<"Removed "<<*itr2<<" from "<<path2<<std::endl;
			remPos++;
		   }
		   itr2++;
	}
	//printset(possibilities1);
	settofile(path1, possibilities1);
	settofile(path2, possibilities2);
	return remPos;
}

#endif
