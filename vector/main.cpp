#include <iostream>
#include "vector.h"

int main(){

	my::vector<int> vec;
	vec.push_back(10);
	vec.push_back(11);
	vec.push_back(12);
	vec.push_back(13);
	vec.push_back(14);
	vec.push_back(15);
	vec.push_back(16);
	vec.push_back(17);
	auto it3 = vec.end();
	std::cout<<"=======================================\n";
	my::vector<int>::Iterator it = vec.begin();
	while(it != vec.end())
	{
		std::cout<< *it<<std::endl;
		++it;
	}
	vec.pop_back();
	it = vec.begin();
	std::cout<<"===========================================\n";
	while(it != vec.end())
	{
	std::cout<< *it<<std::endl;
	++it;
	}
return 0;
}