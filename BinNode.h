//
// Created by 胡博涵 on 2018/1/30.
//

#ifndef CH05_BINTREE_BINNODE_H
#define CH05_BINTREE_BINNODE_H

template<typename T>
class BinNode {
    BinNode<T> *parent, *lChild, *rChild;
    T data;
    int height;//高度
    int size(){
        int s=1;
        if(lChild) s+=lChild->size();//递归地求解，直到达到叶端
        if(rChild) s+=rChild->size();//递归地求解，直到达到叶端
        return s;
    }//子树的规模
    //作为左右子节点插入
    BinNode<T> *insertAsLC(T const &e) {
        //对传入的参数e进行"封装"，使之成为一个新的节点
        lChild = new BinNode(e, this);
        return lChild;
    };

    BinNode<T> *insertAsRC(T const &e) {
        rChild = new BinNode(e, this);
        return rChild;
    }


    BinNode<T> *succ();//获得当前节点的直接后继
    template<typename VST>
    void travLevel(VST &t);//子树层级遍历
    template<typename VST>
    void travPre(VST &t);//子树先序遍历
    template<typename VST>
    void travIn(VST &t);//子树中序遍历
    template<typename VST>
    void travPost(VST &t);//子树后序遍历
};

#endif //CH05_BINTREE_BINNODE_H
