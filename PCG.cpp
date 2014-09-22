/*
 * ************************************************************************* *
 * File:    PCG.cpp
 * Purpose: Implement preconditionded conjugate gradient method
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

double *PCG(double **No, struct CRS *MX, double *V, int n0, double h)
{
    int i, k = 0, n = (n0-2)*(n0-2)*(n0-2), *level;
    double rho, rho1,belta, alpha, error = 0.5, error_limit = 1/double (pow(10, 5));
    double *x = new double [n];
    double *x0 = new double [n];
    double *x1 = new double [n];
    double *r = new double [n];
    double *z = new double [n];
    double *p = new double [n];
    double *q = new double [n];
    for (i=0; i<n; i++){
        x[i] = 0;
        x0[i] = 0;
        x1[i] = 0;
        r[i] = 0;
        z[i] = 0;
        p[i] = 0;
        q[i] = 0;
    }
    int a = (int)(log(n0-1)/log(2));
    level = &a;
    x = ExactSolution(No, n0, h);
    do {
    	r = VecVecRed(V, SPMaVecPro(MX, x0, n), n);
       	cout << "Error in " << k << "th step is " << VecDotPro(r, r, n) << endl;
        z = Multigrid(level, MX, r, n0, h);
        rho = VecDotPro(r, z, n);
        if (k>0){
            belta = rho/rho1;
            p = VecVecAdd(z, VecNumPro(p, belta, n), n);
        }
        else
            p = z;
        q = SPMaVecPro(MX, p, n);
        alpha = rho/VecDotPro(p, q, n);
        x1 = VecVecAdd(x0, VecNumPro(p, alpha, n), n);
        rho1 = rho;
        k = k+1;
        error = VecDotPro(VecVecRed(x1, x0, n), VecVecRed(x1, x0, n), n)/n;
        x0 = x1;
    }
    while (error > error_limit);
    return(x1);
}
    
