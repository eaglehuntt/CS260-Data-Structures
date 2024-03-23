#include "bst.hpp"
#include <iostream>

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinaryNode* BinarySearchTree::locate_parent(int proposed_value) {
    BinaryNode *parent = nullptr;
    BinaryNode *current = root;

    while (current != nullptr) {
        if (proposed_value < current->value) {
            parent = current;
            current = current->left;
        } else if (proposed_value > current->value) {
            parent = current;
            current = current->right;
        } else {
            // If the value already exists in the tree
            // return the parent node
            return parent;
        }
    }

    return parent;
}

void BinarySearchTree::add(int new_value) {
    BinaryNode *parent = locate_parent(new_value);

    if (parent == nullptr && root != nullptr) {
        // The value already exists in the tree
        std::cout << "Value already exists in the tree." << std::endl;
        return;
    }

    BinaryNode *new_node = new BinaryNode;
    new_node->value = new_value;
    new_node->left = nullptr;
    new_node->right = nullptr;

    if (parent == nullptr) {
        // Tree is empty, so the new node becomes the root
        root = new_node;
    } else if (new_value < parent->value) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

int BinarySearchTree::remove(int old_value) {
    BinaryNode *parent = nullptr;
    BinaryNode *current = root;

    // Search for the node to be deleted
    while (current != nullptr && current->value != old_value) {
        parent = current;
        if (old_value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    // If node with given value not found
    if (current == nullptr)
        return -1; // Indicate failure to remove

    // Case 1: Node to be deleted has no children
    if (current->left == nullptr && current->right == nullptr) {
        if (parent == nullptr)
            root = nullptr; // Node to be deleted is the root
        else if (parent->left == current)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete current;
    }
    // Case 2: Node to be deleted has only one child
    else if (current->left == nullptr) {
        if (parent == nullptr)
            root = current->right;
        else if (parent->left == current)
            parent->left = current->right;
        else
            parent->right = current->right;
        delete current;
    } else if (current->right == nullptr) {
        if (parent == nullptr)
            root = current->left;
        else if (parent->left == current)
            parent->left = current->left;
        else
            parent->right = current->left;
        delete current;
    }
    // Case 3: Node to be deleted has two children
    else {
        BinaryNode *successor_parent = current;
        BinaryNode *successor = current->right;

        // Find leftmost node in the right subtree (successor)
        while (successor->left != nullptr) {
            successor_parent = successor;
            successor = successor->left;
        }

        // If successor is not the right child of the node to be deleted
        if (successor_parent != current)
            successor_parent->left = successor->right;
        else
            successor_parent->right = successor->right;

        // Replace value of the node to be deleted with value of successor
        current->value = successor->value;

        // Delete the successor node
        delete successor;
    }

    return 0; // Indicate success
}


bool BinarySearchTree::search(int proposed_value) {
    BinaryNode *current = root;

    while (current != nullptr) {
        if (proposed_value == current->value) {
            return true;
        } else if (proposed_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}

void BinarySearchTree::in_order_traversal_helper(BinaryNode *current) {
    if (current != nullptr) {
        in_order_traversal_helper(current->left);
        std::cout << current->value << " ";
        in_order_traversal_helper(current->right);
    }
}

void BinarySearchTree::in_order_traversal() {
    in_order_traversal_helper(root);
    std::cout << std::endl;
}
