//
// Created by mfbut on 5/14/2019.
//

#ifndef MATRIX_VECTORDIMENSIONMISMATCHERROR_H
#define MATRIX_VECTORDIMENSIONMISMATCHERROR_H
#include "DimensionMismatchError.h"

//used to signify that the operation can't be performed on
//the vector can't be done as they aren't the same size
namespace Matrix {
class Vector;
//class DimensionMismatchError;
//should inherit from DimensionMismatchError
class VectorDimensionMismatchError : public DimensionMismatchError{


 public:
  VectorDimensionMismatchError(const Vector &vec);
  //parameters
 protected:
  int vectorSize;
 public:
  int GetVectorSize() const;
};
}

#endif //MATRIX_VECTORDIMENSIONMISMATCHERROR_H
