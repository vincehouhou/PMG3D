/*
 * ************************************************************************* *
 * File:    Multigrid.cpp
 * Purpose: Implement a multigrid preconditioner of preconditioned conjugate gradient sol\
ver
* Author:  Houdong Hu
* ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
using namespace std;

double *Multigrid(int *level, struct CRS *MX, double *b, int n0, double h)
{
    int i, iter=3, n=(int)(pow(pow(2, *level)-1, 3));
    //cout << n << endl;
    int p=1; //v-cycle
    //int p=2; //w-cycle
    struct CRS *A;
    double *z0 = new double [n];
    double *z = new double [n];
    double *r, *rr, *q, *qq;
    for (i=0; i<n; i++)
        z0[i] = 0;
    if (*level == 1){
        A = GetA(level, MX, n0, h);
        z[0] = b[0]/(A->value[1]);
    }
    else{
        A = GetA(level, MX, n0, h);
        z = Gauss_Seidal(A, b, z0, level, iter);
        r = VecVecRed(b, SPMaVecPro(A, z, n), n);
        rr = Restriction(level, r);
        for (i=0; i<p; i++){
            (*level)--;
            q = Multigrid(level, A, rr, n0, h);
            (*level)++;
        }
        qq = Prolongation(level, q);
        z = VecVecAdd(z, qq, n);
        z = Gauss_Seidal(A, b, z, level, iter);
   }
   return(z);
}


