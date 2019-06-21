//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_MATRIXOUTOFBOUNDSERROR_H
#define MATRIX_MATRIXOUTOFBOUNDSERROR_H
#include "OutOfBoundsError.h"
//used to signify that at least one of the indices
//used to access an element in a matrix is out of bounds
namespace Matrix {

//should inherit from OutOfBoundsError
class MatrixOutOfBoundsError : public OutOfBoundsError {
 public:
  //void catchMatrixOutOfBoundsError() {
//  if (i > matrix.getNumCols - 1) || (j > matrix.getNumRows - 1) {    //not needed
//    throw out_of_range;
//    //goes in matrix and vector
//  }

  MatrixOutOfBoundsError(const Matrix &matrix, int row);
  MatrixOutOfBoundsError(const Matrix &matrix, int row, int indexedcol);


  //MatrixOutOfBoundsError();
  //parameters
//~MatrixOutOfBoundsError() = default;
 protected:
  int numRows, numCols, indexAccessed, col;
 public:
  int GetnumRows() const;
  int GetnumCols() const;
  int GetIndexAccessed() const;
  int GetColAccessed() const;
};
}

#endif //MATRIX_MATRIXOUTOFBOUNDSERROR_H
