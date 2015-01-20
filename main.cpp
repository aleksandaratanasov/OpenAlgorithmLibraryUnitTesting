#include <iostream>
#include <cmath>
#include <array>
#include <iterator>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <gtest.h>

#include <fstream>

#include "../OpenAlgorithmLibrary/bubblesort.h"
#include "../OpenAlgorithmLibrary/quicksort.h"
#include "../OpenAlgorithmLibrary/mergesort.h"
#include "../OpenAlgorithmLibrary/insertionsort.h"
#include "../OpenAlgorithmLibrary/shellsort.h"
#include "../OpenAlgorithmLibrary/heapsort.h"

#define SIZE 1000

// NOTES:
// - Time measurement does not take place inside the test cases
// - Write SMALL test cases (arrays with 10-50); exception: quicksort hybrid (because of the insertion sort)

// Check if two arrays are equal (since we use unordered_map, the order is not important, which is perfect!)
bool equal( const std::array<double,SIZE> &v1, const std::array<double, SIZE> &v2 )
{
    if ( v1.size() != v2.size() )
        return false;

    std::unordered_map <int,int> map1, map2;

    for ( auto it = v1.begin(); it != v1.end(); ++it )
        map1[*it]++;

    for ( auto it = v2.begin(); it != v2.end(); ++it )
        map2[*it]++;

    if ( map1 != map2 )
        return false;

    return true;
}

void sortBubble(std::array<double,SIZE>& a) {
  if(SIZE < 2)
    return;

  size_t index = 0;
  size_t d;
  double pivot;

  for(; index < a.size()-1; ++index)
    for(d = 0; d < (SIZE - index - 1); ++d)
      if(a[d] > a[d + 1]) {
        pivot = a[d];
        a[d] = a[d + 1];
        a[d + 1] = pivot;
      }
}

// Example test cases for the bubble sort
TEST(doubleRandom, sortBubble) {
  // Opens text file with random numbers
  std::fstream fileDoubles;
  fileDoubles.open("randomDouble", std::ios::out | std::ios::in);
  std::cout << "COUNT: " << SIZE << std::endl;

  // Allocate memory for the array that will store all numbers from the file
  std::array<double, SIZE> *a= new std::array<double, SIZE>(), *aCopy = new std::array<double, SIZE>();

  // Fill the array
  for(size_t i = 0; i < SIZE; ++i) {
    double tmp;
    fileDoubles >> tmp;
    (*a)[i] = tmp;
    (*aCopy)[i] = tmp;
//    std::cout << (*a)[i] << std::endl;
  }

  fileDoubles.close();

  size_t i = 0;
  std::cout << "Sorting...";
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  sorting::bubblesort::sort(*a);
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Done" << std::endl;

  EXPECT_TRUE(equal((*a),(*aCopy)));
  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

  std::cout << "Estimated sorting time: " << (double)std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;
  delete a;
}

TEST(doubleAscending, sortBubble) {
  std::array<double,SIZE> *a = new std::array<double,SIZE>();
  size_t i = 0;

  double d = 0 - SIZE/2;

  for(; i < SIZE; ++i) (*a)[i] = d++;

  std::cout << "Sorting...";
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  sortBubble(*a);
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Done" << std::endl;

  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

  std::cout << "Estimated sorting time: " << (double)std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;
  delete a;
}

TEST(doubleDescending, sortBubble) {
  std::array<double,SIZE> *a = new std::array<double,SIZE>();
  size_t i = 0;

  double d = 0 - SIZE/2;

  for(; i < SIZE; ++i) (*a)[i] = d++;

  std::reverse((*a).begin(), (*a).end());

  std::cout << "Sorting...";
  std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
  sortBubble(*a);
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
  std::cout << "Done" << std::endl;

  for(i = 0; i < SIZE-1; ++i) EXPECT_LE((*a)[i],(*a)[i+1]);

  std::cout << "Estimated sorting time: " << (double)std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;
  delete a;
}

//int main(int argc, char **argv) {
int main(int argc, char **argv) {
  std::random_device randDoubleDevice;//, randIntDevice;
  std::mt19937 engD(randDoubleDevice());
  std::uniform_real_distribution<double> distDouble(-9999999.9999999, 9999999.9999999);  //(min, max)

  std::fstream fileDoubles;

  fileDoubles.open("randomDouble", std::ios::out | std::ios::trunc);
  for(size_t i = 0; i < SIZE; ++i) fileDoubles << distDouble(engD) << "\n";
  fileDoubles.close();

  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
