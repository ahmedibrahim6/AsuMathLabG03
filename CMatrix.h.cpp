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
		   CMatrix(CMatrix& m);
		   CMatrix(double d);
		  // CMatrix(string s);
		   void copy(CMatrix& m);
		   void copy(double d);
		   //void copy(string s);
		   void reset();
		   //string getString();
		   CMatrix operator=(CMatrix& m);
		   CMatrix operator=(double d);
		   //CMatrix operator=(string s);



		   void add(CMatrix& m);
		   void operator+=(CMatrix& m);
		   void operator+=(double d);
		   CMatrix operator+(CMatrix& m);
		   CMatrix operator+(double d);
		   void sub(CMatrix& m);
		   void operator-=(CMatrix& m);
		   void operator-=(double d);
		   CMatrix operator-(CMatrix& m);
		   CMatrix operator-(double d);


		   void PrintMatrix();


		   //void mul(CMatrix& m); void operator*=(CMatrix& m); void operator*=(double d); CMatrix operator*(CMatrix& m);CMatrix operator*(double d);
	
};

