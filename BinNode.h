//
// Created by 胡博涵 on 2018/1/30.
//

#ifndef CH05_BINTREE_BINNODE_H
#define CH05_BINTREE_BINNODE_H
#define BinNodePosi(T) BinNode<T>*   //指向binnode节点的类型——节点位置"指针"类型
//BinNode状态及其性质的判断
#define IsRoot(x) ( !(x).parent )
#define IsLChild(x) ( !IsRoot(x) && ( &(x) == (x).parent -> lChild))
#define IsRChild(x) ( !IsRoot(x) && ( &(x) == (x).parent -> rChild))
#define HasParent(x) ( !IsRoot(x) )
#define HasLChild(x) ( (x).lChild )
#define HasRChild(x) ( (x).rChild )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( !HasChild(x) )


#define stature(p) ((p)?(p)->height:-1)     // 节点高度（空树高度为-1）
typedef enum {
    RB_RED, RB_BLACK
} RBColor; // 节点颜色
int max(int a, int b) { return (a > b ? a : b); }

template<typename T>
struct BinNode {
    //成员声明
    BinNodePosi(T)parent;
    BinNodePosi(T)lChild;
    BinNodePosi(T)rChild;
    T data;
    int height;//高度
    int npl;//NULL Path length（左式堆）
    RBColor color;//颜色（红黑树）




    //--------构造函数---------
    BinNode() : parent(nullptr), lChild(nullptr), rChild(nullptr), height(0), npl(1), color(RB_RED) {};//无参数的空节点
    BinNode(T e, BinNodePosi(T)p = nullptr, BinNodePosi(T)lChild = nullptr, BinNodePosi(T)rChild = NULL, int h = 0,
            int l = 1, RBColor c = RB_RED) :
            data(e), parent(p), lChild(lChild), rChild(rChild), height(h), npl(l), color(c) {}
    //------------------------




    //--------操作接口---------
    int size() {
        int s = 1;
        if (lChild) s += lChild->size();//递归地求解，直到达到叶端
        if (rChild) s += rChild->size();//递归地求解，直到达到叶端
        return s;
    }//子树的规模

    //作为左右子节点插入,对传入的参数e进行"封装"，使之成为当前节点的一个新的子节点
    BinNode<T> *insertAsLC(T const &e) {
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

    //运算符重载
    bool operator<(BinNode const &bn) { return data < bn.data; }

    bool operator==(BinNode const &bn) { return data == bn.data; }

    bool operator!=(BinNode const &bn) { return data != bn.data; }

    bool operator>(BinNode const &bn) { return data > bn.data; }

    bool operator>=(BinNode const &bn) { return data >= bn.data; }

    bool operator<=(BinNode const &bn) { return data <= bn.data; }
};

#endif //CH05_BINTREE_BINNODE_H
