/*
 * ************************************************************************
 * File:    TransposeSPMX.cpp
 * Purpose: Transpose of a CRS sparse matrix: Part 1 in OpenMP code
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

int TransposeSPMXNd1(struct CRS *M, int *test, int i)
{
    int j;
    for (j=M->row[i]; j<M->row[i+1]; j++){
        test[M->column[j]]++;
    }
    return 0;
}

