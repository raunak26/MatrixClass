//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_OUTOFBOUNDSERROR_H
#define MATRIX_OUTOFBOUNDSERROR_H
#include "MatrixError.h"

//used to signify that an index used to access
//an element in a matrix/vector is out of bounds
namespace Matrix {

//Should inherit from MatrixError
class OutOfBoundsError : public MatrixError {
 public:
  //void catchOutOfBoundsError();
  //OutOfBoundsError();
  //~OutOfBoundsError()= default;
};
}

#endif //MATRIX_OUTOFBOUNDSERROR_H
