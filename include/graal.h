/*!
 * Edite esse arquivo para incluir suas respostas.
 * @author Selan
 * @date April 6th, 2022.
 */

#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
#include <algorithm>
using std::pair;

namespace graal {

/*!
 * Finds and returns a pair with the smallest and greatest elements in a range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function.Comparison functor.
 *
 * @param first_ Pointer to the first element of the range we want to copy (inclusive).
 * @param last_ Pointer to the last element of the range we want to copy (exclusive).
 * @param cmp The comparison function that return true if the first element is *less* than the
 * second.
 *
 * @return A pair of the smallest and greatest elements.
 *
 */
template <typename Itr, typename Compare>
std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp) {
  if(first == last){
    return std::make_pair(last, last); //Caso entre um conteiner vazio, retornar dois iteradores iguais
  }
    //os iteradores do menor e do maior elemento são inicializados com a primeira posição
    auto min_it = first;
    auto max_it = first;

    for(auto it = first; it != last; ++it){
      if(cmp(*it, *min_it)){
        min_it = it;
      }
      if(cmp(*max_it, *it)){
        max_it = it;
      }
    }

   return std::make_pair(min_it, max_it);
}

template <class BidirIt> void reverse(BidirIt first, BidirIt last) {
      while(first < last){
        --last;
        if(first != last){
          std::swap(*first, *last);
          ++first;
        }
      }
}

template <class InputIt> InputIt copy(InputIt first, InputIt last, InputIt d_first) {
  // TODO: add your code here.
  return first;  // This is just a stub.
}

template <class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
  // TODO: add your code here.
  return first;  // This is just a stub.
}

template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Equal eq) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt, class Equal> InputIt unique(InputIt first, InputIt last, Equal eq) {
  // TODO: add your code here.
  return first;  // This is just a stub.
}

template <class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {
  // TODO: add your code here.
  return first;  // This is just a stub.
}

}  // namespace graal.

#endif
