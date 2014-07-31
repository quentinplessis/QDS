#include <iostream>
#include <list>
#include <ctime>

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


  cout << endl << "Performance test: " << endl;

  list<int> testList1, testList2;
  LinkedList<int> testLList1, testLList2;
  time_t start, end;
  int tests = 10000;


  cout << "------------------" << endl;
  cout << "Push back qds::LinkedList" << endl;
  time(&start);
  for (int k = 0 ; k < tests ; k++) {
    testLList1.clear();
    for (int i = 0 ; i < 50000 ; i++)
      testLList1.pushBack(i);
    if (k * 100.0 / tests / 10 == ((float) (k * 100 / tests / 10)))
      cout << (k * 100 / tests) << "%, ";
  }
  time(&end);
  cout << endl;
  cout << "Size: " << testLList1.getSize() << endl;
  cout << "Time: " << (1000.0 * ((double) difftime(end, start)) / tests) << "ms (total " << difftime(end, start) <<"s for " << tests << " tests)" << endl;


  cout << "------------------" << endl;
  cout << "Push back std::list" << endl;
  time(&start);
  for (int k = 0 ; k < tests ; k++) {
    testList1.clear();
    for (int i = 0 ; i < 50000 ; i++)
      testList1.push_back(i);
    if (k * 100.0 / tests / 10 == ((float) (k * 100 / tests / 10)))
      cout << (k * 100 / tests) << "%, ";
  }
  time(&end);
  cout << endl;
  cout << "Size: " << testList1.size() << endl;
  cout << "Time: " << (1000.0 * ((double) difftime(end, start)) / tests) << "ms (total " << difftime(end, start) <<"s for " << tests << " tests)" << endl;


  cout << "------------------" << endl;
  cout << "Push back + append back qds::LinkedList" << endl;
  time(&start);
  for (int k = 0 ; k < tests ; k++) {
    testLList1.clear();
    testLList2.clear();
    for (int i = 0 ; i < 2 ; i++)
      testLList1.pushBack(i);
    for (int i = 0 ; i < 50000 ; i++)
      testLList2.pushBack(i);
    testLList1.appendBack(&testLList2);
    if (k * 100.0 / tests / 10 == ((float) (k * 100 / tests / 10)))
      cout << (k * 100 / tests) << "%, ";
  }
  time(&end);
  cout << endl;
  cout << "Size: list1 " << testLList1.getSize() << ", list2 " << testLList2.getSize() << endl;
  cout << "Time: " << (1000.0 * ((double) difftime(end, start)) / tests) << "ms (total " << difftime(end, start) <<"s for " << tests << " tests)" << endl;


  cout << "------------------" << endl;
  cout << "Push back + append back std::list" << endl;
  time(&start);
  for (int k = 0 ; k < tests ; k++) {
    testList1.clear();
    testList2.clear();
    for (int i = 0 ; i < 2 ; i++)
      testList1.push_back(i);
    for (int i = 0 ; i < 50000 ; i++)
      testList2.push_back(i);
    //std::copy(testList2.begin(), testList2.end(),
    //std::back_insert_iterator<std::list<int> >(testList1));
    testList1.splice(testList1.end(), testList2);
    if (k * 100.0 / tests / 10 == ((float) (k * 100 / tests / 10)))
      cout << (k * 100 / tests) << "%, ";
  }
  time(&end);
  cout << endl;
  cout << "Size: list1 " << testList1.size() << ", list2 " << testList2.size() << endl;
  cout << "Time: " << (1000.0 * ((double) difftime(end, start)) / tests) << "ms (total " << difftime(end, start) <<"s for " << tests << " tests)" << endl;

  return 0;
}

