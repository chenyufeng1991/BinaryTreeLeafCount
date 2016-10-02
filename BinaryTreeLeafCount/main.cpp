//
//  main.cpp
//  BinaryTreeLeafCount
//
//  Created by chenyufeng on 10/2/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
}Node;

/**
 *  求二叉树叶子节点的个数
 */

void CreateBinaryTree(Node **node)
{
    int num;
    cin >> num;

    if (num == -1)
    {
        return;
    }

    *node = new Node;
    (*node)->data = num;
    (*node)->lChild = NULL;
    (*node)->rChild = NULL;

    cout << "请输入" << num << "的左孩子的节点：";
    CreateBinaryTree(&((*node)->lChild));
    cout << "请输入" << num << "的右孩子的节点：";
    CreateBinaryTree(&((*node)->rChild));
}

int leafCount = 0;

void LeafCountBinaryCount(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node ->lChild == NULL && node ->rChild == NULL)
    {
        leafCount++;
    }

    LeafCountBinaryCount(node->lChild);
    LeafCountBinaryCount(node->rChild);

    return;
}

int main(int argc, const char * argv[])
{
    Node *node;

    cout << "请输入二叉树的节点，输入-1结束:"<< endl;
    CreateBinaryTree(&node);

    LeafCountBinaryCount(node);
    cout << leafCount << endl;

    return 0;
}














