//
// Created by mfbut on 5/14/2019.
//

#include "MatrixOutOfBoundsError.h"
#include "MatrixError.h"
#include "OutOfBoundsError.h"
#include "Matrix.h"
#include <sstream>

Matrix::MatrixOutOfBoundsError::MatrixOutOfBoundsError(const Matrix &matrix, int index) : numRows(matrix.getNumRows()),numCols(matrix.getNumCols()), indexAccessed(index) {
  std::stringstream OutOfBoundsError;
  OutOfBoundsError << "Index out of bounds error" << std::endl;
  error = OutOfBoundsError.str();
}

Matrix::MatrixOutOfBoundsError::MatrixOutOfBoundsError(const Matrix &matrix, int index, int indexedcol) : numRows(matrix.getNumRows()),numCols(matrix.getNumCols()), indexAccessed(index), col(indexedcol) {
  std::stringstream OutOfBoundsError;
  OutOfBoundsError << "Index out of bounds error" << std::endl;
  error = OutOfBoundsError.str();
}

int Matrix::MatrixOutOfBoundsError::GetnumRows() const {
  return numRows;
}
int Matrix::MatrixOutOfBoundsError::GetnumCols() const {
  return numCols;
}

int Matrix::MatrixOutOfBoundsError::GetColAccessed() const{
  return col;
}

int Matrix::MatrixOutOfBoundsError::GetIndexAccessed() const {
  return indexAccessed;
}



