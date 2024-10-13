#ifndef STACK_QUEUES_H
#define STACK_QUEUES_H

#include <iostream>
#include <stdexcept>
using namespace std;


template <class T>
class Node  // Define A node class for using a linked list
{
    public:
        T data;
        Node* next;     // Pointer to the next node
        Node* prev;      // Pointer to the previous node
        Node(T val=T()) : data(val), next(nullptr), prev(nullptr) {}    // Node Constructor 
};



/*-----------------------  A stack implementation using a linked list -----------------------*/

template <class T>
class Stack
{
    private:
        Node<T>* topNode;       // Pointer to the last node in the stack    
        unsigned int size;      // Variable to store the size of the stack

    public:
        Stack() : topNode(nullptr), size(0) {}   // Default Stack Constructor

        Stack(const T& val) : topNode(new Node<T>(val)), size(1) {}  // Stack Constructor with one element

        Stack(const T* arr, const unsigned int& len)     // Another Stack Constructor from array
        {
            topNode = nullptr;
            size = 0;

            for (unsigned int i = 0; i < len; i++)
            {
                push(arr[i]);   // Push the elements onto the stack
            }
        }

        ~Stack()    // Destructor
        {
            while (topNode != nullptr)
            {
                pop();  
            }
        }

        T pop()     // Remove the top item from the stack and return it
        {
            if (size == 0) 
            {
                throw underflow_error("\nStack is empty, cannot pop");
            }
            
            T tempData = topNode->data;     // Save the top value
            Node<T>* tempTop = topNode;        // Save the top node for deletion

            topNode = topNode->prev;        // Update the top node
            
            
            if (topNode != nullptr)   // Clean up the previous top node
            {
                topNode->next = nullptr;
            }

            size--;
            delete tempTop;     // Delete the old top node
            return tempData;    // Return the popped value
        }

        void push(const T& val)     // Add an item to the top of the stack. 
        {
            Node<T>* newNode = new Node<T>(val);
            
            if (size > 0)    // If there are more than one elements in the stack
            {
                newNode->prev = topNode;
                topNode->next = newNode;
            }
            
            topNode = newNode;
            size++;
        }

        T peek() const    // Return the top of the stack
        {
            if (size == 0)
            {
                throw underflow_error("\nStack is empty, cannot peek");
            }
            return topNode->data;
        }

        bool isEmpty() const     // Return true if and only if the stack is empty
        {
            return (size == 0);
        }

  
        T getTop() const   // Return the top value of the stack
        {
            if (size == 0) 
            {
                throw underflow_error("\nStack is empty, cannot get top element");
            }
            return topNode->data;
        }
        
        unsigned int getSize() const {return size;}     // Return the size of the stack
};



/*-----------------------  A queue implementation using a linked list -----------------------*/

template <class T>
class Queue
{
    private:
        Node<T>* firstNode;     // Pointer to the first node in the queue    
        Node<T>* lastNode;      // Pointer to the last node in the queue 
        unsigned int size;      // Variable to store the size of the queue

    public:
        Queue() : firstNode(nullptr), size(0) {}    // Default constructor
        

        Queue(const T& val) : firstNode(new Node<T>(val)), lastNode(firstNode), size(1) {}   // Queue Constructor with one element


        Queue(const T& arr, unsigned int len)       // Another Queue Constructor from array
        {
            firstNode = nullptr;
            lastNode = nullptr;
            size = 0;

            for (unsigned int i = 0; i < len; i++)
            {
                add(arr[i]);
            }
        }


        ~Queue()        // Destructor
        {
            while (firstNode != nullptr)
            {
                remove();
            }
        }


        void add(const T& val)      //  Add an item to the end of the list
        {
            Node<T>* newNode = new Node<T>(val);

            if (size > 0)
            {
                newNode->prev = lastNode;       // Set the new node's previous pointer
                lastNode->next = newNode;       // Link the current last node to the new node
            }
            else    // If the queue is empty
            {
                firstNode = newNode;    // The first node is the new node
            }
            
            lastNode = newNode;     // Update lastNode to the new node
            size++;                 // Increase the size of the queue
        }

        
        T remove()     // Remove the first item in the list
        {
            if (size == 0)
            {
                throw underflow_error("\nQueue is empty, cannot remove");
            }
            
            T tempVal = firstNode->data;            // Get the data to return
            Node<T>* tempNode = firstNode;          // Save the first node to delete
            
            if (size > 1)
            {
                (firstNode->prev)->next = nullptr;      // Move the second item in the queue to the first place
                firstNode = firstNode->prev;            // Update the firstNode ptr
            }
            
            else    // If there is exactly one item in queue
            {
                firstNode = nullptr;
                lastNode = nullptr;
            }
            
            delete tempNode;                        // Free the memory of the of old first Node
            size--;                                 // Decrease the size of the queue
            
            return tempVal;
        }


        T peek() const    // Return the top of the queue
        {
            if (size == 0)
            {
                throw underflow_error("\nQueue is empty, cannot peek");
            }
            return firstNode->data;
        }


        bool isEmpty() const     // Return true if and only if the queue is empty
        {
            return (size == 0);
        }
        

        unsigned int getSize() const { return size; }   // Return the size of the queue
};













#endif  // STACK_QUEUES_H