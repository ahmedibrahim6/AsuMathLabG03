#include "CMatrix.h"
map < char , CMatrix >  mymap;          // a map relates every defined character as matrix with its data as CMatrix data type


int ErrorFlag=0;


bool Re7em (string x)
{ 
	char r=x[0];
	std::map<char, CMatrix> ::iterator it;
	it=mymap.find(r);
	if (it!=mymap.end())
	{
		return 1;
	}
	else
	{
		return 0;
	}

};

int stringop (string y,string x)
{
	int x1=0,x2=0,x3=0;
	x1=Re7em(x);
	x2=Re7em(y);
	x3=x2+x1;
	return x3;
};



char Matrixdeclare (string x)
{
	char c;
	if (x.find("[")!=-1)
	{
		 c=x[0];
	}
return c;
};


void  brackets_no ( string operations)
{
	int bracket1 = count( operations.begin(), operations.end(), '(') ; 					
	int bracket2 = count ( operations.begin(),  operations.end(), ')') ;                                 					
	//int bracket = bracket1 + bracket2; 					
	if (bracket1!=bracket2) 
	{
		ErrorFlag=1;
	}
}
void arrayModification(int y,int x,double*p)
{
	for(int i=y;i<=x+1;i++)
	{
		*(p+(i))=*(p+i+1);
	}
}
void arrayModification(int y,int x,char *p)
{
	for(int i=y;i<=x+1;i++)
	{
		*(p+(i))=*(p+i+1);
	}
}
void arrayModification(int y,int x,string p[])
{
	for(int i=y;i<=x+1;i++)
	{
		(p[y])=(p[y+1]);
	}
}
void arrayModification(int y,int x,int *p)
{
	for(int i=y;i<=x+1;i++)
	{
		*(p+(i))=*(p+i+1);
	}
}

string spacetrim(string x)            //remove any unused spaces from the input string
{
	for(int i=0;i<x.length();i++)
	{
		if(x[i]==' ')
		{x.erase(i,1);}
	}
	return x;
}

char eleresult(char element,double x,string y)
{
	char d=y[0];
	CMatrix f;
	std::map<char, CMatrix> ::iterator it;
	it=mymap.find(d);
	if (it!=mymap.end())
	{
		f=it->second;

	}
	else
	{
		throw("error");
	}
	switch(element)
	{
		case '+':{f=f.eleadd(x);break;}
		case '-':{f=f.elesub(x);break;}
		case '*':{f=f.elemul(x);break;}
		case '/':{f=f.elediv(x);break;}
		case '^':{f=f.elepow(x);break;}
		case '&':{f=f.power(x);break;}
	}
	
	mymap.insert( pair < char , CMatrix > ('f',f));
	std::map<char, CMatrix> ::iterator it2;
	it2=mymap.find('f');
	cout<<it2->first<<" = "<<it2->second<<endl;
	return it2->first; 
}

char matrixresult(char element,string x,string y)
{
	char d=y[0];
	char c=x[0];
	CMatrix f,m;
	std::map<char, CMatrix> ::iterator it;
	std::map<char, CMatrix> ::iterator it1;
	it=mymap.find(d);
	it1=mymap.find(c);
	if (it!=mymap.end()&&it1!=mymap.end())
	{
		f=it->second;
		m=it1->second;
	}
	else
	{
		throw("error");
	}
	switch(element)
	{
		case '+':{f=m+f;break;}
		case '-':{f=m-f;break;}
		case '*':{f=m*f;break;}
		case '/':{f=m/f;break;}
	}
	
	mymap.insert( pair < char , CMatrix > ('f',f));
	std::map<char, CMatrix> ::iterator it2;
	it2=mymap.find('f');
	cout<<it2->first<<" = "<<it2->second<<endl;
	return it2->first; 
}


