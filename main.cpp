#include <iostream>
#include <cmath>
#include <array>
#include <iterator>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <gtest.h>
#include <string>
#include <fstream>


#include "../OpenAlgorithmLibrary/bubblesort.h"
#include "../OpenAlgorithmLibrary/quicksort.h"
#include "../OpenAlgorithmLibrary/mergesort.h"
#include "../OpenAlgorithmLibrary/insertionsort.h"
#include "../OpenAlgorithmLibrary/shellsort.h"
#include "../OpenAlgorithmLibrary/heapsort.h"
#include "randomstring.h"
#include "equalArrays.h"

#define SIZE 100000

using std::string;

std::fstream file;

// NOTES:
// - Time measurement does not have to take place inside the test cases
// - For the random numbers use values stored in files

/******************************************************************************************************************
 * INSERTION SORT
 * NOT WORKING: with Guard and index transformation
 ******************************************************************************************************************/
TEST(doubleT, insertionSortNormal) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::normal::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(doubleT, insertionSortWithGuard) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::withguard::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/*TEST(doubleT, insertionSortWithGuardIdxTransform) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a= new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::withguardidxtransform::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}*/

TEST(intT, insertionSortNormal) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::normal::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, insertionSortWithGuard) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::withguard::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/*TEST(intT, insertionSortWithGuardIdxTransform) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::withguardidxtransform::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}*/

TEST(stringT, insertionSortNormal) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::normal::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, insertionSortWithGuard) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::withguard::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/*TEST(stringT, insertionSortWithGuardIdxTransform) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::insertionsort::withguardidxtransform::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}*/

/******************************************************************************************************************
 * HEAP SORT
 *
 ******************************************************************************************************************/
TEST(doubleT, heapSort) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::heapsort::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, heapSort) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::heapsort::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, heapSort) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::heapsort::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/******************************************************************************************************************
 * SHELL SORT
 *
 ******************************************************************************************************************/
TEST(doubleT, shellSort) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::shellsort::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, shellSort) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::shellsort::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, shellSort) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::shellsort::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/******************************************************************************************************************
 * MERGESORT SORT
 * NOT WORKING: natural
 ******************************************************************************************************************/
TEST(doubleT, mergeSortNatural) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::mergesort::natural::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(doubleT, mergeSortBottomUp) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
  sorting::mergesort::bottomup::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

  delete a;
  delete tmp;
}

/*TEST(intT, mergeSortNatural) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::mergesort::natural::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}*/

TEST(intT, mergeSortBottomUp) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::mergesort::bottomup::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/*TEST(stringT, mergeSortNatural) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::mergesort::natural::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}*/

TEST(stringT, mergeSortBottomUp) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::mergesort::bottomup::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

/******************************************************************************************************************
 * QUICK SORT
 * INCOMPLETE: hybrid
 ******************************************************************************************************************/
