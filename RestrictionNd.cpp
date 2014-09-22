/*
 * ************************************************************************
 * File:    Restriction.cpp
 * Purpose: Restriction step of OpenMP code in a multigrid solver
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

int RestrictionNd(double *q, double ***vv, int m, int nn, int n0)
{
    int k = (int)((m-1)/nn)+1;
    int j = (int)((m-1-(k-1)*nn)/(n0-2))+1;
    int i = m-(j-1)*(n0-2)-(k-1)*nn;
    q[m-1] = 0.125*vv[2*i][2*j][2*k] + 0.0625*(vv[2*i-1][2*j][2*k] + vv[2*i+1][2*j][2*k] + vv[2*i][2*j-1][2*k] + vv[2*i][2*j+1][2*k] + vv[2*i][2*j][2*k-1] + vv[2*i][2*j][2*k+1]) + 0.03125*(vv[2*i][2*j-1][2*k-1] + vv[2*i][2*j-1][2*k+1] + vv[2*i][2*j+1][2*k-1] + vv[2*i][2*j+1][2*k+1] + vv[2*i-1][2*j][2*k-1] + vv[2*i-1][2*j][2*k+1] + vv[2*i+1][2*j][2*k-1] + vv[2*i+1][2*j][2*k+1] + vv[2*i-1][2*j-1][2*k] + vv[2*i-1][2*j+1][2*k] + vv[2*i+1][2*j-1][2*k] + vv[2*i+1][2*j+1][2*k]) + 0.015625*(vv[2*i-1][2*j-1][2*k-1] + vv[2*i-1][2*j-1][2*k+1] + vv[2*i-1][2*j+1][2*k-1] + vv[2*i-1][2*j+1][2*k+1] + vv[2*i+1][2*j-1][2*k-1] + vv[2*i+1][2*j-1][2*k+1] + vv[2*i+1][2*j+1][2*k-1] + vv[2*i+1][2*j+1][2*k+1]);
     return 0;
}
