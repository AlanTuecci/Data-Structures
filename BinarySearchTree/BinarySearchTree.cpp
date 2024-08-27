/**
 * @file BinarySearchTree.cpp
 * @author Alan Tuecci (Alan.Tuecci@outlook.com)
 * @brief Implementation for BinarySearchTree class
 * @version 0.1
 * @date 2024-08-25
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "BinarySearchTree.hpp"

/**
 * @brief default constructor
 *
 */
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : root_ptr_{std::shared_ptr<BinaryNode<ItemType>>(nullptr)}
{
}

/**
 * @brief parameterized constructor
 *
 * @param root_item to be inserted at root of tree
 */
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &root_item) : root_ptr_{std::make_shared<BinaryNode<ItemType>>(root_item, std::shared_ptr<BinaryNode<ItemType>>(nullptr), std::shared_ptr<BinaryNode<ItemType>>(nullptr))}
{
}

/**
 * @brief copy constructor
 *
 * @param another_tree to be copied into the new tree
 */
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree &another_tree)
{
    root_ptr_ = copyTree(another_tree.root_ptr_);
}

/**
 * @brief constructs a new binary search tree of objects that is balanced and contains each and every one of those objects
 *
 * @note these objects MUST have the >, ==, and < operators overloaded in order for this function to work
 * @param nums a sorted vector containing objects of an arbitrary type with overloaded comparison operators
 */
template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(std::vector<ItemType> &items) : root_ptr_{nullptr}
{
    int size = items.size();
    for (int i = 0; i < size; i++)
    {
        add(items[i]);
    }
}

/**
 * @brief returns the pointer to the root of the tree
 *
 * @return the pointer to the root of the tree
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::getRoot() const
{
    return root_ptr_;
}

/**
 * @brief returns a flag indicating whether or not the tree is empty
 *
 * @return true if the tree is empty,
 * @return false otherwise
 */
template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return root_ptr_ == std::shared_ptr<BinaryNode<ItemType>>(nullptr);
}

/**
 * @brief gets the height of the binary search tree structure as the number of nodes on the longest path from root to leaf
 *
 * @return the height of the binary search tree
 */
template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return this->getHeightHelper(root_ptr_);
}

/**
 * @brief gets the number of nodes in the binary search tree structure
 *
 * @return the number of nodes in the binary search tree
 */
template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
    return this->getNumberOfNodesHelper(root_ptr_);
}

/**
 * @brief adds a new entry to the binary search tree
 *
 * @param an_entry to be added into the tree
 * @note insertion retains the BST property such that at any node, all items in its left subtree are < than the item at that node and all items in its right subtree are >
 * @note operators > and < would need to be overloaded for self made data types
 */
template <class ItemType>
void BinarySearchTree<ItemType>::add(const ItemType &an_entry)
{
    std::shared_ptr<BinaryNode<ItemType>> new_node_ptr = std::make_shared<BinaryNode<ItemType>>(an_entry);
    root_ptr_ = placeNode(root_ptr_, new_node_ptr);
}

/**
 * @brief removes an entry from the binary search tree
 *
 * @param an_entry to be removed from the tree
 * @return true if the entry was removed,
 * @return false otherwise
 * @note deletion retains the BST property such that at any node, all items in its left subtree are < than the item at that node and all items in its right subtree are >
 * @note operators > and < would need to be overloaded for self made data types
 */
template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &an_entry)
{
    bool is_successful = false;
    root_ptr_ = removeValue(root_ptr_, an_entry, is_successful);
    return is_successful;
}

/**
 * @brief finds an entry in the tree
 *
 * @param an_entry to be found
 * @return true if entry was located,
 * @return false otherwise
 */
template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType &an_entry)
{
    return (findNode(root_ptr_, an_entry) != std::shared_ptr<BinaryNode<ItemType>>(nullptr));
}

/**
 * @brief displays the preorder traversal through the Binary Search Tree
 *
 */
template <class ItemType>
void BinarySearchTree<ItemType>::displayPreorder()
{
    preorderHelper(root_ptr_);
    std::cout << std::endl;
}

// /**
//  * @brief rearranges the tree to be in-order, so that the leftmost node in the tree is now the root of the tree and every node has no left child and only one right child
//  *
//  */
// template <class ItemType>
// void BinarySearchTree<ItemType>::makeIncreasingBST() {}

