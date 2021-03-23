#define DEBUG

#include <iostream>
#include <cassert>
using namespace std;
/*
 * definition of a red-black tree:
 * 1. the root is black
 * 2. no two consecutive red nodes
 * 3. leaf nodes (null nodes) are all black 
 * 4. for each Node, all simple paths from the Node to its 
 *    descandent leaves have the same number of black nodes
 */
enum Color
{
    red,
    black
};

template <class T1, class T2>
class Node
{
public:
    Color color;
    Node *l;
    Node *r;
    Node *p;
    T1 key;
    T2 content;
    bool isEmpty;
    Node()
    {
        color = black;
        p = NULL;
        l = NULL;
        r = NULL;
        isEmpty = true;
    }
    Node(Node *_p)
    {
        color = black;
        p = _p;
        l = NULL;
        r = NULL;
        isEmpty = true;
    }
    Node(Color _color, T1 _key, Node *_p, Node *_l = NULL, Node *_r = NULL) : color(_color), key(_key), l(_l), r(_r), p(_p)
    {
        isEmpty = true;
    }
    bool operator==(const Node other) const
    {
        return isEmpty == other.isEmpty && color == other.color && key == other.key && p == other.p && l == other.l && r == other.r;
    }
};

template <class T1, class T2>
class red_black_tree
{
#ifndef DEBUG
private:
#else
public:
#endif
    int maxdepth;
    bool first_leaf;

    static bool is_root(Node<T1, T2> *current)
    {
        return current->p == NULL;
    }

    static bool is_left_child(Node<T1, T2> *current)
    {
        return !is_root(current) && current == current->p->l;
    }

    static bool is_right_child(Node<T1, T2> *current)
    {
        return !is_root(current) && current == current->p->r;
    }

    static Color colorof(Node<T1, T2> *current)
    {
        if (current == NULL)
            return black;
        else
            return current->color;
    }

    static Node<T1, T2> *brother(Node<T1, T2> *current)
    {
        if (is_left_child(current))
            return current->p->r;
        else if (is_right_child(current))
            return current->p->l;
        return NULL;
    }

    static Node<T1, T2> *uncle(Node<T1, T2> *current)
    {
        if (is_left_child(current->p))
            return current->p->p->r;
        else if (is_right_child(current->p))
            return current->p->p->l;
        return NULL;
    }

    void clockwise_rotate(Node<T1, T2> *axis)
    {
        Node<T1, T2> *tmp = axis->l;
        axis->l->r->p = axis;
        axis->l = axis->l->r;
        tmp->r = axis;
        if (is_left_child(axis))
        {
            axis->p->l = tmp;
        }
        else if (is_right_child(axis))
        {
            axis->p->r = tmp;
        }
        if (tmp)
            tmp->p = axis->p;
        axis->p = tmp;
        while (root == axis && !is_root(axis))
        {
            root = axis->p;
            axis = axis->p;
        }
    }

    void anticlockwise_rotate(Node<T1, T2> *axis)
    {
        Node<T1, T2> *tmp = axis->r;
        axis->r->l->p = axis;
        axis->r = axis->r->l;
        tmp->l = axis;
        if (is_left_child(axis))
        {
            axis->p->l = tmp;
        }
        else if (is_right_child(axis))
        {
            axis->p->r = tmp;
        }
        if (tmp)
            tmp->p = axis->p;
        axis->p = tmp;
        while (root == axis && !is_root(axis))
        {
            root = axis->p;
            axis = axis->p;
        }
    }

    void consecutive_red_nodes(Node<T1, T2> *current)
    {
        if ((int)current->color == red && is_root(current))
        {
            current->color = black;
            return;
        }
        if ((int)current->color == black || (int)current->p->color == black)
            return;
        if (is_root(current) && current->color == red)
        {
            current->color = black;
            return;
        }
        if (uncle(current) && uncle(current)->color == red)
        {
            uncle(current)->color = black;
            current->p->color = black;
            current->p->p->color = red;
            consecutive_red_nodes(current->p->p);
        }
        else
        {
            if (is_left_child(current))
            {
                if (is_left_child(current->p))
                {
                    current->color = black;
                    clockwise_rotate(current->p->p);
                }
                else
                {
                    Node<T1, T2> *tmp = current->p;
                    //Node *tmp = current->p;
                    clockwise_rotate(current->p);
                    current = tmp;
                    current->color = black;
                    anticlockwise_rotate(current->p->p);
                }
            }
            else
            {
                if (is_left_child(current->p))
                {
                    Node<T1, T2> *tmp = current->p;
                    anticlockwise_rotate(current->p);
                    current = tmp;
                    current->color = black;
                    clockwise_rotate(current->p->p);
                }
                else
                {
                    current->color = black;
                    anticlockwise_rotate(current->p->p);
                }
            }
            consecutive_red_nodes(current->p);
        }
    }

