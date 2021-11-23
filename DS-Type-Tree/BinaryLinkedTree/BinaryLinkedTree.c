//
// Created by P7XXTM1-G on 2021/11/22.
//

#include "BinaryLinkedTree.h"

// 二叉链表（二叉树链式存储结构）

// 创建二叉树
BinaryLinkedTree MakeBinaryTree(TreeElemType rootData, BinaryLinkedTree leftTree, BinaryLinkedTree rightTree) {
    // 创建一棵二叉树 T，其中根节点的值为 rootData，leftTree 和 rightTree 分别作为左子树和右子树
    BinaryLinkedTree T;

    T = (BinaryLinkedTree) malloc(sizeof(BinaryLinkedTreeNode));

    if (T == NULL) {
        return NULL;
    }

    // 赋值根节点
    T->data = rootData;

    // 赋值左子树
    T->leftChild = leftTree;

    // 赋值右子树
    T->rightChild = rightTree;

    return T;
}

// 替换左子树
Status ReplaceLeft(BinaryLinkedTree *binaryLinkedTree, BinaryLinkedTree *leftTree) {
    // 替换左子树，若 binaryLinkedTree 非空，则用 leftTree 替换 binaryLinkedTree 的左子树，并用 leftTree 返回 binaryLinkedTree 的先前左子树
    BinaryLinkedTree temp;

    if (binaryLinkedTree == NULL) {
        // 传入空树
        return ERROR;
    }

    temp = (*binaryLinkedTree)->leftChild;

    // 将新的 leftTree 作为 binaryLinkedTree 的新左子树
    (*binaryLinkedTree)->leftChild = *leftTree;

    // 返回 binaryLinkedTree 的旧左子树
    *leftTree = temp;

    return OK;
}

// 替换右子树
// 步骤等同于 替换左子树，变动为：将左子树地址 修改为 右子树地址
Status ReplaceRight(BinaryLinkedTree *binaryLinkedTree, BinaryLinkedTree *rightTree) {
    BinaryLinkedTree temp;

    if (binaryLinkedTree == NULL) {
        return ERROR;
    }

    temp = (*binaryLinkedTree)->rightChild;

    (*binaryLinkedTree)->rightChild = *rightTree;

    *rightTree = temp;

    return OK;
}

// 剪除左子树
Status CutLeft(BinaryLinkedTree *binaryLinkedTree) {

    if (binaryLinkedTree == NULL) {
        return ERROR;
    }

    // 将空值赋予 binaryLinkedTree 的左子树地址，即可剪除 binaryLinkedTree 的所有左子树
    (*binaryLinkedTree)->leftChild = NULL;

    return OK;
}

// 剪除右子树
Status CutRight(BinaryLinkedTree *binaryLinkedTree) {
    if (binaryLinkedTree == NULL) {
        return ERROR;
    }

    (*binaryLinkedTree)->rightChild = NULL;

    return OK;
}

// 递归遍历
// 前序遍历
// 根 - 左 - 右
Status PreOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    // 当遇到 空左子树 时无需遍历
    if (root == NULL) {
        return OK;
    }

    // 访问结点数据域
    if (visit(root->data)) {
        return ERROR;
    }

    // 递归遍历左子树
    if (PreOrderTraverse(root->leftChild, visit)) {
        return ERROR;
    }

    // 递归遍历右子树
    return PreOrderTraverse(root->rightChild, visit);
}

void PreOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    if (root) {
        printf("%c", root->leftChild->data);
        PreOrderTraverse_OwnStyle(root->leftChild, visit);
        PreOrderTraverse_OwnStyle(root->rightChild, visit);
    }
}

// 中序遍历
// 左 - 根 - 右
Status InOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    // 当遇到 空根节点 时无需遍历
    if (root == NULL) {
        return OK;
    }

    // 递归遍历左子树
    if (InOrderTraverse(root->leftChild, visit)) {
        return ERROR;
    }

    // 访问结点数据域
    if (visit(root->data)) {
        return ERROR;
    }

    // 递归遍历右子树
    return InOrderTraverse(root->rightChild, visit);
}

void InOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    if (root) {
        InOrderTraverse_OwnStyle(root->leftChild, visit);
        printf("%c", root->leftChild->data);
        InOrderTraverse_OwnStyle(root->rightChild, visit);
    }
}

// 后序遍历
// 左 - 右 - 根
Status PostOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    // 当遇到 空根节点 时无需遍历
    if (root == NULL) {
        return OK;
    }

    // 递归遍历左子树
    if (PostOrderTraverse(root->leftChild, visit)) {
        return ERROR;
    }

    // 递归遍历右子树
    if (PostOrderTraverse(root->leftChild, visit)) {
        return ERROR;
    }

    // 访问节点数据域
    return (visit(root->data) == ERROR);
}

void PostOrderTraverse_OwnStyle(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    if (root) {
        PostOrderTraverse_OwnStyle(root->leftChild, visit);
        PostOrderTraverse_OwnStyle(root->rightChild, visit);
        printf("%c", root->leftChild->data);
    }
}

// 非递归遍历
// 沿途找到最左下的结点，将沿途结点指针入栈
BinaryLinkedTreeNode *GoFarLeft(BinaryLinkedTree root, LinkStack *stack) {
    if (root == NULL) {
        return NULL;
    }

    while (root->leftChild != NULL) {
        Push_LS(stack, &root);
        root = root->leftChild;
    }

    return root;
}

// 非递归中序遍历
// 每遇到一个结点就把它入栈，然后遍历左子树
// 遍历完左子树后，从栈顶弹出这个结点并访问该结点，然后按照他的right域遍历该结点的右子树
void InOrderTraverse_I(BinaryLinkedTree root, Status(*visit)(TreeElemType elem)) {
    LinkStack stack;

    InitStack_LS(&stack);

    BinaryLinkedTree pointer;

    pointer = GoFarLeft(root, &stack);

    while (pointer != NULL) {
        // 访问节点
        visit(pointer->data);

        if (pointer->leftChild != NULL) {
            pointer = GoFarLeft(pointer->rightChild, &stack);
            // 令 pointer 指向右孩子为根的子树的最左下结点
        } else if (StackEmpty_LS(stack) != TRUE) {
            // 栈非空时，将元素输出
            Pop_LS(&stack, pointer->data);
        } else {
            // 栈空时遍历结束
            pointer = NULL;
        }
    }
}