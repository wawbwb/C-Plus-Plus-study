#include <iostream>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // 递归插入节点
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }
        
        if (value < current->val) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->val) {
            current->right = insertRecursive(current->right, value);
        }
        
        return current;
    }

    // 中序遍历
    void inorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->val << " ";
            inorderTraversalRecursive(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // 插入节点
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // 打印中序遍历结果
    void printInorder() {
        cout << "Inorder traversal result: ";
        inorderTraversalRecursive(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    
    // 插入一些节点
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);

    // 打印中序遍历结果
    tree.printInorder();

    return 0;
}