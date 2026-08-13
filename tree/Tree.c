#include<stdio.h>

typedef struct BinNode{
    int data;
    struct BinTode *left, *right;
}BinNode, *BinTree;

//创建新节点
BinNode* createNode(int val){
    BinNode *p = (BinNode*)malloc(sizeof(BinNode));
    p -> data = val;
    p -> left = p -> right = NULL;
    return p;
}


struct TreeNode{//二叉树结点定义
    int val;
    struct TreeNode *left;
    struct TreeNdoe *right;

};


// 辅助函数：返回当前节点的最大深度，同时通过指针更新直径
int maxDepth(struct TreeNdoe* node, int* maxDiameter)
{
    if(node == NULL)
    {
        return 0;//空节点深度为0
    }

    //后序遍历：先算左，右子树的深度（递归的核心）
    int leftDepth = maxDepth(node->left, maxDiameter);
    int rightDepth = maxDepth(node->right, maxDiameter);

    //关键一步：更新最大直径（经过当前节点的最长路径）
    int currentDiameter = leftDepth + rightDepth;
    if(currentDiameter > *maxDiameter){
        *maxDiameter = currentDiameter;
    } 

    //返回当前节点深度（左右树较深者 + 1）
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int maxDiameter = 0;
    maxDepth(root, &maxDiameter);
    return maxDiameter;
}

int main(void)
{



}

