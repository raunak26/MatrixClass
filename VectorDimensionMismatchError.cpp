//
// Created by mfbut on 5/14/2019.
//

#include "VectorDimensionMismatchError.h"
#include "Vector.h"
#include "DimensionMismatchError.h"
#include "MatrixError.h"
#include <sstream>

Matrix::VectorDimensionMismatchError::VectorDimensionMismatchError(const Vector &vec) : vectorSize(vec.size()){
  std::stringstream MismatchError;
  MismatchError << "The dimensions of vectors do not match" << std::endl;
  error = MismatchError.str();
}

int Matrix::VectorDimensionMismatchError::GetVectorSize() const {
  return vectorSize;
}

