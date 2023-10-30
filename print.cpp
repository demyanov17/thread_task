#include <iostream>
#include <unistd.h>

 
void print_(){
	int k=1;
	for(;;){
	    for (int i=0; i<k; ++i){
	        std::cout <<'*';
	    }
	    k++;
	    std::cout << std::endl;
	    sleep(1);
}}