#include <cstdlib>
#include <armadillo>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "time.h"

using namespace std; // note use of namespace
using namespace arma; // note use of namespace
int main (int argc, char* argv[])
{
  // read in dimension of square matrix
  int n = atoi(argv[1]);
  auto s = 1/sqrt( (double) n);
  // Start timing
  clock_t start, finish;
  // Allocate space for the three matrices
  mat A(n,n), B(n,n), C(n,n);
  // Set up values for matrix A and B
  for (auto i = 0; i < n; i++){
    for (auto j = 0; j < n; j++) {
      double angle = 2.0*M_PI*i*j/ (( double ) n);
      A(i,j) = s * ( sin ( angle ) + cos ( angle ) );
      B(j,i) =  A(i,j);
    }
  }
  C = 0.0;
  // Then perform the matrix-matrix multiplication using DGEMM
  start = clock();
  C = A*B;
  auto TraceMat = trace(C);
  finish = clock();
  double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
  cout << setiosflags(ios::showpoint | ios::uppercase);
  cout << setprecision(10) << setw(20) << "Time used  for matrix-matrix multiplication=" << timeused  << endl;
  cout << setprecision(10) << setw(20) << "Trace of Matrix=" << TraceMat  << endl;
  return 0;
}















