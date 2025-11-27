#ifndef BINTREE_H
#define BINTREE_H

#include "stack.h"
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
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&S);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&S);
    int remove(BinNodePosi(T) x);
    BinTree<T> *secede(BinNodePosi(T) x);
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

int max(int x, int y)
{
    return x > y ? x : y;
}
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
template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{                                 
    FromParentTo(*x) = NULL;      
    updateHeightAbove(x->parent); 
    int n = removeAt(x);
    _size -= n;
    return n;
}

template <typename T>
void release(T &e)
{
    e = NULL;
}


template <typename T>
void release(BinNodePosi(T) & e)
{
    delete e;
}

template <typename T>
static int removeAt(BinNodePosi(T) x)
{ 
    if (!x)
        return 0;                                 
    int n = 1 + removeAt(x->lc) + removeAt(x->rc); 
    release(x->data);
    release(x);
    return n; 
}

template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        visit(x->data);
        S.push(x->rc);
        x = x->lc;
    }
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

template <typename T, typename VST>
void travPre_I1(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S; 
    if (x)
        S.push(x);
    while (!S.empty())
    { 
        x = S.pop();
        visits(x->data); 
        if (HasRChild(*x))
            S.push(x->rc);
        if (HasLChild(*x))
            S.push(x->lc);
    }
}
template < typename T, typename VST> 
void travPre_I2(BinNodePosi(T) x, VST & visit)
{ 
	Stack<BinNodePosi(T)> S;
    while (true) 
    {
	    visitAlongLeftBranch(x, visit, S);
	    if (S.empty()) break;
	    x = S.pop();
    }
 
}
template <typename T>
template <typename VST>
void BinNode<T>::travPre(VST &visit)
{
    switch (rand() % 3)
    { 
    case 1:
        travPre_I1(this, visit);
        break; 
    case 2:
        travPre_I2(this, visit);
        break;
    default:
        travPre_R(this, visit);
        break;
    }
}

template <typename T>
static void gotoHLVFL(Stack<BinNodePosi(T)> &S)
{
    
    while (BinNodePosi(T) x = S.top()) 
        if (HasLChild(*x))
        { 
            if (HasRChild(*x))
                S.push(x->rc); 
            S.push(x->lc);    
        }
        else               
            S.push(x->rc); 
    S.pop();               
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
template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S; 
    if (x)
        S.push(x);
    while (!S.empty())
    {                   
        if (S.top() != x->parent) 
            gotoHLVFL(S);  
        x = S.pop();
        visits(x->data);
    }
}

template <typename T>
BinTree<T> *BinTree<T>::secede(BinNodePosi(T) x)
{                                 
    FromParentTo(*x) = NULL;      
    updateHeightAbove(x->parent); 
    BinTree<T> *S = new BinTree<T>;
    S->_root = x;
    x->parent = NULL; 
    S->_size = x->size();
    _size -= S->_size;
    return S;
}

template <typename T>
void visits(T e)
{
    std::cout << e << " ";
}
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T> *&S)
{ 
    if ((x->lc = S->_root))
        x->lc->parent = x;
    _size += S->_size;
    updateHeightAbove(x); 
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x;
}
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T> *&S)
{ 
    if ((x->rc = S->_root))
        x->rc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x;
}


template <typename T>
static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        S.push(x);
        x = x->lc;
    }
}
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST &visit)
{
    if (!x)
        return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}
template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        goAlongLeftBranch(x, S);
        if (S.empty())
            break; 
        x = S.pop();
        visits(x->data);
        x = x->rc;       
    }
}
template <typename T, typename VST>
void travIn_I2(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S; 
    while (true)
        if (x)
        {
            S.push(x); 
            x = x->lc; 
        }
        else if (!S.empty())
        {
            x = S.pop();    
            visits(x->data); 
            x = x->rc;       
        }
        else
            break; 
}
template <typename T, typename VST>
void travIn_I3(BinNodePosi(T) x, VST &visit)
{
    bool backtrack = false; 
    while (true)
        if (!backtrack && HasLChild(*x)) 
            x = x->lc;                  
        else
        {                    
            visits(x->data); 
            if (HasRChild(*x))
            {                      
                x = x->rc;         
                backtrack = false; 
            }
            else
            { 
                if (!(x = x->succ()))
                    break;        
                backtrack = true; 
            }
        }
}

template <typename T, typename VST>
void travIn_I4(BinNodePosi(T) x, VST &visit)
{
    while (true)
        if (HasLChild(*x)) 
            x = x->lc;    
        else
        {                        
            visits(x->data);      
            while (!HasRChild(*x)) 
                if (!(x = x->succ()))
                    return; 
                else
                    visits(x->data);
            x = x->rc;              
        }
}

template <typename T>
template <typename VST>
void BinNode<T>::travIn(VST &visit)
{
    switch (rand() & 5)
    {
    case 1:
        travIn_I1(this, visit);
        break;
    case 2:
        travIn_I2(this, visit);
        break;
    case 3:
        travIn_I3(this, visit);
        break;
    case 4:
        travIn_I4(this, visit);
        break;
    default:
        travIn_R(this, visit);
        break;
    }
};

#endif