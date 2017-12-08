
#include "CMatrix.h"




////////////////////////////////////////////////        CONSTRUCTOR       //////////////////////////////////////////////////////


CMatrix::CMatrix()
{
	nR = nC = 0; 
	values = NULL;
}


//////////////////////////////////////////////        DESTRUCTOR         //////////////////////////////////////////////////////


CMatrix::~CMatrix()
{
	reset();
}


////////////////////////////////////////////      COPY CONSTRUCTOR      /////////////////////////////////////////////////////



CMatrix::CMatrix(const CMatrix &d)
{
	if(d.nR==0 && d.nC==0)
	{
		nR=nC=0;
		values=NULL;
		return;
	}

	nR=d.nR;
	nC=d.nC;
	values = new double*[nR];
	for(int i=0;i<nR;i++)
	{
		values[i] = new double[nC]; 
		for(int j=0;j<nC;j++)
		values[i][j]=d.values[i][j];

	}

}


//////////////////////////////////////////////              RESET             /////////////////////////////////////////////////





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





/////////////////////////////////////////////       FOR DEFFERENT INPUTS        ///////////////////////////////////////////////////


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










/////////////////////////////////////////////////      STRING INPUT         ////////////////////////////////////////////////////





CMatrix::CMatrix(string s)                    // constructor takes string 
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





void CMatrix::copy(string s) 
{ 
reset();
char* buffer = new char[s.length()+1]; 
strncpy(buffer,s.c_str(),s.length()+1);
//char* lineContext; 
const char* lineSeparators = ";\r";   ///we removed \n from separators
char* line = strtok(buffer, lineSeparators); 
char* Remainlines=strtok(NULL, "");
while(line) 
{ 
	CMatrix row; 
	//char* context; 
	const char* separators = " []"; 
	char* token = strtok(line, separators); 
	while(token) 
	{ 
		const double token_value=atof(token);
		CMatrix item ;
		item=(const double)token_value;
		row.addColumn(item); 
		token = strtok(NULL, separators); 
	}
if(row.nC>0 && (row.nC==nC || nR==0)) addRow(row);
line = strtok(Remainlines, lineSeparators);
Remainlines= strtok(NULL, "");
} 
delete[] buffer;
}





string CMatrix::getString() 
{ 
	string s; 
	for(int iR=0;iR<nR;iR++) 
	{ 
		for(int iC=0;iC<nC;iC++) 
		{
			
			char buffer[50]; 
			snprintf(buffer, 50, " %f \t", values[iR][iC]); 
			s += buffer; 
		} s+="\n"; 
	} return s; 
}

/*
string CMatrix::getString() 
{ 
	string s; 
	for(int iR=0;iR<nR;iR++) 
	{ 
		for(int iC=0;iC<nC;iC++) 
		{
			
			char buffer[50]; 
			sprintf_s(buffer, 50, "%g\t", values[iR][iC]); 
			s += buffer; 
		} s+="\n"; 
	} return s; 
}
*/








/////////////////////////////////////////////////       USEFUL FUNCTIONS          ////////////////////////////////////////////






void CMatrix::setSubMatrix(int r, int c, CMatrix& m) 
{ 
	if((r+m.nR)>nR || (c+m.nC)>nC)throw("Invalid matrix dimension"); 
	for(int iR=0;iR<m.nR;iR++) 
		for(int iC=0;iC<m.nC;iC++) 
			values[r+iR][c+iC] = m.values[iR][iC]; 
}





CMatrix CMatrix::getSubMatrix(int r, int c, int nr, int nc) 
{ if((r+nr)>nR || (c+nc)>nC)throw("Invalid matrix dimension"); 
CMatrix m(nr, nc); 
for(int iR=0;iR<m.nR;iR++) 
	for(int iC=0;iC<m.nC;iC++) 
		m.values[iR][iC] = values[r+iR][c+iC]; 
return m; 
}




void CMatrix::addColumn(CMatrix& m) 
{ 
	CMatrix n(max(nR, m.nR), nC+m.nC); 
	n.setSubMatrix(0, 0, *this); 
	n.setSubMatrix(0, nC, m); 
	*this = n; 
}





void CMatrix::addRow(CMatrix& m) 
{ 
	CMatrix n(nR+m.nR, max(nC, m.nC)); 
	n.setSubMatrix(0, 0, *this); 
	n.setSubMatrix(nR, 0, m); 
	*this = n; 
}





//////////////////////////////////////////////    COPY MATRIX OPERATOR         ///////////////////////////////////////////////





