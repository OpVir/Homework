#include <iostream> 
#include <cstdlib>

#include "forwardlist.hxx"
#include "vector.hxx"
#include "tools.hxx"

using namespace fwl;

int main() 
{ 
  // vector v;

  // resize(v, 10);
  // fill(v);
  // output(v);
  // remove(v);

  // Elem* head = new Elem;
  // head->next = new Elem;
  // head->next->next = new Elem;

  Elem* head = nullptr;
  forwardlist* list = new forwardlist;
  push(list, 1);
  push(list, 2);
  push(list, 3);
  output(list);
  remove(list);
  output(list);
  std::system("pause");
  return 0; 
}