#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Vector2D
{
public:
  int x;
  int y;
  Vector2D(int x, int y)
  {
    this->x = x;
    this->y = y;
  }

  Vector2D() {}
};

/**
 *
 * @brief Template class for representing a Matrix element...
 *
 * @tparam T
 */
template <typename MatrixValue>
class DynamicMatrix
{
private:
  Vector2D dim;
  MatrixValue **matrix;
  int ID; /*Only added to test implementation...*/

public:
  /**
   * @brief Construct a new Dynamic Matrix object
   *
   * @param rows by default considered as 2x2 matrix
   * @param columns by default considered as 2x2 matrix
   */
  DynamicMatrix(int id, int rows = 2, int columns = 2)
  {
    assert(rows > 0 && columns > 0);
    this->dim.x = rows;
    this->dim.y = columns;
    this->ID = id;
    this->matrix = new MatrixValue *[dim.x];
    for (size_t i = 0; i < rows; i++)
      this->matrix[i] = new MatrixValue[dim.y];
  }

  /**
   * @brief Destroy the Dynamic Matrix object and all his pointers
   *
   */
  ~DynamicMatrix()
  {
    cout << "Se libera cierta cantidad de memoria! del objeto " << this->ID << endl;
    //  Note: Tengo un problema al liberar la memoria :(, estoy alojando dos punteros con la misma dirección, pero no consegui reparar el bug a tiempo...
    for (int i = 0; i < rows(); i++)
      delete[] matrix[i];
    delete[] matrix;
  }

  /**
   * @brief overloading operator to set, and get the elements
   *
   * @param index position..
   * @return MatrixValue *ptr
   */
  MatrixValue *operator[](int index)
  {
    if (index < 0 or index >= dim.x)
      throw std::invalid_argument("Invalid index");
    return matrix[index];
  }

  /**
   * @brief Get dimensions of the matrix
   *
   * @return Vector2D
   */
  Vector2D dimensions()
  {
    return Vector2D(dim.x, dim.y);
  }

  // https://es.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:properties-of-matrix-addition-and-scalar-multiplication/a/properties-of-matrix-addition
  /**
   * @brief overloading operator + to sum matrix
   *
   * @param m
   * @return DynamicMatrix
   */
  DynamicMatrix<MatrixValue> operator+(DynamicMatrix<MatrixValue> &m) const
  {
    assert(this->rows() == m.rows() && this->cols() == m.cols());

    DynamicMatrix<MatrixValue> result(m.rows(), m.cols());

    for (size_t i = 0; i < m.rows(); i++)
    {
      for (size_t j = 0; j < m.cols(); j++)
      {
        result[i][j] = this->matrix[i][j] + m[i][j];
      }
    }
    return result;
  }

  /**
   * @brief overloading operator * for scalar multiplication
   *
   * @tparam Scalar
   * @param scalar
   * @return DynamicMatrix<MatrixValue>
   */
  template <typename Scalar>
  DynamicMatrix<MatrixValue> operator*(const Scalar scalar) const
  {
    DynamicMatrix<MatrixValue> result(3, this->rows(), this->cols());
    for (size_t i = 0; i < this->rows(); i++)
    {
      for (size_t j = 0; j < this->cols(); j++)
      {
        result[i][j] = this->matrix[i][j] * scalar;
      }
    }
    return result;
  }

  /**
   * @brief matrix multiplication
   *
   * @param m
   * @return DynamicMatrix<MatrixValue>
   */
  DynamicMatrix<MatrixValue> operator*(DynamicMatrix<MatrixValue> m) const
  {
    assert(this->cols() == m.rows());
    int rows = this->rows();
    int cols = m.cols();
    DynamicMatrix<MatrixValue> result(4, rows, cols);

    for (int c = 0; c < rows; c++)
    {
      for (int r = 0; r < cols; r++)
      {
        for (int in = 0; in < cols; in++)
        {
          result[c][r] += matrix[c][in] * m[in][r];
        }
      }
    }
    return result;
  }

  DynamicMatrix<MatrixValue> getTranspose()
  {
    DynamicMatrix<MatrixValue> transpose(0, cols(), rows());
    for (size_t i = 0; i < rows(); i++)
    {
      for (size_t j = 0; j < cols(); j++)
      {
        transpose[j][i] = this->matrix[i][j];
      }
    }
    return transpose;
  }

  /**
   * @brief show matrix elements
   *
   */
  void show() const
  {
    for (size_t i = 0; i < rows(); i++)
    {
      for (size_t j = 0; j < cols(); j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  int rows() const { return this->dim.x; }
  int cols() const { return this->dim.y; }
};
