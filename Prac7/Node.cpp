#include "Node.h"

Node::Node() { head = NULL; }

Node::~Node() {
  node *trav;
  node *prev = head;
  if (!head) {
    return;
  }
  while (trav) {
    trav = prev->next;
    delete prev;
    prev = trav;
  }
}

Node::Node(int length, string *value) {

  node *newnode;
  node *trav = head;
  for (int i = 0; i < length; i++) {
    newnode = new node();

    newnode->name = value[i];
    newnode->next = NULL;

    if (i == 0) {
      head = newnode;
      trav = head;
    } else {
      trav->next = newnode;
      trav = trav->next;
    }
  }
}

void Node::display() {
  node *trav = head;
  while (trav) {
    cout << trav->name << " ";
    trav = trav->next;
  }
  cout << endl;
}

// NOTE
// Do NOT change any code above this line
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void Node::reverse() {
  node *trav = head;
  node *tail = 0;
  node *next = 0;

  // Go to end of the list.
  while (trav->next) {
    trav = trav->next;
  }

  // Set tail to the last element.
  tail = trav;
  next = tail;

  // Restart loop.
  while (next != head) {
    trav = head;

    // Loop till we almost reach the tail.
    while (next != trav->next) {
      trav = trav->next;
      // cout << trav->name << " ";
    }

    // Point the previous element to the next one.
    next->next = trav;
    if (!tail->next) {
      tail = next;
    }
    next = trav;
  }

  // Make the tail the head.
  head->next = 0;
  head = tail;
}