string Get_Result(string s1)
{
	int flag=0,FirstOperation=0;               //to count the number of the operations between two brackets ()
	char elements [100]={};                    //contains the operands of the input string * , - , + , / , ^
	int places[100]={};                        //contains the index of each operand 
	string values[100]={};                     //contains all the numbers in the input string in order in string form
	double Values[100]={};					   //contains all the numbers in the input string in order in double form
	double Result;                             //contains the final result of the input string as a double form
	string result;                             //contains the final result of the input string as a string form 
	int j=0,powerflag=0,z;
	int negelement;
	int type=0;
	string c,original=s1;

	if (s1.find(".^")!=-1)
	{
		powerflag=1;//z=s1.find(".^")+1;
	}

	for (int i = 0; i < s1.length(); ++i)
	{
		if (s1[i]=='.'&&(s1[i+1]=='+'||s1[i+1]=='-'||s1[i+1]=='*'||s1[i+1]=='/'||s1[i+1]=='^'))
		{
			s1.erase(i,1);
			s1=spacetrim(s1);
		}
	}


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
	
	for (int i = 0; i <= j; ++i)
	{
		cout<<values[i]<<endl<<Values[i]<<endl;
	}


	if (s1[0]=='-')
	{
		arrayModification(0,j,Values);
		arrayModification(0,j,values);
		arrayModification(0,j,elements);
		arrayModification(0,j,places);
		Values[0]*=(-1);
	}
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='^')
		{
			type=stringop(values[i],values[i+1]);
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
				arrayModification(i+1,j,values);
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
				if (type==0)
				{
					Values[i+1]=pow(Values[i],Values[i+1]);
					result=to_string(Values[i+1]);					
				}
				else if (type==1 && powerflag==1)
				{
					c[0]=eleresult('^',Values[i+1],values[i]);
				}
				else if (type==1 && powerflag==0)
				{
					c[0]=eleresult('&',Values[i+1],values[i]);
				}

				if (negelement==1)
				{
					////////////////////////////////////////////s1.erase(0,places[i]+values[i].length()+2);
					if (places[i+1]==0)
					{
						s1.erase(0,s1.length());

					}
					else
					{
						s1.erase(0,places[i]+values[i].length()+2);
					}
					negelement=0;
				}
				else
				{
				/////////////////////////////////	//s1.erase(0,places[i]+values[i+1].length()+1);
					if (places[i+1]==0)
					{
						s1.erase(0,s1.length());

					}
					else
					{
						s1.erase(0,places[i]+values[i].length()+1);
					}
				}
				if (type==0)
				{
					//Values[i+1]=pow(Values[i],Values[i+1]);
					//result=to_string(Values[i+1]);
					s1.insert(0,result);					
				}
				else if (type==1)
				{
					s1=c[0]+s1;
					//c=eleresult(elements[i],values[i],values[i+1]);
				}
							
				//s1.insert(0,result);
				FirstOperation=1;
			}
			else
			{
				if (type==0)
				{
					Values[i+1]=pow(Values[i],Values[i+1]);
					result=to_string(Values[i+1]);					
				}
				else if (type==1 && powerflag==1)
				{
					c[0]=eleresult('^',Values[i+1],values[i]);
				}
				else if (type==1 && powerflag==0)
				{
					c[0]=eleresult('&',Values[i],values[i+1]);
				}
				if (i+1==j)
				{
					s1.erase(places[i-1]+1,s1.length()-places[i-1]-1);
				}
				else
				{
					s1.erase(places[i-1]+1,places[i+1]-places[i-1]-1);
				}
				if (type==0)
				{
					s1.insert(places[i-1]+1,result);
				}
				else if (type==1)
				{
					s1.insert(places[i-1]+1,c);
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
		
	}
	
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='*')
		{
			type=stringop(values[i],values[i+1]);
			cout<<type<<endl;
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
				arrayModification(i+1,j,values);				
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
				if (type==0)
				{
				Values[i+1]=Values[i]*Values[i+1];
				result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('*',Values[i+1],values[i]);
				}
				else if (type==2)
				{
					c[0]=matrixresult('*',values[i],values[i+1]);
				}
			    if (negelement==1)
				{
					if(places[i+1]==0)
					{
						s1.erase(0,s1.length()-places[i]-1);
					}
					else
					{
						s1.erase(0,places[i]+values[i+1].length()+2);
					}
					//s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}
				if (type==0)
				{
					s1.insert(0,result);
				}
				else
				{
					s1=c[0]+s1;cout<<s1<<endl;
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);				
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
			else
			{
				if (type==0)
				{
					Values[i+1]=Values[i]*Values[i+1];
					result=to_string(Values[i+1]);					
				}
				else if (type==1 )
				{
					c[0]=eleresult('*',Values[i+1],values[i]);
				}
				else if (type==2 )
				{
					c[0]=matrixresult('*',values[i],values[i+1]);
				}
		
				if (i+1==j)
				{
					s1.erase(places[i-1]+1,places[i]+values[i+1].length()+2);
				}
				else
				{
					if (i==0)
					{
						s1.erase(places[i-1]+1,places[i+1]-places[i-1]-1);
					}
					else
					{
						s1.erase(places[i-1]+1,places[i+1]-places[i-1]);
					}
				}
				if (type==0)
				{
					s1.insert(places[i-1]+1,result);
				}
				else 
				{
					s1.insert(places[i-1]+1,c);
					//cout<<s1<<endl;	
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);				
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		
		}cout<<s1<<endl;

		if (elements[i]=='/')
		{
			type=stringop(values[i],values[i+1]);
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
				arrayModification(i+1,j,values);				
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
				if (type==0)
				{
				Values[i+1]=Values[i]/Values[i+1];
				result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('/',Values[i+1],values[i]);
				}
				else if (type==2)
				{
					c[0]=matrixresult('/',values[i],values[i+1]);
				}
				if (negelement==1)
				{
					if(places[i+1]==0)
					{
						s1.erase(0,s1.length()-places[i]-1);///////////////////////////////////////////////////
					}
					else
					{
						s1.erase(0,places[i]+values[i+1].length()+2);
					}
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}            
				if (type==0)
				{
				s1.insert(0,result);
				}
				else
				{
					s1.insert(0,c);
				}	
			}		
			else
			{
				if (type==0)
				{
				Values[i+1]=Values[i]/Values[i+1];
				result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('/',Values[i+1],values[i]);
				}
				else if (type==2)
				{
					c[0]=matrixresult('/',values[i],values[i+1]);
				}
				if (i+1==j)
				{
					if (places[i+1]!=0)
					{
						s1.erase(places[i-1]+1,places[i+1]-places[i]-1);
					}
					else
					{
						s1.erase(places[i-1]+1,s1.length()-places[i-1]-1);
					}
				}
				else
				{
					s1.erase(places[i-1]+1,places[i+1]+4);
				}
				if (type==0)
				{
					s1.insert(places[i-1]+1,result);
				}
				else 
				{
					s1.insert(places[i-1]+1,c);	
				}	
				arrayModification(i,j,Values);
				arrayModification(i,j,values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
		
	}
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='+')
		{
			type=stringop(values[i],values[i+1]);cout<<type<<endl;
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
				if (type==0)
				{
				Values[i+1]=Values[i]+Values[i+1];
				result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('+',Values[i+1],values[i]);
					//values[i+1]=c[0];
					
					cout<<s1<<endl<<Values[i-1]<<endl<<values[i+1];
				}
				else if (type==2)
				{
					c[0]=matrixresult('+',values[i],values[i+1]);
				}
				if (negelement==1)
				{
					s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);
				}
				if (type==0)
				{
				s1.insert(0,result);
				}
				else
				{
				s1.insert(0,c);
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
			else
			{
				if (type==0)
				{
				Values[i+1]=Values[i]+Values[i+1];
				result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('+',Values[i+1],values[i]);
				}
				else if (type==2)
				{
					c[0]=matrixresult('+',values[i],values[i+1]);
				}
				if (i+1==j)
				{
					s1.erase(0,places[i+1]-places[i]);
				}
				else
				{
					s1.erase(0,places[i+1]-places[i]+4);
				}
				if (type==0)
				{
				s1.insert(0,result);
				}
				else
				{
				s1.insert(0,c);
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
			
		}
		if (elements[i]=='-')
		{
			type=stringop(values[i],values[i+1]);
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
				arrayModification(i+1,j,values);
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
				if (type==0)
				{
				Values[i+1]=Values[i]-Values[i+1];
				result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('-',Values[i+1],values[i]);
				}
				else if (type==2)
				{
					c[0]=matrixresult('-',values[i],values[i+1]);
				}
				if (negelement==1)
				{
					if(places[i+1]==0)
					{
						s1.erase(0,s1.length()-places[i]-1);///////////////////////////////////////////////////
					}
					else
					{
						s1.erase(0,places[i]+values[i+1].length()+2);
					}
					//////////////////////////////////////////////s1.erase(0,places[i]+values[i+1].length()+2);
					negelement=0;
				}
				else
				{
					s1.erase(0,places[i]+values[i+1].length()+1);	
				}
				if (type==0)
				{
					s1.insert(0,result);
				}
				else
				{
					s1.insert(0,c);
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
			else
			{
				if (type==0)
				{
					Values[i+1]=Values[i]-Values[i+1];
					result=to_string(Values[i+1]);
				}				
				else if (type==1)
				{
					c[0]=eleresult('-',Values[i+1],values[i]);
				}
				else if (type==2)
				{
					c[0]=matrixresult('-',values[i],values[i+1]);
				}
				if (i+1==j)
				{
					s1.erase(0,places[i+1]-places[i]);
				}
				else
				{
					s1.erase(0,places[i+1]-places[i]+4);
				}
				if (type==0)
				{
					s1.insert(0,result);
				}
				else
				{
					s1.insert(0,c);
				}
				arrayModification(i,j,Values);
				arrayModification(i,j,values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
		
	}
	return s1;
}


////////////////////////////////////////handling the case: ex:5(10*20)//////////////////////////////////////
void BracketsHandling(string& x)                        
{
	int b;
	for (int i = 1; i <x.length(); i++)
	{
		b=i-1;
		if (x[i]=='(' )
		{
			if ( (int)x[b]>=48 && (int)x[b]<=57)
			{
				x.insert(i,"*");
				i=1;
			}
			/*else if(x[b]=='(')
			{
				x.erase(x.begin()+b);i=1;
			}*/
			else if (x[b]==')')
			{
				x.insert(i,"*");
				i=1;
			}
		}
	/*	else if (x[i]==')' && x[b]==')')
			{
				x.erase(x.begin()+b);i=1;
			}*/
		if (x[i]==')' )
		{
			if ( (int)x[i+1]>=48 && (int)x[i+1]<=57)
			{
				x.insert(i+1,"*");
				i=1;
			}}
	}
};
////////////////////////////////////////////////////////////replacing sin in the string//////////////////////////
void SinSearch(string& x)
{
	string v,sub,result;
	double temp=0;
	char z=x.find("sin(");//*p=x.find("sin(");
	if ((int)z != (-1))
	{
		if (x.find(')',x.find("sin("))==-1)
		{
			ErrorFlag=1;
		}
		 sub=x.substr(x.find("sin(")+4,x.find(")",x.find("sin("))-x.find("sin(")-4);
		 //CMatrix Mresult=Get_Result(sub);
		 //temp=atof(result.c_str());
		 //CMatrix c;
	     //Mresult.sinn();
		// temp=sin(temp);
		 string temp2=Get_Result(sub);
		 double temp3=sin(atof(temp2.c_str()));
		 v=std::to_string(temp3);
		 
		 x.replace(x.find("sin("),x.find(")",x.find("sin("))-x.find("sin(")+1,'('+v+/*Mresult*/')');
	}
};

////////////////////////////////////////////////////////// replacing cos////////////////////////////////////////////////////

void CosSearch(string& x)
{
	string v,sub,result;
	double temp=0;
	char z=x.find("cos(");//*p=x.find("sin(");
	if ((int)z != (-1))
	{
		if (x.find(')',x.find("cos("))==-1)
		{
			ErrorFlag=1;
		}
		 sub=x.substr(x.find("cos(")+4,x.find(")",x.find("cos("))-x.find("cos(")-4);
		 //CMatrix Mresult=Get_Result(sub);
		 //temp=atof(result.c_str());
		 //CMatrix c;
	     //Mresult.coss();
		 
		 //temp=cos(temp);
		 //v=std::to_string(temp);
		 string temp2=Get_Result(sub);
		 double temp3=cos(atof(temp2.c_str()));
		 v=std::to_string(temp3);

		 x.replace(x.find("cos("),x.find(")",x.find("cos("))-x.find("cos(")+1,'('+v+/*Mresult*/')');
	}
};

/////////////////////////////////////////////////tan replacement/////////////////////////////////////////////////

void TanSearch(string& x)
{
	string v,sub,result;
	double temp=0;
	char z=x.find("tan(");//*p=x.find("sin(");
	if ((int)z != (-1))
	{
		if (x.find(')',x.find("tan("))==-1)
		{
			ErrorFlag=1;
		}
		 sub=x.substr(x.find("tan(")+4,x.find(")",x.find("tan("))-x.find("tan(")-4);
		 //CMatrix Mresult=Get_Result(sub);
		 //temp=atof(result.c_str());
		 //CMatrix c;
	     //Mresult.tann();
		 //temp=tan(temp);
		 //v=std::to_string(temp);
		 string temp2=Get_Result(sub);
		 double temp3=tan(atof(temp2.c_str()));
		 v=std::to_string(temp3);

		 x.replace(x.find("tan("),x.find(")",x.find("tan("))-x.find("tan(")+1,'('+v+/*Mresult*/')');
	}
};

///////////////////////////////////////////////////trig with no brackets//////////////////////////////

void logtrighandle(string &x)
{
	string temp;
	double result;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i]=='s' && x[i+1]=='i' && x[i+2]=='n')
		{
			while (x[i+3]>=48 && x[i+3]<=57 || x[i+3]=='.')
			{
				temp+=x[i+3];
				i++;
			}
			result=atof(temp.c_str());
			result=sin(result);
			x.replace(x.find("sin"),temp.length()+3,'('+to_string(result)+')');
		}
		else if (x[i]=='t' && x[i+1]=='a' && x[i+2]=='n')
		{
			while (x[i+3]>=48 && x[i+3]<=57 || x[i+3]=='.')
			{
				temp+=x[i+3];
				i++;
			}
			result=atof(temp.c_str());
			result=tan(result);
			x.replace(x.find("tan"),temp.length()+3,'('+to_string(result)+')');
		}
		else if (x[i]=='c' && x[i+1]=='o' && x[i+2]=='s')
		{
			while (x[i+3]>=48 && x[i+3]<=57 || x[i+3]=='.')
			{
				temp+=x[i+3];
				i++;
			}
			result=atof(temp.c_str());
			result=cos(result);
			x.replace(x.find("cos"),temp.length()+3,'('+to_string(result)+')');
		}
		else if (x[i]=='l' && x[i+1]=='o' && x[i+2]=='g' && x[i+3]=='1' && x[i+4]=='0')
		{
			if (x[i+5]=='(')
			{
			string sub=x.substr(x.find("log10(")+6,x.find(")",x.find("log10("))-x.find("log10(")-6),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.logg10();
			double temp1=0;
			string temp2=Get_Result(sub);
			//temp1=atof(sub.c_str());
			temp1=atof(temp2.c_str());
			temp1=log10(temp1);
			v=std::to_string(temp1);
			 x.replace(x.find("log10("),x.find(")",x.find("log10("))-x.find("log10(")+1,'('+v+/*Mresult*/')');
			}
			else{
			while (x[i+5]>=48 && x[i+5]<=57 || x[i+5]=='.')
			{
				temp+=x[i+5];
				i++;
			}
			result=atof(temp.c_str());
			result=log10(result);
			x.replace(x.find("log10"),temp.length()+5,'('+to_string(result)+')');
			}}
		else if (x[i]=='l' && x[i+1]=='o' && x[i+2]=='g' && x[i+3]!='1')
		{
			if (x[i+3]=='(')
			{
				string sub=x.substr(x.find("log(")+4,x.find(")",x.find("log("))-x.find("log(")-4),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.logg();
			//double temp1=0;
			//temp1=atof(sub.c_str());
			//temp1=log(temp1);
			//v=std::to_string(temp1);
			 string temp2=Get_Result(sub);
			double temp3=log(atof(temp2.c_str()));
			v=std::to_string(temp3);
				x.replace(x.find("log("),x.find(")",x.find("log("))-x.find("log(")+1,'('+v+/*Mresult*/')');
			}
			else if(x[i+3]!='1'){
			while (x[i+3]>=48 && x[i+3]<=57 || x[i+3]=='.')
			{
				temp+=x[i+3];
				i++;
			}
			result=atof(temp.c_str());
			result=log(result);
			x.replace(x.find("log"),temp.length()+3,'('+to_string(result)+')');
			}}

	}
};

///////////////////////////////////////////////////////////invsearch/////////////////////////////////////////////////
void invsearch(string &x,int y)
{
	string temp;
	double result;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i]=='a' && x[i+1]=='s' && x[i+2]=='i' && x[i+3]=='n')
		{
			if (x[i+4]=='(')
			{
			string sub=x.substr(x.find("asin(")+5,x.find(")",x.find("asin("))-x.find("asin(")-5),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.asinn();
			//double temp1=0;
			//temp1=asin(temp1);
			//v=std::to_string(temp1);
			string temp2=Get_Result(sub);
			 double temp3=asin(atof(temp2.c_str()));
			 v=std::to_string(temp3);
 
			x.replace(x.find("asin("),x.find(")",x.find("asin("))-x.find("asin(")+1,'('+v+/*Mresult*/')');
			}
		
			else{
			while (x[i+4]>=48 && x[i+4]<=57 || x[i+4]=='.')
			{
				temp+=x[i+4];
				i++;
			}
			result=atof(temp.c_str());
			result=asin(result);
			x.replace(x.find("asin"),temp.length()+4,'('+to_string(result)+')');
			}}
		
		
		else if (x[i]=='a' && x[i+1]=='t' && x[i+2]=='a' && x[i+3]=='n')
		{
			if (x[i+4]=='(')
			{
			string sub=x.substr(x.find("atan(")+5,x.find(")",x.find("atan("))-x.find("atan(")-5);
			//CMatrix Mresult=Get_Result(sub);
			 //	temp=atof(result.c_str());
		 //		CMatrix c;
	     //		Mresult.atann();
			 //double temp1=0;
			 //temp1=atan(temp1);
			 //string v=std::to_string(temp1);
			string temp2=Get_Result(sub);
			 double temp3=sin(atof(temp2.c_str()));
			 string v=std::to_string(temp3);
 
			x.replace(x.find("atan("),x.find(")",x.find("atan("))-x.find("atan(")+1,'('+v+/*Mresult*/')');
			}
			else 
			
			{while (x[i+4]>=48 && x[i+4]<=57 || x[i+4]=='.')
				{
				temp+=x[i+4];
				i++;
				}
				result=atof(temp.c_str());
				result=atan(result);
				x.replace(x.find("atan"),temp.length()+4,'('+to_string(result)+')');
			}}

		else if (x[i]=='a' && x[i+1]=='c' && x[i+2]=='o' && x[i+3]=='s')
		{
			if (x[i+4]=='(')
			{
			string	sub=x.substr(x.find("acos(")+5,x.find(")",x.find("acos("))-x.find("acos(")-5);
			 //CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.acoss();
			//double temp1=0;
			//temp1=acos(temp1);
			//string v=std::to_string(temp1);
			string temp2=Get_Result(sub);
			 double temp3=acos(atof(temp2.c_str()));
			 string v=std::to_string(temp3);

		 x.replace(x.find("acos("),x.find(")",x.find("acos("))-x.find("acos(")+1,'('+v+/*Mresult*/')');
	
			}
			else{
			while (x[i+4]>=48 && x[i+4]<=57 || x[i+4]=='.')
			{
				temp+=x[i+4];
				i++;
			}
			result=atof(temp.c_str());
			result=acos(result);
			x.replace(x.find("acos"),temp.length()+4,'('+to_string(result)+')');
			}}}
};

