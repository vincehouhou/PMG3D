#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h" 
#include <omp.h>
using namespace std;

double *Gauss_Seidal(struct CRS *A, double *b, double *z, int *level, int iter)
{
    int i, n1 = (int)(pow(2, *level)+1), n = (n1-2)*(n1-2)*(n1-2);
    //cout << n << endl;
    //for (i=0; i<n; i++)
       // cout << b[i] << endl;
    //for (i=1; i<=A->column[0]; i++){
    //    cout << A->row[i] << endl;
     //	cout << A->column[i] << endl;
    //}i
    struct CRS *M = new struct CRS;
    int *M1 = new int [n+1];
    //for (i=0; i<=n; i++)
	//    M1[i] = 0;
    M1[0] = 1;
    int *M2 = new int [(A->column[0]+n)/2+1];
    double *M3 = new double [(A->column[0]+n)/2+1], *r, *x;
    #pragma omp parallel if (n>100) shared(n) private(i)
    {
    #pragma omp for
    for (i=0; i<n; i++){
        Gauss_SeidalNd1(A, M1, i);
    }
    }
    for (i=0; i<n; i++)
        M1[i+1] += M1[i];
    #pragma omp parallel if (n>100) shared(n) private(i)
    {
    #pragma omp for
    for (i=0; i<n; i++){
        Gauss_SeidalNd2(A, M1, M2, M3, i);
    }
    }
    /*for (i=0; i<n; i++){
        for (j=A->row[i]; j<A->row[i+1]; j++){
            if (A->column[j]<=i){
                count++;
                //cout << count << endl;
                M1[i+1]++;
                M2[count] = A->column[j];
               // cout << i+1000 << endl;
		//cout << M2[count] << endl;
                M3[count] = A->value[j];
            }
        }
        M1[i+1] += M1[i];
        //cout << M2[M1[i+1]-1] << endl;
        //cout << M1[i] << endl;
    }
    */
    //cout << A->row[0] << endl;
    //cout << 1 << endl;
    //for (i=0; i<5; i++)
       // cout << M1[i] << endl;
    M2[0] = M1[n]-1;
    M3[0] = M1[n]-1;
    M->row = M1;
    M->column = M2;
    M->value = M3;
    //for (i=0; i<n; i++)
       // cout << M->column[M->row[i+1]-1] << endl;
    //cout << 1 << endl;
    for (i=0; i<iter; i++){
        //cout << i << endl;
        r = VecVecRed(b, SPMaVecPro(A, z, n), n);
        //cout << 20 << endl;
  //  cout << VecDotPro(r, r, n) << endl;
        //cout << r[0] << endl;
        //for (i=0; i<n; i++)
         //   cout << b[342] << endl;
        //cout << r[5] << endl;
        //for (i=1; i<n; i++)
          //  r[i] = 1;
        //cout << M->row[1] << endl;
        x = GaussEli(M, r, n);
        //cout << 30 << endl;
        // cout << VecDotPro(x, x, n) << endl;
        //cout << x[0] << endl;
        z = VecVecAdd(z, x, n);
        //cout << 40 << endl;
        // cout << z[0] << endl;
    }
    //cout << 4 << endl;
    return(z);
}
