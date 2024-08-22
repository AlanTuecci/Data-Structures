#include "Node.hpp"

/**
 * @brief default constructor
 */
template <class ItemType>
Node<ItemType>::Node() : next_
{
}

/**
 * @brief parameterized constructor
 *
 * @param an_item to be inserted into the node
 */
template <class ItemType>
Node<ItemType>::Node(const ItemType &an_item) {}

/**
 * @brief parameterized constructor
 *
 * @param an_item to be inserted into the node
 * @param next_node_ptr to be used to point to the next node
 */
template <class ItemType>
Node<ItemType>::Node(const ItemType &an_item, std::shared_ptr<Node<ItemType>> next_node_ptr) {}

/**
 * @brief sets the item to be held by the node
 *
 * @param an_item to be held by the node
 */
template <class ItemType>
void Node<ItemType>::setItem(const ItemType &an_item) {}

/**
 * @brief sets the pointer to the next node in the chain
 *
 * @param next_node_ptr to point to the next node in the chain
 */
template <class ItemType>
void Node<ItemType>::setNext(const std::shared_ptr<Node<ItemType>> next_node_ptr) {}

/**
 * @brief sets the pointer to the previous node in the chain
 *
 * @param prev_node_ptr to point to the previous node in the chain
 */
template <class ItemType>
void Node<ItemType>::setPrevious(const std::shared_ptr<Node<ItemType>> prev_node_ptr) {}

/**
 * @brief gets the item held by the node
 *
 * @return the object held by the node
 */
template <class ItemType>
ItemType Node<ItemType>::getItem() const {}

/**
 * @brief gets the pointer to the next node in the chain
 *
 * @return the pointer to the next node in the chain
 */
template <class ItemType>
std::shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const {}

/**
 * @brief gets the pointer to the previous node in the chain
 *
 * @return the pointer to the next node in the chain
 */
template <class ItemType>
std::shared_ptr<Node<ItemType>> Node<ItemType>::getPrev() const {}