///////////////////////////////////////////////////hsearch////////////////////////////////////////////////////////////////

void hsearch(string& x,int y)
{
	if (y==0)
	{
		string sub=x.substr(x.find("sinh(")+5,x.find(")",x.find("sinh("))-x.find("sinh(")-5),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.sinnh();
			//double temp1=0;
			//temp1=sinh(temp1);
			 //v=std::to_string(temp1);
			string temp2=Get_Result(sub);
			double temp3=sinh(atof(temp2.c_str()));
			v=std::to_string(temp3);
	 
		x.replace(x.find("sinh("),x.find(")",x.find("sinh("))-x.find("sinh(")+1,'('+v+/*Mresult*/')');
	}
	else if (y==1)
	{
		string sub=x.substr(x.find("cosh(")+5,x.find(")",x.find("cosh("))-x.find("cosh(")-5),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.cossh();
			//double temp1=0;
			//temp1=cosh(temp1);
			//v=std::to_string(temp1);
		string temp2=Get_Result(sub);
		 double temp3=cosh(atof(temp2.c_str()));
		 v=std::to_string(temp3);
	 
		x.replace(x.find("cosh("),x.find(")",x.find("cosh("))-x.find("cosh(")+1,'('+v+/*Mresult*/')');
	}
	else if (y==2)
	{
		string sub=x.substr(x.find("tanh(")+5,x.find(")",x.find("tanh("))-x.find("tanh")-5),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.tannh();
			/*double temp1=0;
			temp1=tanh(temp1);
			v=std::to_string(temp1);*/
			string temp2=Get_Result(sub);
			 double temp3=tanh(atof(temp2.c_str()));
			v=std::to_string(temp3);
	
		x.replace(x.find("tanh("),x.find(")",x.find("tanh("))-x.find("tanh(")+1,'('+v+/*Mresult*/')');
	}
};
/////////////////////////////////////////////////////exponential & sqrt calculations/////////////////////////////////////////////