CMatrix CMatrix::operator=(CMatrix d)
{
	
	reset();
	if(d.nR==0 && d.nC==0)
	{
		nR=nC=0;
		values=NULL;
		return *this;
	}

	nR=d.nR;
	nC=d.nC;
	values = new double*[nR];
	for(int i=0;i<nR;i++)
	{
		values[i] = new double[nC]; 
		for(int j=0;j<nC;j++)
		values[i][j]=d.values[i][j];

	}

return *this; 
}



/////////////////////////////////////////////        DOUBLE  INPUT       //////////////////////////////////////////////////////




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





CMatrix CMatrix::operator=(double d) 
{ 
	copy(d); 
return *this; 
}




//////////////////////////////////////////////////////       ADD FUNCTIONS     ////////////////////////////////////////////////


void CMatrix::add(CMatrix m) 
{ 
	if (nR != m.nR || nC != m.nC)
throw("Invalid matrix dimension"); 
for (int iR = 0; iR<nR; iR++)
	for (int iC = 0; iC<nC; iC++)
	values[iR][iC] += m.values[iR][iC]; 
}




void CMatrix::operator+=(CMatrix m) 
{ add(m);}



void CMatrix::operator+=(double d)
{ add(CMatrix(nR, nC, MI_VALUE, d)); }




CMatrix CMatrix::operator+(CMatrix m) 
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



//////////////////////////////////////////////////         SUBTRACT FUNCTIONS       ///////////////////////////////////////



void CMatrix::sub(CMatrix m)
{
	if (nR != m.nR || nC != m.nC)
		throw("Invalid matrix dimension");
	for (int iR = 0; iR<nR; iR++)
		for (int iC = 0; iC<nC; iC++)
			values[iR][iC] -= m.values[iR][iC];
}




void CMatrix::operator-=(CMatrix m)
{
	sub(m);
}




void CMatrix::operator-=(double d)
{
	sub(CMatrix(nR, nC, MI_VALUE, d));
}



CMatrix CMatrix::operator-(CMatrix m)
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






///////////////////////////////////////////        MULTIPLICATION          ///////////////////////////////////////////////////

void CMatrix::mul(CMatrix m)
{ 
	if(nC!=m.nR) 
		throw("Invalid matrix dimension"); 
	if(nC==0 && m.nC==0)
		return;
	
	CMatrix d(nR, m.nC);
	for(int iR=0;iR<d.nR;iR++) 
		for(int iC=0;iC<d.nC;iC++)
		{
			d.values[iR][iC] = 0; 
			for(int k=0;k<m.nR;k++)
			d.values[iR][iC] += values[iR][k]*m.values[k][iC]; 
		}
	

		reset();
	
		this->nR=d.nR;
		this->nC=d.nC;
		values = new double*[nR];
		for(int i=0;i<nR;i++)
		{
			values[i] = new double[nC]; 
			for(int j=0;j<nC;j++)
			values[i][j]=d.values[i][j];
	
		}
	
}

void CMatrix::operator*=(CMatrix m)
{ mul(m); } 

void CMatrix::operator*=(double d)
{ 
	for(int iR=0;iR<nR;iR++) 
		for(int iC=0;iC<nC;iC++) 
			values[iR][iC] *= d;
}


CMatrix CMatrix::operator*(CMatrix m)
{
	CMatrix r = *this;
	r*=m;
	return r;
}
CMatrix CMatrix::operator*(double d)
{
	CMatrix r = *this; 
	r*=d; 
	return r;
}


///////////////////////////////////////////        INCREMENTAL OPERATORS          ///////////////////////////////////////////////////

CMatrix CMatrix::operator++()
{ add(CMatrix(nR, nC, MI_VALUE, 1.0)); return *this;
}
CMatrix CMatrix::operator++(int)
{
CMatrix C = *this; add(CMatrix(nR, nC, MI_VALUE, 1.0)); return C;
}
CMatrix CMatrix::operator--()
{ add(CMatrix(nR, nC, MI_VALUE, -1.0)); return *this;
}
CMatrix CMatrix::operator--(int)
{
CMatrix r = *this; add(CMatrix(nR, nC, MI_VALUE, -1.0)); return r;
}
CMatrix CMatrix::operator-()
{ for(int iR=0;iR<nR;iR++) for(int iC=0;iC<nC;iC++) values[iR][iC] = -values[iR][iC];
return *this;
}
CMatrix CMatrix::operator+()
{ return *this;
}

///////////////////////////////////////////        INVERSE       ///////////////////////////////////////////////////





