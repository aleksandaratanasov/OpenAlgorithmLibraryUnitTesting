#ifndef EQUALARRAYS_H
#define EQUALARRAYS_H

#include <vector>     // for the result of set_difference
#include <algorithm>  // for the set_difference

#define SIZE 100000

//template <typename T>
//bool equal( const std::array<T,SIZE> &v1, const std::array<T, SIZE> &v2 )
//{
//    if ( v1.size() != v2.size() )
//        return false;

//    std::unordered_map <int,T> map1, map2;

//    for ( auto it = v1.begin(); it != v1.end(); ++it )
//        map1[*it]++;

//    for ( auto it = v2.begin(); it != v2.end(); ++it )
//        map2[*it]++;

//    if ( map1 != map2 )
//        return false;

//    return true;
//}

//template <typename T>
//bool equal(const std::array<T,SIZE> &v1, const std::array<T, SIZE> &v2) {
//  std::vector<T> *diff = new std::vector<T>(SIZE*2);
//  typename std::vector<T>::iterator it;

//  it = std::set_difference(v1, v1.size(), v2, v2.size(), (*diff).begin());


//  return true;
//}

template <typename T>
bool equal(const std::array<T,SIZE> &v1, const std::array<T, SIZE> &v2) {
  typename std::array<T,SIZE>::const_iterator it1 = v1.begin();
  typename std::array<T,SIZE>::const_iterator it2 = v2.begin();

  for(; it1 != v1.end(); ++it1, ++it2)  // since we have two arrays with same size we need to check only one of the iterators
    if((*it1) != (*it2)) return false;

  return true;
}

#endif // EQUALARRAYS_H
