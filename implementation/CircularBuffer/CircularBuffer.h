
#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

template <typename T>
class CircularBuffer {
private:
    T* _data;
    int _capacity;
    int _head;
    int _tail;
    int _size;

public:
    /// 1. Конструктор с capacity
    explicit CircularBuffer(int capacity);
    
    /// 2. Деструктор
    ~CircularBuffer();
    
    /// 3. Конструктор копирования
    CircularBuffer(const CircularBuffer& other);
    
    /// 4. Оператор присваивания
    CircularBuffer& operator=(const CircularBuffer& other);
    
    /// 5. push_back(const T& x) - добавить в конец
    void push_back(const T& x);
    
    /// 6. pop_front() - удалить с начала
    void pop_front();
    
    /// 7. operator[](int index) - доступ по индексу
    T& operator[](int index);
    const T& operator[](int index) const;
    
    /// 8. front() - первый элемент
    T& front();
    const T& front() const;
    
    /// 9. back() - последний элемент
    T& back();
    const T& back() const;
    
    /// 10. is_full() - буфер полон
    bool is_full() const;
    
    /// 11. is_empty() - буфер пуст
    bool is_empty() const;
    
    /// 12. clear() - очистить
    void clear();
    
    /// 13. capacity() - размер буфера
    int capacity() const;
    
    /// 14. size() - количество элементов
    int size() const;
};

#endif // CIRCULARBUFFER_H
