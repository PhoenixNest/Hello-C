# Hello-C

## 目录

使用教材：[《数据结构》吴伟民（高等教育出版社）](https://cdn.jsdelivr.net/gh/PhoenixNest/Hello-C@master/readme/Book-PDF.zip)

```tree
├── DS-Type-Sequence    // 顺序表示结构
├── DS-Type-Link        // 链式表示结构
├── DS-Type-Array       // 串与广义表
├── DS-Type-Tree        // 树型结构
├── DS-Type-Graph       // 图型结构
├── DS-Search           // 查找算法
├── DS-Sort             // 排序算法
└── static              // 静态结构体
```

---

### DS-Type-Sequence

+ SqList - 顺序表
+ SqStack - 顺序栈
+ SqQueue - 顺序队

---

### DS-Type-Link

+ LinkList - 链表
+ CircleLinkList - 单循环链表
+ DuelLinkList - 双向链表
+ LinkStack - 链栈
+ LinkQueue - 链队

---

### DS-Tree

> 二叉树性质

+ 在非空二叉树的`第i层上最多有：2^(i-1)个结点（i>=1）`
+ `深度为k`的二叉树`最多有：(2^k)-1个结点（k>=1）`
+ 对于任意一棵二叉树，`如果度为0的结点个数为n0，度为2的结点个数为n2，则：n0 = n2 + 1`
+ 二叉树`结点总数为 n = n0 + n1 + n2`，也可表示为`n = 2n2 + n1 + 1`
+ 具有`n个结点`的完全二叉树的`深度`：`k = [log2n]（下取整）+1`

> 结点性质

对于`含n个结点`的完全二叉树中`编号为（1<= i <= n）的结点`：

1. 如果 i = 1，则`i结点`是这颗完全二叉树的`根`，没有双亲；`否则`其双亲编号为`[i/2]（下取整）`。
2. 如果 2i > n，则`i结点`没有左孩子；`否则`其左孩子的编号为`2i`。
3. 如果 2i + 1 > n，则`i结点`没有右孩子；`否则`其右孩子的编号为`2i + 1`。

---

### DS-Search

+ 二分/折半查找

---

### DS-Sort

+ 插入排序 - 直接插入、希尔
+ 交换排序 - 冒泡、快排
+ 选择排序 - 直接选择、堆
+ 归并排序
+ 基数排序

> 排序算法比较

![DS-Sort](https://cdn.jsdelivr.net/gh/PhoenixNest/Hello-C@master/readme/DS-Sort.png)