CMatrix CMatrix::inverse()
{
    int nr=nR;
    int nc=nC;
    CMatrix d(nR,nC*2,MI_ZEROS,0); //new matrix to carry augmented values
    CMatrix outt(nR,nC);
    CMatrix temp(1,2*nC,MI_ZEROS,0); //inverse matrix
    for(int i=0;i<nC;i++)
    {
        for(int j=0;j<nR;j++)
        {
            d.values[i][j]=values[i][j];  //putting values of matrix in the augm. matrix

        }
    }

    for(int i=0;i<nR;i++)   //ones diagonal
    {
         d.values[i][nR+i]=1;   // adding the identity matrix to augm. matrix
    }


    int j=0;
    double diag=d.values[0][0];
    for(int i2=1;i2<nR;i2++)
    {
        if(d.values[i2][0]>diag)
        {
            for(int k1=0;k1<2*nC;k1++)
            {
                temp.values[0][k1]=d.values[0][k1];
                d.values[0][k1]=d.values[i2][k1];
                d.values[i2][k1]=temp.values[0][k1];
            }
            }
            diag=d.values[0][0];
    }
    double num=0;
    for(int i=0;i<nR;i++)
    {
           for(int x=0;x<2*nC;x++)
           {
               if(diag==0){throw ("matrix has no inverse");}

               d.values[i][x]=d.values[i][x]/diag;
           }
           //cout<<endl;
           for(int k=0;k<nR;k++)
           {
               num=d.values[k][j];
               for(int l=0;l<2*nC;l++)
               {
                   if(k!=i)
                   {
                      d.values[k][l]=d.values[k][l]-(num*d.values[i][l]);
                   }
               }
           }
           if(i==nr-1){goto ending;}
           diag=d.values[i+1][j+1];
        for(int i2=i+1;i2<nR;i2++)
        {
            if(i2==nR-1){break;}
        if(d.values[i2+1][j+1]>diag)
        {
            for(int k1=0;k1<2*nC;k1++)
            {
                temp.values[0][k1]=d.values[i+1][k1];
                d.values[i+1][k1]=d.values[i2+1][k1];
                d.values[i2+1][k1]=temp.values[0][k1];
            }
            diag=d.values[i+1][j+1];
        }
    }
         j++;
       }

    ending :
        for(int p=0;p<nr;p++)
    {
        for(int h=0;h<nc;h++)
        {
            outt.values[p][h]=d.values[p][h+nc];
        }
    }
    //cout<<outt.getString();
    //cout<<endl;
    return outt;
}











/*

CMatrix CMatrix::adjoint()
{
CMatrix adj(nR,nC);                     //Create a matrix to store the adjoint and return it
if (nR == 1)
{
adj.values[0][0] = 1;
return adj;
}

int sign = 1;
CMatrix temp(nR,nC);                    // temp is used to store the cofactors of "this"

for (int i=0; i<nR; i++)
{
for (int j=0; j<nC; j++)
{
temp=getCofactor(i, j);                  // get cofactor of element this[i][j]

// sign of adj[j][i] positive if sum of row
// and column indexes is even.
sign = ((i+j)%2==0)? 1: -1;

// Interchanging rows and columns to get the
// transpose of the cofactor matrix
adj.values[j][i] = (sign)*(temp.getDeterminant());
}
}
return adj;
}

CMatrix CMatrix::inverse()
{
    CMatrix inverse(nR, nC);              //Create a matrix to store the inverse and return it
    CMatrix current(nR, nC);              //this matrix will hold the values of this in the next line
    current=*this;
    // Find determinant of current (this)
    double det = current.getDeterminant();
    if (det == 0)
    {
        throw("Invalid matrix dimension");
    }
	
    // Find adjoint
    CMatrix adj(nR, nC);
    adj= current.adjoint();
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<nR; i++)
        for (int j=0; j<nC; j++)
            inverse.values[i][j] = adj.values[i][j]/det;
 
    return inverse;
}




CMatrix CMatrix::getCofactor(int r, int c) 
{ 
	if (nR <= 1 && nC <= 1)
throw("Invalid matrix dimension"); 

CMatrix m(nR - 1, nC - 1); 

for (int iR = 0; iR<m.nR; iR++)
	for (int iC = 0; iC<m.nC; iC++) 
{

	int sR = (iR<r) ? iR : iR + 1; 
    int sC = (iC<c) ? iC : iC + 1; 
    m.values[iR][iC] = values[sR][sC]; 
	}
return m; 
}




double CMatrix::getDeterminant() {
	if (nR != nC)throw("Invalid matrix dimension"); 

if (nR == 1 && nC == 1)

	return values[0][0];

double value = 0, m = 1;

for (int iR = 0; iR<nR; iR++) 
 {
	value += m * values[0][iR] * getCofactor(0, iR).getDeterminant(); 
m *= -1;
 }
	if(value==0)                                           // to prevent the program to return 0 so the program stops
		throw("can't devide , determinant = zero ");
	
	

return value;
}
*/
///////////////////////////////////////////        DIVISION          ///////////////////////////////////////////////////

