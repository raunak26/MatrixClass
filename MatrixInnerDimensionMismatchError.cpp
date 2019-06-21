//
// Created by mfbut on 5/14/2019.
//
#include "MatrixInnerDimensionMismatchError.h"
#include "Matrix.h"
#include "DimensionMismatchError.h"
#include "MatrixDimensionMismatchError.h"
#include <iostream>
#include <sstream>


Matrix::MatrixInnerDimensionMismatchError::MatrixInnerDimensionMismatchError() {
  std::stringstream MismatchError;
  MismatchError << "Error in inner dimensions of matrix" << std::endl;
}

int Matrix::MatrixInnerDimensionMismatchError::GetnumCols() const {
  return numCols;
}

int Matrix::MatrixInnerDimensionMismatchError::GetnumRows() const {
  return numRows; // returns the number of rows of the matrix
}
