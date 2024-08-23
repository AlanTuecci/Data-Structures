/**
 * @file DoublyLinkedList.cpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Implementation for DoublyLinkedList class
 * @version 0.1
 * @date 2024-08-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "DoublyLinkedList.hpp"

/**
 * @brief default constructor
 *
 */
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() : item_count_{0},
                                                 first_{std::shared_ptr<Node<ItemType>>(nullptr)},
                                                 last_{std::shared_ptr<Node<ItemType>>(nullptr)}
{
}

/**
 * @brief copy constructor
 *
 * @param a_list to be copied
 */
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType> &a_list)
{
    item_count_ = a_list.item_count_;
    std::shared_ptr<Node<ItemType>> orig_chain_ptr = a_list.first_;

    if (orig_chain_ptr == nullptr)
    {
        first_ = std::shared_ptr<Node<ItemType>>(nullptr);
        last_ = std::shared_ptr<Node<ItemType>>(nullptr);
    }
    else
    {
        // Copy first node
        first_ = std::make_shared<Node<ItemType>>();
        first_->setPrevious(std::shared_ptr<Node<ItemType>>(nullptr));
        first_->setItem(orig_chain_ptr->getItem());

        // Copy remaining nodes
        std::shared_ptr<Node<ItemType>> new_chain_ptr = first_; // Points to last node in new chain
        orig_chain_ptr = orig_chain_ptr->getNext();             // Advance original-chain pointer

        while (orig_chain_ptr != nullptr)
        {
            // Get next item from original chain
            ItemType next_item = orig_chain_ptr->getItem();

            // Create a new node containing the next item
            std::shared_ptr<Node<ItemType>> new_node_ptr = std::make_shared<Node<ItemType>>(next_item);

            // Link new node to end of new chain
            new_chain_ptr->setNext(new_node_ptr);
            new_node_ptr->setPrevious(new_chain_ptr);

            // Advance pointer to new last node
            new_chain_ptr = new_chain_ptr->getNext();

            // Advance original chain pointer
            orig_chain_ptr = orig_chain_ptr->getNext();
        }

        // Flag end of chain
        new_chain_ptr->setNext(std::shared_ptr<Node<ItemType>>(nullptr));
        last_ = new_chain_ptr;
    }
}

/**
 * @brief checks if the list is empty
 *
 * @return true if the list is empty,
 * @return false otherwise
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

/**
 * @brief gets the length of the list
 *
 * @return the number of nodes in the list
 */
template <class ItemType>
size_t DoublyLinkedList<ItemType>::getLength() const
{
    return item_count_;
}

/**
 * @brief gets the item at a position
 *
 * @pre 0 <= position < item_count_
 * @param position of the item to be retrieved
 * @return the item at position in list if there is one, otherwise it throws exception: PrecondViolatedExcep
 */
template <class ItemType>
ItemType DoublyLinkedList<ItemType>::getItem(const size_t &position) const
{
    if (0 <= position && position < item_count_)
    {
        std::shared_ptr<Node<ItemType>> pos_ptr = getPointerTo(position);
        return pos_ptr->getItem();
    }
    else
    {
        throw std::runtime_error("PrecondViolatedExcep");
    }
}

/**
 * @brief gets the pointer to node at a position
 *
 * @param position of node
 * @return pointer to a node,
 * @return std::shared_ptr<Node<ItemType>>(nullptr) if position > item_count_
 */
template <class ItemType>
std::shared_ptr<Node<ItemType>> DoublyLinkedList<ItemType>::getPointerTo(const size_t &position) const
{
    if (position < item_count_)
    {
        std::shared_ptr<Node<ItemType>> find = std::make_shared<Node<ItemType>>();
        find = first_;
        for (size_t i = 0; i < position; i++)
        {
            find = find->getNext();
        }
        return find;
    }
    else
    {
        return std::shared_ptr<Node<ItemType>>(nullptr);
    }
}

/**
 * @brief gets the first node in the list
 *
 * @return the first node in the list
 */
template <class ItemType>
std::shared_ptr<Node<ItemType>> DoublyLinkedList<ItemType>::getHeadNode() const
{
    return first_;
}

/**
 * @brief gets the last node in the list
 *
 * @return the last node in the list
 */
template <class ItemType>
std::shared_ptr<Node<ItemType>> DoublyLinkedList<ItemType>::getTailNode() const
{
    return last_;
}

