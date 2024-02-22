#include <iostream>

#include "List.h"


int main(){
	my::List<int> lst;
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	//lst.pop_front();
	//lst.pop_back();
	lst.insert(3,10);
	//lst.push_front(10);
	my::List<int>::Iterator it = lst.begin();
	std::cout<<"===================================\n";
	std::cout<<lst.at(3);
	while(it != lst.end()){
		std::cout<<*it<<std::endl;
		++it;
	}

	return 0;	
}