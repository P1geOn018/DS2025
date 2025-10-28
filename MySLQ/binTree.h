#include "binNode.h"
template <typename T>
class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;
    void updateHeightAbove(BinNodePosi(T) x);
    virtual int updateHeight(BinNodePosi(T) x);

public : BinTree() : _size(0), _root(NULL){};
    ~BinTree(){if(0 < _size)
            remove(_root);
    };
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return _root; }
    BinNodePosi(T) insertAsRoot(T const &e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&T);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&T);
    int remove(BinNodePosi(T) x);
    template <typename VST>
    void travLevel(VST & visit) {if (_root)
            _root->travLevel(visit);
    }
    template <typename VST>
    void travPre(VST & visit){if(_root)
            _root->travPre(visit);
    
    }
    template <typename VST>
    void travIn(VST& visit){if(_root)
            _root->travIn(visit);
    }
    template <typename VST>
    void travPost(VST &visit)
    {
        if (_root)
            _root->travPost(visit);
    }
    bool operator<(BinTree<T> const& t)
    {
        return _root && t._root && lt(_root, t._root);
    }
    bool operator==(BinTree<T> const& t)
    {
        return _root && t._root && (_root == t._root);
    }
};
template <typename T> 
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x ,T const& e)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template <typename T,typename VST>
void travPre_R(BinNodePosi(T) x,VST& visit)
{
    if(!x)
        return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}

template<typename T,typename VST>
void travPost_R(BinNodePosi(T) x,VST& visit)
{
    if(!x)
        return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}

template <typename T,typename VST>
void travIn_R(BinNodePosi(T) x,VST& visit)
{
    if(!x)
        return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}