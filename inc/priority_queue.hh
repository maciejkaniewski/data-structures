#ifndef PRIORITY_QUEUE_HH_
#define PRIORITY_QUEUE_HH_

#include "list.hh"

/**
 * @brief Model a concept of Priority Queue using List
 *
 * @tparam T
 */
template <typename T>
class PriorityQueue {
 public:
  /**
   * @brief Add element to the Priority Queue
   *
   * @param newElement
   * @param priority
   */
  void enqueue(const T &newElement, int priority);

  /**
   * @brief Remove element from the Priority Queue
   *
   * @return T
   */
  T dequeue();

  /**
   * @brief Find destination index basen on priority
   *
   * @param priority
   * @return int
   */
  int findIndex(int priority);

  struct PriorityData {
    T data;
    int priority; // Higer number = higher priority

    bool operator==(const PriorityData &other) const;
  };

  List<PriorityData> priorityQueue;
};

template <typename T>
bool PriorityQueue<T>::PriorityData::operator==(const PriorityQueue::PriorityData &other) const {
  return (this->data == other.data && this->priority == other.priority);
}

template <typename T>
int PriorityQueue<T>::findIndex(int priority) {
  int index = 0;
  if (priorityQueue[index].priority < priority || priorityQueue.isEmpty()) {
    return index;
  } else {
    for (auto i : priorityQueue) {
      ++index;
      if (priorityQueue[index].priority < priority) {
        return index;
      }
    }
  }
  return index;
}

template <typename T>
void PriorityQueue<T>::enqueue(const T &newElement, int priority) {
  int index = findIndex(priority);
  priorityQueue.insert(PriorityData{newElement, priority}, index);
}

template <typename T>
T PriorityQueue<T>::dequeue() {
  PriorityData front = priorityQueue.getFront();
  priorityQueue.remove(front);
  return front.data;
}

#endif /* PRIORITY_QUEUE_HH_ */