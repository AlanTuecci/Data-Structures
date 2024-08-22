/**
 * @file ArrayBag.hpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Interface for ArrayBag class
 * @version 0.1
 * @date 2024-08-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include <iostream>

template <class ItemType>
class ArrayBag
{

public:
    /**
     * @brief Parameterized Constructor
     */
    ArrayBag();

    /**
     * @brief gets the current size of items_
     *
     * @return the current size of the bag
     */
    int getCurrentSize() const;

    /**
     * @brief Get the Frequency of object
     *
     * @param an_entry whose intances in items_ are to be counted up
     * @return int - the number of times an_entry is found
     */
    int getFrequencyOf(const ItemType &an_entry) const;

    /**
     * @brief checks if items_ is empty
     *
     * @return true if item_count_ == 0,
     * @return false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief locates an_entry
     *
     * @param an_entry to be located in items_
     * @return true if an_entry is found in items_,
     * @return false otherwise
     */
    bool contains(const ItemType &an_entry) const;

    /**
     * @brief adds new_entry into items_
     *
     * @param new_entry to insert into items_
     * @return true if new_entry was successfully added to items_,
     * @return false otherwise
     */
    bool add(const ItemType &new_entry);

    /**
     * @brief finds and removes an_entry from items_
     *
     * @param an_entry to be removed
     * @post moves the last entry of the array to the index of the removed item
     * @return true if an_entry was successfully removed from items_,
     * @return false otherwise
     */
    bool remove(const ItemType &an_entry);

    /**
     * @brief makes the array empty
     *
     * @post does not actually empty the contents of items_, but allows for them to be overwritten
     */
    void clear();

    /**
     * @brief combines the contents from both ArrayBag objects, INCLUDING duplicates, adding items from the argument bag as long as there is space
     *
     * @param array_bag_duplicate object whose contents are to be inserted into items_
     */
    void operator+=(const ArrayBag &array_bag_duplicate);

    /**
     * @brief combines the contents from both ArrayBag objects, EXCLUDING duplicates, adding items from the argument bag as long as there is space
     *
     * @param array_bag_duplicate object whose contents are to be inserted into items_
     */
    void operator/=(const ArrayBag &array_bag_duplicate);

protected:
    static const int array_capacity_ = 100;
    ItemType items_[array_capacity_];
    int item_count_;

    /**
     * @brief Get the index of target in items_
     *
     * @param target to be found in items_
     * @return either the index target in items_,
     * @return -1 if items_ does not contain the target
     */
    int getIndexOf(const ItemType &target) const;
};

#include "ArrayBag.cpp"
#endif