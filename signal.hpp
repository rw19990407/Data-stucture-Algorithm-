#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include <cstddef>
template<typename T, std::size_t N> //typename T, and a size N
class Signal
{
public:

	//constructor
	Signal(const T& value = T());

	//copy constuctor
	Signal(const Signal<T, N>& rhs);

	//assignment operator
	Signal<T, N>& operator = (const Signal<T, N>& rhs);

	//length of array
	std::size_t length() const;

	// get copy at index
	// thows std::invalid_argument if bad index
	T at(std::size_t index) const;

	// get reference to value at index
	// thows std::invalid_argument if bad index
	T& at(std::size_t index);

	//assignment 
	T operator[](std::size_t index) const;

	T& operator[](std::size_t index);

private:
	T data[N];
};

#include "signal.tpp"
#endif
