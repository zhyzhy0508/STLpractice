#include <iostream>
using namespace std;
template <typename T>

class myVector{
public:
    myVector():p(nullptr),_capacity(0),_size(0){};

    myVector(int Size, T data)
    {
        this->_capacity = 20 + Size;
        this->_size = Size;
        this->p = new T[_capacity];
        for(int i = 0; i < _size; i++)
        {
            this->p[i] = data;
        }
    };

    myVector(const myVector& vec)
    {
        this->_capacity = vec._capacity;
        this->_size = vec._size;
        this->p = new T[this->_capacity];
        memcpy(this->p,vec.p,this->_size*sizeof(T));
    };

    ~myVector()
    {
        if(p!=NULL)
        {
            delete[] p;
        }
    };

    myVector& operator=(const myVector& vec)
    {
        if(this->p != nullptr)
        {
            if(this == &vec)
            {
                return *this;
            }

            delete[] this->p;
            this->_capacity = 0;
            this->_size = 0;
            this->p = nullptr;
        }
        this->_capacity = vec._capacity;
        this->_size = vec._size;
        this->p = new T[this->_capacity];
        memcpy(this->p,vec.p,this->_size*sizeof(T));

    }

    void print()
    {
        for(int i = 0; i < this->_size ; i++){
            cout << this->p[i] << '\t';
        }
    cout << endl;
    };

    void push_back(T data)
    {
        if(this->p == nullptr)
        {
            this->_capacity = 20;
            this->_size = 0;
            T* p = new T[_capacity];
        }
        if(this->_size == this->_capacity)
        {
            T* new_p = new T[this->_capacity*2];
            memcpy(new_p, p, this->_size*sizeof(T));
            this->_capacity *= 2;
            delete[] p;
            p = new_p;


        }
        this->p[this->_size] = data;
        this->_size ++;
    };

    void pop_back(){
        if(this->_size > 1 )
        {
            this->p[this->_size - 1] = 0;
            this->_size;
        }
    };

    void insert(int pos, T data){
        if(pos >= 0 && pos <= this->_size)
        {
            if(this->_size == this->_capacity)
            {
                T* new_p = new T[this->_capacity*2];
                memcpy(new_p, p, this->_size*sizeof(T));
                this->_capacity *= 2;
                delete[] p;
                p = new_p;

            }
            for(int i = this->_size; i > pos; i--)
            {
                this->p[i] = this->p[i-1];

            }
            this->p[pos] = data;
            this->_size++;

        }
    };

    void clear(){
        _size = 0;
    };

    T& operator[](int index)
    {
        if(index>0 && index < this->_size)
        {
            return this->p[index];
        }
    };



public:
    int _capacity;
    int _size;
    T *p;



};

