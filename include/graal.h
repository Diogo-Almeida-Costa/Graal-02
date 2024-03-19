/*!
 * Edite esse arquivo para incluir suas respostas.
 * @author Selan
 * @date April 6th, 2022.
 */

#ifndef GRAAL_H
#define GRAAL_H

using std::pair;

namespace graal {

/**
 * @brief Encontra os elementos mínimo e máximo em um intervalo, usando um comparador personalizado.
 * 
 * Esta função encontra os elementos mínimo e máximo em um intervalo definido pelos iteradores 'first' e 'last',
 * usando um comparador personalizado 'cmp' para determinar a ordem dos elementos.
 * 
 * @tparam Itr O tipo do iterador para o intervalo.
 * @tparam Compare O tipo do comparador para ordenação.
 * @param first Um iterador para o primeiro elemento do intervalo.
 * @param last Um iterador para o último elemento do intervalo (exclusivo).
 * @param cmp O comparador usado para determinar a ordem dos elementos. Deve retornar true se o primeiro elemento for considerado menor do que o segundo.
 * @return Um par de iteradores, o primeiro apontando para o elemento mínimo e o segundo para o elemento máximo.
 */

template <typename Itr, typename Compare>
std::pair<Itr, Itr> minmax(Itr first, Itr last, Compare cmp) {
   if(first == last){
    return std::make_pair(first, first);
   }
   auto min_it = first;
   auto max_it = first;
   for(auto it = first; it != last; ++it){
    if(cmp(*it, *min_it) || (!cmp(*min_it, *it) && it < min_it )){
      min_it = it;
    }
    if(cmp(*max_it, *it) || (!cmp(*it, *max_it) && it > max_it)){
      max_it = it;
    }
   }

  return std::make_pair(min_it, max_it);
}


/**
 * @brief Reverte a ordem dos elementos em um intervalo.
 *
 * Esta função reverte a ordem dos elementos em um intervalo definido pelos iteradores @p first e @p last.
 *
 * @tparam BidirIt O tipo do iterador bidirecional usado para acessar os elementos.
 * @param first Um iterador para o início do intervalo.
 * @param last Um iterador para o final do intervalo (após o último elemento).
 */

template <class BidirIt> void reverse(BidirIt first, BidirIt last) {
      while(first < last){
        --last;
        if(first != last){
          std::swap(*first, *last);
          ++first;
        }
      }
}


/**
 * @brief Copia elementos de um intervalo para outro.
 *
 * Esta função copia os elementos de um intervalo definido pelos iteradores @p first e @p last
 * para outro intervalo definido pelo iterador @p d_first.
 *
 * @tparam InputIt O tipo do iterador de entrada usado para acessar os elementos do intervalo de origem e destino.
 * @param first Um iterador para o início do intervalo de origem.
 * @param last Um iterador para o final do intervalo de origem (após o último elemento).
 * @param d_first Um iterador para o início do intervalo de destino.
 * @return Um iterador apontando para o próximo elemento no intervalo de destino após a cópia.
 */

template <class InputIt> InputIt copy(InputIt first, InputIt last, InputIt d_first) {
    while(first != last){
      *d_first = *first;
      ++first;
      ++d_first;
    }
    return d_first;
}


/**
 * @brief Encontra o primeiro elemento em um intervalo que satisfaz um predicado.
 *
 * Esta função percorre o intervalo definido pelos iteradores @p first e @p last, e retorna
 * um iterador para o primeiro elemento que satisfaz o predicado especificado pela função
 * @p p.
 *
 * @tparam InputIt O tipo do iterador de entrada usado para acessar os elementos do intervalo.
 * @tparam UnaryPredicate O tipo do predicado unário que determina se um elemento satisfaz a condição.
 * @param first Um iterador para o início do intervalo.
 * @param last Um iterador para o final do intervalo (após o último elemento).
 * @param p O predicado unário que define a condição que o elemento deve satisfazer.
 * @return Um iterador para o primeiro elemento que satisfaz o predicado, ou @p last se nenhum elemento for encontrado.
 */

template <class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
  while(first != last){
    if(p(*first)){
      return first;
    }
    ++first;
  }
  return last;
}

/**
 * @brief Verifica se todos os elementos de um intervalo satisfazem um predicado.
 *
 * Esta função verifica se todos os elementos no intervalo definido pelos iteradores @p first
 * e @p last satisfazem o predicado especificado pela função @p p.
 *
 * @tparam InputIt O tipo do iterador de entrada usado para acessar os elementos do intervalo.
 * @tparam UnaryPredicate O tipo do predicado unário que determina se um elemento satisfaz a condição.
 * @param first Um iterador para o início do intervalo.
 * @param last Um iterador para o final do intervalo (após o último elemento).
 * @param p O predicado unário que define a condição que cada elemento deve satisfazer.
 * @return `true` se todos os elementos do intervalo satisfazem o predicado, `false` caso contrário.
 */

