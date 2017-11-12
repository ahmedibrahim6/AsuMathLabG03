
#include "CMatrix.h"
#include <fstream>



int main(int argv,char* argc[]) // argv   :   number of strings separated by spaces in command line . 
				// argc[] :   content of each string . 
				// argv will be the number of strings pointed to by argc.
				// This will (in practice) be 1 plus the number of arguments,
				// as virtually all implementations will prepend the name of the program to the array.
				
	
{
	
	 if(argv>1)
		 
        {
		 
                cout<<argc[1]<<endl;
                 

                string s;
                ifstream infile(argc[1]);
                
                while(getline(infile, s))
				{
					cout<<s<<endl;




				// we now have the first line in the input file
				// we should discover the instruction that the line points to . then, send it to the functions 
				//of the CMatrix class to make our calculations.



					


				}


                infile.close();
                cout<<endl;
        }


        return 0;
}
/*
	CMatrix A=4;
	A = " [ 2.0 4.0 4.0 ;2.0 2.0 5.0 ; 6.0 4.0 4.0 ]"  ;
	
	CMatrix B(3, 3, 1.0, 1.0, 2.0, 2.0, 3.0, 4.0, 2.0, 4.0, 3.0), C=1.5;
	CMatrix D(3, 2, 1.0, 2.0, 1.0, 2.0, 1.0, 2.0), E(3, 1, 5.0, 6.0, 2.0);
	try {
		C = A - C;
	}
	catch(char* error)
	{
		cout << error << endl;
	}
	try {
		D = D*E;
	}
	catch(char* error)
	{
		cout << error << endl;
	}
	try {
		D = D/E;
	}
	catch(char* error)
	{
		cout << error << endl;
	}
	C.PrintMatrix();
	A = B + A;
	A.PrintMatrix();
	D.PrintMatrix();
	D=A*D;
	D.PrintMatrix();
	CMatrix trialA(2,2, 6.0,2.0,3.0,2.0);
	CMatrix trialB(2,2, 6.0,-4.0,2.0,1.0);
	CMatrix result(2,2,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);
	result=trialB/trialA;
	result.PrintMatrix();
	CMatrix gg;
	string x;
	cout<<"enter matrix dimension as [  ;  ]";
	getline(cin,x);
	gg=x;
	gg.PrintMatrix();
	string y;
	y=result.getString();
	cout<<y<<endl;
}
