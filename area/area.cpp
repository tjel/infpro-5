# include <iostream>

using namespace std;

int main( ) 
{ 
    float PI = 3.141592;                // variables can be initialized during declaration 
    double rad; 
    for(;;)
	{
		cout<< "\nEnter the radius - "; 
		cin>>rad; 
		if(!(rad<0))
			break;
		else
			cout<<" R is smaller than 0 ";
	}
    cout<< "\nArea of the circle is "<< PI * rad * rad<<endl; 
    return 0;
}  
