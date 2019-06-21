//
// Created by mfbut on 5/14/2019.
//

#include "MatrixError.h"
#include <iostream>
#include <sstream>

const char* Matrix::MatrixError::what() const noexcept {
  return error.c_str();
}
