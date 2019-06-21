//
// Created by mfbut on 5/19/2019.
//

#include "MatrixDimensionMismatchError.h"
#include "MatrixError.h"
#include "Matrix.h"
#include <iostream>
#include <sstream>

Matrix::MatrixDimensionMismatchError::MatrixDimensionMismatchError() {
  std::stringstream MismatchError;
  MismatchError << "Matrix Dimensions are not the same" << std::endl;
  error = MismatchError.str();
}

int Matrix::MatrixDimensionMismatchError::GetnumCols() const {
  return numCols; // returns the number of columns of the matrix
}

int Matrix::MatrixDimensionMismatchError::GetnumRows() const {
  return numRows; // returns the number of rows of the matrix
}












