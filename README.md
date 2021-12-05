# Hello-C

## 目录

使用教材：[《数据结构》吴伟民（高等教育出版社）](https://cdn.jsdelivr.net/gh/PhoenixNest/Hello-C@master/readme/Book-PDF.zip)

```tree
├── DS-Type-Sequence    // 顺序存储结构
├── DS-Type-Link        // 链式存储结构
├── DS-Type-Array       // 串与广义表
├── DS-Type-Tree        // 树型结构
├── DS-Type-Graph       // 图型结构
├── DS-Search           // 查找算法
├── DS-Sort             // 排序算法
└── static              // 静态结构体
```

---

### DS-Type-Sequence

+ SqList - 线性表（顺序存储）
+ SqStack - 栈（顺序存储）
+ SqQueue - 队列（顺序存储）

---

### DS-Type-Link

+ LinkList - 线性表（链式存储）
+ CircleLinkList - 单循环链表
+ DuelLinkList - 双向链表
+ LinkStack - 栈（链式存储）
+ LinkQueue - 队列（链式存储）

---

### DS-Type-Array

+ GeneralizeList - 广义表

---

### DS-Tree

+ BinarySequenceTree - 二叉树（顺序表示法）
+ BinaryLinkedTree - 二叉树（二叉链表存储法）
+ TernaryLinkedTree - 三叉树（三叉链表表示法）
+ BinarySortTree - 二叉排序树 / 二叉查找树
+ UnionFindSets - 并查集
+ Heap - 堆

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

> 二叉树遍历

+ 前序遍历（NLR）：等同树的前序遍历
+ 中序遍历（LRN）：等同树的后续遍历
+ 后序遍历（LRN）

> 树的存储

+ `双亲`表示法
+ `双亲孩子`表示法
+ `孩子兄弟`表示法

---

> 并查集

+ 加权合并规则法
+ 路径压缩法

![UnionFindSets_Function_Upgrade](https://cdn.jsdelivr.net/gh/PhoenixNest/Hello-C@master/readme/UnionFindSets_Function_Upgrade.png)

![UnionFindSets_Function_Upgrade_Brief](https://cdn.jsdelivr.net/gh/PhoenixNest/Hello-C@master/readme/UnionFindSets_Function_Upgrade_Brief.png)

---

### DS-Graph

+ MatrixGraph - 图（数组 / 邻接矩阵表示法）
+ AdjacencyListGraph - 图（邻接表表示法）

> 图的性质

+ `无向完全图`包含 `n *（n-1）/2` 条边
+ `有向完全图`包含 `n *（n-1）` 条边
+ 度数（出度 + 入度） = 边数 * 2

> 连通图和强连通图

在`无向图`中

+ 若图中任意两点都连同，则称该图为`连通图`
+ 连通分量是指无向图中的极大连通子图
+ n 个顶点的连通图用邻接矩阵表示时，该矩阵至少有 2（n-1）个非零元素

在`有向图`中

+ 若两点双向可达（v，w间均有路径可达），则称该图`为强连通图`
+ 强连通分量是指有向图中的极大强连通子图

> 图的遍历

+ 深度优先（DFS），类似树的前序遍历
+ 广度优先（BFS），类似树的层次遍历

> 生成树

连通图的生成树是`含有所有顶点且只有 n-1 条边`的连通子图

> 最小生成树

+ Prim算法（加点），适合`稠密图`
+ Kruskal算法（加边），适合`稀疏图`

> 最短路径

+ Dijkstra算法
+ Floyd算法

---

### DS-Search

+ 顺序查找
+ 二分/折半查找

> 性质

+ `折半查找在查找不成功`时，和给定值进行比较的关键字个数最多为 [log2n]（向下取整） + 1

---

### DS-Sort

+ 插入排序 - 直接插入、希尔
+ 交换排序 - 冒泡、快排
+ 选择排序 - 直接选择、堆
+ 归并排序
+ 基数排序

> 排序算法比较

![DS-Sort](https://cdn.jsdelivr.net/gh/PhoenixNest/Hello-C@master/readme/DS-Sort.png)