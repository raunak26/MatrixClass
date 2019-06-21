//
// Created by mfbut on 5/19/2019.
//

#ifndef MATRIX_DIVIDEBYZEROERROR_H
#define MATRIX_DIVIDEBYZEROERROR_H
#include "MatrixError.h"
#include "Matrix.h"

//used to signify an attempted division by scalar value 0
namespace Matrix {

//should inherit from MatrixError
class DivideByZeroError : public MatrixError {
 public:
  //void catchDivideByZeroError{
//    if (scalar == 0) {      //this code belongs in the operators for the division and multiplication operators
//      throw runtime_error;


  DivideByZeroError(double scalar);
 protected:
  double scalar;
  //virtual const char* what() const noexcept override;
//~DivideByZeroError()= default;
};
}

#endif //MATRIX_DIVIDEBYZEROERROR_H
