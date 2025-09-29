/**
 * @file Stepper.h
 * @brief Iterator pattern implementation for traversing collections
 * @author Your Name
 * @date 2025-09-29
 */
#ifndef STEPPER_H
#define STEPPER_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @class Stepper
 * @brief Abstract iterator interface for traversing collections
 * @tparam T The type of elements in the collection
 * 
 * This class provides an iterator interface following the Iterator pattern,
 * allowing uniform traversal of different container types.
 */
template <typename T>
class Stepper {
    public:
        /**
         * @brief Move to and return the first element
         * @return The first element in the collection
         */
        virtual T first() = 0;
        
        /**
         * @brief Move to the next element in the collection
         * 
         * Advances the iterator to the next position if available.
         */
        virtual void next() = 0;
        
        /**
         * @brief Check if there are more elements to iterate over
         * @return true if more elements exist, false otherwise
         */
        virtual bool hasNext() = 0;
        
        /**
         * @brief Get the current element without advancing
         * @return The element at the current position
         */
        virtual T current() = 0;
        
        /**
         * @brief Get the current index position
         * @return The current index as an integer
         */
        virtual int getCurrentIndex() = 0;
        
        /**
         * @brief Virtual destructor for proper cleanup
         */
        virtual ~Stepper() {}
};

/**
 * @class VectorStepper
 * @brief Concrete iterator implementation for std::vector containers
 * @tparam T The type of elements in the vector
 * 
 * This class provides iterator functionality specifically for std::vector,
 * implementing the Stepper interface for vector traversal.
 */
template <typename T>
class VectorStepper : public Stepper<T> {
    private:
        vector<T>* steppingVector;  ///< Pointer to the vector being iterated
        int currentIndex;           ///< Current position in the vector
    
    public:
        /**
         * @brief Constructor for VectorStepper
         * @param vec Pointer to the vector to iterate over
         */
        VectorStepper(vector<T>* vec) : steppingVector(vec), currentIndex(0) {}
        
        /**
         * @brief Destructor for VectorStepper
         */
        ~VectorStepper() {}

        /**
         * @brief Move to and return the first element
         * @return The first element in the vector, or default T() if empty
         * 
         * Resets the iterator to the beginning of the vector and returns
         * the first element if the vector is not empty.
         */
        T first() {
            currentIndex = 0;
            if (steppingVector && !steppingVector->empty()) {
                return (*steppingVector)[currentIndex];
            } else {
                return T();
            }
        }

        /**
         * @brief Move to the next element in the vector
         * 
         * Advances the current index if there are more elements available.
         */
        void next() {
            if (hasNext()) {
                currentIndex++;
            }
        }

        /**
         * @brief Check if there are more elements to iterate over
         * @return true if current position is within vector bounds, false otherwise
         */
        bool hasNext() {
            return steppingVector && currentIndex < steppingVector->size();
        }

        /**
         * @brief Get the current element without advancing
         * @return The element at current position, or default T() if out of bounds
         */
        T current() {
            if (steppingVector && currentIndex < steppingVector->size()) {
                return (*steppingVector)[currentIndex];
            } else {
                return T();
            }
        }

        /**
         * @brief Get the current index position
         * @return The current index as an integer
         */
        int getCurrentIndex() {
            return currentIndex;
        }
};

#endif