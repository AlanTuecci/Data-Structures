/**
 * @file ArrayBag.hpp
 * @author Alan Tuecci (Alan.Tuecci@hotmail.com)
 * @brief Implementation for ArrayBag class
 * @version 0.2
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
ArrayBag<ItemType>::ArrayBag() : item_count_{0}, array_capacity_{DEFAULT_ARRAY_SIZE_}
{
    elements_ = std::shared_ptr<ItemType[]>(new ItemType[array_capacity_]);
}

/**
 * @brief parameterized constructor
 *
 * @param array_size whose value will determine the capacity of the array size at instantiation time
 */
template <class ItemType>
ArrayBag<ItemType>::ArrayBag(const int &array_size) : item_count_{0}, array_capacity_{array_size}
{
    elements_ = std::shared_ptr<ItemType[]>(new ItemType[array_capacity_]);
}

/**
 * @brief gets the current size of elements_
 *
 * @return the current size of the bag
 */
template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return item_count_;
}

/**
 * @brief gets the current capacity of elements_
 *
 * @return the current capacity of elements_
 */
template <class ItemType>
int ArrayBag<ItemType>::getCurrentCapacity() const
{
    return array_capacity_;
}

/**
 * @brief Get the Frequency of object
 *
 * @param an_entry whose intances in elements_ are to be counted up
 * @return int - the number of times an_entry is found
 */
template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &an_entry) const
{
    int frequency = 0;
    int curr_index = 0;
    while (curr_index < item_count_)
    {
        if (elements_[curr_index] == an_entry)
        {
            frequency++;
        }
        curr_index++;
    }

    return frequency;
}

/**
 * @brief checks if elements_ is empty
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
 * @param an_entry to be located in elements_
 * @return true if an_entry is found in elements_,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}

/**
 * @brief adds new_entry at the end of elements_
 *
 * @param new_entry to insert into elements_
 * @return true as long as there is available RAM on the system since the array's size can increase
 */
template <class ItemType>
bool ArrayBag<ItemType>::push_back(const ItemType &new_entry)
{
    if (item_count_ >= array_capacity_)
    {
        // Double the array capacity
        array_capacity_ = array_capacity_ << 1;

        // Allocate new space
        std::shared_ptr<ItemType[]> new_elements = std::shared_ptr<ItemType[]>(new ItemType[array_capacity_]);

        // Copy contents of old array into new array
        for (int i = 0; i < item_count_; i++)
        {
            new_elements[i] = elements_[i];
        }

        // Add new_entry at the back of the new array and update item_count_
        new_elements[item_count_] = new_entry;
        item_count_++;

        // Deallocate the old array and replace it with the new array
        elements_ = new_elements;
    }
    else
    {
        // Add new_entry at the back of the new array and update item_count_
        elements_[item_count_] = new_entry;
        item_count_++;
    }
    return true;
}

/**
 * @brief removes the last entry in the array
 *
 * @return true if the last entry in the array was removed,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::pop_back()
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        item_count_--;
    }
}

/**
 * @brief finds and removes an_entry from elements_
 *
 * @param an_entry to be removed
 * @return true if an_entry was successfully removed from elements_,
 * @return false otherwise
 */
template <class ItemType>
bool ArrayBag<ItemType>::removeInstanceOf(const ItemType &an_entry)
{
    int move_index = getIndexOf(an_entry);
    bool can_remove = !isEmpty() && (move_index > -1);
    if (can_remove)
    {
        for (int i = move_index + 1; i < item_count_; i++)
        {
            elements_[move_index] = elements_[i];
            move_index++;
        }
        item_count_--;
    }
    return can_remove;
}

/**
 * @brief makes the array empty
 *
 * @post does not actually empty the contents of elements_, but allows for them to be overwritten
 */
template <class ItemType>
void ArrayBag<ItemType>::clear()
{
    item_count_ = 0;
}

/**
 * @brief Allows direct element access using the [] operator
 *
 * @param i is the index in the array
 * @note Bounds-checking is NOT performed -> Be sure to avoid using indexes greater than or equal to item_count_
 * @return a copy of the item at the location specified by the parameter
 */
template <class ItemType>
ItemType ArrayBag<ItemType>::operator[](int i) const
{
    return elements_[i];
}

/**
 * @brief Allows direct element access using the [] operator
 *
 * @param i is the index in the array
 * @note Bounds-checking is NOT performed -> Be sure to avoid using indexes greater than or equal to item_count_
 * @return a reference to the item at the location specified by the parameter
 */
template <class ItemType>
ItemType &ArrayBag<ItemType>::operator[](int i)
{
    return elements_[i];
}

//********* PRIVATE METHODS **************//

/**
 * @brief Get the index of target in elements_
 *
 * @param target to be found in elements_
 * @return either the index target in elements_,
 * @return -1 if elements_ does not contain the target
 */
template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    while (!found && (search_index < item_count_))
    {
        if (elements_[search_index] == target)
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
