#pragma once
class CMatrix
{
	int nR, nC;
	double** values;
public:
	CMatrix();
	~CMatrix();
	
		   enum MI { MI_ZEROS, MI_ONES, MI_EYE, MI_RAND, MI_VALUE };
		   CMatrix(int nR, int nC, int initialization = MI_ZEROS, double initializationValue = 0.0);
		   CMatrix(int nR, int nC, double first, ...);
		   CMatrix(CMatrix const& m);
		   CMatrix(double d);
		  // CMatrix(string s);
		   void copy(CMatrix const& m);
		   void copy(double d);
		   //void copy(string s);
		   void reset();
		   //string getString();
		   CMatrix operator=(CMatrix const& m);
		   CMatrix operator=(double d);
		   //CMatrix operator=(string s);



		   void add(CMatrix const& m);
		   void operator+=(CMatrix const& m);
		   void operator+=(double d);
		   CMatrix operator+(CMatrix const& m);
		   CMatrix operator+(double d);
		   void sub(CMatrix const& m);
		   void operator-=(CMatrix const& m);
		   void operator-=(double d);
		   CMatrix operator-(CMatrix const& m);
		   CMatrix operator-(double d);
		   CMatrix operator++();
		   CMatrix operator++(int);
		   CMatrix operator--();
		   CMatrix operator--(int);
		   CMatrix operator-();
		   CMatrix operator+();
	
	
	
	           void mul(CMatrix const& m);
	           void operator*=(CMatrix const& m);
	           void operator*=(double d);
	           CMatrix operator*(CMatrix const& m);
	           CMatrix operator*(double d);
	
		   
	
		   double getDeterminant();
		   CMatrix getCofactor(int r, int c);
		   CMatrix adjoint();
		   CMatrix inverse();
	
	
	
		   void div(CMatrix const& m);
		   CMatrix operator/(CMatrix const& m);
		   void operator/=(CMatrix const& m);
	
	

		   void PrintMatrix();


		   
	
};

