#include <cassert>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class heap {
public:
  heap(){};
  T top();
  void pop();
  void insert(T t);
  int size() { return data.size(); }

private:
  vector<T> data;
  void percdown();
};

template <typename T> void heap<T>::insert(T t) {
  data.push_back(t);
  int parent = data.size() / 2 - 1;
  int cur = data.size() - 1;
  while (parent >= 0 && data[cur] < data[parent]) {
    swap(data[cur], data[parent]);
    cur = parent;
    parent = cur / 2 - 1;
  }
}

template <typename T> void heap<T>::percdown() {
  int cur = 0;
  while (cur < data.size()) {
    int lchild = cur * 2 + 1;
    int rchild = lchild + 1;
    if (lchild < data.size() && data[cur] > data[lchild]) {
      swap(data[lchild], data[cur]);
      cur = lchild;
      continue;
    }

    if (rchild < data.size() && data[cur] > data[rchild]) {
      swap(data[rchild], data[cur]);
      cur = rchild;
      continue;
    }

    break;
  }
}

template <typename T> void heap<T>::pop() {
  assert(data.size() > 0);
  swap(data.front(), data.back());
  data.pop_back();
  percdown();
}

template <typename T> T heap<T>::top() {
  assert(data.size() > 0);
  return data.front();
}

void print(vector<int> &nums) {
  for (auto s : nums)
    cout << s << " " << endl;
}

// strait insert sort O(n^2)
void insert_sort(vector<int> &nums) {
  cout << "insert sort" << endl;
  for (int i = 0; i < nums.size(); i++) {
    int cur = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > cur) {
      nums[j + 1] = nums[j];
      j--;
    }
    j++;
    nums[j] = cur;
  }
  print(nums);
}

// select sort O(n^2)
void select_sort(vector<int> &nums) {
  cout << "select sort" << endl;
  for (int i = 0; i < nums.size(); i++) {
    int curmax = i;
    for (int j = i + 1; j < nums.size(); j++)
      curmax = nums[curmax] < nums[j] ? j : curmax;
    swap(nums[i], nums[curmax]);
  }
  print(nums);
}

// bubble sort O(n^2)
void bubble_sort(vector<int> &nums) {
  cout << "bubble sort" << endl;
  for (int i = 0; i < nums.size() - 1; i++)
    for (int j = 0; j < nums.size() - 1 - i; j++)
      if (nums[j] > nums[j + 1])
        swap(nums[j], nums[j + 1]);

  print(nums);
}

// quick_sort
void quick_sort_helper(vector<int> &nums, int start, int end) {

  // assert(start<=end);
  if (start >= end)
    return;

  int pivot = nums[start];
  int low = start;
  int high = end;
  while (low < high) {
    while (low < high && nums[high] >= pivot)
      high--;
    while (low < high && nums[low] <= pivot)
      low++;
    swap(nums[low], nums[high]);
  }
  if (low == high)
    swap(nums[start], nums[low]);
  quick_sort_helper(nums, start, low - 1);
  quick_sort_helper(nums, low + 1, end);
}

void quick_sort(vector<int> &nums) {
  cout << "quick sort" << endl;
  quick_sort_helper(nums, 0, nums.size() - 1);
}

int main() {
  vector<int> nums = {3, 1, 5, 7, 2, 4, 9, 6};
  quick_sort(nums);
  print(nums);

  /*
  // test head class
  heap<int> hp;
  hp.insert(3);
  hp.insert(2);
  hp.insert(1);

  cout<<"size "<<hp.size()<<endl;
  for(int i=0;i<3;i++){

      cout<<"i is "<<i << " top is " << hp.top() <<endl;
      cout<<"size "<<hp.size()<<endl;
      hp.pop();
  }
  */

  return 0;
}