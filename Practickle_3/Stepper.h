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
        VectorStepper(vector<T>* vec) : steppingVector(vec), currentIndex(0) {}
        ~VectorStepper() {}

        T first() {
            currentIndex = 0;
            if (steppingVector && !steppingVector->empty()) {
                return (*steppingVector)[currentIndex];
            } else {
                std::cout << "aww hell nah either you tryna access an out of bounds, or steppingVector don't exist yet chiefo.\n";
                return T();
            }
        }

        void next() {
            if (hasNext()) {
                currentIndex++;
            }
        }

        bool hasNext() {
            return steppingVector && currentIndex < steppingVector->size();
        }

        T current() {
            if (steppingVector && currentIndex < steppingVector->size()) {
                return (*steppingVector)[currentIndex];
            } else {
                std::cout << "aww hell nah either you tryna access an out of bounds, or steppingVector don't exist yet chiefo.\n";
                return T();
            }
        }
};

#endif