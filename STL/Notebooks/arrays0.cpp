using namespace std;
// constructing arrays
#include <iostream>
#include <array>

// default initialization (non-local = static storage):
array<int,3> global;               // zero-initialized: {0,0,0}

int main ()
{
  // default initialization (local = automatic storage):
  array<int,3> first;              // uninitialized:    {?,?,?}

  // initializer-list initializations:
  array<int,3> second = {10,20};   // initialized as:   {10,20,0}
  array<int,3> third = {1,2,3};    // initialized as:   {1,2,3}

  // copy initialization:
  array<int,3> fourth = third;     // copy:             {1,2,3}

  cout << "The contents of fourth are:";
  for (auto x:fourth) 
    cout << ' ' << x;
  cout << '\n';

  return 0;
}
