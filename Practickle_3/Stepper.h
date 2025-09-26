#ifndef STEPPER_H
#define STEPPER_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Stepper {
    public:
        virtual T first() = 0;
        virtual void next() = 0;
        virtual bool hasNext() = 0;
        virtual T current() = 0;
        virtual ~Stepper() {}
};

template <typename T>
class VectorStepper : public Stepper<T> {
    private:
        vector<T>* steppingVector;
        int currentIndex;
    public:
        VectorStepper(vector<T>* vec);
        ~VectorStepper();
        T first();
        void next();
        bool hasNext();
        T current();
};

#endif