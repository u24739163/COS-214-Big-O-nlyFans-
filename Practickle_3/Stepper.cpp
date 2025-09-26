#include "Stepper.h"

template <typename T>
VectorStepper<T>::VectorStepper(vector<T>* vec) : steppingVector(vec), currentIndex(0) {}

template <typename T>
VectorStepper<T>::~VectorStepper() {}

template <typename T>
T VectorStepper<T>::first() 
{
    currentIndex = 0;
    if (steppingVector && !steppingVector->empty()) 
    {
        return (*steppingVector)[currentIndex];
    }
    else
    {
        std::cout << "aww hell nah either you tryna access an out of bounds, or steppingVector don't exist yet chiefo.\n";
        return T();
    }
}

template <typename T>
void VectorStepper<T>::next() 
{
    if (hasNext()) 
    {
        currentIndex++;
    }
}

template <typename T>
bool VectorStepper<T>::hasNext() 
{
    return steppingVector && currentIndex < steppingVector->size();
}

template <typename T>
T VectorStepper<T>::current() 
{
    if (steppingVector && currentIndex < steppingVector->size()) 
    {
        return (*steppingVector)[currentIndex];
    }
    else
    {
        std::cout << "aww hell nah either you tryna access an out of bounds, or steppingVector don't exist yet chiefo.\n";
        return T();
    }
}