template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
  while(first != last){
    if(!p(*first)){
      return false;
    }
    ++first;
  }
  return true;
}

/**
 * @brief Verifica se algum elemento de um intervalo satisfaz um predicado.
 *
 * Esta função verifica se pelo menos um dos elementos no intervalo definido pelos iteradores @p first
 * e @p last satisfaz o predicado especificado pela função @p p.
 *
 * @tparam InputIt O tipo do iterador de entrada usado para acessar os elementos do intervalo.
 * @tparam UnaryPredicate O tipo do predicado unário que determina se um elemento satisfaz a condição.
 * @param first Um iterador para o início do intervalo.
 * @param last Um iterador para o final do intervalo (após o último elemento).
 * @param p O predicado unário que define a condição que pelo menos um elemento deve satisfazer.
 * @return `true` se pelo menos um elemento do intervalo satisfaz o predicado, `false` caso contrário.
 */

template <class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
  while(first != last){
    if(p(*first)){
      return true;
    }
    first++;
  }
  return false;
}


/**
 * @brief Verifica se nenhum elemento de um intervalo satisfaz um predicado.
 *
 * Esta função verifica se nenhum dos elementos no intervalo definido pelos iteradores @p first
 * e @p last satisfaz o predicado especificado pela função @p p.
 *
 * @tparam InputIt O tipo do iterador de entrada usado para acessar os elementos do intervalo.
 * @tparam UnaryPredicate O tipo do predicado unário que determina se um elemento satisfaz a condição.
 * @param first Um iterador para o início do intervalo.
 * @param last Um iterador para o final do intervalo (após o último elemento).
 * @param p O predicado unário que define a condição que nenhum elemento deve satisfazer.
 * @return `true` se nenhum elemento do intervalo satisfaz o predicado, `false` caso contrário.
 */

template <class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
  for(auto it = first; it != last; ++it){
    if(p(*it)){
      return false;
    }
  }
  return true;
}


/**
 * @brief Verifica se dois intervalos são iguais.
 *
 * Esta função verifica se o intervalo definido pelos iteradores @p first1 e @p last1 é igual ao
 * intervalo definido pelos iteradores @p first2 e @p first2 + (last1 - first1).
 *
 * @tparam InputIt1 O tipo do iterador de entrada usado para acessar os elementos do primeiro intervalo.
 * @tparam InputIt2 O tipo do iterador de entrada usado para acessar os elementos do segundo intervalo.
 * @tparam Equal O tipo do predicado binário que determina se dois elementos são iguais.
 * @param first1 Um iterador para o início do primeiro intervalo.
 * @param last1 Um iterador para o final do primeiro intervalo (após o último elemento).
 * @param first2 Um iterador para o início do segundo intervalo.
 * @param eq O predicado binário que define a condição para igualdade entre elementos.
 * @return `true` se os intervalos forem iguais, `false` caso contrário.
 */

template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq) {
  while(first1 != last1){
    if(!eq(*first1, *first2)){
      return false;
    }
    ++first1;
    ++first2;
  }
  return true;
}

template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Equal eq) {
  while(first1 != last1){
    if(!eq(*first1, *first2)){
      return false;
    }
    ++first1;
    ++first2;
  }
  return true;
}


/**
 * @brief Remove elementos duplicados consecutivos de um intervalo.
 * 
 * @tparam InputIt O tipo do iterador para o intervalo.
 * @tparam Equal O tipo do functor de comparação de igualdade.
 * @param first Um iterador para o primeiro elemento do intervalo.
 * @param last Um iterador para o último elemento do intervalo (exclusivo).
 * @param eq Functor que determina se dois elementos são considerados iguais.
 * @return Um iterador apontando para o último elemento único no intervalo.
 */

template <class InputIt, class Equal> InputIt unique(InputIt first, InputIt last, Equal eq) {
  if(first == last){
    return first;
  }
  auto result = first;
  while(++first != last){
    if((eq(*result, *first)) ){
      *result = std::move(*first);
    }
  }
  return result;
}


/**
 * @brief Rearranja os elementos em um intervalo de forma que os elementos que satisfazem um predicado estejam antes dos elementos que não satisfazem.
 * 
 * @tparam ForwardIt O tipo do iterador para o intervalo.
 * @tparam UnaryPredicate O tipo do predicado unário que determina se um elemento satisfaz a condição.
 * @param first Um iterador para o primeiro elemento do intervalo.
 * @param last Um iterador para o último elemento do intervalo (exclusivo).
 * @param p O predicado que determina se um elemento satisfaz a condição.
 * @return Um iterador para o elemento imediatamente após o último elemento que satisfaz a condição.
 */
template <class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {
  while(first != last){
    while(p(*first)){
      if(++first == last){
        return first;
      }
    }
    do{
      if(--last == first){
        return first;
      }
    } while(!p(*last));
    std::iter_swap(first++, last);
  }
  return first;
}

}  // namespace graal.

#endif
