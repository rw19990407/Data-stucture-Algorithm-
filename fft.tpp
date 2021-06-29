#include "fft.hpp"
#include <stdexcept>
#define M_PI 3.14159265358979323846// for C++
#include <cmath>

std::size_t bitreverse(std::size_t x, int log2n){ 

  std::size_t n = 0; 
  for (std::size_t i = 0; i < log2n; i++){ 
    n <<= 1; 
    n |= (x & 1); 
    x >>= 1; 
  } 
  return n; 
}

template<std::size_t N>
Signal<Complex, N> fft(const Signal<Complex, N>& input) {
    std::size_t X = input.length(); //the X = input length
    if ((X != 0) && ((X & (X - 1)) != 0)) { //if the length is zero or not power of two. throw an error message

        throw std::invalid_argument("index out of range");
    }
    Signal<Complex, N> output;
    for (int i = 0; i <= X - 1; ++i) {
        output[i] = input[bitreverse(i, log2(X))];
    }
            for (int s = 1; s <= log2(X); ++s) {
                Complex w(1., 0); //complex w
                for (int j = 0; j < pow(2,s-1); ++j) {
                    for (int k = j; k <= X - 1; k = k + pow(2, s)) {
                        Complex a = output[k + pow(2, (s - 1))]; //assign a = output [k+pow(2,(s-1))]
                        Complex t = mul(w, a); //t = w*output[k+pow(2,s-1)]
                        Complex u = output[k];
                        output[k] = add(u, t); //output[k] = u + t
                        Complex minus_t = neg(t); //minus_t = - t 
                        output[k + pow(2, s - 1)] = add(u, minus_t); // u - t 
                    }
                    Complex z(cos((-2* M_PI)/pow(2, s)), sin((-2* M_PI)/ pow(2, s))); //translate the polar form to rectangular
                    // Note: the following has to be adapted to your Complex class
                     w = mul(w, z);
                }
            }
            return output;
   
}
       
// TODO
