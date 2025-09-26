#ifndef STEPFATHER_H
#define STEPFATHER_H

#include "Stepper.h"
#include <vector>
using namespace std;

template <typename T>
class StepFather {
    public:
        virtual Stepper<T>* createStepper() = 0;
        virtual void addItem(T item) = 0;
        virtual void removeItem() = 0;
        virtual bool isEmpty() = 0;
        virtual ~StepFather() {}
};

template <typename T>
class VectorFather : public StepFather<T> {
    private:
        vector<T> list;
    public:
        VectorFather();
        ~VectorFather();
        Stepper<T>* createStepper() override;
        void addItem(T item) override;
        void removeItem() override;
        bool isEmpty() override;
        vector<T>* getVector();
};

#endif