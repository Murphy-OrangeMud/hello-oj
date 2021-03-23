#include <iostream>

template <class T1, class T2>
struct pair {
    T1 first;
    T2 second;
    pair(T1 _f, T2 _s)
        : first(_f)
        , second(_s)
    {
    }
};

template <class Key, class Value, int MAX>
class BNode {
public:
    int currentKey;
    BNode<Key, Value, MAX>* parent;
    pair<Key, Value> keys[MAX - 1];
    BNode<Key, Value, MAX>* sons[MAX];
};

/*
 *   According to Knuth's definition, a B-tree of order m is a tree which satisfies the following properties:
 *
 *   Every node has at most m children.
 *   Every non-leaf node (except root) has at least ⌈m/2⌉ child nodes.
 *   The root has at least two children if it is not a leaf node.
 *   A non-leaf node with k children contains k − 1 keys.
 *   All leaves appear in the same level and carry no information.
 */

// MaxDegree指的key的数目，儿子的数目是MaxDegree+1

template <class Key, class Value, int MaxDegree>
class BTree {
public:
    BNode<Key, Value, MaxDegree>* root;

private:
    BNode<Key, Value, MaxDegree> search(Key key,
        BNode<Key, Value, MaxDegree>* current)
    {
        if (current == NULL) {
            return NULL;
        }
        for (int i = 0; i < current->currentKey; i++) {
            if (key == current->keys[i].first) {
                return current;
            } else if (key < current->keys[i].first) {
                return search(key, current->sons[i]);
            }
        }
        return search(key, current->sons[current->currentKey]);
    }
    void insertAndSplit(pair<Key, Value> val,
        BNode<Key, Value, MaxDegree>* node,
        BNode<Key, Value, MaxDegree>* current)
    {
        for (int i = 0; i < current->currentKey; i++) {
            if (val.first < current->keys[i].first || i == current->currentKey - 1) {
                if (current->currentKey < MaxDegree) {
                    if (key < current->keys[i].first) {
                        for (int j = current->currentKey - 1; j >= i; j--) {
                            current->keys[j + 1] = current->keys[j];
                        }
                        current->keys[i] = val;
                        for (int j = current->currentKey; j > i; j--) {
                            current->sons[j + 1] = current->sons[j];
                        }
                        current->sons[i + 1] = node;
                    } else {
                        current->keys[current->currentKey] = val;
                        current->sons[current->currentKey + 1] = node;
                    }
                    current->currentKey++;
                    return;
                } else {
                    // insert the value and find the value to be up
                    // 策略：总是提升右节点，也就是提升的节点总是在提升的key的右边一个
                    pair<Key, Value> tmp = current->keys[MaxDegree / 2];
                    BNode<Key, Value, MaxDegree> thisNode = new BNode<Key, Value, MaxDegree>();
                    BNode<Key, Value, MaxDegree> newNode = new BNode<Key, Value, MaxDegree>();
                    for (int j = 0; j < MaxDegree / 2; j++) {
                        thisNode->keys[j] = current->keys[j];
                    }
                    for (int j = MaxDegree / 2; j < MaxDegree - 1; j++) {
                        newNode->keys[j - MaxDegree / 2] = current->keys[j + 1];
                    }
                    if (i < MaxDegree / 2) {
                        // 把key和node插入thisNode
                        for (int j = 0; j < MaxDegree / 2; j++) {
                            if (thisNode->keys[j] > val.first) {
                                for (int l = MaxDegree / 2 - 1; l >= j; l--) {
                                    thisNode->keys[l + 1] = thisNode->keys[l];
                                }
                                for (int l = 0; l <= j; l++) {
                                    thisNode->sons[l] = current->sons[l];
                                }
                                for (int l = j + 1; l <= MaxDegree / 2 + 1; l++) {
                                    thisNode->sons[l] = current->sons[l - 1];
                                }
                                thisNode->keys[j] = val;
                                thisNode->sons[j + 1] = node;
                            }
                        }
                        if (thisNode->keys[MaxDegree / 2 - 1] < val.first) {
                            thisNode->keys[MaxDegree / 2] = val;
                            thisNode->sons[MaxDegree / 2 + 1] = node;
                        }
                        for (int j = MaxDegree / 2 + 1; j <= MaxDegree; j++) {
                            newNode->sons[j - MaxDegree / 2 - 1] = current->sons[j];
                        }
                    } else {
                        for (int j = MaxDegree / 2 + 1; j < MaxDegree; j++) {
                            if (newNode->keys[j - MaxDegree / 2 - 1] > val.first) {
                                for (int l = MaxDegree - 1; l >= j; l--) {
                                    newNode->keys[l - MaxDegree / 2] = newNode->keys[l - MaxDegree / 2 - 1];
                                }
                                for (int l = MaxDegree / 2 + 1; l <= j; l++) {
                                    newNode->sons[l - MaxDegree / 2 - 1] = current->sons[l];
                                }
                                for (int l = j + 1; l < MaxDegree; l++) {
                                    newNode->sons[l - MaxDegree / 2] = current->sons[l];
                                }
                                newNode->keys[j] = val;
                                newNode->sons[j - MaxDegree / 2] = node;
                            }
                        }
                        if (newNode->keys[MaxDegree - 1 - MaxDegree / 2] < key) {
                            newNode->keys[MaxDegree - MaxDegree / 2] = val;
                            newNode->sons[MaxDegree + 1 - MaxDegree / 2] = node;
                        }
                        for (int j = 0; j <= MaxDegree / 2; j++) {
                            thisNode->sons[j] = current->sons[j];
                        }
                    }
                    if (current->parent == NULL) {
                        current->parent = new BNode<Key, Value, MaxDegree>();
                        current->parent->sons[0] = current;
                    }
                    thisNode->parent = newNode->parent = current->parent;
                    for (int j = 0; j <= current->parent->currentKey; j++) {
                        if (current->parent->sons[j] == current) {
                            current->parent->sons[j] = thisNode;
                            break;
                        }
                    }
                    insertAndSplit(tmp, newNode, current->parent);
                    return;
                }
            }
        }
    }

