/*
 * ************************************************************************
 * File:    TransposeSPMX.cpp
 * Purpose: Transpose of a CRS sparse matrix: Part 2 in OpenMP code
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

int TransposeSPMXNd2(struct CRS *M, int *M1, int *M2, double *M3, int i, int *count)
{
    int j;
    for (j=M->row[i]; j<M->row[i+1]; j++){
        M2[M1[M->column[j]]+count[M->column[j]]] = i;
        M3[M1[M->column[j]]+count[M->column[j]]] = M->value[j];
        count[M->column[j]]++;
    }
    return 0;
}

