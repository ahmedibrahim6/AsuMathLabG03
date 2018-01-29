
#include "CMatrix.h"
map < char , CMatrix >  mymap;          // a map relates every defined character as matrix with its data as CMatrix data type

int  type (string s1,string s2, string A[],int y)
{    int type;
     int t;
	for (int i=0;i<y;i++)
    	{ 
		if (s1==A[i])
		{
    			t=1;	
			for (int j=0;j<y;j++)
			{
				if(s2==A[j])
				{
					t=2;
					break;
				}
			}
			break;
		}
    	}
	if(t!=1||t!=2)
	{
		t=0;
	}
	return t;
 };



//////////////////////////////////////////////////////////GET RESULT////////////////////////////
string Get_Result(string s1)
{
	int flag=0,FirstOperation=0;                                //to count the number of the operations between two brackets ()
	char elements [100]={};                    //contains the operands of the input string * , - , + , / , ^
	int places[100]={};                        //contains the index of each operand 
	string values[100]={};                     //contains all the numbers in the input string in order in string form
	double Values[100]={};					   //contains all the numbers in the input string in order in double form
	double Result;                             //contains the final result of the input string as a double form
	string result;                             //contains the final result of the input string as a string form 
	int j=0;
	int negelement;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='^')
		{
			flag++;
			elements[j]=s1[i];
			places[j]=i;
			if (j==0)
			{
				values[j]=s1.substr(0,i);
				Values[j]=atof(values[j].c_str());
			}
			else
			{
				values[j]=s1.substr(places[j-1]+1,places[j]-places[j-1]-1);
				Values[j]=atof(values[j].c_str());
			}
			j++;
		}
	}
	if (flag==0)
	{
		return s1;
	}
	values[j]=s1.substr(places[j-1]+1,s1.size()-places[j-1]-1);
	Values[j]=atof(values[j].c_str());
	if (s1[0]=='-')
	{
		arrayModification(0,j,Values);
		arrayModification(0,j,elements);
		arrayModification(0,j,places);
		Values[0]*=(-1);
	}
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='^')
		{
			if (FirstOperation==0)
			{
				FirstOperation=1;
			}
			if (elements[i+1]=='-'&&places[i+1]==places[i]+1)
			{
				if (FirstOperation==1)
				{
					s1.erase(places[i+1],1);
				}
				else
				{
					s1.erase(places[i+1]+4,1);
				}
				arrayModification(i+1,j,Values);
				arrayModification(i+1,j,elements);
				arrayModification(i+1,j,places);
				j-=1;
				for (int k = i+1; k < j; k++)
				{
					places[k]-=1;
				}
				if (Values[i+1]>0)
				{
					Values[i+1]*=(-1);
				}
				negelement=1;
			}
			if (i==0)
			{
				Values[i+1]=pow(Values[i],Values[i+1]);
				result=to_string(Values[i+1]);
				if (negelement==1)
				{
					s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}			
				s1.insert(0,result);
				FirstOperation=1;
			}
			else
			{
				Values[i+1]=pow(Values[i],Values[i+1]);
				result=to_string(Values[i+1]);
				if (i+1==j)
				{
					s1.erase(places[i-1]+1,places[i+1]-1);
				}
				else
				{
					s1.erase(places[i-1]+1,places[i+1]+4);
				}
				s1.insert(places[i-1]+1,result);
				arrayModification(i,j,Values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
	}
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='*')
		{
			if (FirstOperation==0)
			{


				FirstOperation=1;
			}		
			if (elements[i+1]=='-'&&places[i+1]==places[i]+1)
			{
				if (FirstOperation==1)
				{
					s1.erase(places[i+1],1);
				}
				else
				{
					s1.erase(places[i+1]+4,1);
				}
				arrayModification(i+1,j,Values);
				arrayModification(i+1,j,elements);
				arrayModification(i+1,j,places);
				j-=1;
				for (int k = i+1; k < j; k++)
				{
					places[k]-=1;
				}
				if (Values[i+1]>0)
				{
					Values[i+1]*=(-1);
				}
				negelement=1;
			}
			if (i==0)
			{
				Values[i+1]=Values[i]*Values[i+1];
				result=to_string(Values[i+1]);
			    if (negelement==1)
				{
					s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{

					s1.erase(0,places[i]+values[i+1].length()+1);
				}
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]*Values[i+1];
				result=to_string(Values[i+1]);
				if (i+1==j)
				{
					s1.erase(places[i-1]+1,places[i+1]+places[i]);
				}
				else
				{
					s1.erase(places[i-1]+1,places[i+1]+places[i]+4);
				}
				s1.insert(places[i-1]+1,result);
				arrayModification(i,j,Values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
		if (elements[i]=='/')
		{
			if (FirstOperation==0)
			{
				FirstOperation=1;
			}
			if (elements[i+1]=='-'&&places[i+1]==places[i]+1)
			{
				if (FirstOperation==1)
				{
					s1.erase(places[i+1],1);
				}
				else
				{
					s1.erase(places[i+1]+4,1);
				}
				arrayModification(i+1,j,Values);
				arrayModification(i+1,j,elements);
				arrayModification(i+1,j,places);
				j-=1;
				for (int k = i+1; k < j; k++)
				{
					places[k]-=1;
				}
				if (Values[i+1]>0)
				{
					Values[i+1]*=(-1);
				}
				negelement=1;
			}
			if (i==0)
			{
				Values[i+1]=Values[i]/Values[i+1];
				result=to_string(Values[i+1]);
				if (negelement==1)
				{
					s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}            
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]/Values[i+1];
				result=to_string(Values[i+1]);
				if (i+1==j)
				{
					s1.erase(places[i-1]+1,places[i+1]);
				}
				else
				{
					s1.erase(places[i-1]+1,places[i+1]+4);
				}
				s1.insert(places[i-1]+1,result);
				arrayModification(i,j,Values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
	}
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='+')
		{
			if (FirstOperation==0)
			{
				FirstOperation=1;
			}
			if ((elements[i+1]=='-'&&places[i+1]==places[i]+1)||Values[i+1]<0)
			{
				if (FirstOperation==1)
				{
					s1.erase(places[i]+1,1);
				}
				else
				{
					s1.erase(places[i]+4,1);
				}
			//	arrayModification(i+1,j,Values);
			//	arrayModification(i+1,j,elements);
			//	arrayModification(i+1,j,places);
				j-=1;
				for (int k = i+1; k < j; k++)
				{
					places[k]-=1;
				}
				if (Values[i+1]>0)
				{
					Values[i+1]*=(-1);
				}
				negelement=1;
			}
			if (i==0)
			{
				Values[i+1]=Values[i]+Values[i+1];
				result=to_string(Values[i+1]);
				if (negelement==1)
				{
					s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]+Values[i+1];
				result=to_string(Values[i+1]);
				if (i+1==j)
				{
					s1.erase(0,places[i+1]-places[i]);
				}
				else
				{
					s1.erase(0,places[i+1]-places[i]+4);
				}
				s1.insert(0,result);
			}
		}
		if (elements[i]=='-')
		{
			if (FirstOperation==0)
			{
				FirstOperation=1;
			}
			if (elements[i+1]=='-'&&places[i+1]==places[i]+1)
			{
				if (FirstOperation==1)
				{
					s1.erase(places[i+1],1);
				}
				else
				{
					s1.erase(places[i+1]+4,1);
				}
				arrayModification(i+1,j,Values);
				arrayModification(i+1,j,elements);
				arrayModification(i+1,j,places);
				j-=1;
				for (int k = i+1; k < j; k++)
				{
					places[k]-=1;
				}
				if (Values[i+1]>0)
				{
					Values[i+1]*=(-1);
				}
				negelement=1;
			}
			if (i==0)
			{
				Values[i+1]=Values[i]-Values[i+1];
				result=to_string(Values[i+1]);
				if (negelement==1)
				{
					s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]-Values[i+1];
				result=to_string(Values[i+1]);
				if (i+1==j)
				{
					s1.erase(0,places[i+1]-places[i]);
				}
				else
				{
					s1.erase(0,places[i+1]-places[i]+4);
				}
				s1.insert(0,result);
			}
		}
	}
	return result;
}



int main(int argv,char* argc[])			// argv : number of parameter in the command .....argc : the parameters as strings
{
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
		
		}

	 infile.close();             // close the file 

    }

else			// if the file path not added as a parameter close the program

	{cout<<"The file path not added . The program closed "<<endl;}

string t="L=(-4^3)+(2-2)sin(1.34))";
	brackets_no(t);
	t=spacetrim(t);
	BracketsHandling(t);
	trigsearch(t);
	BracketsHandling(t);
	/*if (ErrorFlag==1)
	{
		 std:: cout<<"parse error:"<<endl<<"syntax error"<<endl;
		 ErrorFlag=0;
	}
	else
	{*/
	string ss1=t.substr(t.find('=',0)+1,t.length()-t.find('=',0));      //gets the string that should be calculated
	string op;
	string R;
	string operand=t.substr(0,t.find('=',0)+1);   //the name of the variable that we will store the result in
	for(int i=0;i<s1.length();i++)
	{
		if(ss1[i]==')')
		{int k=i;
			do
			{
				k--;
			}
			while(ss1[k] !='(');        
		 	op=ss1.substr(k+1,(i)-(k+1));     //gets the string that between the brackets () 
			//cout<<op<<endl;
			R=Get_Result(op);      //gets the result of the string that between the brackets and stores it in R
		//	cout<<R<<endl;
			ss1.erase(k,i-k+1);    //removes the brackets and the string that has been calculated
			ss1.insert(k,R);       //inserts R at the old opening of the bracket (
			i=0;
		}
	} 
	R=Get_Result(ss1);
	//}


return 0;

}





























