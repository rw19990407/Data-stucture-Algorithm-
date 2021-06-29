#include "signal.hpp"

#include <stdexcept>
// TODO
template<typename T, std::size_t N>
Signal<T,N>::Signal(const T& value){

  for(std::size_t i = 0; i < N; ++i){
    data[i] = value;
  }
}

//assignment
template<typename T, std::size_t N>
Signal<T,N>::Signal(const Signal<T,N> & rhs){

  for(std::size_t i = 0; i < N; ++i){
    data[i] = rhs.data[i];
  }
}

//operator
template<typename T, std::size_t N>
Signal<T,N> & Signal<T,N>::operator=(const Signal<T,N> & rhs){

  for(std::size_t i = 0; i < N; ++i){
    data[i] = rhs.data[i];
  }

  return *this;
}

//std length
template<typename T, std::size_t N>
std::size_t Signal<T,N>::length() const{
  return N;
}

//T at(std::size_t)
template<typename T, std::size_t N>
T Signal<T,N>::at(std::size_t index) const{

    if(index >= N){
    throw std::invalid_argument("index out of range");
  }
  return data[index];
}

//T & at
template<typename T, std::size_t N>
T & Signal<T,N>::at(std::size_t index) {
      if(index >= N){
    throw std::invalid_argument("index out of range");
  }
    
  return data[index];
}

//T operator
template<typename T, std::size_t N>
T Signal<T, N>::operator[](std::size_t index) const {

    return data[index];
}

//T&operator
template<typename T, std::size_t N>
T & Signal<T, N>::operator[](std::size_t index) {

    return data[index];
}