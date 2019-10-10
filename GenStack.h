#ifndef GENERICSTACK_H
#define GENERICSTACK_H

#include <iostream>

template <typename T>
class GenericStack
{
  int size;
  int top;
  T *theStack;
  T *tempArray;
public:
  GenericStack();
  GenericStack(int i);
  ~GenericStack();
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
GenericStack<T>::GenericStack()
{
  theStack = new T[100];
  size = 100;
  top = -1;
}
template <typename T>
GenericStack<T>::GenericStack(int i)
{
  if(i <0)
    throw std::runtime_error("Invalid value entered for stack size");
  theStack = new T[i];
  size = i;
  top = -1;
}
template <typename T>
GenericStack<T>::~GenericStack()
{
  delete theStack;
  delete tempArray;
}
template <typename T>
bool GenericStack<T>::isEmpty()
{
  return top == -1;
}
template <typename T>
void GenericStack<T>::push(T object)
{
  if(isFull())
  {
    resizeArray(theStack,size);
    doubleSize();
  }
  theStack[++top] = object;
}
template <typename T>
T GenericStack<T>::pop()
{
  if(isEmpty())
    throw std::runtime_error("Cannot pop. Stack is empty.");
  return theStack[top--];
}
template <typename T>
T GenericStack<T>::peek()
{
  if(isEmpty())
    throw std::runtime_error("Cannot pop. Stack is empty.");
  return theStack[top];
}
template <typename T>
bool GenericStack<T>::isFull()
{
  return (top == size -1);
}
template <typename T>
void GenericStack<T>::resizeArray(T* newArray,int size)
{
  tempArray = new T[size*2];
  for(int i = 0; i<size; ++i)
    tempArray[i] = newArray[i];
  theStack = tempArray;
  tempArray = NULL;
}
template <typename T>
void GenericStack<T>::doubleSize()
{
  size = size*2;
}

#endif
