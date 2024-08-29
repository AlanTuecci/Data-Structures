/**
 * @file ArrayBag.hpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Interface for ArrayBag class
 * @version 0.2
 * @date 2024-08-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include <iostream>
#include <memory>

template <class ItemType>
class ArrayBag
{

public:
    /**
     * @brief default Constructor
     */
    ArrayBag();

    /**
     * @brief parameterized constructor
     *
     * @param array_size whose value will determine the capacity of the array size at instantiation time
     */
    ArrayBag(const int &array_size);

    /**
     * @brief gets the current size of elements_
     *
     * @return the current size of the bag
     */
    int getCurrentSize() const;

    /**
     * @brief gets the current capacity of elements_
     *
     * @return the current size of the bag
     */
    int getCurrentCapacity() const;

    /**
     * @brief gets the frequency of an object
     *
     * @param an_entry whose intances in elements_ are to be counted up
     * @return the number of times an_entry is found
     */
    int getFrequencyOf(const ItemType &an_entry) const;

    /**
     * @brief checks if elements_ is empty
     *
     * @return true if item_count_ == 0,
     * @return false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief locates an_entry
     *
     * @param an_entry to be located in elements_
     * @return true if an_entry is found in elements_,
     * @return false otherwise
     */
    bool contains(const ItemType &an_entry) const;

    /**
     * @brief adds new_entry into elements_
     *
     * @param new_entry to insert into elements_
     * @return true if new_entry was successfully added to elements_,
     * @return false otherwise
     */
    bool push_back(const ItemType &new_entry);

    /**
     * @brief removes the last entry in the array
     *
     * @return true if the last entry in the array was removed,
     * @return false otherwise
     */
    bool pop_back();

    /**
     * @brief finds and removes an_entry from elements_
     *
     * @param an_entry to be removed
     * @post moves the last entry of the array to the index of the removed item
     * @return true if an_entry was successfully removed from elements_,
     * @return false otherwise
     */
    bool removeInstanceOf(const ItemType &an_entry);

    /**
     * @brief makes the array empty
     *
     * @post does not actually empty the contents of elements_, but allows for them to be overwritten
     */
    void clear();

    /**
     * @brief Allows direct element access using the [] operator
     *
     * @param i is the index in the array
     * @note Bounds-checking is NOT performed -> Be sure to avoid using indexes greater than or equal to item_count_
     * @return a copy of the item at the location specified by the parameter
     */
    ItemType operator[](int i) const;

    /**
     * @brief Allows direct element access using the [] operator
     *
     * @param i is the index in the array
     * @note Bounds-checking is NOT performed -> Be sure to avoid using indexes greater than or equal to item_count_
     * @return a reference to the item at the location specified by the parameter
     */
    ItemType &operator[](int i);

protected:
    static const int DEFAULT_ARRAY_SIZE_ = 1;

    int array_capacity_;
    int item_count_;
    std::shared_ptr<ItemType[]> elements_;

    /**
     * @brief Get the index of target in elements_
     *
     * @param target to be found in elements_
     * @return either the index target in elements_,
     * @return -1 if elements_ does not contain the target
     */
    int getIndexOf(const ItemType &target) const;
};

#include "ArrayBag.cpp"
#endif