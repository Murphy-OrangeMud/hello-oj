// #define DEBUG
#include <iostream>
#ifndef DEBUG
#include "red-black-tree.hpp"
#else
#include "unit-tests.hpp"

#endif
using namespace std;

int main() {
    int data;
    red_black_tree<int> rbTree1, rbTree2;

    cin >> data;
    while (data != 0)
    {
        rbTree1.add(data);
#ifdef DEBUG
        //rbTree1.pre_order();
        //cout << endl;
        //rbTree1.mid_order();
        //cout << endl;
        // test(1, rbTree1, -1);
#endif
        cin >> data;
    }
#ifdef DEBUG
    test(1, rbTree1, 42);
#endif

    rbTree1.pre_order();

    cin >> data;
    while (data != 0)
    {
        rbTree2.add(data);
#ifdef DEBUG
        rbTree2.pre_order();
        cout << endl;
        rbTree2.mid_order();
        cout << endl;
#endif
        cin >> data;
    }

    rbTree2.pre_order();

    rbTree1.merge(rbTree2);
    rbTree1.pre_order();

#ifdef TEST
    test(1, rbTree1, 48);
#endif

    return 0;
}