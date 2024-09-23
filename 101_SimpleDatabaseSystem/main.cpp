#include <iostream>
#include <vector>
#include <algorithm>

const int MIN_DEGREE = 2; // Minimum degree for B-tree

// B-tree Node
class BTreeNode {
public:
    int* keys; // Array of keys
    int t; // Minimum degree
    BTreeNode** children; // Array of child pointers
    int n; // Current number of keys
    bool leaf; // True if leaf node

    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1];
        children = new BTreeNode * [2 * t];
        n = 0;
    }

    void traverse() {
        for (int i = 0; i < n; i++) {
            if (!leaf) {
                children[i]->traverse();
            }
            std::cout << keys[i] << " ";
        }
        if (!leaf) {
            children[n]->traverse();
        }
    }

    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
};

// B-tree
class BTree {
private:
    BTreeNode* root;
public:
    BTree() {
        root = nullptr;
    }

    void traverse() {
        if (root != nullptr) {
            root->traverse();
        }
    }

    void insert(int key);
};

void BTreeNode::insertNonFull(int key) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        n++;
    }
    else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        if (children[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < key) {
                i++;
            }
        }
        children[i + 1]->insertNonFull(key);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = MIN_DEGREE - 1;

    for (int j = 0; j < MIN_DEGREE - 1; j++) {
        z->keys[j] = y->keys[j + MIN_DEGREE];
    }

    if (!y->leaf) {
        for (int j = 0; j < MIN_DEGREE; j++) {
            z->children[j] = y->children[j + MIN_DEGREE];
        }
    }

    y->n = MIN_DEGREE - 1;

    for (int j = i + 1; j < n + 1; j++) {
        children[j] = children[j - 1];
    }

    children[i + 1] = z;

    for (int j = i; j < n; j++) {
        keys[j + 1] = keys[j];
    }

    keys[i] = y->keys[MIN_DEGREE - 1];
    n++;
}

void BTree::insert(int key) {
    if (root == nullptr) {
        root = new BTreeNode(MIN_DEGREE, true);
        root->keys[0] = key;
        root->n = 1;
    }
    else {
        if (root->n == 2 * MIN_DEGREE - 1) {
            BTreeNode* s = new BTreeNode(MIN_DEGREE, false);
            s->children[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < key) {
                i++;
            }
            s->children[i]->insertNonFull(key);
            root = s;
        }
        else {
            root->insertNonFull(key);
        }
    }
}

// Hash Table Implementation
class HashTable {
private:
    struct HashNode {
        int key;
        HashNode* next;
        HashNode(int k) : key(k), next(nullptr) {}
    };

    HashNode** table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) {
        size = s;
        table = new HashNode * [size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        HashNode* newNode = new HashNode(key);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void search(int key) {
        int index = hashFunction(key);
        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                std::cout << "Key " << key << " found in hash table.\n";
                return;
            }
            current = current->next;
        }
        std::cout << "Key " << key << " not found in hash table.\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        HashNode* current = table[index];
        HashNode* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Key " << key << " not found in hash table.\n";
            return;
        }

        if (prev == nullptr) {
            table[index] = current->next; // Remove from head
        }
        else {
            prev->next = current->next; // Remove from chain
        }
        delete current;
        std::cout << "Key " << key << " removed from hash table.\n";
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            HashNode* current = table[i];
            while (current != nullptr) {
                HashNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

// Database Class
class Database {
private:
    BTree bTree;
    HashTable hashTable;

public:
    Database() : bTree(), hashTable(10) {} // Default size for hash table

    void insert(int key) {
        bTree.insert(key);
        hashTable.insert(key);
        std::cout << "Inserted key " << key << " into database.\n";
    }

    void search(int key) {
        std::cout << "Searching for key " << key << ":\n";
        bTree.traverse(); // Print B-tree keys
        hashTable.search(key);
    }

    void remove(int key) {
        hashTable.remove(key);
        std::cout << "Removed key " << key << " from database.\n";
    }

    void displayBTree() {
        std::cout << "B-Tree keys: ";
        bTree.traverse();
        std::cout << std::endl;
    }
};

// Main Function
int main() {
    Database db;

    db.insert(10);
    db.insert(20);
    db.insert(5);
    db.insert(6);
    db.insert(12);
    db.insert(30);
    db.insert(7);
    db.insert(17);

    db.displayBTree();

    db.search(10);
    db.search(15);

    db.remove(10);
    db.displayBTree();

    return 0;
}
