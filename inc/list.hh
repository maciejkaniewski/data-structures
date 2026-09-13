#ifndef LIST_HH_
#define LIST_HH_

#include <memory>

/**
 * @brief Model a concept of bidirectional List
 *
 * @tparam T
 */
template <typename T>
class List {
 public:
  class Node {
   public:
    T data;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;
  };

  /**
   * @brief Construct a new List object
   *
   */
  List();

  /**
   * @brief Destroy the List object
   *
   */
  ~List();

  /**
   * @brief Model a concept of custom Iterator
   *
   */
  class Iterator {
   public:
    using difference_type = long;
    using value_type = T;
    using pointer = const std::shared_ptr<T>;
    using reference = const T &;
    using iterator_category = std::random_access_iterator_tag;

    /**
     * @brief Construct a new Iterator object
     *
     * @param node Node object
     */
    Iterator(std::shared_ptr<Node> node = nullptr);

    /**
     * @brief Increment Iterator
     *
     * @return Iterator
     */
    Iterator operator++();

    /**
     * @brief Decrement Iterator
     *
     * @return Iterator
     */
    Iterator operator--();

    /**
     *  @brief Equal Iterators
     *
     * @param other another Iterator object
     * @return true Iterators are equal
     * @return false Iterators are not equal
     */
    bool operator==(const Iterator &other) const;

    /**
     *  @brief Not equal Iterators
     *
     * @param other another Iterator object
     * @return true Iterators are not equal
     * @return false Iterators not equal
     */
    bool operator!=(const Iterator &other) const;

    /**
     * @brief Greater Iterator
     *
     * a > b
     *
     * @param other another Iterator object
     * @return true  Iterator a is greater than b Iterator
     * @return false Iterator a is less than b Iterator
     */
    bool operator>(const Iterator &other) const;

    /**
     * @brief Less Iterator
     *
     * a < b
     *
     * @param other another Iterator object
     * @return true  Iterator a is less than b Iterator
     * @return false Iterator a is greater than b Iterator
     */
    bool operator<(const Iterator &other) const;

    /**
     * @brief Subtract Iterators
     *
     * @param other another Iterator object
     * @return difference_type result of subtraction
     */
    difference_type operator-(const Iterator &other) const;

    /**
     * @brief Add diff to Iterator
     *
     * @param diff
     * @return Iterator + diff
     */
    Iterator operator+(difference_type diff) const;

    /**
     * @brief Sutract diff from Iterator
     *
     * @param diff
     * @return Iterator - diff
     */
    Iterator operator-(difference_type diff) const;

    /**
     * @brief Acces Iterator
     *
     * @param i
     * @return Iterator
     */
    Iterator operator[](std::size_t i);

    /**
     * @brief Get data from Iterator
     *
     * @return T&
     */
    T &operator*();

   private:
    std::shared_ptr<Node> currentNode = nullptr;
  };

  /**
   * @brief Model a concept of custom const Iterator
   *
   */
  class ConstIterator {
   public:
    using difference_type = long;
    using value_type = T;
    using pointer = const std::shared_ptr<T>;
    using reference = const T &;
    using iterator_category = std::random_access_iterator_tag;

    ConstIterator(std::shared_ptr<Node> node = nullptr);

    ConstIterator operator++();

    ConstIterator operator--();

    bool operator==(const ConstIterator &other) const;

    bool operator!=(const ConstIterator &other) const;

    bool operator>(const ConstIterator &other) const;

    bool operator<(const ConstIterator &other) const;

    difference_type operator-(const ConstIterator &other) const;

    ConstIterator operator+(difference_type diff) const;

    ConstIterator operator-(difference_type diff) const;

    ConstIterator operator[](std::size_t i);

    const T &operator*();

   private:
    std::shared_ptr<Node> currentNode = nullptr;
  };

  /**
   * @brief Check if List is empty
   *
   * @return true List is empty
   * @return false List is not empty
   */
  bool isEmpty() const;

  /**
   * @brief Get the element from back of the List
   *
   * @return const T&
   */
  const T &getBack() const;

  /**
   * @brief Get the element from front of the List
   *
   * @return const T&
   */
  const T &getFront() const;

  /**
   * @brief Push element to the back of the List
   *
   * @param newElement
   */
  void pushBack(const T &newElement);

  /**
   * @brief Push element to the front of the List
   *
   * @param newElement
   */
  void pushFront(const T &newElement);
  
  /**
   * @brief Insert element in specified position
   * 
   * @param newElement 
   * @param index position
   */
  void insert(const T &newElement, int index);

  /**
   * @brief Remove specified element
   * 
   * @param element 
   */
  void remove(const T &element);
  
  /**
   * @brief Remove all occurrences of specified element
   * 
   * @param element 
   */
  void removeAll(const T &element);
  
