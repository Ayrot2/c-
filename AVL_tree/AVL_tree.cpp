#include <iostream>
#include <cmath>

using namespace std;


struct Tree {

    Tree(int _value, Tree* _parent) {
        value = _value;
        parent = _parent;
    }

    int value;
    Tree* right_child;
    Tree* left_child;
    Tree* parent;
    int height_difference;
    int height;

    void HeightUpdate();

};


Tree* LeftTurn(Tree* tree) {

    Tree* NewTree = tree->right_child;
    Tree* NewLeftChild = tree;
    Tree* ReplacementLeftChild = NewTree->left_child;

    NewTree->left_child = NewLeftChild;
    NewTree->left_child->right_child = ReplacementLeftChild;
    NewTree->parent = tree->parent;
    if (NewTree->left_child) if (NewTree->left_child->right_child) NewTree->left_child->right_child->parent = NewTree->left_child;
    if (NewTree->left_child) NewTree->left_child->parent = NewTree;

    NewTree->HeightUpdate();

    return NewTree;
};


Tree* RightTurn(Tree* tree) {

    Tree* NewTree = tree->left_child;
    Tree* NewRightChild = tree;
    Tree* ReplacementRightChild = NewTree->right_child;

    NewTree->right_child = NewRightChild;
    NewTree->right_child->left_child = ReplacementRightChild;
    NewTree->parent = tree->parent;
    if (NewTree->right_child) if (NewTree->right_child->left_child) NewTree->right_child->left_child->parent = NewTree->right_child;
    if (NewTree->right_child) NewTree->right_child->parent = NewTree;

    NewTree->HeightUpdate();

    return NewTree;
};


Tree* Balance(Tree* tree) {

    if (not tree) return nullptr;


    if (tree->height_difference >= 2) {

        if (tree->right_child)
            if (tree->right_child->height_difference < 0) {
                tree->right_child = RightTurn(tree->right_child);
            }

        tree = LeftTurn(tree);
        tree->right_child = Balance(tree->right_child);
        tree->left_child = Balance(tree->left_child);
        return tree;
    }

    if (tree->height_difference <= -2) {

        if (tree->left_child)
            if (tree->left_child->height_difference > 0) {
                tree->left_child = LeftTurn(tree->left_child);
            }

        tree = RightTurn(tree);
        tree->right_child = Balance(tree->right_child);
        tree->left_child = Balance(tree->left_child);
        return tree;
    }

    tree->right_child = Balance(tree->right_child);
    tree->left_child = Balance(tree->left_child);
    return tree;
};


void Tree::HeightUpdate() {
    if (left_child) left_child->HeightUpdate();
    if (right_child) right_child->HeightUpdate();
    height = max(left_child ? left_child->height : 0, right_child ? right_child->height : 0) + 1;
    height_difference = (right_child ? right_child->height : 0) - (left_child ? left_child->height : 0);
};


struct MainTree {

    Tree* TreeRoot;

    void AddElem(int elem_value);

    void DeleteElem(int elem_value);

    void Print();

    void UpdateAllHeights();


    Tree* ReturnValueByCords(int x, int y);
};


void MainTree::AddElem(int elem_value) {

    if (not TreeRoot) {
        TreeRoot = new Tree(elem_value, nullptr);
        UpdateAllHeights();
        return;
    }

    Tree* node = TreeRoot;

    while (true) {
        if (elem_value > node->value) {

            if (node->right_child != nullptr) {
                node = node->right_child;
            }
            else {
                node->right_child = new Tree(elem_value, node);
                node->right_child->height = 1;
                break;
            }

        }
        else if (elem_value < node->value) {

            if (node->left_child != nullptr) {
                node = node->left_child;
            }
            else {
                node->left_child = new Tree(elem_value, node);
                node->left_child->height = 1;
                break;
            }

        }
        else return;
    }

    UpdateAllHeights();
    TreeRoot = Balance(TreeRoot);
    UpdateAllHeights();
};


