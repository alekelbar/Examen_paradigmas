#include "../include/helpers.hpp"

// Este código lo estoy tomando de mi propio github:
// https://github.com/alekelbar/Repo-Tstructures/blob/master/src/Exercises.cpp

void merge(std::vector<int> &vect, int start, int middle, int end)
{
  // Necesitamos construir indices para recorrer las listas
  // - Inidice izq para recorrer la lista izquierda
  // se inicializa con start...
  // - Indice der para recorrer la lista derecha
  // se inicializa con middle + 1...
  // - Indice k que resulta auxiliar para ordenar
  // se inicializa con 0
  int izq = start;
  int der = middle + 1;
  int k = 0;
  std::vector<int> aux{0};

  // mientras ningun indice haya desbordado
  while (izq <= middle && der <= end)
  {
    // Al estar ordenados ambos, el menor de ambas listas
    // será el menor de todos...
    if (vect[izq] < vect[der])
    {
      aux[k] = vect[izq];
      izq++;
    }
    else
    {
      aux[k] = vect[der];
      der++;
    }
    k++;
  }

  // La finalización del ciclo implica que alguna de las dos listas se
  // acabo(desbordo) entonces toca crear un algoritmo para llenar la lista con
  // el resto de elementos...

  // Si fuese el caso de la izquierda...
  for (size_t idx = der; idx <= end; idx++)
  {
    aux[k] = vect[idx];
    k++;
  }
  // si fuese el caso de la derecha...
  for (size_t idx = izq; idx <= middle; idx++)
  {
    aux[k] = vect[idx];
    k++;
  }

  // Finalmente el vector auxiliar es una copia ordenada de toda la lista
  // pasada...
  for (size_t idx = 0; idx < k; idx++)
  {
    vect[start + idx] = aux[idx];
  }
}

void mergeSort(std::vector<int> &vect, int start, int end)
{
  // Algoritmo de ordenamiento por mezcla...
  // 1) Ordenar la mitad izquierda...
  // 2) Ordenar la mitad derecha...
  // 3) Mezcla las dos mitades...

  // localizar el valor medio del arreglo...
  int middle = (start + end) / 2; // División entera...
  if (start < end)
  {                                   // si La lista tiene al menos dos elementos...
    mergeSort(vect, start, middle);   // ordeno la mitad izquierda
    mergeSort(vect, middle + 1, end); // ordeno la mitad derecha
    merge(vect, start, middle, end);  // ordeno toda la lista...
  }
}

bool oddNumber(int x) { return x % 2 != 0; }

int howManyOdd(std::vector<int> v)
{
  int count = 0;
  for (auto &&i : v)
  {
    if (oddNumber(i))
      count++;
  }
  return count;
}

void Swap(int &x, int &y)
{
  int aux = x;
  x = y;
  y = aux;
}

std::vector<int> orderPairsAndOdd(std::vector<int> &v)
{
  // Luego de un analisis, determine el siguiente algoritmo...

  // Paso 1) Ordenar... Utilizando merge sort, para la recursividad, y eficiencia..
  mergeSort(v, 0, v.size() - 1);

  // Paso 2) desplazar todo impar a la derecha, y comparar para el orden... los pares
  // por ordenamiento ya estan ordenados..
  bubbleSortModified(v);
  return v;
}

void bubbleSortModified(std::vector<int> &v)
{
  int times = howManyOdd(v) - 1;

  for (size_t i = 0; i < times; i++)
    for (size_t j = i; j < v.size() - 1; j++)
    {
      // Dado que estan ordenados solo debe cumplirse...
      // Que un numero sea impar, y su siguiente en caso de serlo, ser mayor que el...
      if (oddNumber(v.at(j)) && !(oddNumber(v.at(j + 1)) and v.at(j + 1) < v.at(j)))
      {
        Swap(v.at(j), v.at(j + 1));
      }
    }
}
