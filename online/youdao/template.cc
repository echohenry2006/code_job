// compile: // g++ -std=c++11 sol1.cc -o sol1.exe
#include <iostream>
#include <string>
#include <vector>

// iterator erase (const_iterator position);
// iterator erase (const_iterator first, const_iterator last);
// front() back() push_back() pop_back()

// insert
/*
single element (1)
iterator insert (const_iterator position, const value_type& val);
fill (2)
iterator insert (const_iterator position, size_type n, const value_type& val);
range (3)
template <class InputIterator>
iterator insert (const_iterator position, InputIterator first, InputIterator
last);
move (4)
iterator insert (const_iterator position, value_type&& val);
initializer list (5)
iterator insert (const_iterator position, initializer_list<value_type> il);
*/

// assign
/*
range (1)
template <class InputIterator>
  void assign (InputIterator first, InputIterator last);
fill (2)
void assign (size_type n, const value_type& val);
initializer list (3)
void assign (initializer_list<value_type> il);
*/
#include <queue>
// back() empty() front() pop() push() size()
#include <set>
#include <stack>

// insert()
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>

/*
  std::bitset<16> foo;
  std::bitset<16> bar (0xfa2);
  std::bitset<16> baz (std::string("0101111001"));
*/
// count() nums of 1's
// all()
// any() Test if any bit is set
// size() Return size (public member function )
// None() Test if no bit is set (public member function )
// set() set all bits to 1
// set(size_t pos, bool val = true) set bit at pos to val
// reset()
// reset(size_t pos, bool val = true)
// test() Returns whether the bit at position pos is set (i.e., whether it is
// one).
// to_string() Convert to string (public member function )
// to_ulong() unsigned long to_ulong() const;
// to_ullong()

#include <algorithm>
#include <cassert>
using namespace std;

int main(int argc, char **argv) {}