/**
 * @brief checks if the tree is balanced
 *
 * @return true if the tree is balanced,
 * @return false otherwise
 */
template <class ItemType>
bool BinarySearchTree<ItemType>::isBalanced()
{
    std::shared_ptr<BinaryNode<ItemType>> leftSubtreePtr = root_ptr_->getLeftChildPtr();
    std::shared_ptr<BinaryNode<ItemType>> rightSubtreePtr = root_ptr_->getRightChildPtr();
    int leftSubtreeHeight = getHeightHelper(leftSubtreePtr);
    int rightSubtreeHeight = getHeightHelper(rightSubtreePtr);
    if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// /**
//  * @brief checks if the tree is a complete Binary Search Tree
//  *
//  * @return true if the tree is complete,
//  * @return false otherwise
//  */
// template <class ItemType>
// bool BinarySearchTree<ItemType>::isComplete() {}

// /**
//  * @brief checks if the tree is a full Binary Search Tree
//  *
//  * @return true if the tree is full,
//  * @return false otherwise
//  */
// template <class ItemType>
// bool BinarySearchTree<ItemType>::isFull() {}

//-----Private Methods------

/**
 * @brief recursively prints the contents of the subtree pointed to by the node pointer
 *
 * @param node that points to the root node in a subtree
 */
template <class ItemType>
void BinarySearchTree<ItemType>::preorderHelper(std::shared_ptr<BinaryNode<ItemType>> node)
{
    if (node == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        return;
    }
    std::cout << node->getItem() << " ";
    preorderHelper(node->getLeftChildPtr());
    preorderHelper(node->getRightChildPtr());
}

/**
 * @brief called by the copy constructor - recursively copies every node in the tree pointed to by the parameter pointer
 *
 * @param old_tree_root_ptr that points to the root of the tree to be copied
 * @return pointer to the root of the copied subtree
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> old_tree_root_ptr) const
{
    std::shared_ptr<BinaryNode<ItemType>> new_tree_ptr;

    // Copy tree nodes during a preorder traversal
    if (old_tree_root_ptr != std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        // Copy node
        new_tree_ptr = std::make_shared<BinaryNode<ItemType>>(old_tree_root_ptr->getItem(), std::shared_ptr<BinaryNode<ItemType>>(nullptr), std::shared_ptr<BinaryNode<ItemType>>(nullptr));
        new_tree_ptr->setLeftChildPtr(copyTree(old_tree_root_ptr->getLeftChildPtr()));
        new_tree_ptr->setRightChildPtr(copyTree(old_tree_root_ptr->getRightChildPtr()));
    }
}

/**
 * @brief called by getHeight() - returns the height of the subtree
 *
 * @param subtree_ptr that points to the root fo the current subtree
 * @return the height of the BST structure as the number of nodes on the longest path from root to leaf
 */
template <class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr) const
{
    if (subtree_ptr == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        return 0;
    }
    else
    {
        return 1 + std::max(getHeightHelper(subtree_ptr->getLeftChildPtr()), getHeightHelper(subtree_ptr->getRightChildPtr()));
    }
}

/**
 * @brief called by getNumberOfNodes() - returns the number of nodes in the subtree
 *
 * @param subtree_ptr that points to the root of the current subtree
 * @return number of nodes in the subtree
 */
template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr) const
{
    if (subtree_ptr == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        return 0;
    }
    else
    {
        return 1 + getNumberOfNodesHelper(subtree_ptr->getLeftChildPtr()) + getNumberOfNodesHelper(subtree_ptr->GetRightChildPtr());
    }
}

