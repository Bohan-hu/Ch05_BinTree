//
// Created by 胡博涵 on 2018/2/2.
//

#ifndef CH05_BINTREE_BINTREE_H
#define CH05_BINTREE_BINTREE_H

#include "BinNode.h"
#include "Stack.h"

template<typename T>
class BinTree {
protected:
    int _size;//规模
    BinNodePosi(T)_root;//根节点
    virtual int updateHeight(BinNodePosi(T)x) {
        x->height = 1 + max(stature(x->lChild), stature(x->rChild));//为什么要用stature宏？因为防止空树高度为-1的情况出现
        return x->height;
    }//更新某节点的高度，传入参数为节点指针
    void updateHeightAbove(BinNodePosi(T)x) {
        while (x) {
            updateHeight(x);
            x = x->parent;
        }
    }//更新某节点及其祖先节点的高度
public:
    BinTree() : _size(0), _root(nullptr) {}//构造函数
    ~BinTree() { if (_size > 0) remove(_root); }//析构函数
    int size() const { return _size; }

    bool empty() const { return !_root; }//若是空树，直接返回根节点是否是空指针（空树根节点默认初始化为空的指针）
    BinNodePosi(T)root() const { return _root; }

    BinNodePosi(T)insertAsRoot(T const &e) {
        _root = new BinNode<T>(e);//调用构造函数，申请一个新的空间给节点类，并让root指向这个节点
        _size = 1;//更新规模
        return _root;
    };

    BinNodePosi(T)insertAsLC(BinNodePosi(T)x, T const &e) {
        _size++;//更新规模
        x->insertAsLC(e);
        updateHeightAbove(x);
        return x->lChild;
    };//作为左子插入
    BinNodePosi(T)insertAsRC(BinNodePosi(T)x, T const &e) {
        _size++;//更新规模
        x->insertAsRC(e);
        updateHeightAbove(x);
        return x->rChild;
    }//作为右子插入
    BinNodePosi(T)attachAsLC(BinNodePosi(T)x, BinTree<T> *&BT) {
        //x->lChild=BT;（类型检查为什么能过？）
        x->lChild = BT->_root;//在C++的类的成员函数中，允许直接访问该类的对象的私有成员变量
        if (BT->_root != nullptr) //不是空树
            BT->_root->parent = x;//接入父节点
        _size += BT->_size;//更新规模
        updateHeightAbove(x);//更新高度
        //原树需要释放吗？
        return x;//返回接入位置

    };//作为左子树连接
    BinNodePosi(T)attachAsRC(BinNodePosi(T)x, BinTree<T> *BT) {
        x->rChild = BT->_root;//在C++的类的成员函数中，允许直接访问该类的对象的私有成员变量
        if (BT->_root != nullptr) //不是空树
            BT->_root->parent = x;//接入父节点
        _size += BT->_size;//更新规模
        updateHeightAbove(x);//更新高度
        //原树需要释放吗？
        return x;//返回接入位置
    }//作为右子树连接

    int remove(BinNodePosi(T)x) {//删除以节点x为根的子树，返回该子树原先的规模
        (x->parent->lChild == x ? x->parent->lChild : x->parent->rChild) = nullptr;    //切断向下的联系
        updateHeightAbove(x->parent);//更新祖先的高度
        int n = x->size();
        return n;//返回x的规模
    }
    //-----------------注意：以上三个函数可能存在内存泄漏的问题，需要另外编写函数解决，此处就暂时不写了-----------------


    BinTree<T> *secede(BinNodePosi(T)x);//把以x为节点的子树从其中摘除，并返回原有子树的根节点


    void travLevel();//层次遍历

    void travPre_Recursive(BinNodePosi(T)x) { //先序遍历（先遍历根，再遍历左，再遍历右）第1版代码（递归）
        if (!x) return;//基线条件（要求访问的节点为空）
        std::cout << x->data << " ";// << std::endl;
        travPre_Recursive(x->lChild);
        travPre_Recursive(x->rChild);
    }

    void travPre_Stack1(BinNodePosi(T)x) {  //先序遍历（迭代版1）
        Stack<BinNodePosi(T)> S; //引入记录节点位置的辅助栈
        if (x) { // 如果该节点不是空节点
            S.push(x); //把该节点压入栈中（事实上只能是根节点）
        }
        while (!S.empty()) { //如果栈不是空的
            x = S.pop(); //弹出栈顶的节点，并访问
            std::cout << x->data << " ";//<< std::endl;
            if (x->rChild != nullptr) S.push(x->rChild);
            if (x->lChild != nullptr) S.push(x->lChild);
        }
    }

    static void visitAlongLeftBranch(BinNodePosi(T)x, Stack<BinNodePosi(T)> &S) {
        while (x) {
            std::cout << x->data << " ";
            S.push(x->rChild);
            x = x->lChild;
        }
    }

    void travPre_Stack2(BinNodePosi(T)x) {  //先序遍历（迭代版1）
        Stack<BinNodePosi(T)> S; //引入记录节点位置的辅助栈
        while (!S.empty()) { //如果栈不是空的
            x = S.pop(); //弹出栈顶的节点，并访问
            std::cout << x->data << " ";//<< std::endl;
            if (x->rChild != nullptr) S.push(x->rChild);
            if (x->lChild != nullptr) S.push(x->lChild);
        }
    }

};


#endif //CH05_BINTREE_BINTREE_H
