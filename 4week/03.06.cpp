#include <algorithm>
#include <iostream>
#include <utility>

class Container{
public:

	Container() : m_data(nullptr), m_size(0) {}

	Container(std::size_t size) : m_size(size){ m_data = new int[m_size]{}; }

	Container(const Container & other) : m_size(other.m_size) {
		m_data = new int[m_size]{};
		std::ranges::copy(other.m_data, other.m_data + m_size, m_data);
	}

	Container(Container && other) : Container(){ swap(other); }

	Container & operator=(Container other){
        swap(other);
		return *this;
	}

    ~Container() { if (m_data) delete[] m_data; }

    const int& front() const{ return m_data[0]; }
    const int& back() const{ return m_data[m_size - 1]; }

    int& operator[](int index){ return m_data[index]; }
    const int& operator[](int index) const{ return m_data[index]; }

    const int Get_capacity() const{ return capacity; }

    const int Get_size() const{ return m_size; }

    bool is_empty() const{ return m_size == 0; }

    void clear(){ m_size = 0; }

    void push_back(int);

public:

	void swap(Container & other);

private:

    int capacity{0};
    int *m_data{nullptr}; std::size_t m_size{0};

};

void Container::swap(Container & other){
		using std::swap; 

		swap(m_data, other.m_data);
		swap(m_size, other.m_size);
	}

inline void swap(Container & x, Container & y) { x.swap(y); }

void Container::push_back(int new_element){
    if(capacity == m_size){
        capacity == 0 ? capacity = 1: capacity*=2;

        m_data = (int*)realloc(m_data, sizeof(int) * capacity); //так безопасно делать?
    }

    m_data[m_size] = new_element;
    m_size++;
}




int main(){
    Container vec;

    for(int i{0}; i< 10; i++){
        vec.push_back(i);
    }
    std::cout<< vec.Get_capacity() << " " << vec.Get_size() << std::endl;

    for(int i{0}; i< vec.Get_size(); i++){
        std::cout << vec[i] << std::endl;
    }

    std::cout<< vec.back() << " "<< vec.front() << std::endl;

    vec.clear();
    std::cout<< vec.Get_capacity() << " " << vec.Get_size() << " "<< vec.is_empty() << std::endl;
}