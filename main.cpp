
#include<iostream>
using namespace std;

#include"CMatrix.h"
int main()
{
	
	CMatrix A(3, 3, 2.0, 4.0, 4.0, 2.0, 2.0, 5.0, 6.0, 4.0, 4.0), B(3.0, 3.0, 1.0, 1.0, 2.0, 2.0, 3.0, 4.0, 2.0, 4.0, 3.0), C=1.5;

	try {
		C = A - C;
	}
	catch(char* error)
	{
		cout << error << endl;
	}
	C.PrintMatrix();
	/*A = B + A;
	A.PrintMatrix();*/

}