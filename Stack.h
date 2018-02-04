#ifndef STACK
#define STACK
#include <iostream>
#include <string>

#define DEFAULT_CAPACITY 3

template<typename T>
class Stack {
private:
    int _size;
    int _capacity;
    T *_elem;
public:
    Stack() {
        _elem = new T[DEFAULT_CAPACITY];
        for (int i = 0; i < DEFAULT_CAPACITY; i++) _elem[i] = 0;
        _size = 0;
        _capacity = 3;
    }

    ~Stack() { delete[]_elem; }

    void enlarge() {
        if (_size < _capacity) return;
        T *_oldelem = _elem;
        _capacity *= 2;
        _elem = new T[_capacity];
        for (int i = 0; i < _size; i++)
            _elem[i] = _oldelem[i];
        delete[]_oldelem;
    }

    void shrink() {
        if (_size * 2 > _capacity) return;
        T *_oldelem = _elem;
        _capacity /= 2;
        _elem = new T[_capacity];
        for (int i = 0; i < _size; i++)
            _elem[i] = _oldelem[i];
        delete[]_oldelem;
    }

    void push(T a) {
        enlarge();
        _size++;
        _elem[_size - 1] = a;
    }

    T pop() {
        T tmp;
        tmp = _elem[_size - 1];
        _size--;
        shrink();
        return tmp;
    }

    int size() { return _size; }

    bool empty() { return !_size; }

    void clear() {
        _size = 0;
        shrink();
    }

    T top() { return _elem[_size - 1]; }

    void print() {
        for (int i = 0; i < _size; i++)
            std::cout << _elem[i] << " ";
        std::cout << std::endl;
        std::cout << "<<<BOTTOM" << std::endl;
    }
};

#endif