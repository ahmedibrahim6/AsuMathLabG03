
#include <cstdlib>
#include <stdarg.h>
#include<iostream>
using namespace std;
class CMatrix
{
	int nR, nC;
	double** values;
public:
	CMatrix();
	~CMatrix();
	CMatrix(const CMatrix& d);
	
		   enum MI { MI_ZEROS, MI_ONES, MI_EYE, MI_RAND, MI_VALUE };
		   CMatrix(int nR, int nC, int initialization = MI_ZEROS, double initializationValue = 0.0);
		   CMatrix(int nR, int nC, double first, ...);
		  // CMatrix(CMatrix m);
		   CMatrix(double d);
		  // CMatrix(string s);
		   //void copy(CMatrix m);
		   void copy(double d);
		   //void copy(string s);
		   void reset();
		   //string getString();
		   CMatrix operator=(CMatrix m);
		   CMatrix operator=(double d);
		   //CMatrix operator=(string s);



		   void add(CMatrix m);
		   void operator+=(CMatrix m);
		   void operator+=(double d);
		   CMatrix operator+(CMatrix m);
		   CMatrix operator+(double d);
		   void sub(CMatrix m);
		   void operator-=(CMatrix m);
		   void operator-=(double d);
		   CMatrix operator-(CMatrix m);
		   CMatrix operator-(double d);
		   CMatrix operator++();
		   CMatrix operator++(int);
		   CMatrix operator--();
		   CMatrix operator--(int);
		   CMatrix operator-();
		   CMatrix operator+();
	
	
	
	           void mul(CMatrix m);
	           void operator*=(CMatrix m);
	           void operator*=(double d);
	           CMatrix operator*(CMatrix m);
	           CMatrix operator*(double d);
	
		   
	
		   double getDeterminant();
		   CMatrix getCofactor(int r, int c);
		   CMatrix adjoint();
		   CMatrix inverse();
	
	
	
		   void div(CMatrix m);
		   CMatrix operator/(CMatrix m);
		   void operator/=(CMatrix m);
	
			 void copy(string s); 
		   string getString();
		   void setSubMatrix(int iR, int iC, CMatrix& m);
		   CMatrix getSubMatrix(int r, int c, int nr, int nc);
		   void addColumn(CMatrix& m); 
		   void addRow(CMatrix& m);
		   CMatrix operator=(string s);


		   void PrintMatrix();


		   
	
};
