/*
 * ************************************************************************* *
 * File:    GaussEli.cpp
 * Purpose: Part 1 of Gauss elimination OpenMP code
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

int GaussEliNd1(struct CRS *MT, double *r, int i)
{
     int j;
     for (j=MT->row[i]+1; j<MT->row[i+1]; j++){
        r[MT->column[j]] -= r[i]*MT->value[j]/MT->value[MT->row[i]];
     }
     return 0;
}

