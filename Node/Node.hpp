/**
 * @file Node.hpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Interface for Node class
 * @version 0.1
 * @date 2024-08-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef NODE_
#define NODE_

#include <iostream>
#include <memory>

template <class ItemType>
class Node
{
public:
    /**
     * @brief default constructor
     */
    Node();

    /**
     * @brief parameterized constructor
     *
     * @param an_item to be inserted into the node
     */
    Node(const ItemType &an_item);

    /**
     * @brief parameterized constructor
     *
     * @param an_item to be inserted into the node
     * @param next_node_ptr to be used to point to the next node
     */
    Node(const ItemType &an_item, const std::shared_ptr<Node<ItemType>> &next_node_ptr);

    /**
     * @brief parameterized constructor
     *
     * @param an_item to be inserted into the node
     * @param next_node_ptr to be used to point to the next node
     * @param prev_node_ptr to be used to point to the previous node
     */
    Node(const ItemType &an_item, const std::shared_ptr<Node<ItemType>> &next_node_ptr, const std::shared_ptr<Node<ItemType>> &prev_node_ptr);

    /**
     * @brief sets the item to be held by the node
     *
     * @param an_item to be held by the node
     */
    void setItem(const ItemType &an_item);

    /**
     * @brief sets the pointer to the next node in the chain
     *
     * @param next_node_ptr to point to the next node in the chain
     */
    void setNext(const std::shared_ptr<Node<ItemType>> next_node_ptr);

    /**
     * @brief sets the pointer to the previous node in the chain
     *
     * @param prev_node_ptr to point to the previous node in the chain
     */
    void setPrevious(const std::shared_ptr<Node<ItemType>> prev_node_ptr);

    /**
     * @brief gets the item held by the node
     *
     * @return the object held by the node
     */
    ItemType getItem() const;

    /**
     * @brief gets the pointer to the next node in the chain
     *
     * @return the pointer to the next node in the chain
     */
    std::shared_ptr<Node<ItemType>> getNext() const;

    /**
     * @brief gets the pointer to the previous node in the chain
     *
     * @return the pointer to the next node in the chain
     */
    std::shared_ptr<Node<ItemType>> getPrevious() const;

private:
    ItemType item_;
    std::shared_ptr<Node<ItemType>> next_;
    std::shared_ptr<Node<ItemType>> prev_;
};

#include "Node.cpp"
#endif