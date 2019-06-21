//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_MATRIXDIMENSIONMISMATCHERROR_H
#define MATRIX_MATRIXDIMENSIONMISMATCHERROR_H
#include "DimensionMismatchError.h"

//used to signify that the operation requested to be
//performed on the matrices cannot be done because
//they are not the same size
namespace Matrix {
//class DimensionMismatchError;
//should inherit from DimensionMismatchError
class MatrixDimensionMismatchError : DimensionMismatchError{
 public:
  MatrixDimensionMismatchError();
  //MatrixDimensionMismatchError() = default;
 protected:
  int numRows, numCols;
 public:
  int GetnumRows() const;
  int GetnumCols() const;
};
}

#endif //MATRIX_MATRIXDIMENSIONMISMATCHERROR_H
