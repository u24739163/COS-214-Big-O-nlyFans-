#ifndef STEPPER_H
#define STEPPER_H

class Stepper {
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual void hasNext() = 0;
        virtual void current() = 0;
};

class VectorStepper : public Stepper {
    public:
        void first();
        void next();
        void hasNext();
        void current();
};

#endif