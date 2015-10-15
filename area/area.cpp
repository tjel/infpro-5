#include <iostream>
#include <cmath>

int main( ) 
{              
    double rad; 
    while(1)
    {
	std::cout<< "\nEnter the radius - "; 
	std::cin>>rad; 
	if(!(rad<0))
	     break;
	else
	     std::cout<<"R is smaller than 0 ";
    }
    std::cout<< "\nArea of the circle is "<< M_PI * rad * rad<<std::endl; 
    return 0;
}  
