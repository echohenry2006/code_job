/* Copyright (C)
 * 2016 - Yong Yang
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */
/**
 * @file leet_144.cc
 * @brief
 * @author Yong Yang
 * @version 1.0
 * @date 2016-06-30
 */
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> q;
        q.push(root);



        while (!q.empty()) {
            TreeNode* ptr = q.top();
            q.pop();

            // TODO
        }
    };
};

void destroyTree(TreeNode* root) {
    if (!root)
        return;

    if (root->left)
        destroyTree(root->left);
    if (root->right)
        destroyTree(root->right);
    delete root;
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 *
 * @return
 */
int main(int argc, char** argv) {
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    TreeNode* root = new TreeNode(1);
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

    cout << "*******************" << endl;

    destroyTree(root);

    return 0;
}


