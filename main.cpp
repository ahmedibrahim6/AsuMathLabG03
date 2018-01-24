
#include "CMatrix.h"

void string_parsing(string s)

{
	char* buffer = new char[s.length()+1]; 
strncpy(buffer,s.c_str(),s.length()+1);
	//cout<<buffer<<endl;
	delete[] buffer;

}

bool is_one_line(string s)
{
	int open_bracket_count=0;
	int close_bracket_count=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='[')
			open_bracket_count++;

	}	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==']')
			close_bracket_count++;

	}	
	//cout<<open_bracket_count<<close_bracket_count<<endl;
	if(close_bracket_count==open_bracket_count)
		return true;
	else
		return false;

}



int main(int argv,char* argc[])			// argv : number of parameter in the command .....argc : the parameters as strings
{
	map < char , CMatrix >  mymap;          // a map relates every defined character as matrix with its data as CMatrix data type
	string  Matrix_String;		 
	string s1,s2;
	
	 	
if(argv>1)			// ensure that the file path added
	{
	
		ifstream infile(argc[1]);		// open the file whose path included in argc[1]
	
	

	
		while (getline(infile,s1))                       //  read every line in string s1
		{
			//while(s1=="")	getline(infile,s1);
			
			
			if(s1.find('[')!=-1 )                   // if this line contains matrix declaration 
			{
				//int brackets[2];
				bool one_line = is_one_line(s1);


				if(one_line)            // if the declaration in one line only we work on s1
				{
					//string_parsing(s1);




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
					cout<<s1<<endl;
				}
				else                     //  if the declaration in more than one line 
				{
					do{
					getline(infile,s2);
					string s3='\n'+s2;
					s1.replace(s1.length()-1,1,s3);
					}while (!is_one_line(s1));
					for (int i=0;i<s1.length();i++)
					cout<<s1[i];
				
/*
					 
					        cout<<s1<<endl;
					         cout<<s2<<endl;// we get the second line until ']'. store it in s2 
							string s3;
					for (int i=0;i<s1.length()-1;i++)
						s3[i]=s1[i];
					//and add it to the first line (s1)
					string s4=s3+s2;
					cout<<s4<<endl;
					//char d[s1.length()+s2.length()+2];
					//cout<<s3<<endl;
					//string_parsing(s2);
*/

					
					Matrix_String=s1.substr(s1.find('['),s1.length()-s1.find('['));
					
					for(int i=0;i<s1.length(); i++)                   
		    		{
						if(s1[i]==' '||s1[i]=='\n'||s1[i]=='\r')                  // we skip spaces and newlines

							continue;

						else
						{
							mymap.insert( pair < char , CMatrix > (s1[i],CMatrix(Matrix_String)));   //insert new matrix
							cout<<s1[i]<<" ="<<endl<<mymap[s1[i]].getString()<<endl<<endl;		 //print this matrix
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
                                                int mid =s1.find(",",first+1) ;
						if(mid!=-1 )
                                                {
						   int last=s1.find(")",mid+1);
						   string First=s1.substr(first+1,mid-first-1);
						   string Second=s1.substr(mid+1,last-mid-1);
						   int N1=atoi(First.c_str());
						   int N2=atoi(Second.c_str());
						   if (N1==0 || N2==0)
						   {
						 	   cout<<operations[0]<<" ="<<endl<<"[] "<<"("<<N1<<"*"<<N2<<")"<<endl;
							   break;
						   }
						   else
						   {
							   mymap[operations[0]]=mymap[operations[0]].ones(N1,N2);
							   cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							   break;
						   }
                                                }
                                                else 
                                                {
                                                   int last=s1.find(")",first+1);
                                                   string Number=s1.substr(first+1,last-first-1);
						   int number=atoi(Number.c_str());
						   if (number==0 || (first+1 == last))
						   {
							   cout<<operations[0]<<" ="<<endl<<"[] "<<"(0*0)"<<endl;
							   break;
						   }
						   else
						   {
						       	   mymap[operations[0]]=mymap[operations[0]].ones(number);
							   cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							   break;
						   }
                                                }
					}


                    if(int x=s1.find("eye")!=-1)
					{	
						int first=s1.find("(",x+1);
                                                int mid=s1.find(",",first+1);
						if(mid !=-1 )
                                                {
						   int last=s1.find(")",mid+1);
						   string First=s1.substr(first+1,mid-first-1);
						   string Second=s1.substr(mid+1,last-mid-1);
						   int N1=atoi(First.c_str());
						   int N2=atoi(Second.c_str());
						   if (N1==0 || N2 ==0)
						   {
						 	   cout<<operations[0]<<" ="<<endl<<"[] "<<"("<<N1<<"*"<<N2<<")"<<endl;
							   break;
						   }
						   else
						   {
							   mymap[operations[0]]=mymap[operations[0]].eye(N1,N2);
							   cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							   break;
						   }
                                                }
                                                else 
                                                {
                                                   int last=s1.find(")",first+1);
                                                   string Number=s1.substr(first+1,last-first-1);
						   int number=atoi(Number.c_str());
						   if (number==0 || (first+1 == last))
						   {
							   cout<<operations[0]<<" ="<<endl<<"[] "<<"(0*0)"<<endl;
							   break;
						   }
						   else
						   {
						       	   mymap[operations[0]]=mymap[operations[0]].eye(number);
							   cout<<operations[0]<<" ="<<endl<<mymap[operations[0]].getString()<<endl;
							   break;
						   }
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
								   	mymap[operations[0]]= (it1->second).elediv() ;
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



			else if ((s1.length()==2))//||(s1.length()==1))
			{
				map<char,CMatrix>::iterator it1;
				it1 =mymap.find(s1[0]);
				cout<<(it1->second)<<endl;
				
				/*map<char,CMatrix>::iterator it1;
				int flag =0;
				for(int i=0;i<s1.length(); i++)                   
		    		{
						if(s1[i]==' '||s2[i]=='\n'||s2[i]=='\r')             // we skip spaces and newlines
		    				
							continue;

						else
						{
							it1 =mymap.find(s1[i]);
							cout<<(it1->second)<<endl;
							break;
						}
					}
*/
			}
		
		}
	

	 infile.close();             // close the file 

    }

else			// if the file path not added as a parameter close the program

	{cout<<"The file path not added . The program closed "<<endl;}

return 0;

}

















