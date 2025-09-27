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
        VectorFather() {}
        ~VectorFather() {}

        Stepper<T>* createStepper() override {
            return new VectorStepper<T>(&list);
        }

        void addItem(T item) override {
            list.push_back(item);
        }

        void removeItem() override {
            if (!list.empty()) {
                list.pop_back();
            }
        }

        bool isEmpty() override {
            return list.empty();
        }

        vector<T>* getVector() {
            return &list;
        }
};

#endif