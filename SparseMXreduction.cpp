/*
 * *************************************************************************
 * File:    SparseMXreduction.cpp
 * Author:  Houdong Hu
 * *************************************************************************
 */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

struct CRS *SparseMXreduction(struct CRS *MX, double *Ve, double *V, int n0, int nn)
{
    struct CRS *MMX = new struct CRS;
    int *count = new int [(n0-2)*(n0-2)*(n0-2)];
    int *MMX1 = new int [(n0-2)*(n0-2)*(n0-2)+1];
    int *MMX2 = new int [MX->column[0]+1];
    double *MMX3 = new double [MX->column[0]+1];
    int i, m, nnnn = (n0-2)*(n0-2)*(n0-2);
    int a, b, *tcount, *tvcount;
    a=0; b=0; tcount=&a; tvcount=&b;
    int t=(n0-2)*(n0-2)*(n0-2)+1;
    MMX1[0] = 1;
    // #pragma omp parallel shared(nnnn) private(m)
    // {
    // #pragma omp for 
    //#pragma omp parallel if (nnnn>20) shared(nnnn) private(m)
    //{
    //#pragma omp for
    for (m=1; m<=nnnn; m++){
	SparseMXNdreduction(MMX1, MMX2, MMX3, MX, Ve, V, tcount, tvcount, count, n0, nn, m);
    }
    //}
    for (m=1; m<=nnnn; m++)
        MMX1[m] = MMX1[m-1] + count[m-1];
//}
    int *MMX22 = new int[*tcount+1];
    double *MMX33 = new double[*tcount+1];
    for (i=1; i<*tcount+1; i++){
        MMX22[i] = MMX2[i];
        MMX33[i] = MMX3[i];
    }
    MMX22[0] = *tcount;
    MMX33[0] = *tcount;
    MMX->row = MMX1;
    MMX->column = MMX22;
    MMX->value = MMX33;
    return(MMX);
}