void CMatrix::div(CMatrix m)
{  
	CMatrix INV(nR, nC);
	INV=m.inverse();
	if(nC!=INV.nR) 
		throw("Invalid matrix dimension");
	CMatrix current (nR,nC);
	current=*this;
	CMatrix result(nR,INV.nC);
	result= current*INV;
	reset();
	if(result.nR==0 && result.nC==0)
	{
		nR=nC=0;
		values=NULL;
		return;
	}

	nR=result.nR;
	nC=result.nC;
	values = new double*[nR];
	for(int i=0;i<nR;i++)
	{
		values[i] = new double[nC]; 
		for(int j=0;j<nC;j++)
		values[i][j]=result.values[i][j];

	}

	
}

void CMatrix::operator/=(CMatrix m)
{ div(m); } 


CMatrix CMatrix::operator/(CMatrix m)
{
	CMatrix r = *this;
	r/=m;
	return r;
}






///////////////////////////////////////////        PRINT MATRIX          ///////////////////////////////////////////////////




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
void CMatrix::PrintMatrix()			// works only with 32*32 matrix
{
for (int i = 0; i < nR; i++)
	{
		for (int j = 0; j < 12; j++)
			cout << values[i][j] << "   ";
		cout <<endl;
	}
	cout<< endl<<endl;
	for (int i = 0; i < nR; i++)
	{
		for (int j = 12; j < 24; j++)
			cout << values[i][j] << "   ";
		cout <<endl;
	}
	cout<< endl<<endl;
	for (int i = 0; i < nR; i++)
	{
		for (int j = 24; j < nC; j++)
			cout << values[i][j] << "   ";
		cout <<endl;
	}
}
*/











//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


CMatrix CMatrix::transpose ()
{	//CMatrix that =*this					// there's no need for this line we already have this matrix that the function calls
	CMatrix result(nC,nR);
	for (int i=0 ; i< nR ;i++)
	{
   		for (int j =0 ; j<nC; j++) 
   		{
      			result.values[j][i]= values[i][j];
   		}
	}
return result;
}



/*

CMatrix CMatrix::elediv ()
{
	CMatrix result(nR,nC);
 	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=1.0/values[iR][iC];
		}
	}
	return result;

}
*/



/////////////////////////////////////    dividing the elements of a matrix with a certain value    //////////////////////////////////////

CMatrix CMatrix::elediv (double element)
{
	CMatrix result(nR,nC);
	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=values[iR][iC]/element;
		}
	}
 	
	return result;

}

/////////////////////////////////////    powering the elements of a matrix with a certain value    //////////////////////////////////////

CMatrix CMatrix::elepow (double element)
{
	CMatrix result(nR,nC);
 	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=pow((values[iR][iC]),element);
		}
	}
	return result;

}

/////////////////////////////////////    subtracting the elements of a matrix with a certain value    //////////////////////////////////////

CMatrix CMatrix::elesub (double element)
{
	CMatrix result(nR,nC);
 	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=values[iR][iC]-element;
		}
	}
	return result;

}

/////////////////////////////////////    adding the elements of a matrix with a certain value    //////////////////////////////////////

CMatrix CMatrix::eleadd (double t)
{
	CMatrix result(nR,nC);
 	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=t+values[iR][iC];
		}
	}
	return result;

}

/////////////////////////////////////    multiplying the elements of a matrix with a certain value    //////////////////////////////////////


CMatrix CMatrix::elemul (double t)
{
	CMatrix result(nR,nC);
 	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=t*values[iR][iC];
		}
	}
	return result;

}





/////////////////////////////////////    declaring a matrix with random numbers    //////////////////////////////////////

CMatrix CMatrix::random(int nR, int nC)
{
	CMatrix result(nR,nC);
	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=(rand() % 1000000) / 1000000.0;
		}
	}
	return result;
}

/////////////////////////////////////    declaring a matrix with zeros    //////////////////////////////////////


CMatrix CMatrix::zeros(int nR, int nC)
{
	CMatrix result(nR,nC);
	for(int iR=0;iR<nR;iR++)
	{
		for(int iC=0;iC<nC;iC++)
		{
			result.values[iR][iC]=0;
		}
	}
	return result;
}






