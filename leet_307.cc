#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {
    }
};

void destroyTree(TreeNode* root) {
    if (!root)
        return;

    if (root->left)
        destroyTree(root->left);
    if (root->right)
        destroyTree(root->right);
    delete root;
};

vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
void createTree(vector<int> &data, TreeNode* &root) {
    assert(root == NULL);
    root = new TreeNode(data[0]);
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < data.size();) {
        TreeNode* p = q.front();
        q.pop();
        if (i < data.size()) {
            p->left = new TreeNode(data[i]);
            i++;
            q.push(p->left);
        }
        if (i < data.size()) {
            p->right = new TreeNode(data[i]);
            i++;
            q.push(p->right);
        }
    }
}

struct SegTreeNode {
    int left;
    int right;
    int val;
    SegTreeNode* lchild;
    SegTreeNode* rchild;
    SegTreeNode(int l, int r): left(l), right(r), lchild(NULL), rchild(NULL) {};
};

class NumArray {
  public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        range = n;
        tree.resize(2 * n);
        createTree(nums, 1, n, 1);
    };
    void update(int i, int val) {
        update_helper(i+1, val, 1, range, 1);
    };
    int sumRange(int i, int j) {
        return sumRange_helper(i+1, j+1, 1, range , 1);
    };
  private:
    int createTree(vector<int> &nums, int l, int r, int index);
    int sumRange_helper(int i, int j, int l, int r, int index);
    void update_helper(int i, int val, int l , int r, int index);

    //SegTreeNode* root;
    //vector<SegTreeNode> tree;
    vector<int> tree;
    int range;
};

int NumArray::createTree(vector<int> &nums, int l, int r, int index) {
#ifdef DEBUG
    printf("l-->%d r-->%d index-->%d\n", l, r, index);
#endif
    if(l == r) {
        tree[index] = nums[l-1];
        return nums[l-1];
    }
    int mid = (l + r) >> 1;
    int val1 = createTree(nums, l, mid, index << 1);
    int val2 = createTree(nums, mid + 1, r, index << 1 | 1);
    tree[index] = val1 + val2;
    return tree[index];
}


int NumArray::sumRange_helper(int i, int j, int l, int r, int index) {
#ifdef DEBUG
    printf("l-->%d r-->%d index-->%d\n", l, r, index);
#endif
    assert(l <= r);
    assert(i >= l);
    assert(j <= r);

    if(i == l && j == r)return tree[index];
    int mid = (l + r) >> 1;
    if(mid >= j)
        return sumRange_helper(i, j, l, mid, index << 1);
    if(mid + 1 <= i)
        return sumRange_helper(i, j, mid + 1, r, index << 1 | 1);
    return sumRange_helper(i, mid, l, mid, index) + sumRange_helper(mid + 1, j, mid + 1, r, index);

}

void NumArray::update_helper(int i , int val, int l, int r, int index) {
    assert(i >= l && i <= r);
    if(l == r) {
        tree[index] = val;
        return ;
    }

    int mid = (l + r) >> 1;
    if(i <= mid)
        update_helper(i, val, l, mid, index << 1);
    else
        update_helper(i, val, mid + 1, r, index << 1 | 1);
    tree[index] = tree[index << 1] + tree[index << 1 | 1];
    return ;
}







int main(int argc , char** argv) {
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    int i = 0;
    int j = 2;
    printf("sum range of %d and %d is: %d\n", i, j, numArray.sumRange(i, j));
    numArray.update(1, 2);
    printf("sum range of %d and %d is: %d\n", i, j, numArray.sumRange(i, j));
    return 0;


}












