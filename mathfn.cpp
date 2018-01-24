#include<iostream>
#include <string>
#include <vector>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

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
void arrayModification(int y,int x,int *p)
{
	for(int i=y;i<=x+1;i++)
	{
		*(p+(i))=*(p+i+1);
	}
}
string Get_Result(string s1)
{
	int flag=0;                                //to count the number of the operations between two brackets ()
	char elements [100]={};                    //contains the operands of the input string * , - , + , / , ^
	int places[100]={};                        //contains the index of each operand 
	string values[100]={};                     //contains all the numbers in the input string in order in string form
	double Values[100]={};					   //contains all the numbers in the input string in order in double form
	double Result;                             //contains the final result of the input string as a double form
	string result;                             //contains the final result of the input string as a string form 
	int j=0;
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
	values[j]=s1.substr(places[j-1]+1,s1.size()-places[j-1]-1);
	Values[j]=atof(values[j].c_str());
	for (int i = 0; i < j; i++)
	{
		if (elements[i]=='^')
		{
			
			if (i==0)
			{
				Values[i+1]=pow(Values[i],Values[i+1]);
				result=to_string(Values[i+1]);
				s1.erase(0,places[i]+values[i+1].length()+1);
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=pow(Values[i],Values[i+1]);
				result=to_string(Values[i+1]);
				s1.erase(places[i-1]+1,places[i+1]-1);
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
			
			if (i==0)
			{
				Values[i+1]=Values[i]*Values[i+1];
				result=to_string(Values[i+1]);
				s1.erase(0,places[i]+values[i+1].length()+1);
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]*Values[i+1];
				result=to_string(Values[i+1]);
				//arrayModification(i,j,Values);
				s1.erase(places[i-1]+1,places[i+1]-1);
				s1.insert(places[i-1]+1,result);
				arrayModification(i,j,Values);
				arrayModification(i,j,elements);
				arrayModification(i,j,places);
			}
		}
		if (elements[i]=='/')
		{
			
			if (i==0)
			{
				Values[i+1]=Values[i]/Values[i+1];
				result=to_string(Values[i+1]);
				s1.erase(0,places[i]+values[i+1].length());              
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]/Values[i+1];
				result=to_string(Values[i+1]);
				//arrayModification(i,j,Values);
				s1.erase(places[i-1]+1,places[i+1]-1);
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
			if (i==0)
			{
				Values[i+1]=Values[i]+Values[i+1];
				result=to_string(Values[i+1]);
				s1.erase(0,places[i]+values[i+1].length()+1);
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]+Values[i+1];
				result=to_string(Values[i+1]);
				s1.erase(0,places[i+1]-1);
				s1.insert(0,result);
			}
		}
		if (elements[i]=='-')
		{
			if (i==0)
			{
				Values[i+1]=Values[i]-Values[i+1];
				result=to_string(Values[i+1]);
				s1.erase(0,places[i]+values[i+1].length()+1);
				s1.insert(0,result);
			}
			else
			{
				Values[i+1]=Values[i]-Values[i+1];
				result=to_string(Values[i+1]);
				s1.erase(0,places[i+1]-1);       
				s1.insert(0,result);
			}
		}
		
	}
	return s1;
}

string spacetrim(string x)            //remove any unused spaces from the input string
{
	for(int i=0;i<x.length();i++)
	{
		if(x[i]==' '||x[i]==NULL)
		{x.erase(i,1);}
	}
	return x;
}

/*string trigEvaluate (string s1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		if(s1[i]=='s'||s1[i]=='c'||s1[i]=='t')
	}
}*/
string hesab (string t)
{
	//string t="100/(50*2+50-50)";
	t=spacetrim(t);
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
	//cout<<t<<endl;  
	R=Get_Result(s1);
	//cout<<operand<<R<<endl;
	
	return R;
}

int main()
{
	char x[]="[[2.0[3.4;2.4 ;(3.5+9.1)] 2^3 -3+1.2 15/3]]";
	string s=x;
	char* spearators = "[] ;,";
	char* token = strtok(x, spearators);
	string array[1000];
	string array2[1000];
	int indeces[1000];
	int g=0;
	while(token)
	{	
		
		array[g]= token;
		g++;
		token = strtok(NULL, spearators);
	}
	for (int i=0;i<=g;i++)
	{
		if(i!=0)
		indeces[i]=s.find(array[i],indeces[i-1]);
		else
		indeces[i]=s.find(array[i]);
	}
	for (int i=0;i<g;i++)
	{
		//cout<<array[i];
		array2[i]=hesab(array[i]);
		cout<<array2[i]<<endl;
	}
	for(int i=g;i>=0;i--)
	{
		s.replace(indeces[i],array[i].length(),array2[i]);
	}
	cout<<s<<endl;
}