  /**
   * @brief Get Iterator from front of the List
   * 
   * @return Iterator 
   */
  Iterator begin();

  /**
   * @brief  Get Iterator from back of the List
   * 
   * @return Iterator 
   */
  Iterator end();

  ConstIterator constBegin() const;

  ConstIterator constEnd() const;

  /**
   * @brief Get element from the specified index
   * 
   * @param index 
   * @return T& 
   */
  T &operator[](int index);

 private:
  std::shared_ptr<Node> header;
  std::shared_ptr<Node> trailer;
};

template <typename T>
List<T>::Iterator::Iterator(typename std::shared_ptr<Node> node) {
  currentNode = node;
}

template <typename T>
typename List<T>::Iterator
List<T>::Iterator::operator++() {
  return currentNode = currentNode->next;
}

template <typename T>
typename List<T>::Iterator
List<T>::Iterator::operator--() {
  return currentNode = currentNode->prev;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator &other) const {
  return currentNode == other.currentNode;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator &other) const {
  return !(*this == other);
}

template <typename T>
bool List<T>::Iterator::operator>(const Iterator &other) const {
  return !(*this < other);
}

template <typename T>
bool List<T>::Iterator::operator<(const Iterator &other) const {
  Iterator currentIterator = Iterator(currentNode);
  for (currentIterator; currentIterator.currentNode != nullptr;
       ++currentIterator) {
    if (currentIterator == other.currentNode) {
      return true;
    }
  }
  return false;
}

template <typename T>
typename List<T>::Iterator::difference_type
List<T>::Iterator::operator-(const Iterator &other) const {
  difference_type counter = 0;
  Iterator currentIterator = Iterator(currentNode);
  if (currentIterator < other.currentNode) {
    while (currentIterator != other.currentNode) {
      ++currentIterator;
      counter++;
    }
  } else {
    while (currentIterator != other.currentNode) {
      --currentIterator;
      counter++;
    }
  }
  return counter;
}

template <typename T>
typename List<T>::Iterator
List<T>::Iterator::operator+(difference_type diff) const {
  Iterator currentIterator = Iterator(currentNode);
  for (int i = 0; i < diff; ++i) {
    ++currentIterator;
  }
  return Iterator(currentIterator);
}

template <typename T>
typename List<T>::Iterator
List<T>::Iterator::operator-(difference_type diff) const {
  Iterator currentIterator = Iterator(currentNode);
  for (int i = 0; i < diff; ++i) {
    --currentIterator;
  }
  return Iterator(currentIterator);
}

template <typename T>
typename List<T>::Iterator
List<T>::Iterator::operator[](std::size_t i) {
  Iterator currentIterator = Iterator(currentNode);
  return Iterator(currentIterator + i);
}

template <typename T>
T &List<T>::Iterator::operator*() {
  return currentNode->data;
}

template <typename T>
List<T>::ConstIterator::ConstIterator(std::shared_ptr<Node> node) {
  currentNode = node;
}

template <typename T>
typename List<T>::ConstIterator
List<T>::ConstIterator::operator++() {
  return currentNode = currentNode->next;
}

template <typename T>
typename List<T>::ConstIterator
List<T>::ConstIterator::operator--() {
  return currentNode = currentNode->prev;
}

template <typename T>
bool List<T>::ConstIterator::operator==(const ConstIterator &other) const {
  return currentNode == other.currentNode;
}

template <typename T>
bool List<T>::ConstIterator::operator!=(const ConstIterator &other) const {
  return !(*this == other);
}

template <typename T>
bool List<T>::ConstIterator::operator>(const ConstIterator &other) const {
  return !(*this < other);
}

template <typename T>
bool List<T>::ConstIterator::operator<(const ConstIterator &other) const {
  ConstIterator currentIterator = ConstIterator(currentNode);
  for (currentIterator; currentIterator.currentNode != nullptr;
       ++currentIterator) {
    if (currentIterator == other.currentNode) {
      return true;
    }
  }
  return false;
}

template <typename T>
typename List<T>::ConstIterator::difference_type
List<T>::ConstIterator::operator-(const ConstIterator &other) const {
  difference_type counter = 0;
  ConstIterator currentIterator = ConstIterator(currentNode);
  if (currentIterator < other.currentNode) {
    while (currentIterator != other.currentNode) {
      ++currentIterator;
      counter++;
    }
  } else {
    while (currentIterator != other.currentNode) {
      --currentIterator;
      counter++;
    }
  }
  return counter;
}

template <typename T>
typename List<T>::ConstIterator
List<T>::ConstIterator::operator+(difference_type diff) const {
  ConstIterator currentIterator = ConstIterator(currentNode);
  for (int i = 0; i < diff; ++i) {
    ++currentIterator;
  }
  return ConstIterator(currentIterator);
}

