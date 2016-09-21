#include "xAxis.h"


xAxis::~xAxis() {
        node* current_Node = this->head;
        while (current_Node->next != 0) {
                current_Node = current_Node->next;
        }
        delete current_Node;

        delete this->head;
}
xAxis::xAxis() {
        this->head = 0;
}
/* constructor: length is the length of the x-axis
        n is an array of labels to describe the values in the x-axis
        v is an array of values for each label
   If the value is negative then store it as 0.	*/
xAxis::xAxis(int length, string* n, double* v) {
        this->head = 0;
        node* prev_Node = 0;
        node* current_Node = 0;

        for (int i = 0; i < length; i++) {
                // Check for negative values.
                double value = v[i];
                if (value < 0) {
                        value = 0;
                }

                current_Node = new node {value, n[i], 0};

                if (this->head == 0) {
                        this->head = current_Node;
                }

                // Point the next of the previous node to the new node.
                if (prev_Node) {
                        prev_Node->next = current_Node;
                }
                // Let previous node contain this node for next iteration.
                prev_Node = current_Node;
        }
}

/*appends one node to the linked list with the value v and the label n
   If the value is negative then store it as 0.*/
void xAxis::extend(double v,string n) {
        node* last_Node = this->head;
        // Traverse entire list to the end.
        while (last_Node->next != 0) {
                last_Node = last_Node->next;
        }

        // Check for negative values.
        double value = v;
        if (value < 0) {
                value = 0;
        }

        node* current_Node = new node {value, n, 0};

        last_Node->next = current_Node;
}

/*removes the last node from the linked list*/
void xAxis::shorten() {
        node* last_Node = this->head;
        node* prev_Node = 0;
        // Traverse entire list to the end.
        while (last_Node->next != 0) {
                // Save the previous node.
                prev_Node = last_Node;
                last_Node = last_Node->next;
        }

        last_Node->next = 0;
        // Delete the last node.
        delete last_Node;

        // Point previous node to 0;
        prev_Node->next = 0;
}
/*removes the node with the label n from the linked list*/
void xAxis::deleteNode(string n) {
        node* current_Node = this->head;
        node* prev_Node = 0;
        node* next_Node = 0;

        // Traverse till we find the name;
        while (current_Node->next != 0) {
                // If found exit loop.
                if (current_Node->label == n) {
                        break;
                }

                prev_Node = current_Node;
                current_Node = current_Node->next;
                // TODO: THIS LOOKS FISHY.
                next_Node = current_Node->next;
        }

        // If the current node is the head we must repoint the head.
        if (current_Node == this->head) {
                this->head = current_Node->next;
        }

        // Delete current_Node.
        current_Node->next = 0;
        delete current_Node;

        // Fix pointers.
        prev_Node->next = next_Node;
}
/*increases the value of the node with label n by val*/
void xAxis::increaseValueBy(string n,double val) {
        node* current_Node = this->head;
        // Traverse till we find the name;
        while (current_Node->next != 0) {
                // If found exit loop.
                if (current_Node->label == n) {
                        break;
                }
                current_Node = current_Node->next;
        }

        current_Node->value += val;
}
/*decreases the value of the node with label n by val
   If the value becomes negative then store it as 0.*/
void xAxis::decreaseValueBy(string n,double val) {
        node* current_Node = this->head;
        // Traverse till we find the name;
        while (current_Node->next != 0) {
                // If found exit loop.
                if (current_Node->label == n) {
                        break;
                }
                current_Node = current_Node->next;
        }

        current_Node->value -= val;
}
/*the node which has the label o must be changed so that it has the label n*/
void xAxis::changeLabel(string o,string n) {
        node* current_Node = this->head;
        // Traverse till we find the name;
        while (current_Node->next != 0) {
                // If found exit loop.
                if (current_Node->label == o) {
                        break;
                }
                current_Node = current_Node->next;
        }

        current_Node->label = n;
}
/*displays all the nodes in a " label    value " newline  format.

   ie:
   one   1.97
   two   2.8076
   three   3.21
 */
void xAxis::display() {
        node* current_Node = this->head;
        cout << current_Node->label << "\t" << current_Node->value << endl;

        // Traverse till we reach the end;
        do {
                current_Node = current_Node->next;
                cout << current_Node->label << "\t" << current_Node->value << endl;

        } while (current_Node->next != 0);
}