    void double_black(Node<T1, T2> *current)
    {
        if (is_root(current))
        {
            return;
        }
        if (brother(current)->color == red)
        {
            if (is_left_child(current))
            {
                anticlockwise_rotate(current->p);
                double_black(current);
            }
            else
            {
                clockwise_rotate(current->p);
                double_black(current);
            }
        }
        else
        {
            if (colorof(brother(current)->l) == black && colorof(brother(current)->r) == black)
            {
                cout << "brother: " << brother(current)->key << " " << brother(current)->color << endl;
                brother(current)->color = red;
                if (current->p->color == red)
                {
                    current->p->color = black;
                    return;
                }
                else
                {
                    double_black(current->p);
                }
            }
            else
            {
                if (is_left_child(current))
                {
                    if (colorof(brother(current)->r) == red)
                    {
                        Node<T1, T2> *one = current->p;
                        Node<T1, T2> *two = brother(current);
                        Node<T1, T2> *four = brother(current)->r;
                        anticlockwise_rotate(current->p);
                        two->color = one->color;
                        one->color = black;
                        four->color = black;
                    }
                    else
                    {
                        Node<T1, T2> *five = brother(current)->l;
                        Node<T1, T2> *one = current->p;
                        clockwise_rotate(brother(current));
                        anticlockwise_rotate(current->p);
                        five->color = one->color;
                        one->color = black;
                    }
                }
                else
                {
                    if (colorof(brother(current)->l) == red)
                    {
                        Node<T1, T2> *one = current->p;
                        Node<T1, T2> *two = brother(current);
                        Node<T1, T2> *four = brother(current)->l;
                        clockwise_rotate(current->p);
                        two->color = one->color;
                        one->color = black;
                        four->color = black;
                    }
                    else
                    {
                        Node<T1, T2> *five = brother(current)->r;
                        Node<T1, T2> *one = current->p;
                        anticlockwise_rotate(brother(current));
                        clockwise_rotate(current->p);
                        five->color = one->color;
                        one->color = black;
                    }
                }
            }
        }
    }

    void pre_order(Node<T1, T2> *node)
    {
        cout << node->key << " ";
#ifdef DEBUG
        cout << node->color << " ";
#endif
        if (node->l)
            pre_order(node->l);
        if (node->r)
            pre_order(node->r);
    }

    void post_order(Node<T1, T2> *node)
    {
        if (node->l)
            post_order(node->l);
        if (node->r)
            post_order(node->r);
        cout << node->key << " ";
#ifdef DEBUG
        cout << node->color << " ";
#endif
    }

    void mid_order(Node<T1, T2> *node)
    {
        if (node->l)
            mid_order(node->l);
        cout << node->key << " ";
#ifdef DEBUG
        cout << node->color << " ";
#endif
        if (node->r)
            mid_order(node->r);
    }

    void post_order_add(Node<T1, T2> *node)
    {
        if (node->l)
            post_order_add(node->l);
        if (node->r)
            post_order_add(node->r);
        add(node->key);
    }

    void merge(Node<T1, T2> *other_root)
    {
        post_order_add(other_root);
    }

public:
    Node<T1, T2> *root;

    red_black_tree()
    {
        root = new Node<T1, T2>(NULL);
    }

    red_black_tree(Node<T1, T2> *_root)
    {
        root = _root;
    }

    Node<T1, T2> *search(T1 key)
    {
        Node<T1, T2> *current = root;
        while (true)
        {
            if (current->isEmpty)
            {
                return NULL;
            }
            if (key == current->key)
            {
                return current;
            }
            else if (key < current->key)
            {
                current = current->l;
            }
            else
            {
                current = current->r;
            }
        }
    }
    void del(Node<T1, T2> *iterator)
    {
        Node<T1, T2> current = iterator;
        if (current->l->isEmpty)
        {
            if (is_left_child(current))
            {
                current->p->l = current->r;
                temp = current;
                current = current->p->l;
                current->p = temp->p;
            }
            else
            {
                current->p->r = current->r;
                temp = current;
                current = current->p->r;
                current->p = temp->p;
            }
        }
        else if (current->r->isEmpty)
        {
            if (is_left_child(current))
            {
                current->p->l = current->l;
                temp = current;
                current = current->p->l;
                current->p = temp->p;
            }
            else
            {
                current->p->r = current->l;
                temp = current;
                current = current->p->r;
                current->p = temp->p;
            }
        }
        else
        {
            Node<T1, T2> *rmost = current->l;
            bool flag = false;
            while (!rmost->r->isEmpty)
            {
                flag = true;
                rmost = rmost->r;
            }
            T1 tmp = current->key;
            current->key = rmost->key;
            rmost->key = tmp;
            current = rmost;
            if (flag)
            {
                current->p->r = current->l;
                temp = current;
                current = current->p->r;
                current->p = temp->p;
            }
            else
            {
                current->p->l = current->l;
                temp = current;
                current = current->p->l;
                current->p = temp->p;
            }
        }
        if (temp->color == red)
        {
            return;
        }
        else
        {
            //current->isEmpty = true;
            //current->key = 0;
            double_black(current);
        }
    }

