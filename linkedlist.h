#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

namespace qds {

template<typename T> class Node {

  public:
    inline Node(T& element) {
      this->element = element;
      next = NULL;
    }

    inline void setNext(Node<T>* node) {
      next = node;
    }

    inline Node<T>* getNext() {
      return next;
    }

    inline T getElement() const {
      return element;
    }

    inline void setElement(T& element) {
      this->element = element;
    }

  private:
    T element;
    Node<T>* next;

};

template<typename T> class LinkedList {

  public:
    inline LinkedList() {
      front = back = current = NULL;
      inCharge = true;
      size = 0;
    }

    inline ~LinkedList() {
      if (inCharge)
        destroyElements();
      front = back = current = NULL;
      size = 0;
    }

    inline void destroyElements() {
      Node<T>* temp;
      while (front != NULL) {
        temp = front->getNext();
        delete front;
        front = temp;
      }
    }

    inline void setInCharge(bool inCharge) {
      this->inCharge = inCharge;
    }

    inline int getSize() const {
      return size;
    }

    inline bool isEmpty() const {
      return size == 0;
    }

    inline Node<T>* getFront() const {
      return front;
    }

    inline Node<T>* popFront() {
      if (size == 0)
        return NULL;
      Node<T>* res = front;
      front = front->getNext();
      size--;
      return res;
    }

    inline Node<T>* getBack() const {
      return back;
    }

    inline void clear() {
      if (inCharge)
        destroyElements();
      front = back = current = NULL;
      size = 0;
    }

    inline void pushBack(T element) {
      Node<T>* newNode = new Node<T>(element);
      if (size == 0) {
        back = newNode;
        front = newNode;
      }
      else {
        back->setNext(newNode);
        back = newNode;
      }
      size++;
    }

    inline void pushFront(T element) {
      Node<T>* newNode = new Node<T>(element);
      if (size == 0) {
        back = newNode;
        front = newNode;
      }
      else {
        newNode->setNext(front);
        front = newNode;
      }
      size++;
    }

    inline void appendBack(LinkedList<T>* list) {
      back->setNext(list->getFront());
      back = list->getBack();
      size += list->getSize();
      list->setInCharge(false);
      list->clear();
    }

    inline void appendFront(LinkedList<T>* list) {
      list.getBack()->setNext(front);
      front = list->getFront();
      size += list->getSize();
      list->setInCharge(false);
      list->clear();
    }

    inline T* toArray() {
      T* array = NULL;
      if (size > 0) {
        array = new T[size];
        Node<T>* temp = front;
        int i = 0;
        while (temp != NULL) {
          array[i] = temp->getElement();
          i++;
          temp = temp->getNext();
        }
      }
      return array;
    }

    inline void startBrowse() {
      current = front;
    }

    inline bool browse(T& element) {
      if (current == NULL)
        return false;
      element = current->getElement();
      current = current->getNext();
      return true;
    }

  private:
    Node<T>* front;
    Node<T>* back;
    Node<T>* current;
    int size;
    bool inCharge;

};

}

#endif // LINKEDLIST_H
