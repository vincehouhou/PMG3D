/*
 * ************************************************************************* *
 * File:    Prolongation.cpp
 * Purpose: Prolongation step in multigrid solver
 * Author:  Houdong Hu
 * ************************************************************************* */

#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

double *Prolongation(int *level, double *r)
{
    int n0 = (int)(pow(2, (*level)-1)+1);
    int n1 = (int)(pow(2, *level)+1); 
    int i, j, k, m, nn = (n0-2)*(n0-2), nnn = (n1-2)*(n1-2), nnnn = (n0-2)*(n0-2)*(n0-2), nnnnn = (n1-2)*(n1-2)*(n1-2);
    double ***vv = new double**[n1];
    for (i=0; i<n1; i++){
        vv[i] = new double*[n1];
        for (j=0; j<n1; j++){
            vv[i][j] = new double[n1];
            for (k=0; k<n1; k++)
                vv[i][j][k] = 0;
        }
    }
    double *qq = new double [nnnnn];
    #pragma omp parallel if ((*level)>3) shared(nnnn) private(k)
    {
    #pragma omp for
    for (m=1; m<=nnnn; m++){
        ProlongationNd(vv, r, m, nn, n0);
    }
    }
    for (m=1; m<=nnnnn; m++){
        k = (int)((m-1)/nnn)+1;
        j = (int)((m-1-(k-1)*nnn)/(n1-2))+1;
        i = m-(j-1)*(n1-2)-(k-1)*nnn;
        m = i + (j-1)*(n1-2) + (k-1)*nnn;
        qq[m-1] = vv[i][j][k];
    }
    return qq;
}
                
