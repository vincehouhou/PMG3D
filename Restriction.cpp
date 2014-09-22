/*
 * ************************************************************************
 * File:    Restriction.cpp
 * Purpose: Restriction step of a multigrid solver
 * Author:  Houdong Hu
 * ************************************************************************
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
 
double *Restriction(int *level, double *r)
{
    int n0 = (int)(pow(2, (*level)-1)+1);
    int n1 = (int)(pow(2, *level)+1);
    int i, j, k, m, nn = (n0-2)*(n0-2), nnn = (n1-2)*(n1-2), nnnn = (n0-2)*(n0-2)*(n0-2), nnnnn = (n1-2)*(n1-2)*(n1-2);
    double ***vv = new double**[n1];
    for (i=0; i<n1; i++){
        vv[i] = new double*[n1];
        for (j=0; j<n1; j++){
           vv[i][j] = new double[n1];
        }
    }
    double *q= new double [nnnn]; 
    for (m=1; m<=nnnnn; m++){
        k = (int)((m-1)/nnn)+1;
        j=(int)((m-1-(k-1)*nnn)/(n1-2))+1;
        i=m-(j-1)*(n1-2)-(k-1)*nnn;
        vv[i][j][k] = r[m-1];
    }

    #pragma omp parallel if ((*level)>3) shared (nnnn) private (m)
    {
    #pragma omp for
    for (m=1; m<=nnnn; m++){
        RestrictionNd(q, vv, m, nn, n0);
    }
    }
    return q;
}
