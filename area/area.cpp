# include <iostream>
#include  <math.h>
using namespace std;

int main( ) 
{              
    double rad; 
    while(1)
    {
		cout<< "\nEnter the radius - "; 
		cin>>rad; 
		if(!(rad<0))
			break;
		else
			cout<<" R is smaller than 0 ";
    }
    cout<< "\nArea of the circle is "<< M_PI * rad * rad<<endl; 
    return 0;
}  
