/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
 */
#include "linkedList.h"
// Provide the implementation for the LinkedList class in this file.

template <class T> ostream &operator<<(ostream &os, LinkedList<T> &ll) {
  // cout << ll.size();
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

template <class T> LinkedList<T>::LinkedList() { this->head = 0; }

template <class T> LinkedList<T>::LinkedList(const LinkedList<T> &other) {
  this->head = 0;
  for (int i = 0; i < other.size(); i++) {
    insert(this->size(), other.get(i));
  }
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
  this->clear();
  this->head = 0;
  for (int i = 0; i < other.size(); i++) {
    this->insert(i, other.get(i));
  }

  return *this;
}

template <class T> LinkedList<T> *LinkedList<T>::clone() {
  LinkedList<T> *newList = new LinkedList<T>(*this);
  return newList;
}

template <class T> LinkedList<T>::~LinkedList() { this->clear(); }

template <class T> void LinkedList<T>::insert(int index, T data) {
  if (index < 0 || index > this->size()) {
    throw "invalid index";
  }

  Node<T> *currentNode = this->head;
  Node<T> *nextNode = 0;

  if (index == 0) {
    if (this->head) {
      nextNode = this->head;
    }
    Node<T> *newNode = new Node<T>(data, nextNode);
    this->head = newNode;
  } else if (index == this->size()) {
    while (currentNode->next) {
      currentNode = currentNode->next;
    }
    Node<T> *newNode = new Node<T>(data, 0);
    currentNode->next = newNode;

    return;
  }

  for (int i = 0; i < index; i++) {
    if (currentNode) {
      if (i == (index - 1)) {
        nextNode = currentNode->next;

        Node<T> *newNode = new Node<T>(data, nextNode);

        currentNode->next = newNode;
      }
    }
    currentNode = currentNode->next;
  }
}

template <class T> T LinkedList<T>::remove(int index) {
  if (this->size() == 0) {
    throw "empty structure";
  }

  if (!(index >= 0 && index < this->size())) {
    throw "invalid index";
  }

  Node<T> *currentNode = this->head;
  Node<T> *previousNode = 0;
  Node<T> *nextNode = 0;

  T data = 0;

  if (!currentNode) {
    return 0;
  }

  if (index == 0) {
    if (currentNode->next) {
      nextNode = currentNode->next;
    }
    data = currentNode->data;
    currentNode->next = 0;
    currentNode = 0;
    this->head = nextNode;

    return data;
  }

  for (int i = 0; i <= index; i++) {
    if (currentNode) {
      if (i == index) {
        Node<T> *nextNode = currentNode->next;
        data = currentNode->data;
        currentNode->next = 0;
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

template <class T> T LinkedList<T>::get(int index) const {
  if (this->size() == 0) {
    throw "empty structure";
  }

  if (!(index >= 0 && index < this->size())) {
    throw "invalid index";
  }

  Node<T> *currentNode = this->head;
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

template <class T> bool LinkedList<T>::isEmpty() {
  if (!this->head) {
    return true;
  }
  return false;
}

template <class T> void LinkedList<T>::clear() {
  Node<T> *currentNode = this->head;
  Node<T> *nextNode = 0;

  while (currentNode) {
    nextNode = currentNode->next;
    currentNode->next = 0;
    delete currentNode;
    currentNode = nextNode;
  }
  this->head = 0;
}

template <class T> Node<T> *LinkedList<T>::getLeader() const {
  return this->head;
}

template <class T> ostream &LinkedList<T>::print(ostream &os) { return os; }

template <class T> int LinkedList<T>::size() const {
  Node<T> *currentNode = this->head;
  int size = 0;
  while (currentNode) {
    ++size;
    currentNode = currentNode->next;
  }

  return size;
}

template <class T> T LinkedList<T>::operator[](int index) {
  return this->get(index);
}

template <class T>
LinkedList<T> &LinkedList<T>::operator+(const LinkedList<T> &other) {
  for (int i = 0; i < other.size(); i++) {
    this->insert(this->size(), other.get(i));
  }

  return *this;
}
