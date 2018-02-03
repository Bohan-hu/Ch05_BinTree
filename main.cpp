#include <iostream>
#include "BinTree.h"

int main() {
    std::cout << "Building a Tree......" << std::endl;
    BinTree<char> tree;
    //书中例题的树
    BinNodePosi(char)i = tree.insertAsRoot('i');
    BinNodePosi(char)d = tree.insertAsLC(i, 'd');
    BinNodePosi(char)l = tree.insertAsRC(i, 'l');
    BinNodePosi(char)c = tree.insertAsLC(d, 'c');
    BinNodePosi(char)h = tree.insertAsRC(d, 'h');
    BinNodePosi(char)a = tree.insertAsLC(c, 'a');
    BinNodePosi(char)b = tree.insertAsRC(a, 'b');
    BinNodePosi(char)f = tree.insertAsLC(h, 'f');
    BinNodePosi(char)e = tree.insertAsLC(f, 'e');
    BinNodePosi(char)g = tree.insertAsRC(f, 'g');
    BinNodePosi(char)k = tree.insertAsLC(l, 'k');
    BinNodePosi(char)j = tree.insertAsLC(k, 'j');
    BinNodePosi(char)n = tree.insertAsRC(l, 'n');
    BinNodePosi(char)m = tree.insertAsLC(n, 'm');
    BinNodePosi(char)p = tree.insertAsRC(n, 'p');
    BinNodePosi(char)o = tree.insertAsLC(p, 'o');

    tree.travPre_Recursive(i);



    return 0;
}