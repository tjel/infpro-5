# include <iostream>
# include <math.h>
using namespace std;

int main( ) 
<<<<<<< HEAD
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
=======
{                 // variables can be initialized during declaration 
    float  rad; 
    cout<< "Enter the radius"; 
    cin>>rad; 
    cout<< "Area of the circle is "<<M_PI * rad * rad; 
>>>>>>> d2e5ada4662399bd921376713fe553e873d8b83c
    return 0;
}  