template <typename T>
typename List<T>::ConstIterator
List<T>::ConstIterator::operator-(difference_type diff) const {
  ConstIterator currentIterator = ConstIterator(currentNode);
  for (int i = 0; i < diff; ++i) {
    --currentIterator;
  }
  return ConstIterator(currentIterator);
}

template <typename T>
typename List<T>::ConstIterator
List<T>::ConstIterator::operator[](std::size_t i) {
  ConstIterator currentIterator = ConstIterator(currentNode);
  return ConstIterator(currentIterator + i);
}

template <typename T>
const T &
List<T>::ConstIterator::operator*() {
  return currentNode->data;
}

template <typename T>
List<T>::List() {
  header = std::make_shared<Node>();
  trailer = std::make_shared<Node>();
  header->next = trailer;
  trailer->prev = header;
}

template <typename T>
List<T>::~List() {
  while (!isEmpty()) {
    remove(getFront());
  }
  header->next = nullptr;
  trailer->prev = nullptr;
}

template <typename T>
bool List<T>::isEmpty() const {
  return (header->next == trailer);
}

template <typename T>
const T &
List<T>::getBack() const {
  return (trailer->prev->data);
}

template <typename T>
const T &
List<T>::getFront() const {
  return (header->next->data);
}

template <typename T>
void List<T>::pushBack(const T &newElement) {
  std::shared_ptr<Node> newNode = std::make_shared<Node>();
  newNode->data = newElement;
  if (isEmpty()) {
    header->next = newNode;
    trailer->prev = newNode;
    newNode->prev = header;
    newNode->next = trailer;
  } else {
    std::shared_ptr<Node> previousBack = trailer->prev;
    trailer->prev = newNode;
    newNode->prev = previousBack;
    newNode->next = trailer;
    previousBack->next = newNode;
  }
}

template <typename T>
void List<T>::pushFront(const T &newElement) {
  std::shared_ptr<Node> newNode = std::make_shared<Node>();
  newNode->data = newElement;
  if (isEmpty()) {
    header->next = newNode;
    trailer->prev = newNode;
    newNode->prev = header;
    newNode->next = trailer;
  } else {
    std::shared_ptr<Node> previousFront = header->next;
    header->next = newNode;
    newNode->next = previousFront;
    newNode->prev = header;
    previousFront->prev = newNode;
  }
}

template <typename T>
void List<T>::insert(const T &newElement, int index) {
  std::shared_ptr<Node> current = header->next;
  std::shared_ptr<Node> newNode = std::make_shared<Node>();
  ;
  newNode->data = newElement;
  if (index == 0) {
    pushFront(newElement);
  } else {
    int counter = 0;
    std::shared_ptr<Node> oldNode = std::make_shared<Node>();

    while (counter != index) {
      if (counter == (index - 1)) {
        oldNode = current;
      }
      current = current->next;
      counter++;
    }
    oldNode->next = newNode;
    newNode->next = current;
    newNode->prev = oldNode;
  }
}

template <typename T>
void List<T>::remove(const T &element) {
  std::shared_ptr<Node> current = header->next;
  bool found = false;
  while (!found) {
    if (current->data == element) {
      found = true;
      std::shared_ptr<Node> inFrontDeleted = current->prev;
      std::shared_ptr<Node> behindDeleted = current->next;
      inFrontDeleted->next = behindDeleted;
      behindDeleted->prev = inFrontDeleted;
    }
    current = current->next;
  }
}

template <typename T>
void List<T>::removeAll(const T &element) {
  std::shared_ptr<Node> current = header->next;
  while (current->next != nullptr) {
    if (current->data == element) {
      std::shared_ptr<Node> inFrontDeleted = current->prev;
      std::shared_ptr<Node> behindDeleted = current->next;
      inFrontDeleted->next = behindDeleted;
      behindDeleted->prev = inFrontDeleted;
    }
    current = current->next;
  }
}

template <typename T>
typename List<T>::Iterator
List<T>::begin() {
  return Iterator(header->next);
}

template <typename T>
typename List<T>::Iterator
List<T>::end() {
  return Iterator(trailer);
}

template <typename T>
typename List<T>::ConstIterator
List<T>::constBegin() const {
  return ConstIterator(header->next);
}

template <typename T>
typename List<T>::ConstIterator
List<T>::constEnd() const {
  return ConstIterator(trailer);
}

template <typename T>
T &List<T>::operator[](int index) {
  static T element;
  std::shared_ptr<Node> current = header->next;
  element = current->data;
  for (int i = 0; i < index; i++) {
    current = current->next;
    element = current->data;
  }
  return element;
}

#endif /* LIST_HH_ */