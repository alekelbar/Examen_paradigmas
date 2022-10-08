#include <iostream>
#include <vector>
#include <assert.h>
#include "../include/helpers.hpp"
#include "../include/Matrix.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
  if (argc >= 2 and string(argv[1]) == "--test")
  {
    vector<int> test{1, 6, 9, 7, 2, 3};
    cout << "Waiting for {1, 6, 9, 7, 2, 3} => {2, 6, 9, 7, 3, 1} by: orderPairsAndOdd" << endl;
    assert(Equal(orderPairsAndOdd(test), {2, 6, 9, 7, 3, 1}) == true);

    DynamicMatrix<int> A{1, 2, 2};

    int cont = 1;
    for (size_t i = 0; i < A.rows(); i++)
    {
      for (size_t j = 0; j < A.cols(); j++)
      {
        A[i][j] = cont;
        cont++;
      }
    }
    cout << "La matriz A" << endl;
    A.show();

    cout << "La transpuesta de la matriz..." << endl;
    DynamicMatrix<int> transpose = A.getTranspose();
    transpose.show();

    cout << "La matriz por el scalar 2" << endl;
    DynamicMatrix<int> scalar = A * 2;
    scalar.show();

    // Tuve un error aca a la hora de liberar la memoría y no tuve tiempo de depurarlo, lo siento :(
    // como podra observar el objeto 1, se libera 2 veces...
    cout << "La matriz C = A*A" << endl;
    DynamicMatrix<int> C = A * A;
    C.show();

    cout << "\nTest suit complete" << endl;
  }

  return 0;
}
