#ifndef __DYN_ARR_EXCEP__
#define __DYN_ARR_EXCEP__
#define max_size std::numeric_limits<T>::max()
#define min_size std::numeric_limits<T>::min()

template <typename T>
class Dy_arr{
public:
	Dy_arr();
	Dy_arr(const int &);
	Dy_arr(const Dy_arr &);
	Dy_arr(Dy_arr&&);
	Dy_arr & operator=(const Dy_arr &);
	Dy_arr & operator=(Dy_arr&&);
	T& operator[](const int&);
	void print();
	void resize(const int&);
	void push_back(const T&);
	T pop_back();
	~Dy_arr();
private:
	T * m_ptr;
	int m_size;
	int m_num_of_elem;
};

#endif
	
