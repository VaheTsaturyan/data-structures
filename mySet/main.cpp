#include <iostream>
#include "mySet.h"

using namespace std;

int main(){
	mySet<int> se;
	se.insert(15);
	se.insert(17);
	se.insert(10);
	se.insert(9);
	se.insert(7);
	se.insert(8);
	se.insert(13);
	se.insert(19);
	se.insert(20);
	se.insert(14);
	se.insert(18);
	se.insert(11);
	se.print();
	se.erase(15);
	std::cout<<"rease(15)"<<std::endl;
	se.print();
	std::cout<< "se1\n";
	mySet<int> se1(se);
	se1.print();
	mySet<int> se2;
	se2 = se;
	se.clear();
	std::cout<<"se2\n";
	//se2.print();
	se2.print();
	return 0;
}
