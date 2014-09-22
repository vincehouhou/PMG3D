/*
 * ************************************************************************
 * File:    vincehouhou.h
 * Purpose: Head file of all cpp codes
 * Author:  Houdong Hu
 * ************************************************************************
 */

#ifndef _VINCEHOUHOU_H_
#define _VINCEHOUHOU_H_

double getTime();
int **Element(int n0);
int **ElementNode(int **El, int n0);
double *ExactSolution(double **No, int n0, double h);
double Integral(double x, double y, double z, double det);
double *GaussEli(struct CRS *M, double *r, int n);
int GaussEliNd1(struct CRS *MT, double *r, int i);
int GaussEliNd2(struct CRS *MT, double *r, int i);
double *Gauss_Seidal(struct CRS *A, double *b, double *z, int *level, int iter);
int Gauss_SeidalNd1(struct CRS *A, int *M1, int i);
int Gauss_SeidalNd2(struct CRS *A, int *M1, int *M2, double *M3, int i);
struct CRS *GetA(int *level, struct CRS *MX, int n0, double h);
double *Multigrid(int *level, struct CRS *MX, double *r, int n0, double h);
struct CRS *Matrixsetup(double *V, double **No, int **El, int **E_N, int **N_E,int n0, int n1, double h);
double **Node(int n0, double h);
double *PCG(double **No, struct CRS *MX, double *V, int n0, double h);
int ProlongationNd(double ***vv, double *r, int m, int nn, int n0);
double *Prolongation(int *level, double *r);
double *Restriction(int *level, double *r);
int RestrictionNd(double *q, double ***vv, int m, int nn, int n0);
int SparseMXNdreduction(int *MMX1, int *MMX2, double *MMX3, struct CRS *MX, double *Ve, double *V, int *tcount, int *tvcount, int *count, int n0, int nn, int m);
int SparseMXNdsetup(int **El, int **E_N, int **N_E, int *count, int **tja, int n0, int k);
struct CRS *SparseMXreduction(struct CRS *MX, double *Ve, double *V, int n0, int nn);
struct CRS *SparseMXsetup(double **No, int **El, int **E_N, int **N_E, int n0, int n1, double h);
double *SPMaVecPro(struct CRS *MX, double *p, int n);
int SPMaVecProNd(struct CRS *MX, double *q, double *p, int n, int i);
int Stiffmatrix(struct CRS *MX, double *Ve, double **No, int **El, int n1, int k, double h);
int **Transpose(int **E_N, int n0);
int TransposeSPMXNd1(struct CRS *M, int *test, int i);
int TransposeSPMXNd2(struct CRS *M, int *M1, int *M2, double *M3, int i, int *count);
struct CRS *TransposeSPMX(struct CRS *M, int n);
double VecDotPro(double *a, double *b, int n);
double *VecNumPro(double *p, double belta, int n);
double *VecVecAdd(double *a, double *b, int n);
double *VecVecRed(double *a, double *b, int n);

#endif
