#include <iostream>
#include <vector>

class Container:std::vector<int>{
    public:

    const int& front() const;
    const int& back()  const;

    const int Get_size();
    const int Get_capacity();

    const int Get_size() const;
    const int Get_capacity() const;

    bool is_empty();
    bool is_empty() const;

    virtual int& operator[](int);
    virtual const int& operator[](int) const;

    int& front();
    int& back();

    void clear();
    void push_back(int);

    private:

    int capacity{0};
    int *m_data{nullptr}; std::size_t m_size{0};
    const int element_size = sizeof(int);

};

int& Container::front(){
    return this->m_data[0];
}

const int& Container::front() const{
    return this->m_data[0];
}

int& Container::back(){
    return this->m_data[this->m_size - 1];
}

const int& Container::back() const{
    return this->m_data[this->m_size - 1];
}

int& Container::operator[](int index)
{
    if (index >= this->m_size){
        throw std::range_error("Index out of range");
    }
    return this->m_data[index];
}

const int& Container::operator[](int index) const
{
    if (index >= this->m_size){
        throw std::range_error("Index out of range");
    }
    return this->m_data[index];
}

const int Container::Get_capacity(){
    return this->capacity;
}

const int Container::Get_size(){
    return this->m_size;
}

const int Container::Get_capacity() const{
    return this->capacity;
}

const int Container::Get_size() const{
    return this->m_size;
}

bool Container::is_empty(){
    return this->m_size == 0;
}

bool Container::is_empty() const{
    return this->m_size == 0;
}

void Container::clear(){
    while(this->m_size){
        this->pop_back();
        m_size--;
    }
}

void Container::push_back(int new_element){
    if(this->capacity == this->m_size){
        capacity == 0 ? capacity = 1: capacity*=2;
        int *tmp = new int[capacity];
        memmove(tmp, this->m_data, element_size * this->m_size);
        delete[] this->m_data;
        m_data = tmp;
    }

    m_data[this->m_size] = new_element;
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