/**
 * @brief called by add() - recursively places the new node as a leaf retaining the BST property
 *
 * @param subtree_ptr that points to the root of the subtree
 * @param new_node_ptr that points to the new node to be added to the tree
 * @return a pointer to the root of the subtree in which the node was placed
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr, std::shared_ptr<BinaryNode<ItemType>> new_node_ptr)
{
    if (subtree_ptr == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        return new_node_ptr;
    }
    else
    {
        if (subtree_ptr->getItem() > new_node_ptr->getItem())
        {
            subtree_ptr->setLeftChildPtr(placeNode(subtree_ptr->getLeftChildPtr(), new_node_ptr));
        }
        else if ((subtree_ptr->getItem() == new_node_ptr->getItem()) && (subtree_ptr->getItem() > new_node_ptr->getItem()))
        {
            subtree_ptr->setLeftChildPtr(placeNode(subtree_ptr->getLeftChildPtr(), new_node_ptr));
        }
        else
        {
            subtree_ptr->setRightChildPtr(placeNode(subtree_ptr->getRightChildPtr(), new_node_ptr));
        }
        return subtree_ptr;
    }
}

/**
 * @brief called by remove() - removes a node whose value matches the target value
 *
 * @param subtree_ptr that points to the root of the subtree
 * @param target to be found and removed from the subtree
 * @param success a flag to indicate that the node was successfully removed
 * @return a pointer to the subtree in which the target was found
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr, const ItemType &target, bool &success)
{
    if (subtree_ptr == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        // Not found here
        success = false;
    }
    else if (subtree_ptr->getItem() == target)
    {
        // Item is in the root of some subtree
        subtree_ptr = removeNode(subtree_ptr);
        success = true;
    }
    else if (subtree_ptr->getItem() > target)
    {
        // Search the left subtree
        subtree_ptr->setLeftChildPtr(removeValue(subtree_ptr->getLeftChildPtr(), target, success));
    }
    else
    {
        // Search the right subtree
        subtree_ptr->setRightChildPtr(removeValue(subtree_ptr->getRightChildPtr(), target, success));
    }
    return subtree_ptr;
}

/**
 * @brief called by removeValue() - removes the node pointed to by the parameter such that the BST property is retained
 *
 * @param node_ptr that points to the node
 * @return a pointer to the subtree after the node has been removed
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> node_ptr)
{
    // Case 1 - Node is a leaf -> it is deleted
    if (node_ptr->isLeaf())
    {
        node_ptr.reset();
        return node_ptr;
    }

    // Case 2 - Node has one child - parent adopts child
    else if (node_ptr->getLeftChildPtr() == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        // Has right child only
        return node_ptr->getRightChildPtr();
    }
    else if (node_ptr->getRightChildPtr() == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        // Has left child only
        return node_ptr->getLeftChildPtr();
    }

    // Case 3 - Node has two children - find successor node
    else
    {
        ItemType new_node_value;
        node_ptr->setRightChildPtr(removeLeftmostNode(node_ptr->getRightChildPtr(), new_node_value));
        node_ptr->setItem(new_node_value);
        return node_ptr;
    }
}

/**
 * @brief called by removeNode() - removes the node conatining the inorder successor of the node to be deleted
 *
 * @param node_ptr that points to the node to be removed
 * @param inorder_successor a reference to the inorder sucessor (the smallest value in the left subtree) of the node to be deleted
 * @return a pointer to the subtree after the inorder successor node has been deleted
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> node_ptr, ItemType &inorder_successor)
{
    if (node_ptr->getLeftChildPtr() == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        inorder_successor = node_ptr->getItem();
        return removeNode(node_ptr);
    }
    else
    {
        node_ptr->setLeftChildPtr(removeLeftmostNode(node_ptr->getLeftChildPtr(), inorder_successor));
        return node_ptr;
    }
}

/**
 * @brief called by contains() - finds the node in the subtree whose value matches the target's value
 *
 * @param subtree_ptr that points to the subtree
 * @param target to be found in the subtree
 * @return a pointer to the node containing the target,
 * @return std::shared_ptr<BinaryNode<ItemType>>(nullptr) if not found
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> subtree_ptr, const ItemType &target) const
{
    // Uses a binary search
    if (subtree_ptr == std::shared_ptr<BinaryNode<ItemType>>(nullptr))
    {
        // Not found
        return subtree_ptr;
    }
    else if (subtree_ptr->getItem() == target)
    {
        // Found
        return subtree_ptr;
    }
    else if (subtree_ptr->getItem() > target)
    {
        // Not found - Search left subtree
        return findNode(subtree_ptr->getLeftChildPtr(), target);
    }
    else
    {
        // Not found - Search right subtree
        return findNode(subtree_ptr->getRightChildPtr(), target);
    }
}