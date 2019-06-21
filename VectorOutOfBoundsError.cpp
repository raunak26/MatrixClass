//
// Created by mfbut on 5/14/2019.
//


#include "VectorOutOfBoundsError.h"
#include "OutOfBoundsError.h"
#include "MatrixError.h"
#include "Vector.h"
#include <sstream>

Matrix::VectorOutOfBoundsError::VectorOutOfBoundsError(const Vector &vec, int index)
: vectorSize(vec.size()), indexAccessed(index) {
  std::stringstream OutOfBoundsError;
  OutOfBoundsError << "Index out of bounds error" << std::endl;
  error = OutOfBoundsError.str();
}

int Matrix::VectorOutOfBoundsError::GetIndexAccessed() const {
  return indexAccessed;
}

int Matrix::VectorOutOfBoundsError::GetVectorSize() const {
  return vectorSize;
}

