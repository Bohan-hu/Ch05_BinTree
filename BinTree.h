//
// Created by 胡博涵 on 2018/2/2.
//

#ifndef CH05_BINTREE_BINTREE_H
#define CH05_BINTREE_BINTREE_H

#include "BinNode.h"

template<typename T>
class BinTree {
protected:
    int _size;//规模
    BinNodePosi(T) _root;//根节点
    virtual int updateHeight(BinNodePosi(T) x);//更新某节点的高度，传入参数为节点指针
    void updateHeightAbove(BinNodePosi(T) x);//更新某节点及其祖先节点的高度
public:
    BinTree():_size(0),_root(nullptr){}//构造函数
    ~BinTree(){if(_size>0) remove(_root);}//析构函数
    int size() const { return _size;}
    bool empty() const { return !_root;}//若是空树，直接返回根节点是否是空指针（空树根节点默认初始化为空的指针）
    BinNodePosi(T) root() const { return _root;}
    BinNodePosi(T) insertAsRoot( T const &e );
    BinNodePosi(T) insertAsLC( BinNodePosi(T) x, T const &e);//作为左子插入
    BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const &e);//作为右子插入
    BinNodePosi(T) attachAsLC( BinNodePosi(T) x, BinTree<T> *BT);//作为左子树连接
    BinNodePosi(T) attachAsRC( BinNodePosi(T) x, BinTree<T> *BT);//作为右子树连接
    int remove(BinNodePosi(T) x);//删除以节点x为根的子树，返回该子树原先的规模
    BinTree<T>* secede( BinNodePosi(T) x);//把以x为节点的子树从其中摘除，并返回原有子树的根节点
   /* 施工中。。。。。。。。
    template <typename VST>
             void travLevel(VST& visit){if(_root) _root->travLevel(visit);}//层次遍历
    template <typename VST>
             void travPre(VST& visit){if(_root) _root->travPre()}
    */



};


#endif //CH05_BINTREE_BINTREE_H