void expsqrt(string &x)
{
	string temp;
	double result,temp1=0;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i]=='s' && x[i+1]=='q' && x[i+2]=='r' && x[i+3]=='t')
		{
			if (x[i+4]=='(')
			{
			string sub=x.substr(x.find("sqrt(")+5,x.find(")",x.find("sqrt("))-x.find("sqrt(")-5),v;
			//CMatrix Mresult=Get_Result(sub);
			//temp=atof(result.c_str());
			//CMatrix c;
			//Mresult.sqrtt();
			// temp1=sqrt(temp1);
			//v=std::to_string(temp1);
			string temp2=Get_Result(sub);
		 double temp3=sqrt(atof(temp2.c_str()));
		 v=std::to_string(temp3);

			 x.replace(x.find("sqrt("),x.find(")",x.find("sqrt("))-x.find("sqrt(")+1,'('+v+/*Mresult*/')');
			}
		
			else{
			while (x[i+4]>=48 && x[i+4]<=57 || x[i+4]=='.')
			{
				temp+=x[i+4];
				i++;
			}
			result=atof(temp.c_str());
			result=sqrt(result);
			x.replace(x.find("sqrt"),temp.length()+4,'('+to_string(result)+')');
			}}
		
		
		else if (x[i]=='e' && x[i+1]=='x' && x[i+2]=='p')      ////////////////////////warning
		{
			if (x[i+3]=='(')
			{
			string sub=x.substr(x.find("exp(")+4,x.find(")",x.find("exp("))-x.find("exp(")-4);
			//CMatrix Mresult=Get_Result(sub);
			 //	temp=atof(result.c_str());
				temp1=atof(sub.c_str());
		 //		CMatrix c;
	     //		Mresult.expp();
			 // temp1=exp(temp1);
			 //string v=std::to_string(temp1);
				string temp2=Get_Result(sub);
		 double temp3=exp(atof(temp2.c_str()));
		string v=std::to_string(temp3);

			 x.replace(x.find("exp("),x.find(")",x.find("exp("))-x.find("exp(")+1,'('+v+/*Mresult*/')');
			}
			else 
			
			{while (x[i+3]>=48 && x[i+3]<=57 || x[i+3]=='.')
				{
				temp+=x[i+3];
				i++;
				}
				result=atof(temp.c_str());
				result=exp(result);
				x.replace(x.find("exp"),temp.length()+3,'('+to_string(result)+')');
			}}}
};
/////////////////////////////////////////////////////summing fn///////////////////////////////////////////////////////
void trigsearch(string& x)
{
	char z=x.find("sin("),z1=x.find("cos("),z2=x.find("tan("),z3=x.find("acos"),z4=x.find("asin"),z5=x.find("atan");
	string sub="0",temp;
	char z6=x.find("sinh"),z7=x.find("cosh"),z8=x.find("tanh");
	while ((int)z4 !=-1)
	{
		z4=x.find("asin");
		invsearch(x,0);
	}
	while ((int)z3 !=-1)
	{
		z3=x.find("acos");
		invsearch(x,1);
	}
		while ((int)z5 !=-1)
	{
		z5=x.find("atan");
		invsearch(x,2);
	}
		while ((int)z6 !=-1)
	{
		z6=x.find("sinh");
		hsearch(x,0);
	}
		while ((int)z7 !=-1)
	{
		z7=x.find("cosh");
		hsearch(x,1);
	}
		while ((int)z8 !=-1)
	{
		z8=x.find("tanh");
		hsearch(x,2);
	}
		
	while((int)z != -1)
	{
		z=x.find("sin(");
		SinSearch(x);
	}
	while ((int)z1 != (-1))
	{
		z1=x.find("cos(");
		CosSearch(x);
	}
	while ((int)z2 != (-1))
	{
		z2=x.find("tan(");
		TanSearch(x);
	}
	int i=0;
	while ((x.find("sin",i)!=-1 || x.find("cos",i)!=-1 || x.find("tan",i)!=-1 ||x.find("log",i)!=-1) && i<x.length())
	{
		i++;
		logtrighandle(x);
	}
	i=0;
	while((x.find("exp")!=-1 || x.find("sqrt")!=-1)&& i<x.length())
	{
		i++;
		expsqrt(x);
	}
	
//return sub;
};





