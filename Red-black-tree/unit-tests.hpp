#include <iostream>
#include "red-black-tree.hpp"
using namespace std;

bool first_leaf = false;
int maxdepth = 0;

template <class T>
bool equal(Node<T> *des, Node<T> *src)
{
    if (des == NULL && src == NULL)
        return true;
    else if ((des == NULL && src != NULL) || (des != NULL && src == NULL) || !(*des == *src))
        return false;
    return equal(des->l, src->l) && equal(des->r, src->r);
}

template <class T>
void test_brother_uncle(Node<T> *current)
{
    assert(red_black_tree<T>::uncle(current) == red_black_tree<T>::brother(current->p));
}

//to be revised here
/*
template <class T>
void test_rotate(Node<T> *current)
{
    Node<T> *tmp;
    red_black_tree<T>::copy(tmp, current);
    red_black_tree<T>::clockwise_rotate(current);
    red_black_tree<T>::anticlockwise_rotate(current);
    assert(equal(tmp, current));
    red_black_tree<T>::anticlockwise_rotate(current);
    red_black_tree<T>::clockwise_rotate(current);
    assert(equal(tmp, current));
}
*/

template <class T>
void dfs_depth(Node<T> *current, int depth)
{
    if (current == NULL)
    {
        if (first_leaf)
        {
            first_leaf = false;
            maxdepth = depth;
        }
        else
        {
            assert(depth == maxdepth);
        }
        return;
    }
    else
    {
#ifdef DEBUG
        cout << current->key << " " << current->color << endl;
#endif
        if (red_black_tree<T>::colorof(current->l) == black)
            dfs_depth(current->l, depth + 1);
        else
            dfs_depth(current->l, depth);
        if (red_black_tree<T>::colorof(current->r) == black)
            dfs_depth(current->r, depth + 1);
        else
            dfs_depth(current->r, depth);
    }
}

template <class T>
bool check_consecutive_red_nodes(Node<T> *current)
{
    if (current == NULL)
        return true;
    if (red_black_tree<T>::colorof(current) == red && (red_black_tree<T>::colorof(current->l) == red || red_black_tree<T>::colorof(current->r) == red))
    {
        cout << current->key << " " << current->color << endl;
        return false;
    }
    else
        return check_consecutive_red_nodes(current->l) && check_consecutive_red_nodes(current->r);
}

template <class T>
void test_red_black_tree_1(Node<T> *root)
{
    assert(red_black_tree<T>::colorof(root) == black);
}

template <class T>
void test_red_black_tree_2(Node<T> *root)
{
    assert(check_consecutive_red_nodes(root));
}

template <class T>
void test_red_black_tree_4(Node<T> *root)
{
    first_leaf = true;
    dfs_depth(root, 1);
}

template <class T>
void test_search_inexist(red_black_tree<T> tree, T newkey)
{
    assert(tree.search(newkey) == NULL);
}

template <class T>
void test_search_exist(red_black_tree<T> tree, T oldkey)
{
    assert(tree.search(oldkey) != NULL);
}

template <class T>
void test_add_del(red_black_tree<T> tree, T newkey, T oldkey)
{
    assert(tree.add(oldkey) == NULL);
    tree.add(newkey);
    test_red_black_tree_1(tree.root);
    test_red_black_tree_2(tree.root);
    test_red_black_tree_4(tree.root);
    test_search_exist(tree, newkey);
    tree.del(&newkey);
    maxdepth = 0;
    first_leaf = true;
    test_red_black_tree_1(tree.root);
    test_red_black_tree_2(tree.root);
    test_red_black_tree_4(tree.root);
    test_search_inexist(tree, newkey);
}

template<class T>
void test(int kase, red_black_tree<T> tree, T newkey)
{
    //cout << "testing util functions..." << endl;
    //test_brother_uncle(tree.root);
    //test_brother_uncle(tree.root->l);
    //test_brother_uncle(tree.root->r);
    //cout << "brother and uncle function passed for test case " << kase << "!\n";
    //test_rotate(tree.root);
    //test_rotate(tree.root->l);
    //test_rotate(tree.root->r);
    //cout << "rotate function passed for test case " << kase << "!\n";
    cout << "testing the tree..." << endl;
    test_red_black_tree_1(tree.root);
    test_red_black_tree_2(tree.root);
    test_red_black_tree_4(tree.root);
    cout << "the initial tree satisfies the definition!\n";
    if (!tree.root->l->r->isEmpty)
        test_search_exist(tree,tree.root->l->r->key);
    if (!tree.root->r->l->isEmpty)
        test_search_exist(tree, tree.root->r->l->key);
    test_search_exist(tree, tree.root->key);
    test_search_inexist(tree,newkey);
    cout << "search function passed for test case " << kase << "!\n";
    test_add_del(tree, newkey, tree.root->l->r->key);
    cout << "add and delete function passed for test case " << kase << "!\n";
}