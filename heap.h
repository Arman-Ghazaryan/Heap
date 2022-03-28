#pragma once
#include <vector>
#include <string>
#include <algorithm>


namespace Heap
{
    template <class T>
    class heap
    {
    public:
        heap();
        heap(std::vector<T> const &vec);
        ~heap();

        T &front();
        void sort(std::string str);
        bool is_heap();

        T &operator[](const int index);

    private:
        template <class N>
        struct node
        {
        public:
            node *_left_pointer_next;
            node *_right_pointer_next;
            node *_heap_pointer_prev;
            node *_pointer_next;
            node *_pointer_prev;
            N _data;
        };

        void swap_(node<T> *_ptr1, node<T> *_ptr2);
        void sort_(std::vector<T> const &_vec);
        void make_heap_(std::vector<T> const &_vec);

        node<T> *_head;
        node<T> *_back;
        std::string heap_struct;
        size_t size;
    };

    template <class T>
    heap<T>::heap()
    {
        _head = nullptr;
        heap_struct = "";
        size = 0;
    }

    template <class T>
    heap<T>::heap(std::vector<T> const &_vec)
    {
        _head = nullptr;
        heap_struct = "";
        size = 0;
        make_heap_(_vec);
    }

    template <class T>
    heap<T>::~heap()
    {

        _head = nullptr;
        _back = nullptr;
        heap_struct = "";
        size = 0;
    }

    template <class T>
    T &heap<T>::front()
    {
        return _head->_data;
    }

    template <class T>
    void heap<T>::sort(std::string str)
    {
        if (str == "MAX")
        {
            heap_struct = str;
            for (int j = 0; j < size - 1; j++)
            {
                node<T> *temp = _head;
                for (int i = 1; i < size; i++)
                {
                    if (temp->_data < temp->_pointer_next->_data)
                        swap_(temp, temp->_pointer_next);
                    temp = temp->_pointer_next;
                }
            }
        }
        else if (str == "MIN")
        {
            heap_struct = str;
            for (int j = 0; j < size - 1; j++)
            {
                node<T> *temp = _head;
                for (int i = 1; i < size; i++)
                {
                    if (temp->_data > temp->_pointer_next->_data)
                        swap_(temp, temp->_pointer_next);
                    temp = temp->_pointer_next;
                }
            }
        }
    }

    template <class T>
    bool heap<T>::is_heap()
    {
        int count = 0;
        if (heap_struct == "MAX" || heap_struct == "")
        {
            node<T> *temp = _head;
            for (int i = 0; i < size; i++)
            {
                if (temp->_left_pointer_next == nullptr && temp->_right_pointer_next == nullptr || temp->_left_pointer_next == nullptr && temp->_right_pointer_next->_data <= temp->_data || temp->_left_pointer_next->_data <= temp->_data && temp->_right_pointer_next == nullptr || temp->_left_pointer_next->_data <= temp->_data && temp->_right_pointer_next->_data <= temp->_data)
                    count++;
                temp = temp->_pointer_next;
            }
        }
        else if (heap_struct == "MIN" || heap_struct == "")
        {
            node<T> *temp = _head;
            for (int i = 0; i < size; i++)
            {
                if (temp->_left_pointer_next == nullptr && temp->_right_pointer_next == nullptr || temp->_left_pointer_next == nullptr && temp->_right_pointer_next->_data >= temp->_data || temp->_left_pointer_next->_data >= temp->_data && temp->_right_pointer_next == nullptr || temp->_left_pointer_next->_data >= temp->_data && temp->_right_pointer_next->_data >= temp->_data)
                    count++;
                temp = temp->_pointer_next;
            }
        }
        if (count == size)
            return 1;
        else
            return 0;
    }

    template <class T>
    T &heap<T>::operator[](const int index)
    {
        node<T> *temp = _head;

        if (index <= size - 1 && index >= 0)
        {
            for (int i = 0; i != index; i++)
                temp = temp->_pointer_next;
            return temp->_data;
        }
    }

    template <class T>
    void heap<T>::swap_(node<T> *_ptr1, node<T> *_ptr2)
    {
        T data = _ptr2->_data;
        _ptr2->_data = _ptr1->_data;
        _ptr1->_data = data;
    }

    template <class T>
    void heap<T>::sort_(std::vector<T> const &_vec)
    {
        std::sort(_vec.begin(), _vec.end());
    }

    template <class T>
    void heap<T>::make_heap_(std::vector<T> const &_vec)
    {
        node<T> *_temp_vec = new node<T>, *_temp_heap, *_max_elem;
        T _max_data;

        _temp_vec->_pointer_next = nullptr;
        _temp_vec->_heap_pointer_prev = nullptr;
        _temp_vec->_pointer_prev = _temp_vec;
        _temp_vec->_data = _vec[0];
        _head = _temp_vec;
        _back = _temp_vec;

        for (int i = 1; i < _vec.size(); ++i)
        {
            _temp_vec = new node<T>;
            _temp_vec->_pointer_next = nullptr;
            _temp_vec->_pointer_prev = _back;
            _temp_vec->_data = _vec[i];
            _back->_pointer_next = _temp_vec;
            _back = _temp_vec;
        }
        size += _vec.size();

        _temp_vec = _head;
        _temp_heap = _head;
        _temp_heap = _temp_heap->_pointer_next;

        for (int i = 0; i < _vec.size(); ++i, _temp_vec = _temp_vec->_pointer_next)
        {
            if (_temp_heap != nullptr)
            {
                _temp_vec->_left_pointer_next = _temp_heap;
                _temp_heap->_heap_pointer_prev = _temp_vec;
                _temp_heap = _temp_heap->_pointer_next;
            }
            else
            {
                _temp_vec->_left_pointer_next = nullptr;
            }

            if (_temp_heap != nullptr)
            {
                _temp_vec->_right_pointer_next = _temp_heap;
                _temp_heap->_heap_pointer_prev = _temp_vec;
                _temp_heap = _temp_heap->_pointer_next;
            }
            else
            {
                _temp_vec->_right_pointer_next = nullptr;
            }
        }

        _max_elem = _head;
        _temp_heap = _head->_pointer_next;

        for (int i = 1; i != size; i++)
        {
            if (_temp_heap->_data > _max_elem->_data)
                _max_elem = _temp_heap;
            _temp_heap = _temp_heap->_pointer_next;
        }

        while (_max_elem->_heap_pointer_prev != nullptr)
        {
            swap_(_max_elem, _max_elem->_heap_pointer_prev);
            _max_elem = _max_elem->_heap_pointer_prev;
        }
    }
}