    void merge(BNode<Key, Value, MaxDegree>* node, BNode<Key, Value, MaxDegree>* current)
    {
        for (int i = 0; i <= current->currentKey; i++) {
            if (current->sons[i] == node) {
                if (i != current->currentKey) {
                    if (current->sons[i + 1]->currentKey > MaxDegree / 2) {
                        // borrow a key from its next
                        node->keys[node->currentKey] = current->sons[i + 1]->keys[0];
                        node->sons[node->currentKey + 1] = current->sons[i + 1]->sons[0];
                        for (int j = 0; i < current->sons[i + 1]->currentKey - 1; j++) {
                            current->sons[i + 1]->keys[j] = current->sons[i + 1]->keys[j + 1];
                            current->sons[i + 1]->sons[j] = current->sons[i + 1]->sons[j + 1];
                        }
                        current->sons[i + 1]->sons[current->sons[i + 1]->currentKey - 1] = current->sons[i + 1]->sons[current->sons[i + 1]->currentKey];
                        current->sons[i + 1]->currentKey--;
                        node->currentKey++;
                    } else {
                        // merge the node and its next
                        BNode<Key, Value, MaxDegree>* nodeMerge = new BNode<Key, Value, MaxDegree>();
                        for (int j = 0; j < node->currentKey; j++) {
                            nodeMerge->keys[j] = node->keys[j];
                            nodeMerge->sons[j] = node->sons[j];
                        }
                        nodeMerge->sons[node->currentKey] = node->sons[node->currentKey];
                        nodeMerge->keys[node->currentKey] = current->keys[i + 1];
                        for (int j = 0; j < current->sons[i + 1]->currentKey; j++) {
                            nodeMerge->keys[j + node->currentKey + 1] = current->sons[i + 1]->keys[j];
                            nodeMerge->sons[j + node->currentKey + 1] = current->sons[i + 1]->sons[j];
                        }
                        nodeMerge->currentKey = node->currentKey + current->sons[i + 1]->currentKey + 1;
                        nodeMerge->sons[node->currentKey + current->sons[i + 1]->currentKey + 1] = current->sons[i + 1]->sons[current->sons[i + 1]->currentKey];
                        // delete
                        current->sons[i] = nodeMerge;
                        current->keys[i] = NULL;
                        for (int j = i; j < current->currentKey - 1; j++) {
                            current->keys[j] = current->keys[j + 1];
                            current->sons[j + 1] = current->sons[j + 2];
                        }
                        current->currentKey--;
                        merge(current, current->parent);
                    }
                } else {
                    if (current->sons[i - 1]->currentKey > MaxDegree / 2) {
                        // borrow a key from its prev
                        node->sons[node->currentKey + 1] = node->sons[node->currentKey];
                        for (int j = node->currentKey - 1; j > 0; j--) {
                            node->keys[j + 1] = node->keys[j];
                            node->sons[j + 1] = node->sons[j];
                        }
                        node->keys[0] = current->sons[i - 1]->keys[current->sons[i - 1]->currentKeys - 1];
                        current->sons[i - 1]->keys[current->sons[i - 1]->currentKeys - 1] = NULL;
                        node->sons[0] = current->sons[i - 1]->sons[current->sons[i - 1]->currentKeys];
                        current->sons[i - 1]->sons[current->sons[i - 1]->currentKeys] = NULL;
                        current->sons[i - 1]->currentKey--;
                        node->currentKey++;
                    } else {
                        // merge the node and its prev
                        BNode<Key, Value, MaxDegree>* nodeMerge = new BNode<Key, Value, MaxDegree>();
                        for (int j = 0; j < current->sons[i - 1]->currentKey; j++) {
                            nodeMerge->keys[j] = current->sons[i - 1]->keys[j];
                            nodeMerge->sons[j] = current->sons[i - 1]->sons[j];
                        }
                        nodeMerge->sons[current->sons[i - 1]->currentKey] = current->sons[i - 1]->sons[current->sons[i - 1]->currentKey];
                        nodeMerge->keys[current->sons[i - 1]->currentKey] = current->keys[i];
                        for (int j = 0; j < node->currentKey; j++) {
                            nodeMerge->keys[j + current->sons[i - 1]->currentKey + 1] = node->keys[j];
                            nodeMerge->sons[j + current->sons[i - 1]->currentKey + 1] = node->sons[j];
                        }

                        nodeMerge->currentKey = node->currentKey + current->sons[i - 1]->currentKey + 1;
                        nodeMerge->sons[node->currentKey + current->sons[i + 1]->currentKey + 1] = node->sons[node->currentKey];
                        // delete
                        current->sons[i] = nodeMerge;
                        current->keys[i] = NULL;
                        for (int j = i; j < current->currentKey - 1; j++) {
                            current->keys[j] = current->keys[j + 1];
                            current->sons[j + 1] = current->sons[j + 2];
                        }
                        current->currentKey--;
                        merge(current, current->parent);
                    }
                }
            }
        }
    }

