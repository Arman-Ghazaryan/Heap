#pragma once
#include <vector>
#include <string>
#include <algorithm>

int min;

int find_min(std::vector<int> const &vec)
{
    int pos = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[pos])
            pos = i;
    }
    return pos;
}

int find_max(std::vector<int> const &vec, std::vector<int> const &pos_, int position)
{
    int pos = min;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[pos] && position != i && pos_[i] != i)
            pos = i;
    }
    return pos;
}

int left_next(int ind)
{
    return 2 * ind + 1;
}

int right_next(int ind)
{
    return 2 * ind + 2;
}

int left_back(int ind)
{
    return (ind - 1) / 2;
}

int right_back(int ind)
{
    return (ind - 2) / 2;
}

bool is_heap_(std::vector<int> const &vec)
{
    if (vec.size() % 2 == 0)
    {
        for (int i = 0; i < vec.size() / 2; ++i)
        {
            if (vec[i] >= vec[left_next(i)] && vec[i] >= vec[right_next(i)] || vec[i] >= vec[left_next(i)] && right_next(i) >= vec.size())
            {
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        for (int i = 0; i < vec.size() / 2; ++i)
        {
            if (vec[i] >= vec[left_next(i)] && vec[i] >= vec[right_next(i)])
            {
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
}
void make_heap_(std::vector<int> &vec)
{
    int temp;

    while (!is_heap_(vec))
    {
        for (int pos = vec.size() - 1, i = pos; pos > 0; --i, pos = i)
        {
            if (pos % 2 != 0)
            {
            skip:
                while (vec[pos] > vec[left_back(pos)] && pos != 0)
                {
                    temp = vec[pos];
                    vec[pos] = vec[left_back(pos)];
                    vec[left_back(pos)] = temp;
                    pos = left_back(pos);
                    if (!(vec[pos] > vec[left_back(pos)]) && pos != 0)
                        pos = i;
                }
            }
            else
            {
                while (vec[pos] > vec[right_back(pos)] && pos != 0)
                {
                    temp = vec[pos];
                    vec[pos] = vec[right_back(pos)];
                    vec[right_back(pos)] = temp;
                    pos = right_back(pos);
                    if (pos % 2 != 0)
                        goto skip;
                    if (!(vec[pos] > vec[right_back(pos)]) && pos != 0)
                        pos = i;
                }
            }
        }
    }
}


#pragma once
#include <vector>
#include <string>
#include <algorithm>

int min;

int find_min(std::vector<int> const &vec)
{
    int pos = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[pos])
            pos = i;
    }
    return pos;
}

int find_max(std::vector<int> const &vec, std::vector<int> const &pos_, int position)
{
    int pos = min;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[pos] && position != i && pos_[i] != i)
            pos = i;
    }
    return pos;
}

int left_next(int ind)
{
    return 2 * ind + 1;
}

int right_next(int ind)
{
    return 2 * ind + 2;
}

int left_back(int ind)
{
    return (ind - 1) / 2;
}

int right_back(int ind)
{
    return (ind - 2) / 2;
}

bool is_heap_(std::vector<int> const &vec)
{
    if (vec.size() % 2 == 0)
    {
        for (int i = 0; i < vec.size() / 2; ++i)
        {
            if (vec[i] >= vec[left_next(i)] && vec[i] >= vec[right_next(i)] || vec[i] >= vec[left_next(i)] && right_next(i) >= vec.size())
            {
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        for (int i = 0; i < vec.size() / 2; ++i)
        {
            if (vec[i] >= vec[left_next(i)] && vec[i] >= vec[right_next(i)])
            {
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
}

void make_heap_(std::vector<int> &vec)
{
    int temp;

    if (vec.size() % 2 != 0)
    {
        while (!is_heap_(vec))
        {
            for (int pos = (vec.size() - 2) / 2, i = pos; pos >= 0; --i, pos = i)
            {
                while (vec[pos] < vec[left_next(pos)])
                {
                    temp = vec[pos];
                    vec[pos] = vec[left_next(pos)];
                    vec[left_next(pos)] = temp;
                    pos = left_back(pos);
                    if (pos % 2 != 0)
                        goto skip;
                }
                {
                skip:
                    while (vec[pos] < vec[right_next(pos)] && right_next(pos) < vec.size() && pos >= 0)
                    {

                        temp = vec[pos];
                        vec[pos] = vec[right_next(pos)];
                        vec[right_next(pos)] = temp;
                        pos = right_back(pos);
                    }
                }
            }
        }
    }
    else
    {
        while (!is_heap_(vec))
        {
            for (int pos = (vec.size() - 2) / 2, i = pos; pos >= 0; --i, pos = i)
            {
                while (vec[pos] < vec[left_next(pos)])
                {
                    temp = vec[pos];
                    vec[pos] = vec[left_next(pos)];
                    vec[left_next(pos)] = temp;
                    pos = left_back(pos);
                    if (pos % 2 != 0)
                        goto skip1;
                }
                {
                skip1:
                    while (vec[pos] < vec[right_next(pos)] && pos >= 0)
                    {

                        temp = vec[pos];
                        vec[pos] = vec[right_next(pos)];
                        vec[right_next(pos)] = temp;
                        pos = right_back(pos);
                    }
                }
            }
        }
    }
}

void heapify_(std::vector<int> &vec, int left, int right, int index)
{
    if (index <= (vec.size() - 2) / 2)
    {
        int a = left_next(index), b = right_next(index), largest = index;
        if (vec[a] > vec[index])
            largest = a;
        if (vec[b] > vec[largest] && b < vec.size())
            largest = b;
        if (largest != index)
        {
            int temp = vec[index];
            vec[index] = vec[largest];
            vec[largest] = temp;
            heapify_(vec, left, right, largest);
        }
    }
}

void make_heap_v2(std::vector<int> &vec)
{
    for (int i = (vec.size() - 2) / 2; i >= 0; i--)
        heapify_(vec, 0, vec.size(), i);
}
