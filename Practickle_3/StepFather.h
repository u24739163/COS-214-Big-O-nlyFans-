#ifndef STEPFATHER_H
#define STEPFATHER_H

#include "Stepper.h"

template <typename T>
class StepFather {
    public:
        virtual Stepper * createFather() = 0;
        virtual void addItem(T item) = 0;
        virtual void removeItem() = 0;
        virtual isEmpty() = 0;
};

template <typename T>
class VectorFather : public StepFather {
    private:
        vector<T> list;

    public:
        VectorFather();
        ~VectorFather();
        VectorStepper createVectorStepper();
};

#endif