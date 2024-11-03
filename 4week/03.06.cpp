#include <algorithm>
#include <iostream>
#include <utility>

class Container{
public:

	Container() : m_data(nullptr), m_size(0), m_capacity(1) {}

	Container(std::size_t size) : m_size(size), m_capacity(size){ m_data = new int[m_size]{}; }

	Container(const Container & other) : m_size(other.m_size) {
		m_data = new int[m_size]{};
        m_capacity = other.m_capacity;
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

    int getCapacity() const{ return m_capacity; }

    int getSize() const{ return m_size; }

    bool isEmpty() const{ return m_size == 0; }

    void clear(){ m_size = 0; }

    void push_back(int&);

public:

	void swap(Container & other);

private:

    std::size_t m_capacity;
    int *m_data; std::size_t m_size;

};

void Container::swap(Container & other){
		using std::swap; 

		swap(m_data, other.m_data);
		swap(m_size, other.m_size);
    	swap(m_capacity, other.m_capacity);
	}

inline void swap(Container & x, Container & y) { x.swap(y); }

void Container::push_back(int& new_element){
    if(m_capacity == m_size){
        m_capacity == 0 ? m_capacity = 1: m_capacity *= 2;

        auto m_data_copy = new int[m_capacity];
        std::ranges::copy(m_data, m_data + m_size, m_data_copy);

        delete[] m_data;
        m_data = m_data_copy;
    }

    m_data[m_size] = new_element;
    m_size++;
}

int main(){
    Container vec;

    for(int i{0}; i< 10; i++){
        vec.push_back(i);
    }
    std::cout<< vec.getCapacity() << " " << vec.getSize() << std::endl;

    for(int i{0}; i< vec.getSize(); i++){
        std::cout << vec[i] << std::endl;
    }

    std::cout<< vec.back() << " "<< vec.front() << std::endl;

    vec.clear();
    std::cout<< vec.getCapacity() << " " << vec.getSize() << " "<< vec.isEmpty() << std::endl;
}