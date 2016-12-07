/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
 */
// Provide the implementation for the DoubleList class in this file.

template <class T> ostream &operator<<(ostream &os, DoubleList<T> &ll) {
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

template <class T> DoubleList<T>::DoubleList() { this->dhead = 0; }

template <class T> DoubleList<T>::DoubleList(const DoubleList<T> &other) {
  // this->clear();
  this->dhead = 0;
  for (int i = 0; i < other.size(); i++) {
    this->insert(this->size(), other.get(i));
  }
}

template <class T>
DoubleList<T> &DoubleList<T>::operator=(const DoubleList<T> &other) {
  // this->clear();
  this->dhead = 0;
  for (int i = 0; i < other.size(); i++) {
    this->insert(i, other.get(i));
  }
  return *this;
}

template <class T> DoubleList<T> *DoubleList<T>::clone() {
  DoubleList<T> *newList = new DoubleList<T>(*this);
  return newList;
}

template <class T> DoubleList<T>::~DoubleList() { this->clear(); }

template <class T> void DoubleList<T>::insert(int index, T element) {
  if (index < 0 || index > this->size()) {
    throw "invalid index";
  }

  dNode<T> *currentNode = this->dhead;
  dNode<T> *nextNode = 0;

  if (index == 0) {
    if (this->dhead) {
      nextNode = this->dhead;
    }
    dNode<T> *newNode = new dNode<T>(element, nextNode, 0);

    if (nextNode) {
      nextNode->prev = newNode;
    }
    this->dhead = newNode;
  } else if (index == this->size()) {
    while (currentNode && currentNode->next) {
      currentNode = currentNode->next;
    }
    dNode<T> *newNode = new dNode<T>(element, 0, currentNode);
    currentNode->next = newNode;

    return;
  }

  for (int i = 0; i < index; i++) {
    if (currentNode) {
      if (i == (index - 1)) {
        nextNode = currentNode->next;
        dNode<T> *newNode = new dNode<T>(element, nextNode, currentNode);
        if (nextNode) {
          nextNode->prev = newNode;
        }
        currentNode->next = newNode;
      }
    }
    currentNode = currentNode->next;
  }
}

template <class T> T DoubleList<T>::remove(int index) {
  if (this->size() == 0) {
    throw "empty structure";
  }

  if (!(index >= 0 && index < this->size())) {
    throw "invalid index";
  }

  dNode<T> *currentNode = this->dhead;
  dNode<T> *previousNode = 0;
  dNode<T> *nextNode = 0;

  T data;

  if (!currentNode) {
    return 0;
  }

  if (index == 0) {
    if (currentNode->next) {
      nextNode = currentNode->next;
      nextNode->prev = 0;
    }
    data = currentNode->data;
    delete currentNode;

    this->dhead = nextNode;
    return data;
  }

  for (int i = 0; i <= index; i++) {
    if (currentNode) {
      if (i == index) {
        dNode<T> *nextNode = currentNode->next;
        if (nextNode) {
          nextNode->prev = previousNode;
        }
        data = currentNode->data;

        currentNode->next = 0;
        currentNode->prev = 0;

        delete currentNode;

        if (previousNode) {
          previousNode->next = nextNode;
        }
        return data;
      }
    }
    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  return data;
}

template <class T> T DoubleList<T>::get(int index) const {
  if (this->size() == 0) {
    throw "empty structure";
  }

  if (!(index >= 0 && index < this->size())) {
    throw "invalid index";
  }

  dNode<T> *currentNode = this->dhead;
  if (!currentNode) {
    return 0;
  }

  if (index == 0) {
    return currentNode->data;
  }

  for (int i = 0; i <= index; i++) {
    if (currentNode) {
      if (i == index) {
        return currentNode->data;
      }
    }
    currentNode = currentNode->next;
  }

  return 0;
}

template <class T> T DoubleList<T>::operator[](int index) {
  return this->get(index);
}

template <class T> bool DoubleList<T>::isEmpty() {
  if (this->dhead) {
    return false;
  }
  return true;
}

template <class T> void DoubleList<T>::clear() {
  dNode<T> *currentNode = this->dhead;
  dNode<T> *nextNode = 0;

  if (!currentNode) {
    return;
  }
  while (currentNode && currentNode->next) {
    nextNode = currentNode->next;
    delete currentNode;
    currentNode = nextNode;
  }
  this->dhead = 0;
}

template <class T> dNode<T> *DoubleList<T>::getHead() const {
  return this->dhead;
}

template <class T> ostream &DoubleList<T>::print(ostream &os) {
  return LinkedList<T>::print(os);
}

template <class T> int DoubleList<T>::size() const {
  dNode<T> *currentNode = this->dhead;
  int size = 0;
  while (currentNode) {
    ++size;
    currentNode = currentNode->next;
  }

  return size;
}

template <class T>
DoubleList<T> &DoubleList<T>::operator+(const DoubleList<T> &other) {
  // cout << "+operator";
  // cout << other.size();

  for (int i = 0; i < other.size(); i++) {
    this->insert(this->size(), other.get(i));
  }
  return *this;
}
