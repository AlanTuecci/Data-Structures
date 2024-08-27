/**
 * @file BinaryNode.cpp
 * @author Alan Tuecci (Alan.Tuecci@outlook.com)
 * @brief Implementation for BinaryNode class
 * @version 0.1
 * @date 2024-08-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "BinaryNode.hpp"

/**
 * @brief default constructor
 */
template <class ItemType>
BinaryNode<ItemType>::BinaryNode() : item_{},
                                     left_child_ptr_{std::shared_ptr<BinaryNode<ItemType>>(nullptr)},
                                     right_child_ptr_{std::shared_ptr<BinaryNode<ItemType>>(nullptr)}
{
}

/**
 * @brief parameterized constructor
 *
 * @param an_item to be held by the node
 */
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &an_item) : item_{an_item},
                                                            left_child_ptr_{std::shared_ptr<BinaryNode<ItemType>>(nullptr)},
                                                            right_child_ptr_{std::shared_ptr<BinaryNode<ItemType>>(nullptr)}
{
}

/**
 * @brief parameterized constructor
 *
 * @param an_item to be held by the node
 * @param left_ptr to point to the left child of the node
 * @param right_ptr to point to the right child of the node
 */
template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType &an_item, std::shared_ptr<BinaryNode<ItemType>> left_ptr, std::shared_ptr<BinaryNode<ItemType>> right_ptr) : item_{an_item},
                                                                                                                                                             left_child_ptr_{left_child_ptr_},
                                                                                                                                                             right_child_ptr_{right_child_ptr_}
{
}

/**
 * @brief sets the item to be held by the node
 *
 * @param an_item to be held by the node
 */
template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType &an_item)
{
    item_ = an_item;
}

/**
 * @brief gets the item held by the node
 *
 * @return the item held by the node
 */
template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item_;
}

/**
 * @brief checks if the node is a leaf
 *
 * @return true if the node is a leaf,
 * @return false otherwise
 */
template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    return ((left_child_ptr_ == std::shared_ptr<BinaryNode<ItemType>>(nullptr)) && (right_child_ptr_ == std::shared_ptr<BinaryNode<ItemType>>(nullptr)));
}

/**
 * @brief gets the pointer to the node's left child
 *
 * @return pointer to the node's left child
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() const
{
    return left_child_ptr_;
}

/**
 * @brief gets the pointer to the node's right child
 *
 * @return pointer ot the node's right child
 */
template <class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr() const
{
    return right_child_ptr_;
}

/**
 * @brief sets the pointer to the node's left child
 *
 * @param left_ptr to the left child node
 */
template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> left_ptr)
{
    left_child_ptr_ = left_ptr;
}

/**
 * @brief sets the pointer to the node's right child
 *
 * @param right_ptr to the right child node
 */
template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> right_ptr)
{
    right_child_ptr_ = right_ptr;
}