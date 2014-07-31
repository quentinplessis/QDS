#include <iostream>

#include "linkedlist.h"

using namespace qds;
using namespace std;


int main() {
  cout << "--------------- QDS ---------------" << endl << endl;
  //
  // Linked List
  //
  LinkedList<int> linkedList;
  linkedList.pushBack(0);
  linkedList.pushBack(1);
  linkedList.pushBack(2);
  linkedList.pushBack(3);
  linkedList.pushBack(4);

  cout << "------------------" << endl;
  cout << "Linked lists" << endl;
  cout << "------------------" << endl;
  linkedList.startBrowse();
  int element;
  while (linkedList.browse(element)) {
    cout << "Element : " << element << endl;
  }


  return 0;
}

