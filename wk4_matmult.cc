#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;

#include <math.h>
#include <stdlib.h>

void readArr(int, int, double **);
void multArrs(int, double **, int, double **, int, double **);

int main(int argc, char *argv[])
{
  int ar = atoi(argv[1]);
  int ac = atoi(argv[2]);
  int br = atoi(argv[3]);
  int bc = atoi(argv[4]);

  if (ac != br)
  {
    cerr<< "Matrix dimensions mismatch; exiting.\n";
    exit(-1);
  }

  // reserve space for the three arrays
  double **A = new double*[ar];	// each el. of this points to a row of A
  for (int i = 0; i < ar; i++)
    A[i] = new double[ac];	// a row of 'ac' floats

  double **B = new double*[br];
  for (int i = 0; i < br; i++)
    B[i] = new double[bc];	// a row of 'bc' floats

  double **C = new double*[ar];	// each el. of this points to a row of C
  for(int i = 0 ; i < ar ; i++ )
    C[i] = new double [bc];
            
  // now that sufficient storage is allocated, start reading from kbd

  readArr(ar, ac, A);
  readArr(br, bc, B);

  multArrs(ar, A, bc, B, ac, C);

  for(int i = 0 ; i < ar; i++){
    for(int j = 0 ; j < bc ; j++)
      cout << C[i][j]<< " ";
    cout<<endl;
  }
         
  // now print out answer, nice and plainly

}

// read from kbd into this array, row by row
//  for a total of r x c entries;
//  WARNING: space for array must have been reserved beforehand
void readArr(int r, int c, double **arr)
{
  for(int i = 0 ; i < r ; i++){
    for(int j = 0 ; j < c ; j++){
      cin>> arr[i][j];
    }
  }
  // code for reading in r rows of c elements each goes here
}

void multArrs(int ar, double **A, int bc, double **B, int br, double **C)
{
  int i , j , k; 
    for(i = 0 ; i < ar ; i++)
      for( k = 0 ; k < bc ; k++)
	for(j = 0 ; j < br ; j++)
	  C[i][k] += A[i][j]*B[j][k];
}
