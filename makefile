/*
 * ************************************************************************
 * File:    makefile
 * Author:  Houdong Hu
 * ************************************************************************
 */

OBJS = main.o Node.o Element.o ElementNode.o Transpose.o Matrixsetup.o SparseMXsetup.o Stiffmatrix.o SparseMXreduction.o SparseMXNdsetup.o SparseMXNdreduction.o Integral.o PCG.o ExactSolution.o VecVecRed.o SPMaVecPro.o Multigrid.o VecDotPro.o VecVecAdd.o VecNumPro.o GetA.o Gauss_Seidal.o Restriction.o Prolongation.o GaussEli.o TransposeSPMX.o Timer.o ProlongationNd.o RestrictionNd.o SPMaVecProNd.o Gauss_SeidalNd1.o Gauss_SeidalNd2.o GaussEliNd1.o GaussEliNd2.o TransposeSPMXNd1.o TransposeSPMXNd2.o
CC = g++
DEBUG = -g
CFLAGS = -fopenmp -Wall -c $(DEBUG)
LFLAGS = -fopenmp -Wall $(DEBUG)

vincehouhou : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o vincehouhou

main.o : main.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) main.cpp

Node.o : Node.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Node.cpp

Element.o : Element.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Element.cpp

ElementNode.o : ElementNode.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) ElementNode.cpp

Transpose.o : Transpose.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Transpose.cpp

Matrixsetup.o : Matrixsetup.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Matrixsetup.cpp

SparseMXsetup.o : SparseMXsetup.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SparseMXsetup.cpp

Stiffmatrix.o : Stiffmatrix.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Stiffmatrix.cpp

SparseMXreduction.o: SparseMXreduction.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SparseMXreduction.cpp

SparseMXNdreduction.o: SparseMXNdreduction.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SparseMXNdreduction.cpp

SparseMXNdsetup.o: SparseMXNdsetup.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SparseMXNdsetup.cpp

Integral.o : Integral.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Integral.cpp

PCG.o : PCG.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) PCG.cpp

ExactSolution.o : ExactSolution.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) ExactSolution.cpp

VecVecRed.o : VecVecRed.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecVecRed.cpp

SPMaVecPro.o : SPMaVecPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SPMaVecPro.cpp

SPMaVecProNd.o : SPMaVecPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) SPMaVecProNd.cpp

Multigrid.o : Multigrid.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Multigrid.cpp

VecDotPro.o : VecDotPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecDotPro.cpp

VecVecAdd.o : VecVecAdd.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecVecAdd.cpp

VecNumPro.o : VecNumPro.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) VecNumPro.cpp

GetA.o : GetA.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GetA.cpp

Gauss_Seidal.o : Gauss_Seidal.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Gauss_Seidal.cpp

Gauss_SeidalNd1.o : Gauss_SeidalNd1.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Gauss_SeidalNd1.cpp

Gauss_SeidalNd2.o : Gauss_SeidalNd2.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Gauss_SeidalNd2.cpp

Restriction.o : Restriction.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Restriction.cpp

RestrictionNd.o : RestrictionNd.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) RestrictionNd.cpp

Prolongation.o : Prolongation.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Prolongation.cpp

ProlongationNd.o : ProlongationNd.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) ProlongationNd.cpp

GaussEli.o : GaussEli.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GaussEli.cpp

GaussEliNd1.o : GaussEliNd1.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GaussEliNd1.cpp

GaussEliNd2.o : GaussEliNd2.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) GaussEliNd2.cpp

TransposeSPMX.o : TransposeSPMX.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) TransposeSPMX.cpp

TransposeSPMXNd1.o : TransposeSPMXNd1.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) TransposeSPMXNd1.cpp

TransposeSPMXNd2.o : TransposeSPMXNd2.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) TransposeSPMXNd2.cpp

getTime.o : Timer.cpp vincehouhou.h types.h
	$(CC) $(CFLAGS) Timer.cpp

clean:
	\rm *.o vincehouhou


