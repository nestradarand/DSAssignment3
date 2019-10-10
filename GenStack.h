#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

template <typename T>
class GenStack
{
  int size;
  int top;
  T *theStack;
  T *tempArray;
public:
  GenStack();
  GenStack(int i);
  ~GenStack();
  bool isEmpty();
  void push(T object);
  T pop();
  T peek();
  bool isFull();
private:
  void resizeArray(T* newArray,int size);
  void doubleSize();
};

template <typename T>
GenStack<T>::GenStack()
{
  theStack = new T[100];
  size = 100;
  top = -1;
}
template <typename T>
GenStack<T>::GenStack(int i)
{
  if(i <0)
    throw std::runtime_error("Invalid value entered for stack size");
  theStack = new T[i];
  size = i;
  top = -1;
}
template <typename T>
GenStack<T>::~GenStack()
{
  delete theStack;
  delete tempArray;
}
template <typename T>
bool GenStack<T>::isEmpty()
{
  return top == -1;
}
template <typename T>
void GenStack<T>::push(T object)
{
  if(isFull())
  {
    resizeArray(theStack,size);
    doubleSize();
  }
  theStack[++top] = object;
}
template <typename T>
T GenStack<T>::pop()
{
  if(isEmpty())
    throw std::runtime_error("Cannot pop. Stack is empty.");
  return theStack[top--];
}
template <typename T>
T GenStack<T>::peek()
{
  if(isEmpty())
    throw std::runtime_error("Cannot pop. Stack is empty.");
  return theStack[top];
}
template <typename T>
bool GenStack<T>::isFull()
{
  return (top == size -1);
}
template <typename T>
void GenStack<T>::resizeArray(T* newArray,int size)
{
  tempArray = new T[size*2];
  for(int i = 0; i<size; ++i)
    tempArray[i] = newArray[i];
  theStack = tempArray;
  tempArray = NULL;
}
template <typename T>
void GenStack<T>::doubleSize()
{
  size = size*2;
}

#endif
