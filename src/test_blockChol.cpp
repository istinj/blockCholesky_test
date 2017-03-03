/*
 * test_blockChol.cpp
 *
 *  Created on: 02/mar/2017
 *      Author: istin
 */
#include <iostream>
#include <Eigen/Core>

#include "SparseMatrix.h"

SparseMatrix* s_Matrix;


int main(int argc, char **argv) {
	s_Matrix = new SparseMatrix(36, 36);

	s_Matrix->initializeMatrix(4);
}
