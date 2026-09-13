#ifndef QUEUE_HH_
#define QUEUE_HH_

#include "list.hh"

/**
 * @brief Model a concept of Queue using List
 * 
 * @tparam T 
 */
template <typename T>
class Queue {
 public:
  List<T> queue;
  
  /**
   * @brief Add new element to the Queue
   * 
   * @param newElement 
   */
  void enqueue(const T &newElement);
  
  /**
   * @brief Remove element from the Queue
   * 
   * @return T 
   */
  T dequeue();
};

template <typename T>
void Queue<T>::enqueue(const T &newElement) {
  queue.pushBack(newElement);
}

template <typename T>
T Queue<T>::dequeue() {
  T front = queue.getFront();
  queue.remove(front);
  return front;
}

#endif /* QUEUE_HH_ */