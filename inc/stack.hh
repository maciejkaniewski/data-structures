#ifndef STACK_HH_
#define STACK_HH_

#include "list.hh"

/**
 * @brief Model a concept of Stack using List
 *
 * @tparam T
 */
template <typename T>
class Stack {
 public:
 
  List<T> stack;

  /**
   * @brief Push element to the Stack
   * 
   * @param newElement 
   */
  void push(const T &newElement);
  
  /**
   * @brief Pop elemnet from the Stack
   * 
   * @return T 
   */
  T pop();
};

template <typename T>
void Stack<T>::push(const T &newElement) {
  stack.pushBack(newElement);
}

template <typename T>
T Stack<T>::pop() {
  T back = stack.getBack();
  stack.remove(back);
  return back;
}

#endif /* STACK_HH_ */