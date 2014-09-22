#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

int Gauss_SeidalNd2(struct CRS *A, int *M1, int *M2, double *M3, int i)
{
    int j, count=0;
    for (j=A->row[i]; j<A->row[i+1]; j++){
        if (A->column[j]<=i){
            M2[M1[i]+count] = A->column[j];
            M3[M1[i]+count] = A->value[j];
            count++;
        }
    }
    return 0;
}
