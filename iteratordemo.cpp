#include "iteratordemo.h"
#include <iostream>

int main(void){
	DList<int> regular;
	DList<int>::const_iterator it;
	DList<int>::iterator it2;
	for(int i=0;i<3;i++){
		regular.push_front(i);
	}

	//2 1 0
	for(it=regular.cbegin();it!=regular.cend();it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	for(it2=regular.begin();it2!=regular.end();it2++){
		*it2+=1;
	}

	//3 2 1
	for(it=regular.cbegin();it!=regular.cend();it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

}