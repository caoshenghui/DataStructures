#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_

template <typename T>
class BinaryTreeNode{
    private:
        T info;
        BinaryTreeNode<T> *left;            // 指向左子树指针
        BinaryTreeNode<T> *rigth;           // 指向右子树指针
    public:
        BinaryTreeNode();                                   // 默认构造函数
        BinaryTreeNode(const T& ele);                       // 给定数据的构造函数
        BinaryTreeNode(const T& ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);       // 子树构造函数
        T value();                                          // 返回当前结点的数据
        void setLeftchild(BinaryTreeNode<T>* l);            // 设置当前结点的左子树
        void setRightchild(BinaryTreeNode<T>* r);           // 设置当前结点的右子树
        void setValue(const T& val);                        // 设置当前结点的数字域
        bool isLeaf() const;                                // 判断当前结点是否为叶结点
        BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &Node);        // 重载赋值操作符
        BinaryTreeNode<T>* leftchild() const;               // 当前结点的左孩子
        BinaryTreeNode<T>* rightchild() const;              // 当前结点的右孩子
};

#endif