TEST(doubleT, quicksortNormal) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::normal::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(doubleT, quicksortBitshift) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::normalwithshift::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(doubleT, quicksort3Waypart) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::threewaypartwithshift::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(doubleT, quicksortHybrid) {
  size_t i = 0;
  double t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a = new std::array<double, SIZE>(), *tmp = new std::array<double, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayDouble", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::hybrid::sort<double, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<double>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, quicksortNormal) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::normal::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, quicksortBitshift) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::normalwithshift::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, quicksort3Waypart) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::threewaypartwithshift::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(intT, quicksortHybrid) {
  size_t i = 0;
  int t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<int, SIZE> *a = new std::array<int, SIZE>(), *tmp = new std::array<int, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayInteger", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::hybrid::sort<int, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<int>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, quickSortNormal) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::normal::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, quickSortBitshift) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::normalwithshift::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, quickSort3Waypart) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::threewaypartwithshift::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}

TEST(stringT, quickSortHybrid) {
  size_t i = 0;
  string t;
  // Allocate memory for the array that will store all numbers from the file
  std::array<string, SIZE> *a = new std::array<string, SIZE>(), *tmp = new std::array<string, SIZE>();

  // Opens text file with random numbers and load those in both arrays
  file.open("originalArrayString", std::ios::out | std::ios::in);
  for(size_t i = 0; i < SIZE; ++i) {
    file >> t;
    (*a)[i] = t;
    (*tmp)[i] = t;
  }
  file.close();

  // Shuffle content of the original array a (not tmp!)
  std::random_shuffle((*a).begin(), (*a).end());
//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new: " << (*a)[i] << std::endl;

  sorting::quicksort::hybrid::sort<string, SIZE>(*a);

  // Check if the original values have remained intact after the sorting
  EXPECT_TRUE(equal<string>((*a),(*tmp)));

  // Check if the sorted array is indeed sorted (this is actually not requires since equal also means that the sorted array is the same as the SORTED original one)
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

//  for(size_t i = 0; i < SIZE; ++i) std::cout << "old: " << (*tmp)[i] << " | new_sorted: " << (*a)[i] << std::endl;
  delete a;
  delete tmp;
}



//int main(int argc, char **argv) {
int main(int argc, char **argv) {
  // Create all files with values that will be required by the different test
  // Measure times
  std::chrono::high_resolution_clock::time_point begin, end;
  std::fstream file;

  // Values are in ascending order
  //  - double ascending array will also be used for the time measurement
  double startD = -SIZE/2;
  file.open("originalArrayDouble", std::ios::out | std::ios::trunc);
  for(size_t i = 0; i < SIZE; ++i, startD += 1.0123456789) file << startD << std::endl;
  file.close();

  int startI = -SIZE/2;
  file.open("originalArrayInteger", std::ios::out | std::ios::trunc);
  for(size_t i = 0; i < SIZE; ++i, ++startI) file << startI << std::endl;
  file.close();

  std::string startStr = "a";



  /*
  // RANDOM double
  std::random_device randDoubleDevice, randomIntegerDevice;
  std::mt19937 engI(randomIntegerDevice());
  std::mt19937 engD(randDoubleDevice());
  std::uniform_int_distribution<int> distInt(-9999999, 9999999);
  std::uniform_real_distribution<double> distDouble(-9999999.9999999, 9999999.9999999);  //(min, max)
  std::fstream file;
  size_t i;

  std::array<double, SIZE> *doubleArr = new std::array<double, SIZE>();
  file.open("randomDouble", std::ios::out | std::ios::trunc);
  for(i = 0; i < SIZE; ++i) {
    double mean = distDouble(engD);
    file << mean << "\n";
    (*doubleArr)[i] = mean;
  }
  file.close();

  std::array<double, SIZE> *doubleArr2 = new std::array<double, SIZE>();
  std::copy_n((*doubleArr).begin(), SIZE, (*doubleArr2).begin());
  begin = std::chrono::high_resolution_clock::now();
  sorting::insertionsort::normal::sort(*doubleArr);
  for(i = 0; i < SIZE; ++i) { std::cout << "OLD: " << (*doubleArr2)[i] << " | NEW: " << (*doubleArr)[i] << std::endl; }
  end = std::chrono::high_resolution_clock::now();
  std::cout << "Estimated sorting time: " << (double)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;

  delete doubleArr;

  std::array<int, SIZE> *intArr = new std::array<int, SIZE>();
  file.open("randomInteger", std::ios::out | std::ios::trunc);
  for(i = 0; i < SIZE; ++i) file << distInt(engI) << "\n";
  file.close();
  delete intArr;

  */

  size_t i;
  std::array<std::string, SIZE> *strArr = new std::array<std::string, SIZE>();
  for(i = 0; i < SIZE; ++i) (*strArr)[i] = testing::randstr(100);

  sorting::heapsort::sort(*strArr);
  file.open("originalArrayString", std::ios::out | std::ios::trunc);
  for(i = 0; i < SIZE; ++i) file << (*strArr)[i] << "\n";
  file.close();
  delete strArr;
/*
//  double startValueD = 0-SIZE/2+.00000000009;
//  std::array<double, SIZE> *a = new std::array<double, SIZE>();
//  for(size_t i = 0; i < SIZE; ++i, ++startValueD) (*a)[i] = startValueD;
//  delete a;

//  startValueD = SIZE/2;
//  a = new std::array<double, SIZE>();
//  for(size_t i = SIZE-1; i > 0; --i, startValueD-=1.0123456789) (*a)[i] = startValueD;
//  std::cout << "***************************************************" << std::endl;
////  for(size_t i = 0; i < SIZE-1; ++i) { std::cout << (*a)[i] << std::endl; }
//  delete a;*/

  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
