#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "vincehouhou.h"
#include "types.h"
#include <omp.h>
using namespace std;

int Gauss_SeidalNd1(struct CRS *A, int *M1, int i)
{
    int j;
    M1[i+1] = 0;
    for (j=A->row[i]; j<A->row[i+1]; j++){
        if (A->column[j]<=i){
            M1[i+1]++;
        }
    }
    //M1[i+1] += M1[i];
    return 0;
}
