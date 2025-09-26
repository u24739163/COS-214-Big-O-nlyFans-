#include "StepFather.h"

template <typename T>
VectorFather<T>::VectorFather() {}

template <typename T>
VectorFather<T>::~VectorFather() {}

template <typename T>
Stepper<T>* VectorFather<T>::createStepper() {
    return new VectorStepper<T>(&list);
}

template <typename T>
void VectorFather<T>::addItem(T item) {
    list.push_back(item);
}

template <typename T>
void VectorFather<T>::removeItem() {
    if (!list.empty()) {
        list.pop_back();
    }
}

template <typename T>
bool VectorFather<T>::isEmpty() {
    return list.empty();
}

template <typename T>
vector<T>* VectorFather<T>::getVector() {
    return &list;
}