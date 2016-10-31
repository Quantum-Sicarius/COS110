#include "circularList.h"
// Provide the implementation for the CircularList class in this file.

template <class T> ostream &operator<<(ostream &os, CircularList<T> &ll) {
  os << "[";
  for (int i = 0; i < ll.size(); i++) {
    os << ll.get(i);
    if ((i + 1) < ll.size()) {
      os << ",";
    }
  }
  os << "]";

  return os;
}

template <class T> CircularList<T>::CircularList() { this->head = 0; }

template <class T> CircularList<T>::CircularList(const CircularList<T> &other) {
  // LinkedList<T>::LinkedList(dynamic_cast<const LinkedList<T> *>(&other));
  this->clear();
  this->head = 0;
  for (int i = 0; i < other.size(); i++) {
    this->insert(this->size(), other.get(i));
  }
}

template <class T>
CircularList<T> &CircularList<T>::operator=(const CircularList<T> &other) {
  this->clear();
  this->head = 0;
  for (int i = 0; i < other.size(); i++) {
    this->insert(i, other.get(i));
  }

  return *this;
}

template <class T> CircularList<T> *CircularList<T>::clone() {
  CircularList<T> *newList = new CircularList<T>(*this);
  return newList;
}

template <class T> CircularList<T>::~CircularList() { this->clear(); }

template <class T> void PointTailToHead(CircularList<T> *l) {
  Node<T> *currentNode = l->getLeader();

  while (currentNode && currentNode->next) {
    if (currentNode->next != l->getLeader()) {
      currentNode = currentNode->next;
    } else {
      break;
    }
  }
  if (currentNode) {
    currentNode->next = l->getLeader();
  }
}

template <class T> void CircularList<T>::insert(int index, T data) {
  if (index < 0 || index > this->size()) {
    throw "invalid index";
  }
  Node<T> *currentNode = this->head;
  Node<T> *nextNode = 0;

  if (index == 0) {
    // Get tail.
    while (currentNode && currentNode->next) {
      if (currentNode->next == this->head) {
        break;
      }
      currentNode = currentNode->next;
    }
    Node<T> *tail = currentNode;

    // Insert at front.
    if (this->head) {
      nextNode = this->head;
    }
    Node<T> *newNode = new Node<T>(data, nextNode);
    this->head = newNode;

    // Point tail to head.
    if (tail) {
      tail->next = this->head;
    } else {
      this->head->next = this->head;
    }
    return;

  } else if (index == this->size()) {
    // Insert at back.
    while (currentNode && currentNode->next) {
      if (currentNode->next != this->head) {
        currentNode = currentNode->next;
      } else {
        break;
      }
    }
    Node<T> *newNode = new Node<T>(data, this->head);
    currentNode->next = newNode;
    return;
  }

  // Insert at index.
  for (int i = 0; i < index; i++) {
    if (currentNode) {
      if (i == (index - 1)) {
        nextNode = currentNode->next;

        Node<T> *newNode = new Node<T>(data, nextNode);
        currentNode->next = newNode;
      }
    }
    if (currentNode->next != this->head) {
      currentNode = currentNode->next;
    }
  }
}

template <class T> T CircularList<T>::remove(int index) {
  if (this->size() == 0) {
    throw "empty structure";
  }

  if (!(index >= 0 && index < this->size())) {
    throw "invalid index";
  }
  Node<T> *oldHead = this->head;
  Node<T> *currentNode = this->head;
  Node<T> *previousNode = 0;
  Node<T> *nextNode = 0;

  T data;

  if (!currentNode) {
    return 0;
  }

  if (index == 0) {
    if (currentNode->next != this->head) {
      nextNode = currentNode->next;
    }
    data = currentNode->data;
    currentNode->next = 0;
    delete currentNode;
    this->head = nextNode;

    // Change the last node to point to head.
    currentNode = this->head;
    while (currentNode && currentNode->next != oldHead) {
      currentNode = currentNode->next;
    }
    if (currentNode) {
      currentNode->next = this->head;
    }

    return data;
  }

  for (int i = 0; i <= index; i++) {
    if (currentNode) {
      if (i == index) {
        nextNode = currentNode->next;
        data = currentNode->data;
        currentNode->next = 0;
        delete currentNode;
        if (previousNode) {
          previousNode->next = nextNode;
        }

        // Change the last node to point to head.
        currentNode = this->head;
        while (currentNode && currentNode->next != oldHead) {
          currentNode = currentNode->next;
        }
        if (currentNode) {
          currentNode->next = this->head;
        }

        return data;
      }
    }
    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  return data;
}

template <class T> T CircularList<T>::get(int index) const {
  return LinkedList<T>::get(index);
}

template <class T> bool CircularList<T>::isEmpty() {
  if (this->head) {
    return false;
  }
  return true;
}

template <class T> void CircularList<T>::clear() {
  Node<T> *currentNode = this->head;
  Node<T> *nextNode = 0;

  while (currentNode) {
    if (currentNode->next != this->head) {
      nextNode = currentNode->next;
      currentNode->next = 0;
      delete currentNode;
      currentNode = nextNode;
    } else {
      break;
    }
  }
  this->head = 0;
}

template <class T> Node<T> *CircularList<T>::getLeader() const {
  return this->head;
}

template <class T> ostream &CircularList<T>::print(ostream &os) {
  return LinkedList<T>::print(os);
}

template <class T> int CircularList<T>::size() const {
  Node<T> *currentNode = this->head;
  int size = 0;

  while (currentNode) {
    ++size;
    if (currentNode->next != this->head) {
      currentNode = currentNode->next;
    } else {
      break;
    }
  }

  return size;
}

template <class T>
CircularList<T> &CircularList<T>::operator+(const CircularList<T> &other) {
  for (int i = 0; i < other.size(); i++) {
    this->insert(this->size(), other.get(i));
  }

  return *this;
}
