/**
 * @file StepFather.h
 * @brief Abstract container classes with iterator support
 * @author Your Name
 * @date 2025-09-29
 */
#ifndef STEPFATHER_H
#define STEPFATHER_H

#include "Stepper.h"
#include <vector>
using namespace std;

/**
 * @class StepFather
 * @brief Abstract base class for containers that support iteration
 * @tparam T The type of elements stored in the container
 * 
 * This class defines the interface for containers that can create
 * iterators and perform basic container operations.
 */
template <typename T>
class StepFather {
    public:
        /**
         * @brief Create an iterator for this container
         * @return Pointer to a Stepper object for traversing the container
         */
        virtual Stepper<T>* createStepper() = 0;
        
        /**
         * @brief Add an item to the container
         * @param item The item to add to the container
         */
        virtual void addItem(T item) = 0;
        
        /**
         * @brief Remove an item from the container
         * 
         * Typically removes the last item (stack-like behavior).
         */
        virtual void removeItem() = 0;
        
        /**
         * @brief Check if the container is empty
         * @return true if container has no elements, false otherwise
         */
        virtual bool isEmpty() = 0;
        
        /**
         * @brief Virtual destructor for proper cleanup
         */
        virtual ~StepFather() {}
};

/**
 * @class VectorFather
 * @brief Concrete container implementation using std::vector
 * @tparam T The type of elements stored in the vector
 * 
 * This class provides a wrapper around std::vector with iterator
 * support and additional utility methods for container manipulation.
 */
template <typename T>
class VectorFather : public StepFather<T> {
    private:
        vector<T> list;  ///< Internal vector storage for elements
    
    public:
        /**
         * @brief Default constructor for VectorFather
         */
        VectorFather() {}
        
        /**
         * @brief Destructor for VectorFather
         */
        ~VectorFather() {}

        /**
         * @brief Create a stepper iterator for this vector
         * @return Pointer to a VectorStepper for traversing this container
         */
        Stepper<T>* createStepper() override {
            return new VectorStepper<T>(&list);
        }

        /**
         * @brief Add an item to the end of the vector
         * @param item The item to add to the container
         */
        void addItem(T item) override {
            list.push_back(item);
        }

        /**
         * @brief Remove the last item from the vector
         * 
         * Removes the last element if the vector is not empty.
         */
        void removeItem() override {
            if (!list.empty()) {
                list.pop_back();
            }
        }

        /**
         * @brief Check if the vector is empty
         * @return true if vector has no elements, false otherwise
         */
        bool isEmpty() override {
            return list.empty();
        }

        /**
         * @brief Get direct access to the internal vector
         * @return Pointer to the internal std::vector
         * 
         * Provides direct access to the underlying vector for
         * operations not covered by the container interface.
         */
        vector<T>* getVector() {
            return &list;
        }

        /**
         * @brief Get iterator to the beginning of the vector
         * @return Iterator pointing to the first element
         */
        typename vector<T>::iterator begin() {
            return list.begin();
        }

        /**
         * @brief Get iterator to the end of the vector
         * @return Iterator pointing past the last element
         */
        typename vector<T>::iterator end() {
            return list.end();
        }

        /**
         * @brief Erase element at specified position
         * @param pos Iterator pointing to the element to erase
         * @return Iterator to the element following the erased element
         */
        typename vector<T>::iterator erase(typename vector<T>::iterator pos) {
            return list.erase(pos);
        }

        /**
         * @brief Erase elements in specified range
         * @param first Iterator to the first element to erase
         * @param last Iterator to one past the last element to erase
         * @return Iterator to the element following the last erased element
         */
        typename vector<T>::iterator erase(typename vector<T>::iterator first, typename vector<T>::iterator last) {
            return list.erase(first, last);
        }
};

#endif