    bool insert(Key key, Value value, BNode<Key, Value, MaxDegree>* current)
    {
        for (int i = 0; i < current->currentKey; i++) {
            if (key < current->keys[i].first) {
                // 键值对要被插入到这里
                // 由B树的构造过程，B树的子节点数目一定比键数目多1，因此说明这是叶子节点
                if (current->sons[i] == NULL) {
                    // insert this key into this node
                    if (current->currentKey < MaxDegree) {
                        for (int j = current->currentKey - 1; j >= i; j--) {
                            current->keys[j + 1] = current->keys[j];
                        }
                        current->keys[i] = pair<Key, Value>(key, value);
                        current->currentKey++;
                        return true;
                    }
                    // split
                    else {
                        insertAndSplit(pair<Key, Value>(key, value), NULL, current);
                        return true;
                    }
                } else {
                    return insert(key, value, current->sons[i]);
                }
            }
        }
    }

    bool del(Key key, BNode<Key, Value, MaxDegree>* current)
    {
        for (int i = 0; i < current->currentKey; i++) {
            if (key == current->keys[i].first) {
                if (current->sons[i] == NULL) {
                    // leaf node
                    for (int j = i; j < current->currentKey - 1; j++) {
                        current->keys[i] = current->keys[i + 1];
                    }
                    current->currentKey--;
                    if (current->currentKey > MaxDegree / 2) {
                        return true;
                    } else {
                        merge(current, current->parent);
                        return true;
                    }
                } else {
                    // exchange the node with its successor
                    BNode<Key, Value, MaxDegree>* tmp = current;
                    pair<Key, Value> thisKey;
                    while (tmp->sons[tmp->currentKey] != NULL) {
                        for (int j = 0; j < tmp->currentKey; j++) {
                            if (tmp->keys[i].first > key) {
                                tmp = tmp->sons[i];
                                break;
                            }
                        }
                    }
                    for (int j = 0; j < tmp->currentKey; j++) {
                        if (tmp->keys[j].first > key) {
                            pair<Key, Value> tmpVal = tmp->keys[ji];
                            tmp->keys[j] = current->keys[i];
                            current->keys[i] = tmpVal;
                            break;
                        }
                    }
                    return del(key, current->sons[i]);
                }
            }
        }
    }

public:
    Value Search(Key key)
    {
        Bnode<Key, Value, MaxDegree>* node = search(key, root);
        if (node == NULL) {
            std::cout << "No such key in this tree\n";
            return NULL;
        }
        for (int i = 0; i < node->currentKey - 1; i++) {
            if (node->keys[i].first == key) {
                return node->keys[i].second;
            }
        }
    }

    bool Insert(Key key, Value value)
    {
        BNode<Key, Value, MaxDegree>* current = search(key, root);
        if (current != NULL) {
            std::cout << "Key " << key << " already exists in the tree.\n";
            return false;
        }
        return insert(key, value, root);
    }

    bool Delete(Key key)
    {
        BNode<Key, Value, MaxDegree>* current = search(key, root);
        if (current == NULL) {
            std::cout << "No such key in this tree\n";
            return false;
        } else {
            del(key, current);
            return true;
        }
    }
};
