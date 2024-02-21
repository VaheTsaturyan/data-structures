#include <iostream>
#include "myList.h"


int main(){
	myList<int> a;
	a.push_back(5);
	a.push_back(10);
	a.push_back(20);
	std::cout << a[2] << std::endl;

	return 0;
}
