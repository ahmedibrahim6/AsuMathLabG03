
#include "CMatrix.h"






int main(int argv,char* argc[])			// argv : number of parameter in the command .....argc : the parameters as strings
{
	map < char , CMatrix >  mymap;          // a map relates every defined character as matrix with its data as CMatrix data type
	string s1,s2, Matrix_String;		 
	
	
	 	
if(argv>1)			// ensure that the file path added
	{
	
		ifstream infile(argc[1]);		// open the file whose path included in argc[1]
	
	

	
		while (getline(infile,s1))                       //  read every line in string s1
		{
			if(s1.find('[')!=-1 )                   // if this line contains matrix declaration 
			{
				if(s1.find(']')!=-1)            // if the declaration in one line only we work on s1
				{

					Matrix_String=s1.substr(s1.find('['),s1.length()-s1.find('['));   // have the string from '[' to ']'

					for(int i=0;i<s1.length(); i++)                    // to store the names of matrix
		     		{
						if(s1[i]==' ')//||s[i]=='\n'||s[i]=='\r')                  // we skip spaces 

							continue;

			 			else
			 			{
							mymap.insert( pair < char , CMatrix > (s1[i],CMatrix(Matrix_String)));           // insert new matrix 
							cout<<s1[i]<<" ="<<endl<<mymap[s1[i]].getString()<<endl<<endl;                   // print this matrix with its data
							break;          
			 			}
					}
				}
				else                      //  if the declaration in more than one line 
				{
			
					getline(infile,s2,']');          // we get the second line until ']'. store it in s2 
					s2=s1+s2+']';			//and add it to the first line (s1)
					Matrix_String=s2.substr(s2.find('['),s2.length()-s2.find('['));
					
					for(int i=0;i<s2.length(); i++)                   
		    		{
						if(s2[i]==' '||s2[i]=='\n'||s2[i]=='\r')                  // we skip spaces and newlines

							continue;

						else
						{
							mymap.insert( pair < char , CMatrix > (s2[i],CMatrix(Matrix_String)));   //insert new matrix
							cout<<s2[i]<<" ="<<endl<<mymap[s2[i]].getString()<<endl<<endl;		 //print this matrix
							getline(infile,s1);                              // skip the rest of the last line of the matrix declaration
							//if(s1.find(';')!=-1)                  
							break;
						}

				
					}	
		

				}

			}
			
		
			else if(s1.find('=')!=-1)                      // if this line contains an operation
			{

			
				vector<char> operations;       // this variable will hold the chars in one operation  like : C=A+B
				//char operations[6];
				map<char,CMatrix>::iterator it1;           // iterator that iterates over the map to find the desired value(CMatrix) of a certain key(char)
				map<char,CMatrix>::iterator it2;           // iterator to find the CMatrix of the second operand

				
				for(int i=0; i<s1.length(); i++)
				{ 
					if(s1[i]==' '||s1[i]=='\n'||s1[i]=='\r')              //removing spaces and newlines

						continue;
					else
					{
						operations.push_back(s1[i]);               //storing chars in the vector operations
					}
				}


				for(int i=0;i<operations.size();i++)        // loop over the chars in one operation to find the operator (+or-..)
				{
					if(int x=s1.find("zeros")!=-1)
					{	
						int first=s1.find("(",x+1);
						int mid=s1.find(",",first+1);
						int last=s1.find(")",mid+1);
						string First=s1.substr(first+1,mid-first-1);
						string Second=s1.substr(mid+1,last-mid-1);
						first=atoi(First.c_str());
						last=atoi(Second.c_str());
						if (first==0 || last ==0)
						{
							cout<<operations[0]<<" ="<<endl<<"[] "<<"("<<first<<"*"<<last<<")"<<endl;
							break;
						}
						else
						{
							mymap[operations[0]]=mymap[operations[0]].zeros(first,last);
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							break;
						}
					}

					if(int x=s1.find("rand")!=-1)
					{
						int first=s1.find("(",x+1);
						int mid=s1.find(",",first+1);
						int last=s1.find(")",mid+1);
						string First=s1.substr(first+1,mid-first-1);
						string Second=s1.substr(mid+1,last-mid-1);
						first=atoi(First.c_str());
						last=atoi(Second.c_str());
						if (first==0 || last ==0)
						{
							cout<<operations[0]<<" ="<<endl<<"[] "<<"("<<first<<"*"<<last<<")"<<endl;
							break;
						}
						else
						{
							mymap[operations[0]]=mymap[operations[0]].random(first,last);
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							break;
						}
					}	

					if(int x=s1.find("ones")!=-1)
					{	
						int first=s1.find("(",x+1);
						int mid=s1.find(",",first+1);
						int last=s1.find(")",mid+1);
						string First=s1.substr(first+1,mid-first-1);
						string Second=s1.substr(mid+1,last-mid-1);
						first=atoi(First.c_str());
						last=atoi(Second.c_str());
						if (first==0 || last ==0)
						{
							cout<<operations[0]<<" ="<<endl<<"[] "<<"("<<first<<"*"<<last<<")"<<endl;
							break;
						}
						else
						{
							mymap[operations[0]]=mymap[operations[0]].ones(first,last);
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							break;
						}
					}


                                        if(int x=s1.find("eye")!=-1)
					{	
						int first=s1.find("(",x+1);
						int mid=s1.find(",",first+1);
						int last=s1.find(")",mid+1);
						string First=s1.substr(first+1,mid-first-1);
						string Second=s1.substr(mid+1,last-mid-1);
						first=atoi(First.c_str());
						last=atoi(Second.c_str());
						if (first==0 || last ==0)
						{
							cout<<operations[0]<<" ="<<endl<<"[] "<<"("<<first<<"*"<<last<<")"<<endl;
							break;
						}
						else
						{
							mymap[operations[0]]=mymap[operations[0]].eye(first,last);
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							break;
						}
					}

					//switch(operations[i])
					if (operations[i]=='+')
					{
						//case '+' :
						try                   
						{
							it1 =mymap.find(operations[i-1]);      //find the CMatrix of the first operand 
			 				it2 =mymap.find(operations[i+1]);      //find the CMatrix of the second operand
							mymap[operations[0]]= (it1->second) + (it2->second) ;       // store the result in new matrix or override on existed matrix
							cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;    // print the name of matrix and result 
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
						
						char o=operations[i+1];
						int first=s1.find(operations[i+1],0);
						int start=s1.find("(",first+1);
						string number;
						if (start==-1)
						{
							number=s1.substr(first+1,s1.size()-first-1);
						}			
						else 
						{
							int end=s1.find(")",first+1);
							number=s1.substr(start+1,end-start-1);
						}
						double Num=atof(number.c_str());
						int find= number.find("0");
						int y =((Num==0) &&(find==-1))? 1 :0;
						
						switch (o)
						{
							case '-': it1 =mymap.find(operations[i-1]);
						   		  mymap[operations[0]]= (it1->second).elesub(Num) ;
						     		  cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
								  break;

							case '^': it1 =mymap.find(operations[i-1]);
								  mymap[operations[0]]= (it1->second).elepow(Num) ;
								  cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
								  break;

							case '/':  
								   if (y==1)
								   	{
								   	it1 =mymap.find(operations[i+2]);
								   	mymap[operations[0]]= (it1->second).eledive() ;
								   	cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
								   	}
								   else 
									{
									it1 =mymap.find(operations[i-1]);
									mymap[operations[0]]= (it1->second).elediv(Num) ;
								   	cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
									}
								   
								   break;

							case '+':  it1 =mymap.find(operations[i-1]);
								   mymap[operations[0]]= (it1->second).eleadd(Num) ;
								   cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
								   break;

							case '*':  it1 =mymap.find(operations[i-1]);
								   mymap[operations[0]]= (it1->second).elemul(Num) ;
								   cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
								   break;
						}
						
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

	 infile.close();             // close the file 

    }

else			// if the file path not added as a parameter close the program

	{cout<<"The file path not added . The program closed "<<endl;}

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
