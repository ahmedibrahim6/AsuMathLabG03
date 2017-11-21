#include <string>
#include<iostream>
#include <fstream>
using namespace std;

#include"CMatrix.h"

string stringtrim(string a)
{
	string b="[";
	int pos=a.find(b);
	for(int i=0;i<a.length()-pos;i++)
	{
		a[i]=a[i+pos];
	}
	for(int j=a.length()-pos;j<a.length();j++)
	{
		a[j]=NULL;
	}
	return a;
}

int main()
{
	
	/*CMatrix A(3, 3, 2.0, 4.0, 4.0, 2.0, 2.0, 5.0, 6.0, 4.0, 4.0), B(3, 3, 1.0, 1.0, 2.0, 2.0, 3.0, 4.0, 2.0, 4.0, 3.0), C=1.5;
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
	*/
	char names[100];
	CMatrix Mnames [100];
	int count=0;                                     // count is to store the number of matrices entered ....
	string s, Matrix_String;

	ifstream infile("D:\\test.txt");    // the path of file to read from test is example and test2 is bigexample

	while (count<2)                       //  here it is less than 2 to read A & B
	{
		getline(infile,s,']');
		s+=']';
		Matrix_String=stringtrim(s);              // get matrix string as [....;....;...]
		//cout<<Matrix_String<<endl;
		Mnames[count]=Matrix_String;               //store matrix in the array

		for(int i=0;i<s.length(); i++)                    // to store the names
		{
			if(s[i]==' '||s[i]=='\n')                  // we skip spaces and newlines
				continue;
			else
			{
				names[count]=s[i];                   // and store the first char ie. A or B
				break;
			}

				
		}
		count++;                                      // increment count to signal a matrix is read
		getline(infile,s);                           // extra getline to remove trailing newlines
	

	}

	int counter=0;                                   // counter is to get number of operations entered
	char operations[12][6];                           // 2d array to store operations as char
	int row=0;
	while ( getline(infile,s))                         
	{
		int column=0;
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]==' '||s[i]=='\n'||s[i]=='\r')              //removing spaces and newlines
				continue;
			else
			{
				operations[row][column]=s[i];               //storing chars in the array
				column++;
			}
		}
		counter++;                                         //increment counter to count the number of operations entered
		row++;

	}
	

	for (int i=0; i<counter; i++)
	{
		names[count]=operations[i][0];                    //store the first elements in operation in the names array ie. CDEFGH
		count++;
	}


	/////////////////////////////////////////////
	
	cout<<names[0]<<'=';
	Mnames[0].PrintMatrix(); 
	cout<<names[1]<<'=';
	Mnames[1].PrintMatrix();
	
	////////////////////////////////////////

	for (int i=0;i<count;i++)           //  to print the array of names 
		cout<<names[i];

	for (int i=0; i<12;i++)                    // for loop to pass on array of operations
	{
		for (int j=0;j<6; j++)
		{
			if (operations[i][j]=='+')
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])           // get the element before the +    x
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])    // get the element after the +    y
								for (int z=0; z<count;z++)
									if (operations[i][0]==names[z])      // get the element before =   z
									{
										Mnames[z]=Mnames[x]+Mnames[y];       // add x and y then store result in z
										cout<<operations[i][0]<<"=\t";
										cout<<Mnames[z].getString();
									}



			}
			else if (operations[i][j]=='-')                     ///// same for all operations
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])
								for (int z=0; z<count;z++)
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x]-Mnames[y];
										cout<<operations[i][0]<<"=\t";
										cout<<Mnames[z].getString();
									}
			}
			else if (operations[i][j]=='*')
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])
								for (int z=0; z<count;z++)
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x]*Mnames[y];
										cout<<operations[i][0]<<"=\t";
										cout<<Mnames[z].getString();
									}
			}
			else if (operations[i][j]=='/')                                //put this else and the code inside it in a comment and the rest of the code runs correctly
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])
								for (int z=0; z<count;z++)
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x]/Mnames[y];     // doesn't work in big example and code stops here,why? (Dimensions are correct)
										cout<<operations[i][0]<<"=\t";           
										Mnames[z].PrintMatrix();
									}
			}
			else if (operations[i][j]=='.')
			{
				
						for(int y=0;y<count;y++)
							if (operations[i][j+2]==names[y])
								for (int z=0; z<count;z++)
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[y].elediv();
										cout<<operations[i][0]<<"=\t";
										cout<<Mnames[z].getString();
									}
			}
			else if (operations[i][j]=='\'')
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						
								for (int z=0; z<count;z++)
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x].transpose();
										cout<<operations[i][0]<<"=\t";
										cout<<Mnames[z].getString();
									}
			}

		}

		cout<<endl;
	}

	infile.close();
}
