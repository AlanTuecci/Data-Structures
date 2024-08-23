/**
 * @file DoublyLinkedList.hpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Interface for DoublyLinkedList class
 * @version 0.1
 * @date 2024-08-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <algorithm>
#include <memory>
#include "../Node/Node.hpp"

template <class ItemType>
class DoublyLinkedList
{
public:
    /**
     * @brief default constructor
     *
     */
    DoublyLinkedList();

    /**
     * @brief copy constructor
     *
     * @param a_list to be copied
     */
    DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list);

    /**
     * @brief checks if the list is empty
     *
     * @return true if the list is empty,
     * @return false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief gets the length of the list
     *
     * @return the number of nodes in the list
     */
    size_t getLength() const;

    /**
     * @brief gets the item at a position
     *
     * @pre 0 <= position < item_count_
     * @param position of the item to be retrieved
     * @return the item at position in list if there is one, otherwise it throws exception: PrecondViolatedExcep
     */
    ItemType getItem(const size_t &position) const;

    /**
     * @brief gets the pointer to node at a position
     *
     * @param position of node
     * @return pointer to a node,
     * @return std::shared_ptr<Node<ItemType>>(nullptr) if position > item_count_
     */
    std::shared_ptr<Node<ItemType>> getPointerTo(const size_t &position) const;

    /**
     * @brief gets the first node in the list
     *
     * @return the first node in the list
     */
    std::shared_ptr<Node<ItemType>> getHeadNode() const;

    /**
     * @brief gets the last node in the list
     *
     * @return the last node in the list
     */
    std::shared_ptr<Node<ItemType>> getTailNode() const;

    /**
     * @brief inserts an item at a position
     *
     * @param position indicating point of insertion
     * @param new_element to be inserted in list
     * @post new_element is added at position in list (the node previously at that position is now at position+1)
     * @return true always - it always inserts, if position > item_count_, then it inserts at end of list
     */
    bool insert(const size_t &position, const ItemType &new_element);

    /**
     * @brief inserts an item at the end of the list
     *
     * @param new_element to be inserted in list
     * @post new_element is added at the end of the list
     * @return true always - it always inserts
     */
    bool push_back(const ItemType &new_element);

    /**
     * @brief inserts an item at the front of the list
     *
     * @param new_element to be inserted in list
     * @post new_element is added at the front of the list
     * @return true always - it always inserts
     */
    bool push_front(const ItemType &new_element);

    /**
     * @brief deletes a node at a position
     *
     * @param position indicating point of deletion
     * @post node at position is deleted, if any. List order is retained
     * @return true if there is a node at position to be deleted,
     * @return false otherwise
     */
    bool remove(const size_t &position);

    /**
     * @brief deletes the last node
     *
     * @post the last node is deleted, if any. List order is retained
     * @return true if there is a node to be deleted,
     * @return false otherwise
     */
    bool pop_back();

    bool pop_front();

    /**
     * @brief deletes all nodes in the list and item_count_ is set to 0
     */
    void clear();

    /**
     * @brief prints the contents of the list
     *
     */
    void display();

    /**
     * @brief swaps the nodes at positions i and j (i must be less than j)
     *
     * @pre i < j
     * @param i is the index (integer) of the first item we are swapping in the list
     * @param j is the index (integer) of the second item we are swapping in the list
     * @post swaps the element at position i with the element at position j
     * @example we have [1,2,3,4,5] in our list, so calling swap(1,2) will make it [1,3,2,4,5] (note: we start from index 0)
     */
    void swap(const int &i, const int &j);

private:
    std::shared_ptr<Node<ItemType>> first_;
    std::shared_ptr<Node<ItemType>> last_;
    size_t item_count_;
};

#include "DoublyLinkedList.cpp"
#endif