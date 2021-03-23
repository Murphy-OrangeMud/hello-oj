#include <iostream>
#include "red-black-tree.hpp"
using namespace std;

template <class T>
void print(Node<T> *node) {
    cout << node->content << " ";
    #ifdef DEBUG
    cout << node->color << " ";
    #endif
}

template<class T>
void copy(Node<T> *des, Node<T> *src)
{
    if (des == NULL)
    {
        src = NULL;
        return;
    }
    src = new Node<T>(des->color, des->content, des->p, des->l, des->r);
    copy(des->l, src->l);
    copy(des->r, src->r);
}