    void del(T1 key)
    {
        while (true)
        {
            Node<T1, T2> *current = search(key);
            Node<T1, T2> *temp;
            if (current == NULL)
            {
                cout << "No such Node in current tree!" << endl;
                return;
            }
            else
            {
                if (current->l->isEmpty)
                {
                    if (is_left_child(current))
                    {
                        current->p->l = current->r;
                        temp = current;
                        current = current->p->l;
                        current->p = temp->p;
                    }
                    else
                    {
                        current->p->r = current->r;
                        temp = current;
                        current = current->p->r;
                        current->p = temp->p;
                    }
                }
                else if (current->r->isEmpty)
                {
                    if (is_left_child(current))
                    {
                        current->p->l = current->l;
                        temp = current;
                        current = current->p->l;
                        current->p = temp->p;
                    }
                    else
                    {
                        current->p->r = current->l;
                        temp = current;
                        current = current->p->r;
                        current->p = temp->p;
                    }
                }
                else
                {
                    Node<T1, T2> *rmost = current->l;
                    bool flag = false;
                    while (!rmost->r->isEmpty)
                    {
                        flag = true;
                        rmost = rmost->r;
                    }
                    T1 tmp = current->key;
                    current->key = rmost->key;
                    rmost->key = tmp;
                    current = rmost;
                    if (flag)
                    {
                        current->p->r = current->l;
                        temp = current;
                        current = current->p->r;
                        current->p = temp->p;
                    }
                    else
                    {
                        current->p->l = current->l;
                        temp = current;
                        current = current->p->l;
                        current->p = temp->p;
                    }
                }
                if (temp->color == red)
                {
                    return;
                }
                else
                {
                    //current->isEmpty = true;
                    //current->key = 0;
                    double_black(current);
                }
            }
        }
    }

    // return the pointer to the added Node
    Node<T1, T2> *add(T1 key)
    {
        if (root->isEmpty == true)
        {
            root->key = key;
            root->isEmpty = false;
            root->l = new Node<T1, T2>(black, 0, root, NULL, NULL);
            root->r = new Node<T1, T2>(black, 0, root, NULL, NULL);
            return root;
        }
        else
        {
            Node<T1, T2> *current = root;
            while (true)
            {
                if (key <= current->key)
                {
                    if (!current->l->isEmpty)
                    {
                        current = current->l;
                    }
                    else
                    {
                        current->l->color = red;
                        current->l->key = key;
                        current->l->p = current;
                        current->l->isEmpty = false;
                        current->l->l = new Node<T1, T2>(current->l);
                        current->l->r = new Node<T1, T2>(current->l);
                        if (current->color == black)
                        {
                            return current->l;
                        }
                        else
                        {
                            Node<T1, T2> *tmp = current;
                            consecutive_red_nodes(current->l);
                            return tmp;
                        }
                    }
                }
                else
                {
                    if (!current->r->isEmpty)
                    {
                        current = current->r;
                    }
                    else
                    {
                        current->r->color = red;
                        current->r->key = key;
                        current->r->p = current;
                        current->r->isEmpty = false;
                        current->r->l = new Node<T1, T2>(current->r);
                        current->r->r = new Node<T1, T2>(current->r);
                        if (current->color == black)
                        {
                            return current->r;
                        }
                        else
                        {
                            Node<T1, T2> *tmp = current;
                            consecutive_red_nodes(current->r);
                            return tmp;
                        }
                    }
                }
            }
        }
    }

    void pre_order()
    {
        pre_order(root);
    }

    void post_order()
    {
        post_order(root);
    }

    void mid_order()
    {
        mid_order(root);
    }

    void merge(red_black_tree other)
    {
        merge(other.root);
    }
};