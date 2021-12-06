//
// Created by P7XXTM1-G on 2021/11/22.
//

#include "BinaryLinkedTree.h"

// 二叉链表（二叉树链式存储结构）

// 创建二叉树
BinaryLinkedTree MakeBinaryTree(TreeElemType rootData, BinaryLinkedTree leftTree, BinaryLinkedTree rightTree) {
    // 创建一棵二叉树 newTree，其中根节点的值为 rootData，leftTree 和 rightTree 分别作为左子树和右子树
    BinaryLinkedTree newTree;

    newTree = (BinaryLinkedTree) malloc(sizeof(BinaryLinkedTreeNode));

    if (newTree == NULL) {
        return NULL;
    }

    // 赋值根节点
    newTree->data = rootData;

    // 赋值左子树
    newTree->leftChild = leftTree;

    // 赋值右子树
    newTree->rightChild = rightTree;

    return newTree;
}

// 先序构造二叉树
BinaryLinkedTree CreateBinaryLinkedTree(char *defBT, int *i) {
    // 基于先序遍历构造二叉树
    // defBT：树形描述序列
    // i：当前位标，初值为0

    BinaryLinkedTree newTree;

    TreeElemType elem;

    elem = defBT[*i++];

    if ('#' == elem) {
        // 初始化空树
        InitBinaryLinkedTree(&newTree);
    } else {
        // 构造根结点
        newTree = MakeBinaryTree(elem, NULL, NULL);

        // 构造左子树
        newTree->leftChild = CreateBinaryLinkedTree(defBT, i);

        // 构造右子树
        newTree->rightChild = CreateBinaryLinkedTree(defBT, i);
    }

    return newTree;
}

// 销毁二叉树
void DestroyBinaryLinkedTree(BinaryLinkedTree *root) {
    // 二叉树非空
    if (root != NULL) {
        // 递归销毁左子树
        DestroyBinaryLinkedTree(&(*root)->leftChild);
        // 递归销毁右子树
        DestroyBinaryLinkedTree(&(*root)->rightChild);

        // 释放根结点
        free(root);
    }
}

// 判空
Status BinaryLinkedTreeEmpty(BinaryLinkedTree root) {
    return root == NULL ? TRUE : FALSE;
}

// 二叉树深度
int BinaryLinkedTreeDepth(BinaryLinkedTree root) {
    int depthLeft, depthRight;
    if (root == NULL) {
        // 空二叉树深度为0
        return 0;
    } else {
        // 求左子树深度
        depthLeft = BinaryLinkedTreeDepth(root->leftChild);

        // 求右子树深度
        depthRight = BinaryLinkedTreeDepth(root->rightChild);

        // 左子树、右子树深度的较大值 + 1
        return (depthLeft > depthRight ? depthLeft : depthRight) + 1;
    }
}

// 统计叶子结点个数
void CountLeaf(BinaryLinkedTree root, int *count) {
    if (root != NULL) {
        if (root->leftChild != NULL && root->rightChild != NULL) {
            // 叶子总数计数
            count++;
        }

        // 计算左子树
        CountLeaf(root->leftChild, count);

        // 计算右子树
        CountLeaf(root->rightChild, count);
    }
}

// 替换左子树
Status ReplaceLeft(BinaryLinkedTree *root, BinaryLinkedTree *leftTree) {
    // 替换左子树，若 root 非空，则用 leftTree 替换 root 的左子树，并用 leftTree 返回 root 的先前左子树
    BinaryLinkedTree temp;

    if (root == NULL) {
        // 传入空树
        return ERROR;
    }

    temp = (*root)->leftChild;

    // 将新的 leftTree 作为 root 的新左子树
    (*root)->leftChild = *leftTree;

    // 返回 root 的旧左子树
    *leftTree = temp;

    return OK;
}

// 替换右子树
// 步骤等同于 替换左子树，变动为：将左子树地址 修改为 右子树地址
Status ReplaceRight(BinaryLinkedTree *root, BinaryLinkedTree *rightTree) {
    BinaryLinkedTree temp;

    if (root == NULL) {
        return ERROR;
    }

    temp = (*root)->rightChild;

    (*root)->rightChild = *rightTree;

    *rightTree = temp;

    return OK;
}

// 剪除左子树
Status CutLeft(BinaryLinkedTree *root) {

    if (root == NULL) {
        return ERROR;
    }

    // 将空值赋予 root 的左子树地址，即可剪除 root 的所有左子树
    (*root)->leftChild = NULL;

    return OK;
}

// 剪除右子树
Status CutRight(BinaryLinkedTree *root) {
    if (root == NULL) {
        return ERROR;
    }

    (*root)->rightChild = NULL;

    return OK;
}

// -------------------------------------------------------------------------------//

// 递归遍历
// 先序遍历
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

// -------------------------------------------------------------------------------//

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

// -------------------------------------------------------------------------------//

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

// -------------------------------------------------------------------------------//

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
// 算法思想：
// 1.每遇到一个结点就把它入栈，然后遍历左子树
// 2.遍历完左子树后，从栈顶弹出这个结点并访问该结点，然后按照他的right域遍历该结点的右子树
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

// -------------------------------------------------------------------------------//

// 非递归层次遍历（广度优先遍历 / 宽度优先遍历）
// 算法思想：
// 1.初始化一个队列，把根结点（如果有）入队。
// 2.若队列非空，则循环执行 步骤3～5，否则遍历结束。
// 3.出队一个结点，并访问数据域。
// 4.若该结点的左子树非空，则将左子树入队。
// 5.若该结点的右子树非空，则将右子树入队。
void LevelOrderTraverse(BinaryLinkedTree root, Status(*visit)(TreeElemType elemType)) {
    if (root != NULL) {
        LinkQueue queue;

        InitQueue_LQ(&queue);

        BinaryLinkedTree pointer = root;

        // 访问根结点，并将根结点入队，
        visit(pointer->data);
        EnQueue_LQ(&queue, pointer);

        // 当队列非空时重复执行操作，队头结点出队
        while (DeQueue_LQ(&queue, pointer)) {
            // 访问左子树并入队
            if (pointer->leftChild != NULL) {
                visit(pointer->leftChild->data);
                EnQueue_LQ(&queue, pointer->leftChild);
            }

            // 访问右子树并入队
            if (pointer->rightChild != NULL) {
                visit(pointer->rightChild->data);
                EnQueue_LQ(&queue, pointer->rightChild);
            }
        }
    }
}