/**
 * @brief inserts an item at a position
 *
 * @param position indicating point of insertion
 * @param new_element to be inserted in list
 * @post new_element is added at position in list (the node previously at that position is now at position+1)
 * @return true always - it always inserts, if position > item_count_, then it inserts at end of list
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const size_t &position, const ItemType &new_element)
{
    // Create a new node containing the new entry and get a pointer to position
    std::shared_ptr<Node<ItemType>> new_node_ptr = std::make_shared<Node<ItemType>>(new_element);
    std::shared_ptr<Node<ItemType>> pos_ptr = getPointerTo(position);

    // Attach new node to chain
    if (first_ == nullptr)
    {
        // Chain is empty - insert first node
        new_node_ptr->setNext(std::shared_ptr<Node<ItemType>>(nullptr));
        new_node_ptr->setPrevious(nullptr);
        first_ = new_node_ptr;
        last_ = new_node_ptr;
    }
    else if (pos_ptr == first_)
    {
        // Insert new node at beginning of list
        new_node_ptr->setNext(first_);
        new_node_ptr->setPrevious(std::shared_ptr<Node<ItemType>>(nullptr));
        first_->setPrevious(new_node_ptr);
        first_ = new_node_ptr;
    }
    else if (pos_ptr == nullptr)
    {
        // Insert at end of list
        new_node_ptr->setNext(std::shared_ptr<Node<ItemType>>(nullptr));
        new_node_ptr->setPrevious(last_);
        last_->setNext(new_node_ptr);
        last_ = new_node_ptr;
    }
    else
    {
        // Insert new node before node to which pos_ptr points to
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrevious(pos_ptr->getPrevious());
        pos_ptr->getPrevious()->setNext(new_node_ptr);
        pos_ptr->setPrevious(new_node_ptr);
    }

    // Increase count of entries
    item_count_++;

    // It will always insert
    return true;
}

/**
 * @brief inserts an item at the end of the list
 *
 * @param new_element to be inserted in list
 * @post new_element is added at the end of the list
 * @return true always - it always inserts
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::push_back(const ItemType &new_element)
{
    return insert(item_count_, new_element);
}

/**
 * @brief inserts an item at the front of the list
 *
 * @param new_element to be inserted in list
 * @post new_element is added at the front of the list
 * @return true always - it always inserts
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::push_front(const ItemType &new_element)
{
    return insert(0, new_element);
}

/**
 * @brief deletes a node at a position
 *
 * @param position indicating point of deletion
 * @post node at position is deleted, if any. List order is retained
 * @return true if there is a node at position to be deleted,
 * @return false otherwise
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const size_t &position)
{
    // Get pointer to position
    std::shared_ptr<Node<ItemType>> pos_ptr = getPointerTo(position);

    if (pos_ptr == std::shared_ptr<Node<ItemType>>(nullptr))
    {
        return false;
    }
    else
    {
        // Remove node from chain

        if (first_ == last_)
        {
            // Single node in list
            first_ = std::shared_ptr<Node<ItemType>>(nullptr);
            last_ = std::shared_ptr<Node<ItemType>>(nullptr);

            // Deallocation not necessary since using smart pointers
        }
        else if (pos_ptr == first_)
        {
            // Remove first node
            first_ = pos_ptr->getNext();
            first_->setPrevious(std::shared_ptr<Node<ItemType>>(nullptr));

            // Deallocation not necessary since using smart pointers
        }
        else if (pos_ptr == last_)
        {
            // Remove last node
            last_ = pos_ptr->getPrevious();
            last_->setNext(std::shared_ptr<Node<ItemType>>(nullptr));

            // Deallocation not necessary since using smart pointers
        }
        else
        {
            // Remove node from somewhere in the middle
            pos_ptr->getPrevious()->setNext(pos_ptr->getNext());
            pos_ptr->getNext()->setPrevious(pos_ptr->getPrevious());

            // Deallocation not necessary since using smart pointers
        }

        item_count_--;
        return true;
    }
}

/**
 * @brief deletes the last node
 *
 * @post the last node is deleted, if any. List order is retained
 * @return true if there is a node to be deleted,
 * @return false otherwise
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::pop_back()
{
    return remove(item_count_ - 1);
}

/**
 * @brief deletes the first node
 *
 * @post the first node is deleted, if any. List order is retained
 * @return true if there is a node to be deleted,
 * @return false otherwise
 */
template <class ItemType>
bool DoublyLinkedList<ItemType>::pop_front()
{
    return remove(0);
}

/**
 * @brief deletes all nodes in the list and item_count_ is set to 0
 */
template <class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    std::shared_ptr<Node<ItemType>> node_to_delete = first_;
    while (first_ != nullptr)
    {
        first_ = first_->getNext();

        // Return node to the system
        node_to_delete->setNext(std::shared_ptr<Node<ItemType>>(nullptr));
        node_to_delete->setPrevious(std::shared_ptr<Node<ItemType>>(nullptr));

        node_to_delete = first_;
    }
    // head_ is nullptr; node_to_delete is nullptr
    last_ = nullptr;
    item_count_ = 0;
}

/**
 * @brief prints the contents of the list
 *
 */
template <class ItemType>
void DoublyLinkedList<ItemType>::display()
{
    if (getLength() == 0)
    {
        return;
    }
    std::shared_ptr<Node<ItemType>> iterator = first_;
    while (iterator != std::shared_ptr<Node<ItemType>>(nullptr))
    {
        if (iterator->getNext() == nullptr)
        {
            std::cout << iterator->getItem() << std::endl;
        }
        else
        {
            std::cout << iterator->getItem() << " ";
        }
        iterator = iterator->getNext();
    }
    return;
}

/**
 * @brief swaps the nodes at positions i and j (i must be less than j)
 *
 * @pre i < j
 * @param i is the index (integer) of the first item we are swapping in the list
 * @param j is the index (integer) of the second item we are swapping in the list
 * @post swaps the element at position i with the element at position j
 * @example we have [1,2,3,4,5] in our list, so calling swap(1,2) will make it [1,3,2,4,5] (note: we start from index 0)
 */
template <class ItemType>
void DoublyLinkedList<ItemType>::swap(const int &i, const int &j)
{
    if (i < j)
    {
        std::shared_ptr<Node<ItemType>> first = getPointerTo(i);
        std::shared_ptr<Node<ItemType>> second = getPointerTo(j);

        ItemType first_item = first->getItem();
        ItemType second_item = second->getItem();

        first->setItem(second_item);
        second->setItem(first_item);
    }
}