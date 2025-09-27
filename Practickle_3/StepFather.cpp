#include "StepFather.h"

template <typename T>
VectorFather<T>::VectorFather() {}

template <typename T>
VectorFather<T>::~VectorFather() {}

template <typename T>
Stepper<T>* VectorFather<T>::createStepper() 
{
    return new VectorStepper<T>(&list);
}

template <typename T>
void VectorFather<T>::addItem(T item) 
{
    list.push_back(item);
}

template <typename T>
void VectorFather<T>::removeItem() 
{
    if (!list.empty()) 
    {
        list.pop_back();
    }
}

template <typename T>
bool VectorFather<T>::isEmpty() 
{
    return list.empty();
}

template <typename T>
vector<T>* VectorFather<T>::getVector() {
    return &list;
}

template <typename T>
vector<T>* VectorFather<T>::getVector() 
{
    return &list;
}

template <typename T>
vector<T>::iterator VectorFather<T>::begin() 
{
    return list.begin();
}
template <typename T>
vector<T>::iterator VectorFather<T>::end() 
{
    return list.end();
}

template <typename T>
vector<T>::iterator VectorFather<T>::erase(vector<T>::iterator pos) 
{
    return list.erase(pos);
}

template <typename T>
vector<T>::iterator VectorFather<T>::erase(vector<T>::iterator first, vector<T>::iterator last) 
{
    return list.erase(first, last);
}