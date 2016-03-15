#include <cstdlib>    
#include <iostream>    
   
#include "arrList.h"    
    
using namespace std;   
   
int main(int argc, char *argv[]){
	arrList<int> a(10);
	
	for(int i = 1; i <= 10; i++){
//		a.insert(i-1,i*2);
        a.append(i*2);
	}
    
	a.print();
	cout<<a.getPos(14)<<"\n";
	a.insert(2,9);
	a.print();
	a.del(5);
	a.print();
	return 0;
}   
