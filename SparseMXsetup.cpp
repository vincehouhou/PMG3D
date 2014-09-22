/*
 * *************************************************************************
 * File:    SparseMXsetup.cpp
 * Purpose: Find the dimension of sparse matrix format of A in Ax = b
 * Author:  Houdong Hu
 * *************************************************************************
 */


#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

struct CRS *SparseMXsetup(double **No, int **El, int **E_N, int **N_E, int n0, int n1, double h)
{
    
    int nn = n0*n0*n0, i, k, l, ttest=0, tcount = 0;
    int *test = new int[nn];
    int *count = new int[nn];
    int **tja = new int*[nn];
    // #pragma omp parallel for shared(nn) private(k)
    for (k=0; k<nn; k++){
        test[k] = 0;
        count[k] =0;
        for (l=N_E[0][k]; l<N_E[0][k+1]; l++){
           test[k] = test[k] + E_N[0][N_E[1][l]+1] - E_N[0][N_E[1][l]];
        }
        ttest += test[k];
	tja[k] = new int[test[k]+1];
	for (l=0; l<test[k]+1; l++)
	     tja[k][l] = 0;
    }
     /*  test[nn] is an array to find the number of overlapping nodes with each node
     *  ttest is the number of non-zero elements in A
     *  both test and ttest are the max possible number, there can be some repeating ones
     */
    int a = (int)(log(n0-1)/log(2));
    #pragma omp parallel if (a>1) shared(nn) private(k)
    {
    #pragma omp for
    for (k=0; k<nn; k++){
	SparseMXNdsetup(El, E_N, N_E, count, tja, n0, k);
    }
    }
    for (k=0; k<nn; k++)
	tcount += count[k];
    struct CRS *MMX = new struct CRS;
    int *MX1 = new int [nn+1];
    MX1[0] = 1;
    for (k=1; k<nn+1; k++){
        MX1[k] = MX1[k-1] + count[k-1];
    }
    int *MX2 = new int [tcount+1];
    double *MX3 = new double [tcount+1];
    i=1;
    //#pragma omp parallel for shared(nn) private(k)
    for (k=0; k<nn; k++){
	MX3[k] = 0;
	for (l=1; l<=count[k]; l++){
		MX2[i] = tja[k][l];
        i++;
	}
    }
    MX2[0] = tcount;
    MX3[0] = tcount;
    MMX->row = MX1;
    MMX->column = MX2;
    MMX->value = MX3;
    return (MMX);
}
