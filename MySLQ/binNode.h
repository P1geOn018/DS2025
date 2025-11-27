#ifndef BINNODE_H
#define BINNODE_H

#include "stack.h"
#include "queue.h"
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)
typedef enum
{
    RB_RED,
    RB_BLACK
} RBColor;

template <typename T>
struct BinNode
{
    T data;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
    int height;
    int npl;
    RBColor color;

    BinNode() : parent(NULL), lc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
    int size();
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();
    template <typename VST>
    void travLevel(VST &);
    template <typename VST>
    void travPre(VST &);
    template <typename VST>
    void travIn(VST &);
    template <typename VST>
    void travPost(VST &);
    bool operator<(BinNode const &bn) { return data < bn.data; }
    bool operator==(BinNode const &bn) { return data == bn.data; }
};

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
#define sibling(p) (IsChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)
#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x).parent->lc)
#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
    return lc = new BinNode(e, this);
}
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
    return rc = new BinNode(e, this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::succ()
{
    BinNodePosi(T) s = this; 
    if (rc)
    {           
        s = rc; 
        while (HasLChild(*s))
            s = s->lc; 
    }
    else
    { 
        while (IsRChild(*s))
            s = s->parent;
        s = s->parent;     
    }
    return s;
}
template <typename T>
template <typename VST>
void BinNode<T>::travLevel(VST &visit)
{                           
    Queue<BinNodePosi(T)> Q; 
    Q.enqueue(this);      
    std::cout << "调用了层次遍历";
    while (!Q.empty())
    { 
        BinNodePosi(T) x = Q.dequeue();
        // visit(x->data);
        std::cout << x->data << " "; 
        if (HasLChild(*x))
            Q.enqueue(x->lc); 
        if (HasRChild(*x))
            Q.enqueue(x->rc);
    }
    std::cout << std::endl;
}
#endif