void MainTree::DeleteElem(int elem_value) {

    Tree* node = TreeRoot;

    while (true) {
        if (elem_value > node->value) {

            if (node->right_child) {
                node = node->right_child;
            }
            else return;

        }
        else if (elem_value < node->value) {

            if (node->left_child) {
                node = node->left_child;
            }
            else return;

        }
        else break;
    }

    if (node->right_child) {

        Tree* permutative_node = node->right_child;
        while (permutative_node->left_child) permutative_node = permutative_node->left_child;

        Tree* permutative_node_right_child = permutative_node->right_child;

        if (permutative_node->parent->value > permutative_node->value)
            permutative_node->parent->left_child = permutative_node_right_child;
        else permutative_node->parent->right_child = permutative_node_right_child;

        if (permutative_node->right_child) permutative_node->right_child->parent = permutative_node->parent;

        node->value = permutative_node->value;

    }
    else if (node->left_child) {

        Tree* permutative_node = node->left_child;
        while (permutative_node->right_child) permutative_node = permutative_node->right_child;

        if (permutative_node->parent->value < permutative_node->value)
            permutative_node->parent->right_child = permutative_node->left_child;
        else permutative_node->parent->left_child = permutative_node->left_child;

        if (permutative_node->left_child) permutative_node->left_child->parent = permutative_node->parent;

        node->value = permutative_node->value;

    }
    else {

        if (node->parent == nullptr and node->right_child == nullptr and node->left_child == nullptr) {
            TreeRoot = nullptr;
            return;
        }
        if (node->value > node->parent->value) node->parent->right_child = nullptr;
        else node->parent->left_child = nullptr;
    }

    UpdateAllHeights();
    TreeRoot = Balance(TreeRoot);
    UpdateAllHeights();

}

void MainTree::Print() {

    if (TreeRoot) cout << "tree height: " << TreeRoot->height << endl;
    else {
        cout << "tree height: " << 0 << endl;
        cout << "n \n \n";
        return;
    }

    for (int y = 0; y < TreeRoot->height; ++y) {

        for (int i = TreeRoot->height - int(pow(2, y - 1)); i > 0; --i) cout << "   ";

        for (int x = 0; x < pow(2, y); ++x) {
            Tree* tree_xy = ReturnValueByCords(x, y);
            if (tree_xy) cout << tree_xy->value << " ";
            else cout << "n" << " ";
            if (x % 2) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Tree* ReturnTreeByCords(int x, int y, Tree* tree) {
    if (y == 0 and x == 0) return tree;
    else if (x - pow(2, y - 1) < 0) {
        if (tree->left_child) return ReturnTreeByCords(x, y - 1, tree->left_child);
        else return nullptr;
    }
    else {
        if (tree->right_child) return ReturnTreeByCords(x - int(pow(2, y - 1)), y - 1, tree->right_child);
        else return nullptr;
    }
}


Tree* MainTree::ReturnValueByCords(int x, int y) {
    return ReturnTreeByCords(x, y, TreeRoot);
}


void MainTree::UpdateAllHeights() {
    TreeRoot->HeightUpdate();
}


int main() {

    MainTree tree = MainTree();

    tree.AddElem(9);
    tree.Print();
    tree.AddElem(4);
    tree.Print();
    tree.AddElem(15);
    tree.Print();
    tree.AddElem(7);
    tree.Print();
    tree.AddElem(13);
    tree.Print();
    tree.AddElem(5);
    tree.Print();
    tree.AddElem(8);
    tree.Print();
    tree.AddElem(10);
    tree.Print();
    tree.AddElem(18);
    tree.Print();
    tree.AddElem(20);
    tree.Print();
    tree.AddElem(-2);
    tree.Print();
    tree.AddElem(3);
    tree.Print();
    tree.AddElem(22);
    tree.Print();
    tree.AddElem(14);
    tree.Print();
    tree.AddElem(0);
    tree.Print();
    tree.DeleteElem(9);
    tree.Print();
    tree.DeleteElem(20);
    tree.Print();
    tree.DeleteElem(5);
    tree.Print();
    tree.DeleteElem(8);
    tree.Print();
    tree.DeleteElem(15);
    tree.Print();
    tree.DeleteElem(10);
    tree.Print();
    tree.DeleteElem(13);
    tree.Print();
    tree.DeleteElem(14);
    tree.Print();
    tree.DeleteElem(18);
    tree.Print();
    tree.DeleteElem(22);
    tree.Print();
    tree.DeleteElem(7);
    tree.Print();
    tree.DeleteElem(-2);
    tree.Print();
    tree.DeleteElem(0);
    tree.Print();
    tree.DeleteElem(0);
    tree.Print();
    tree.DeleteElem(3);
    tree.Print();
    tree.DeleteElem(4);
    tree.Print();

    return 0;
}
