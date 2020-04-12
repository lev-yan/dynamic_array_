#include <iostream>
#include <limits>
#include <exception>
#include <stdexcept>
#include "dyn_arr.hpp"
#define max_size std::numeric_limits<T>::max()
#define min_size std::numeric_limits<T>::min()

	template <typename T>
Dy_arr<T>::Dy_arr() : m_ptr(nullptr), 
	m_size(0), 
	m_num_of_elem(0)
{
	std::cout << "=== Dy_arr def ctor called " << std::endl;
}

	template <typename T>
Dy_arr<T>::Dy_arr(const int& size) : m_size(size)
{
	try{
		if (size > max_size || size < 0){ 
			throw std::out_of_range("out of range ");
		}
	}
	catch(const std::out_of_range & s)
	{
		std::cerr << s.what() << std::endl;
		exit(0);
		//std::terminate();
	}
	if (m_size == 0){
		m_ptr = nullptr;
	} else {
		m_ptr = new T[m_size];
		for (int i = 0; i <  m_size; ++i){
			m_ptr[i] = 0;
		}
	}
	std::cout << "=== Dy_arr param ctor called " << std::endl;
}

	template <typename T>
Dy_arr<T>::Dy_arr(const Dy_arr & obj) : m_size(obj.m_size)
{
	if (m_size == 0){
		m_ptr = nullptr;
	} else {
		m_ptr = new T[obj.m_size];
		for (int i = 0; i < m_size; ++i){
			m_ptr[i] = obj.m_ptr[i];
		}
	}
	std::cout << "=== Dy_arr copy ctor called " << std::endl;
}

	template <typename T>
Dy_arr<T>::Dy_arr(Dy_arr && obj) : m_size(obj.m_size)
{
	if (m_size == 0){
		m_ptr = nullptr;
	} else {
		m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
		obj.m_size = 0;
		std::cout << "=== Dy_arr move ctor called " << std::endl;
	}
}

	template <typename T>
Dy_arr<T> & Dy_arr<T>::operator=(const Dy_arr & obj)
{
	if (this == &obj){
		return *this;
	}
	if (m_size < obj.m_size){
		delete[] m_ptr;
		m_ptr = new T[obj.m_size];
		m_size = obj.m_size;
		m_num_of_elem = obj.m_num_of_elem;
		for (int i = 0; i < obj.m_size; ++i){
			m_ptr[i] = obj.m_ptr[i];
		}
		return *this;
	} else {
		for (int i = 0; i < obj.m_size; ++i){
			m_ptr[i] = obj.m_ptr[i];
		}
	}
	return *this;
	std::cout << "=== Dy_arr copy ass oper called " << std::endl;
}

	template <typename T>
Dy_arr<T> & Dy_arr<T>::operator=(Dy_arr && obj)
{
	if (this == &obj){
		return *this;
	} else {
		delete[] m_ptr;
		m_ptr = obj.m_ptr;
		m_size = obj.m_size;
		m_num_of_elem = obj.m_num_of_elem;
		obj.m_ptr = nullptr;
		obj.m_size = 0;
		obj.m_num_of_elem = 0;
		return *this;
	}
}

	template <typename T>
T& Dy_arr<T>::operator[](const int& index)
{
	try
	{
		if (index >= m_size || index < 0)
			throw std::invalid_argument("out of range error");
	}
	catch(const std::invalid_argument & i)
	{
		std::cerr << i.what() << std::endl;
		exit(0);
		//std::terminate();
	}
	return m_ptr[index];
}

	template <typename T>
void Dy_arr<T>::print()
{
	if (!m_size) return;
	for (int i = 0; i < m_size; i++){
		std::cout << m_ptr[i] << std::endl;
	}
}

	template <typename T>
void Dy_arr<T>::resize(const int& size)
{
	try{
		if (size >= max_size || size < 0)
			throw std::out_of_range("out of range");
	}
	catch(const std::out_of_range & s)
	{
		std::cerr << s.what() << std::endl;
		exit(0);
		//std::terminate();
	}
	if (m_size == size)
		return;
	if (size == 0){
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = 0;
		return;
	}
	if (m_ptr == nullptr){
		m_ptr = new T[size];
	} else {
		T* ptr = m_ptr;
		m_ptr = new T[size];
		for (int i = 0; i < m_size; ++i){
			m_ptr[i] = ptr[i];
		}
		for (int i = m_size; i < size; ++i){
			m_ptr[i] = 0;
		}
		m_size = size;
		delete[] ptr;
	}
}

	template <typename T>
void Dy_arr<T>::push_back(const T & value)
{
	try{
		if (value < min_size || value > max_size)
			throw std::out_of_range("invalid value");
	}
	catch(const std::out_of_range & v)
	{
		std::cerr << v.what() << std::endl;
		exit(0);
	//	std::terminate();
	}
	T *new_ptr = m_ptr;
	++m_size;
	m_ptr = new T[m_size];
	for (int i = 0; i < m_size - 1; ++i){
		m_ptr[i] = new_ptr[i];
	}
	m_ptr[m_size - 1] = value;
	delete[] new_ptr;
}

	template <typename T>
T Dy_arr<T>::pop_back()
{
	if (m_size == 0){
		std::cerr << "size must be greater than 1" 
			<< std::endl;
		return -1;
	}
T last_value = m_ptr[m_size - 1];
--m_size;
T*new_ptr = m_ptr;
m_ptr = new T[m_size];
for (int i = 0; i < m_size; ++i){
	m_ptr[i] = new_ptr[i];
}
delete[] new_ptr;
std::cout << "The last value was " 
<< last_value << std::endl;
return last_value;

}

	template <typename T>
Dy_arr<T>::~Dy_arr()
{
	delete[] m_ptr;
	m_ptr = nullptr;
	std::cout << "=== Dy_arr dtor called " << std::endl;
}

int main()
{
	Dy_arr <int> a;
	Dy_arr <int> b(5);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	b.print();
	b.pop_back();
	b.print();
	b.pop_back();
	b.print();
	b.pop_back();
	b.print();
	b.pop_back();
	b.print();
	b[0] = 8;
	b.push_back(44);
	std::cout << std::endl;
	b.resize(6);
	b.print();
	std::cout << std::endl;
	b.resize(9);
	b.print();
	std::cout << std::endl;
	Dy_arr <int> k(9);
	Dy_arr <int> l(88);
	Dy_arr <int> c(b);
	c.print();
	Dy_arr <int> d(std::move(a));
	Dy_arr <int> e;
	e = a;
	Dy_arr <int> f;
	f = std::move(a);
	return 0;
}
