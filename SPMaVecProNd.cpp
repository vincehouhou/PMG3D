/*
 * ************************************************************************
 * File:    main.cpp
 * Purpose: Product of a CRS sparse matrix and a vector in OpenMP code
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

int SPMaVecProNd(struct CRS *MX, double *q, double *p, int n, int i)
{
    int j;
    q[i] = 0;
    for (j=MX->row[i]; j<MX->row[i+1]; j++){
        q[i] += MX->value[j]*p[MX->column[j]];
    }
    return 0;
}

