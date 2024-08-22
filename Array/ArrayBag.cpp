/**
 * @file ArrayBag.hpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Implementation for ArrayBag class
 * @version 0.1
 * @date 2024-08-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "ArrayBag.hpp"

/**
 * @brief Parameterized Constructor
 */
template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : item_count_{0}
{
}

/**
 * @brief gets the current size of items_
 *
 * @return the current size of the bag
 */
template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

/**
 * @brief Get the Frequency of object
 *
 * @param an_entry whose intances in items_ are to be counted up
 * @return int - the number of times an_entry is found
 */
template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
    int frequency = 0;
    int curr_index = 0;
    while (curr_index < item_count_)
    {
        if (items_[curr_index] == an_entry)
        {
            frequency++;
        }
        curr_index++;
    }

    return frequency;
}

/**
 * @brief checks if items_ is empty
 *
 * @return true if item_count_ == 0,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return item_count_ == 0;
}

/**
 * @brief locates an_entry
 *
 * @param an_entry to be located in items_
 * @return true if an_entry is found in items_,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}

/**
 * @brief adds new_entry at the end of items_
 *
 * @param new_entry to insert into items_
 * @return true if new_entry was successfully added to items_,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &new_entry)
{
    bool has_room = (item_count_ < array_capacity_);
    if (has_room)
    {
        items_[item_count_] = new_entry;
        item_count_++;
        return true;
    }
    return false;
}

/**
 * @brief finds and removes an_entry from items_
 *
 * @param an_entry to be removed
 * @post moves the last entry of the array to the index of the removed item
 * @return true if an_entry was successfully removed from items_,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &an_entry)
{
    int found_index = getIndexOf(an_entry);
    bool can_remove = !isEmpty() && (found_index > -1);
    if (can_remove)
    {
        item_count_--;
        items_[found_index] = items_[item_count_];
    }
    return can_remove;
}

/**
 * @brief makes the array empty
 *
 * @post does not actually empty the contents of items_, but allows for them to be overwritten
 */
template <class ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}

/**
 * @brief combines the contents from both ArrayBag objects, INCLUDING duplicates, adding items from the argument bag as long as there is space
 *
 * @param array_bag_duplicate object whose contents are to be inserted into items_
 */
template <class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag &array_bag_duplicate)
{
    for (int i = 0; i < array_bag_duplicate.getCurrentSize(); i++)
    {
        bool has_room = (item_count_ < array_capacity_);
        if (has_room == true)
        {
            items_[item_count_] = array_bag_duplicate[i];
            item_count_++;
        }
        else
        {
            std::cout << "Insertion failed! " << i << " items from array_bag_duplicate have been added into the array!";
            break;
        }
    }
}

/**
 * @brief combines the contents from both ArrayBag objects, EXCLUDING duplicates, adding items from the argument bag as long as there is space
 *
 * @param array_bag_duplicate object whose contents are to be inserted into items_
 */
template <class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag &array_bag_duplicate)
{
    for (int i = 0; i < array_bag_duplicate.getCurrentSize(); i++)
    {
        if (contains(array_bag_duplicate[i]) == false)
        {
            add(array_bag_duplicate[i]);
        }
        else
        {
            std::cout << "Insertion failed! " << i << " items from array_bag_duplicate have been added into the array!";
            break;
        }
    }
}

//********* PRIVATE METHODS **************//

/**
 * @brief Get the index of target in items_
 *
 * @param target to be found in items_
 * @return either the index target in items_,
 * @return -1 if items_ does not contain the target
 */
template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    while (!found && (search_index < item_count_))
    {
        if (items_[search_index] == target)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        }
    }

    return result;
}
