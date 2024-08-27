/**
 * @file BinarySearchTree.hpp
 * @author Alan Tuecci (Alan.Tuecci@outlook.com)
 * @brief Interface for BinarySearchTree Class
 * @version 0.1
 * @date 2024-08-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "../BinaryNode/BinaryNode.hpp"
#include <memory>
#include <vector>
#include <cstdlib>
#include <iostream>

template <class ItemType>
class BinarySearchTree
{
public:
    /**
     * @brief default constructor
     *
     */
    BinarySearchTree();

    /**
     * @brief parameterized constructor
     *
     * @param root_item to be inserted at root of tree
     */
    BinarySearchTree(const ItemType &root_item);

    /**
     * @brief copy constructor
     *
     * @param another_tree to be copied into the new tree
     */
    BinarySearchTree(const BinarySearchTree &another_tree);

    /**
     * @brief constructs a new binary search tree of objects that is balanced and contains each and every one of those objects
     *
     * @note these objects MUST have the >, ==, and < operators overloaded in order for this function to work
     * @param nums a sorted vector containing objects of an arbitrary type with overloaded comparison operators
     */
    BinarySearchTree(std::vector<ItemType> &items);

    /**
     * @brief returns the pointer to the root of the tree
     *
     * @return the pointer to the root of the tree
     */
    std::shared_ptr<BinaryNode<ItemType>> getRoot() const;

    /**
     * @brief returns a flag indicating whether or not the tree is empty
     *
     * @return true if the tree is empty,
     * @return false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief gets the height of the binary search tree structure as the number of nodes on the longest path from root to leaf
     *
     * @return the height of the binary search tree
     */
    int getHeight() const;

    /**
     * @brief gets the number of nodes in the binary search tree structure
     *
     * @return the number of nodes in the binary search tree
     */
    int getNumberOfNodes() const;

    /**
     * @brief adds a new entry to the binary search tree
     *
     * @param an_entry to be added into the tree
     * @note insertion retains the BST property such that at any node, all items in its left subtree are < than the item at that node and all items in its right subtree are >
     * @note operators > and < would need to be overloaded for self made data types
     */
    void add(const ItemType &an_entry);

    /**
     * @brief removes an entry from the binary search tree
     *
     * @param an_entry to be removed from the tree
     * @return true if the entry was removed,
     * @return false otherwise
     * @note deletion retains the BST property such that at any node, all items in its left subtree are < than the item at that node and all items in its right subtree are >
     * @note operators > and < would need to be overloaded for self made data types
     */
    bool remove(const ItemType &an_entry);

    /**
     * @brief finds an entry in the tree
     *
     * @param an_entry to be found
     * @return true if entry was located,
     * @return false otherwise
     */
    bool contains(const ItemType &an_entry);

    /**
     * @brief displays the preorder traversal through the Binary Search Tree
     *
     */
    void displayPreorder();

    // /**
    //  * @brief rearranges the tree to be in-order, so that the leftmost node in the tree is now the root of the tree and every node has no left child and only one right child
    //  *
    //  */
    // void makeIncreasingBST();

    /**
     * @brief checks if the tree is balanced
     *
     * @return true if the tree is balanced,
     * @return false otherwise
     */
    bool isBalanced();

    // /**
    //  * @brief checks if the tree is a complete Binary Search Tree
    //  *
    //  * @return true if the tree is complete,
    //  * @return false otherwise
    //  */
    // bool isComplete();

    // /**
    //  * @brief checks if the tree is a full Binary Search Tree
    //  *
    //  * @return true if the tree is full,
    //  * @return false otherwise
    //  */
    // bool isFull();

private:
    std::shared_ptr<BinaryNode<ItemType>> root_ptr_;

    /**
     * @brief recursively prints the contents of the subtree pointed to by the node pointer
     *
     * @param node that points to the root node in a subtree
     */
    void preorderHelper(std::shared_ptr<BinaryNode<ItemType>> node);

    /**
     * @brief called by the copy constructor - recursively copies every node in the tree pointed to by the parameter pointer
     *
     * @param old_tree_root_ptr that points to the root of the tree to be copied
     * @return pointer to the root of the copied subtree
     */
    std::shared_ptr<BinaryNode<ItemType>> copyTree(const std::shared_ptr<BinaryNode<ItemType>> old_tree_root_ptr) const;

    /**
     * @brief called by getHeight() - returns the height of the subtree
     *
     * @param subtree_ptr that points to the root fo the current subtree
     * @return the height of the BST structure as the number of nodes on the longest path from root to leaf
     */
    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr) const;

    /**
     * @brief called by getNumberOfNodes() - returns the number of nodes in the subtree
     *
     * @param subtree_ptr that points to the root of the current subtree
     * @return number of nodes in the subtree
     */
    int getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr) const;

    /**
     * @brief called by add() - recursively places the new node as a leaf retaining the BST property
     *
     * @param subtree_ptr that points to the root of the subtree
     * @param new_node_ptr that points to the new node to be added to the tree
     * @return a pointer to the root of the subtree in which the node was placed
     */
    std::shared_ptr<BinaryNode<ItemType>> placeNode(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr, std::shared_ptr<BinaryNode<ItemType>> new_node_ptr);

    /**
     * @brief called by remove() - removes a node whose value matches the target value
     *
     * @param subtree_ptr that points to the root of the subtree
     * @param target to be found and removed from the subtree
     * @param success a flag to indicate that the node was successfully removed
     * @return a pointer to the subtree in which the target was found
     */
    std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr, const ItemType &target, bool &success);

    /**
     * @brief called by removeValue() - removes the node pointed to by the parameter such that the BST property is retained
     *
     * @param node_ptr that points to the node
     * @return a pointer to the subtree after the node has been removed
     */
    std::shared_ptr<BinaryNode<ItemType>> removeNode(std::shared_ptr<BinaryNode<ItemType>> node_ptr);

    /**
     * @brief called by removeNode() - removes the node conatining the inorder successor of the node to be deleted
     *
     * @param node_ptr that points to the node to be removed
     * @param inorder_successor a reference to the inorder sucessor (the smallest value in the left subtree) of the node to be deleted
     * @return a pointer to the subtree after the inorder successor node has been deleted
     */
    std::shared_ptr<BinaryNode<ItemType>> removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> node_ptr, ItemType &inorder_successor);

    /**
     * @brief called by contains() - finds the node in the subtree whose value matches the target's value
     *
     * @param subtree_ptr that points to the subtree
     * @param target to be found in the subtree
     * @return a pointer to the node containing the target,
     * @return std::shared_ptr<BinaryNode<ItemType>>(nullptr) if not found
     */
    std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr, const ItemType &target) const;
};

#include "BinarySearchTree.cpp"
#endif