int main(int argv,char* argc[])			// argv : number of parameter in the command .....argc : the parameters as strings
{
	string t="L = 12.1*M + (A).^(4/(3.2+5.6))";
	brackets_no(t);
	t=spacetrim(t);
	BracketsHandling(t);
	trigsearch(t);
	BracketsHandling(t);
	if (ErrorFlag==1)
	{
		 std:: cout<<"parse error:"<<endl<<"syntax error"<<endl;
		 ErrorFlag=0;
	}
	else
	{
	string s1=t.substr(t.find('=',0)+1,t.length()-t.find('=',0));      //gets the string that should be calculated
	string op;
	string R;
	string operand=t.substr(0,t.find('=',0)+1);   //the name of the variable that we will store the result in
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]==')')
		{int k=i;
			do
			{
				k--;
			}
			while(s1[k] !='(');        
		 	op=s1.substr(k+1,(i)-(k+1));     //gets the string that between the brackets () 
			//cout<<op<<endl;
			R=Get_Result(op);      //gets the result of the string that between the brackets and stores it in R
		//	cout<<R<<endl;
			s1.erase(k,i-k+1);    //removes the brackets and the string that has been calculated
			s1.insert(k,R);       //inserts R at the old opening of the bracket (
			i=0;
		}
	}
	cout<<t<<endl;  
	R=Get_Result(s1);
	cout<<operand<<R<<endl;
	}
	
	
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
char hh='*';
double o=2;
string hg="M*2+5";
//char g=eleresult(hh,o,hg);
string h=Get_Result(hg);
h=Get_Result(h);
cout<<h<<endl;
string gh="N";
//char v=matrixresult(hh,hg,gh);

return 0;

}