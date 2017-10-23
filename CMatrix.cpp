#include "CMatrix.h"
#include <cstdlib>
#include <stdarg.h>
#include<iostream>
using namespace std;

CMatrix::CMatrix()
{
	nR = nC = 0; 
	values = NULL;
}


CMatrix::~CMatrix()
{
	reset();
}


void CMatrix::reset() 
{ 
	if (values) 
{ 
	for (int i = 0; i<nR; i++)
	delete[] values[i]; 
delete[] values; 
}
nR = nC = 0; 
values = NULL;
}

CMatrix::CMatrix(int nR, int nC, int initialization, double initializationValue) 
{ 
	this->nR = nR;
	this->nC = nC; 
if ((nR*nC) == 0) 
{ 
	values = NULL; return;
}
values = new double*[nR]; 
for (int iR = 0; iR<nR; iR++) 
{ 
	values[iR] = new double[nC]; 
for (int iC = 0; iC<nC; iC++) 
{ 
	switch (initialization) 
{
case MI_ZEROS: values[iR][iC] = 0; break; 
case MI_ONES: values[iR][iC] = 1; break; 
case MI_EYE: values[iR][iC] = (iR == iC) ? 1 : 0; break; 
case MI_RAND: values[iR][iC] = (rand() % 1000000) / 1000000.0; break; 
case MI_VALUE: values[iR][iC] = initializationValue;
break; 
} 
} 
} 
}

CMatrix::CMatrix(int nR, int nC, double first, ...)
{
	this->nR = nR;
	this->nC = nC; 
	if ((nR*nC) == 0) 
	{ 
		values = NULL; return;
	}
	values = new double*[nR];
	va_list va;
	va_start(va, first);

	for (int iR = 0; iR<nR; iR++)
	{
		values[iR] = new double[nC];

	for (int iC = 0; iC<nC; iC++) 
	{ 
		values[iR][iC] = (iC == 0 && iR == 0) ? first : va_arg(va, double); 
	} 
	}
	va_end(va);
}


CMatrix::CMatrix(CMatrix& m) 
{ 
	nR = nC = 0; 
values = NULL; 
copy(m); 
}

void CMatrix::copy(CMatrix& m) { 
	reset(); 
	this->nR = m.nR;
	this->nC = m.nC;
if ((nR*nC) == 0)
{ values = NULL; 
return; }
values = new double*[nR]; 
for (int iR = 0; iR<nR; iR++) 
{ values[iR] = new double[nC]; 
for (int iC = 0; iC<nC; iC++)
{ 
	values[iR][iC] = m.values[iR][iC]; 
} 
}
 }

CMatrix::CMatrix(double d) 
{
	nR = nC = 0; 
values = NULL;
copy(d); 
}

void CMatrix::copy(double d) 
{ 
	reset();
this->nR = 1; 
this->nC = 1; 
values = new double*[1]; 
values[0] = new double[1]; 
values[0][0] = d; 
}










CMatrix CMatrix::operator=(CMatrix& m)
{
	copy(m); 
return *this; 
}
CMatrix CMatrix::operator=(double d) 
{ 
	copy(d); 
return *this; 
}




void CMatrix::add(CMatrix& m) 
{ 
	if (nR != m.nR || nC != m.nC)
throw("Invalid matrix dimension"); 
for (int iR = 0; iR<nR; iR++)
	for (int iC = 0; iC<nC; iC++)
	values[iR][iC] += m.values[iR][iC]; 
}



void CMatrix::operator+=(CMatrix& m) 
{ add(m);}


void CMatrix::operator+=(double d)
{ add(CMatrix(nR, nC, MI_VALUE, d)); }


CMatrix CMatrix::operator+(CMatrix& m) 
{ 
	CMatrix r = *this;
r += m; 
return r; 
}
CMatrix CMatrix::operator+(double d) 
{ 
	CMatrix r = *this; 
r += d;
return r;
}


void CMatrix::sub(CMatrix& m)
{
	if (nR != m.nR || nC != m.nC)
		throw("Invalid matrix dimension");
	for (int iR = 0; iR<nR; iR++)
		for (int iC = 0; iC<nC; iC++)
			values[iR][iC] -= m.values[iR][iC];
}

void CMatrix::operator-=(CMatrix& m)
{
	sub(m);
}


void CMatrix::operator-=(double d)
{
	sub(CMatrix(nR, nC, MI_VALUE, d));
}


CMatrix CMatrix::operator-(CMatrix& m)
{
	CMatrix r = *this;
	r -= m;
	return r;
}
CMatrix CMatrix::operator-(double d)
{
	CMatrix r = *this;
	r -= d;
	return r;
}



void CMatrix::PrintMatrix()
{
	for (int i = 0; i < nR; i++)
	{
		for (int j = 0; j < nC; j++)
			cout << values[i][j] << "   ";
		cout <<endl;
	}
}







/*
CMatrix::CMatrix(string s)
{
	nR = nC = 0;
	values = NULL;
	copy(s);
}

CMatrix CMatrix::operator=(string s)
{
	copy(s);
	return *this;
}
string CMatrix::getString()

{

	string s;
	for (int iR = 0; iR<nR; iR++)
	{
		for (int iC = 0; iC<nC; iC++)
		{
			char buffer[50];
			sprintf_s(buffer, 50, "%g\t", values[iR][iC]);
			s += buffer;
		}
		s += "\n";
	}
	return s;
}
void CMatrix::copy(string s)
{
	reset();

	char* buffer = new char[s.length() + 1];

	strcpy(buffer, s.c_str());

	char* lineContext;
	char* lineSeparators = ";\r\n";
	char* line = strtok_s(buffer, lineSeparators, &lineContext);
	while (line)
	{
		CMatrix row;
		char* context;
		char* separators = " []";
		char* token = strtok_s(line, separators, &context);
		while (token)
		{
			CMatrix item = atof(token);
			row.addColumn(item);
			token = strtok_s(NULL, separators, &context);
		}
		if (row.nC>0 && (row.nC == nC || nR == 0))
			addRow(row);
		line = strtok_s(NULL, lineSeparators, &lineContext);
	}
	delete[] buffer;
}

*/