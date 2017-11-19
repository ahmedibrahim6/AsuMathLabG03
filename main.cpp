
#include "CMatrix.h"
#include <vector>





int main(int argv,char* argc[])
{
	map < char , CMatrix >  mymap;
	int count=0;                                     // count is to store the number of matrices entered ....
	string s1,s2, Matrix_String;
	char name;
	int counter=0;                                
	int row=0;    
	 	
if(argv>1)
	{
	
		ifstream infile(argc[1]);						// the path of file to read from test is example and test2 is bigexample
	
	

	
		while (getline(infile,s1))                       //  here it is less than 2 to read A & B
		{
			if(s1.find('[')!=-1 )
			{
				if(s1.find(']')!=-1)
				{

					Matrix_String=s1.substr(s1.find('['),s1.length()-s1.find('['));

					for(int i=0;i<s1.length(); i++)                    // to store the names
		     		{
						if(s1[i]==' ')//||s[i]=='\n'||s[i]=='\r')                  // we skip spaces and newlines

							continue;

			 			else
			 			{
							mymap.insert( pair < char , CMatrix > (s1[i],CMatrix(Matrix_String)));
							cout<<s1[i]<<" ="<<endl<<mymap[s1[i]].getString()<<endl<<endl;                   // and store the first char ie. A or B
							break;
			 			}
					}
				}
				else
				{
			
					getline(infile,s2,']');
					s2=s1+s2+']';
					Matrix_String=s2.substr(s2.find('['),s2.length()-s2.find('['));
					for(int i=0;i<s2.length(); i++)                    // to store the names
		    		{
						if(s2[i]==' '||s2[i]=='\n'||s2[i]=='\r')                  // we skip spaces and newlines

							continue;

						else
						{
							mymap.insert( pair < char , CMatrix > (s2[i],CMatrix(Matrix_String)));// and store the first char ie. A or B
							cout<<s2[i]<<" ="<<endl<<mymap[s2[i]].getString()<<endl<<endl;
							getline(infile,s1);
							//if(s1.find(';')!=-1)                  
							break;
						}

				
					}	
		

				}

			}
			
		
			else if(s1.find('=')!=-1)
			{

			
				vector<char> operations; 
				//char operations[6];
				map<char,CMatrix>::iterator it1;
				map<char,CMatrix>::iterator it2;

				int column=0;
				for(int i=0; i<s1.length(); i++)
				{ 
					if(s1[i]==' '||s1[i]=='\n'||s1[i]=='\r')              //removing spaces and newlines

						continue;
					else
					{
						operations.push_back(s1[i]);               //storing chars in the array
						column++;
					}
				}


				for(int i=0;i<operations.size();i++)
				{

					//switch(operations[i])
					if (operations[i]=='+')
					{
						//case '+' :
						try
						{
							it1 =mymap.find(operations[i-1]);
			 				it2 =mymap.find(operations[i+1]);
							mymap[operations[0]]= (it1->second) + (it2->second) ;
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
						}
						catch(const char* error) {cout<<" Error : "<<error<<endl;}
				
					}

					else if(operations[i]=='-')
						//case '-' :
					{
						try
						{
			 				it1 =mymap.find(operations[i-1]);
			 				it2 =mymap.find(operations[i+1]);
							mymap[operations[0]]= (it1->second) - (it2->second) ;
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
						}
						catch(const char* error) {cout<<" Error : "<<error<<endl;}
				

					}

					else if(operations[i]=='*')
						//case '*' :
					{
						try
						{
			 				it1 =mymap.find(operations[i-1]);
			 				it2 =mymap.find(operations[i+1]);
							mymap[operations[0]]= (it1->second) * (it2->second) ;
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
						}

						catch(const char* error) {cout<<" Error : "<<error<<endl;}
						
					}
			
			
					else if(operations[i]=='/')
						//case '/' :
					{
						try
						{
			 				it1 =mymap.find(operations[i-1]);
			 				it2 =mymap.find(operations[i+1]);
							mymap[operations[0]]= (it1->second) / (it2->second) ;
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
						}

						catch(const char* error) {cout<<" Error : "<<error<<endl;}

					}
		

					else if(operations[i]=='.')
					{
						//case '.' :
						//try{
						it1 =mymap.find(operations[i+2]);
						mymap[operations[0]]= (it1->second).elediv() ;
						cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
						//}
						//catch(const char* error)
						//{cout<<" Error : "<<error<<endl;}
						break;
					}
			
			
					else if(operations[i]=='\'')
					{
						//case '\'' :
						//try{
			 			it1 =mymap.find(operations[i-1]);
						mymap[operations[0]]= (it1->second).transpose() ;
						cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
		    			//}
						//catch(const char* error)
						//{cout<<" Error : "<<error<<endl;}
						break;
					}
		  
				}

			}
		
		}

	 infile.close();

    }

else

	{cout<<"The file path not added"<<endl;}

return 0;

}







