/**
 * @file BinaryNode.hpp
 * @author Alan Tuecci (Alan.Tuecci@outlook.com)
 * @brief Interface for BinaryNode class
 * @version 0.1
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template <class ItemType>
class BinaryNode
{
public:
    /**
     * @brief default constructor
     */
    BinaryNode();

    /**
     * @brief parameterized constructor
     *
     * @param an_item to be held by the node
     */
    BinaryNode(const ItemType &an_item);

    /**
     * @brief parameterized constructor
     *
     * @param an_item to be held by the node
     * @param left_ptr to point to the left child of the node
     * @param right_ptr to point to the right child of the node
     */
    BinaryNode(const ItemType &an_item, std::shared_ptr<BinaryNode<ItemType>> left_ptr, std::shared_ptr<BinaryNode<ItemType>> right_ptr);

    /**
     * @brief sets the item to be held by the node
     *
     * @param an_item to be held by the node
     */
    void setItem(const ItemType &an_item);

    /**
     * @brief gets the item held by the node
     *
     * @return the item held by the node
     */
    ItemType getItem() const;

    /**
     * @brief checks if the node is a leaf
     *
     * @return true if the node is a leaf,
     * @return false otherwise
     */
    bool isLeaf() const;

    /**
     * @brief gets the pointer to the node's left child
     *
     * @return pointer to the node's left child
     */
    std::shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;

    /**
     * @brief gets the pointer to the node's right child
     *
     * @return pointer ot the node's right child
     */
    std::shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;

    /**
     * @brief sets the pointer to the node's left child
     *
     * @param left_ptr to the left child node
     */
    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> left_ptr);

    /**
     * @brief sets the pointer to the node's right child
     *
     * @param right_ptr to the right child node
     */
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> right_ptr);

private:
    ItemType item_;
    std::shared_ptr<BinaryNode<ItemType>> left_child_ptr_;
    std::shared_ptr<BinaryNode<ItemType>> right_child_ptr_;
};

#include "BinaryNode.cpp"
#endif