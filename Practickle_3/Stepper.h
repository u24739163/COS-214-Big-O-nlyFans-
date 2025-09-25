#ifndef STEPPER_H
#define STEPPER_H

#include <vector>
using namespace std;

template <typename T>
class Stepper {
    public:
        virtual void first() = 0;
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
        void first() override;
        void next() override;
        bool hasNext() override;
        T current() override;
};

#endif