/*
		getline(infile,s,'[');
		s+=']';
		//Matrix_String=stringtrim(s);
		Matrix_String=s.substr(s.find('['),s.length()-s.find('['));              // get matrix string as [....;....;...]
		//cout<<Matrix_String<<endl;
		Mnames[count]=Matrix_String;               //store matrix in the array

		for(int i=0;i<s.length(); i++)                    // to store the names
		{
			if(s[i]==' '||s[i]=='\n'||s[i]=='\r')                  // we skip spaces and newlines
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

	while ( getline(infile,s))                         
	{
		

	}
	
*/
/*
	for (int i=0; i<counter; i++)
	{
		names[count]=operations[i][0];                    //store the first elements in operation in the names array ie. CDEFGH
		count++;
	}


	/////////////////////////////////////////////
	
	cout<<endl<<names[0]<<'='<<endl;
	cout<<Mnames[0].getString()<<endl<<endl; 
	
	cout<<names[1]<<'='<<endl;
	
	cout<<Mnames[1].getString()<<endl<<endl;
	
	
	
	////////////////////////////////////////

	/*for (int i=0;i<count;i++)           //  to print the array of names 
		cout<<names[i];
	*/	
//try{
/*
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
								try{
									if (operations[i][0]==names[z])      // get the element before =   z
									{
										Mnames[z]=Mnames[x]+Mnames[y];       // add x and y then store result in z
										cout<<operations[i][0]<<"="<<endl;
										//Mnames[z].PrintMatrix();
										cout<<Mnames[z].getString();
									}
								}
								catch(const char* error){cout<<endl<<"Error : "<<error<<endl;}


			}
			else if (operations[i][j]=='-')                     ///// same for all operations
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])
								for (int z=0; z<count;z++)
								try{
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x]-Mnames[y];
										cout<<operations[i][0]<<"="<<endl;
										//Mnames[z].PrintMatrix();
										cout<<Mnames[z].getString();
									}
								}
								catch(const char* error){cout<<endl<<"Error : "<<error<<endl;}
			}
			else if (operations[i][j]=='*')
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])
								for (int z=0; z<count;z++)
								try{
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x]*Mnames[y];
										cout<<operations[i][0]<<"="<<endl;
										cout<<Mnames[z].getString();
										//Mnames[z].PrintMatrix();
									}
								}
								catch(const char* error){cout<<endl<<"Error : "<<error<<endl;}
			}
			else if (operations[i][j]=='/')                                //put this else and the code inside it in a comment and the rest of the code runs correctly
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						for(int y=0;y<count;y++)
							if (operations[i][j+1]==names[y])
								for (int z=0; z<count;z++)
								try{
									if (operations[i][0]==names[z])
									{
										//cout<<Mnames[y].getDeterminant()<<endl;
										//if(Mnames[y].getDeterminant()==0)
										//{
										//	cout<<"can't devide . Determinant is zero"<<endl;
										//break;}
										//else{
										Mnames[z]=Mnames[x]/Mnames[y];     // doesn't work in big example and code stops here,why? (Dimensions are correct)
										cout<<operations[i][0]<<"="<<endl;           
										cout<<Mnames[z].getString();
										//Mnames[z].PrintMatrix();
										//}
									}
								}
								catch(const char* w){cout<<endl<<"Error : "<<w<<endl;}

							
			}
			else if (operations[i][j]=='.')
			{
				
						for(int y=0;y<count;y++)
							if (operations[i][j+2]==names[y])
								for (int z=0; z<count;z++)
								//try{
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[y].elediv();
										cout<<operations[i][0]<<"="<<endl;
										//Mnames[z].PrintMatrix();
										cout<<Mnames[z].getString();
									}
								//}
								//catch(const char* error){cout<<endl<<"Error : "<<error<<endl;}
			}
			else if (operations[i][j]=='\'')
			{
				for(int x=0;x<count;x++)
					if (operations[i][j-1]==names[x])
						
								for (int z=0; z<count;z++)
								//try{
									if (operations[i][0]==names[z])
									{
										Mnames[z]=Mnames[x].transpose();
										cout<<operations[i][0]<<"="<<endl;
										cout<<Mnames[z].getString();
										//Mnames[z].PrintMatrix();
									}
								//}
								//catch(const char* error){cout<<endl<<"Error : "<<error<<endl;}
			}

		}

		cout<<endl;
	}

//}
//catch(const char* w)
//{	cout<<endl<<endl<<s<<endl;}

	infile.close();
}
else
{cout<<"The file path not added"<<endl;}

        return 0;
	}
	

*/













/*
int main(){
	map < char , CMatrix >  my_map;


	my_map.insert( pair < char , CMatrix > ('A',CMatrix("[2.3 2.7;7.6 4.5]")));
	my_map.insert( pair < char , CMatrix > ('B',CMatrix("[2.3 2.7;7.6 4.5;1.3 22.4]")));
	my_map.insert( pair < char , CMatrix > ('C',CMatrix("[2.53 2.37;73.6 5.5]")));


	//cout<<my_map.size()<<endl;
try{
	cout<<(my_map['A']+my_map['B']).getString()<<endl;
}
catch(const char* error)
{cout<<"error : "<<error<<endl;}
	//map<char,CMatrix>::iterator it =my_map.begin();
	//cout<<(it->first)<<endl<<((it->second).getString())<<endl;


	//string s="[2.0 4.0;6.0 1.0]";
	//CMatrix x=CMatrix(s);
	//cout<<x.getString()<<endl;
	



	return 0;
}

*/


























/*int x,v=0,index=0;string y;
			string newinstructions;
			while(input.find(']',index)!=-1)
			{v++;

			 x = input.find(']',index);
		   y=input.substr(index,x+1-index);
			somefunction(y);
				index+=(x+1);
				if(v==2)
				newinstructions=input.substr(index,input.length()-1-index);

			}
			
			
			
			cout<<newinstructions<<endl;





		*/