#include "BTree.hpp"
#include <assert.h>
using namespace std;

int main() {
    BTree<int, int, 3> testTree;
    testTree.Insert(1,1);
    testTree.Insert(2,3);
    testTree.Insert(3,4);
    testTree.Insert(4,5);
    testTree.PrintTree();
    //assert(testTree.Search(3) == 4);
    //testTree.Delete(4);
    //assert(testTree.Search(4) == NULL);
    //testTree.Insert(4,8);
    //assert(testTree.Search(4) == 8);
    return 0;
}