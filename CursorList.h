//============================================================================
// Name        : CursorList.h
// Author      : Alexander M. Westphal / Paul Schröder
// Version     : Version 1.0
// Copyright   : Alexander M. Westphal / Paul Schröder
// Description : CursorList Template Class
//============================================================================

#ifndef ALGODAT_CURSORLIST_H
#define ALGODAT_CURSORLIST_H

#include "student.h"
#include <iostream>
#include <iterator>

template <typename T> class CursorList {

public:
    typedef T valuetype;
    const static int array_size_start = 30;
    int start_data = -1;
    int start_free = 0;
    int counter = 0;

    /**
     * Struct Element to represent a Element(Row) in the LinkedList.
     * A zeile-Element consists of a Generic Data Object, a previous Index and a next Index.
     * Previous will indicate the previous zeile-Element.
     * Next will indicate the next zeile-Element.
     */
    struct zeile {
    public:
        T data;
        int prev;
        int next;

        zeile(){};
        zeile(int inputPrev, int inputNext){
            prev = inputPrev;
            next = inputNext;
        }
    };

    zeile arr[array_size_start];

    /**
     * Inner-Class ListIterator.
     * Class to implement a Iterator for the LinkedList.
     */
    class ListIterator {
        typedef ListIterator iterator;

    public:
        int m_index;
        zeile *m_el;
        /**
         * Constuctor of the Inner-class ListIterator
         * @param index will indcate the index of the iterator
         * @param el will be a pointer, pointing on the element in the List.
         */
        ListIterator(int index, zeile *el) {
            m_index = index;
            m_el = el;
        }

        /**
         * Overloading the * operator
         * @return will return the Data of a zeile-object.
         */
        T& operator *() {
            return m_el[m_index].data;
        }

        /**
         *
         * @param rhs
         * @return
         */
        iterator& operator = (const iterator& rhs){
            m_el = rhs.m_el;
            m_index = rhs.m_index;
        }

        /**
         * Comparing a iterator with another iterator on inequality.
         * @param rhs the iterator to compare as const.
         * @return will return true in case the iterator a not the same.
         */
        bool operator != (const iterator& rhs) const{
            return  m_el != rhs.m_el || m_index != rhs.m_index;
        }

        /**
         * Comparing a iterator with another iterator on equality.
         * @param rhs the iterator to compare as const.
         * @return will return true in case the iterator a the same.
         */
        bool operator == (const iterator& rhs) const{
            return m_el == rhs.m_el || m_index == rhs.m_index;
        }

        /**
         * will postincrement a iterator.
         * @return will return a postincremented iterator.
         */
        iterator& operator ++(){
            m_index = m_el[m_index].next;
            return *this;
        }

        /**
         * Will preincrement a iterator.
         * @return will return a preincremented iterator.
         */
        iterator operator ++(int){
            ListIterator clone (m_index, m_el);
            ++(*this);
            return clone;
        }
    };

    typedef ListIterator iterator;

    /**
     * Constructor for the CursorList-Class.
     */
    CursorList() {
        for (int i = 0; i < array_size_start - 1; i++) {
            arr[i] = zeile(i - 1, i + 1);
        }
        arr[array_size_start] = zeile(array_size_start - 1, -1);
    }

    /**
     * Method to check whether a List is Empty.
     * @return will return true in case it is empty else false.
     */
    bool empty() {
        return counter == 0;
    }

    /**
     * Method to Return the size of the List.
     * @return will return the size a int-value
     */
    int size() {
        return counter;
    }

    /**
     * Will return the first element in the LinkedList
     * In case the List is Empty it will return a NullPointer
     * @return
     */
    T& front() {
        return *begin();
    }

    /**
     * Method to put a Student in front of the List.
     * Given student will be put on the first position of the List.
     * So the start_Data will point on this given Student.
     * @param stud will be the student-object to add into the List.
     * Will throw a Exception in case the list is full and unable to store a new Student.
     */
    void push_front(T para){
        int next_free = arr[start_free].next;
        if (empty()){
            set_counter(get_counter() + 1);
            start_data = start_free;
            arr[start_data].data = para;
            arr[start_data].prev = -1;
            arr[start_data].next = -1;
            start_free = next_free;
        } else  {
            set_counter(get_counter() + 1);
            arr[start_data].prev = start_free;
            arr[start_free].data = para;
            arr[start_free].prev = -1;
            arr[start_free].next = start_data;
            start_data = start_free;
            start_free = next_free;
        }
    }

    /**
     * Method to delete the first Element of the LinkedList.
     * The former second element will be the new start_Data and first Element of the List.
     */
    void pop_front(){
        if (!empty()){
            if (get_counter() == 1){
                set_counter(get_counter() - 1);
                einhaengen_free(start_data);
                start_data = -1;
            }else {
                set_counter(get_counter() - 1);
                int new_start_data = arr[start_data].next;
                einhaengen_free(start_data);
                start_data = new_start_data;
            }
        } else {
            throw std::runtime_error( "The List is already empty " );
        }
    }

    /**
     * Method to put a new Element in front of the free_Space_list.
     * @param current will be the current Index.
     */
    void einhaengen_free(int current){
        arr[start_free].prev = current;
        arr[current].next = start_free;
        arr[current].prev = -1;
        start_free = current;
    }

    /**
     * Will return the first element in the Iterator.
     * @return so the index and the zeile-Element.
     */
    iterator begin(){
        return iterator(start_data, arr);
    }

    /**
     * Method to get the end of a iterator.
     * @return will return the end as an int-value (-1).
     */
    iterator end() {
        return iterator(-1, arr);
    }

    /**
     * Method to insert something at a specifed position.
     * @param itr where to insert.
     * @param value what to insert.
     * @return will return a iterator pointing on the inserted object.
     */
    iterator insert(iterator itr, T& value) {
    if (empty() || itr == begin()){
        push_front(value);
        return begin();
    } else if (itr != begin() || itr != end()) {
        set_counter(get_counter() + 1);
        int save = arr[itr.m_index].prev; // 3
        int next_free = arr[start_free].next; // new free
        int save_next = arr[save].next;
        arr[start_free].data = value;
        arr[start_free].prev = save;
        arr[start_free].next = save_next;
        arr[save_next].prev = start_free;
        arr[save].next = start_free;
        start_free = next_free;
        arr[start_free].prev = -1;
    } else {
            set_counter(get_counter() + 1);
            for(iterator it = begin(); it != end(); ++it) {
                if (arr[it.m_index].next == -1){
                    int next_free = arr[start_free].next;
                    arr[start_free].data = value;
                    arr[start_free].prev = it.m_index;
                    arr[start_free].next = -1;
                    arr[it.m_index].next = start_free;
                    start_free = next_free;
                    arr[start_free].prev = -1;
                }
            }
        }
        return itr;
    }

    /**
     * Method to delete zeile-object from the linked-list.
     * @param start Startpoint to begin deleting
     * @param stop Stop to end deleting, is exclusive
     * @return will return a iterator pointing on the stop element.
     */
    iterator erase(iterator start, iterator stop) {
        int before_start = arr[start.m_index].prev;
        for(iterator it = start; it != stop; ++it) {
            set_counter(get_counter() - 1);
            einhaengen_free(it.m_index);
        }
        if (start == begin() && stop == end()){
            start_data = -1;
        } else if (start != begin() && stop != end()){
            arr[before_start].next = stop.m_index;
            arr[stop.m_index].prev = before_start;
        } else if (start == begin() && stop != end()) {
            start_data = stop.m_index;
            arr[start_data].prev = -1;
        } else {
            arr[before_start].next = -1;
        }
        return stop;
    };

    /**
     * Method to delete a zeile-object at a specified position.
     * @param itr position to delete the object
     * @return will return a iterator.
     */
    iterator erase(iterator itr) {
        if (itr.m_index == start_data) {
            ++itr;
            pop_front();
            return itr;
        } else {
            int posToDelete = itr.m_index;
            int posBeforeDelete = arr[itr.m_index].prev;
            int posAfterDelete = arr[itr.m_index].next;

            ++itr;

            arr[posBeforeDelete].next = posAfterDelete;
            arr[posAfterDelete].prev = posBeforeDelete;
            arr[posToDelete].prev = -1;
            arr[posToDelete].next = start_free;
            arr[start_free].prev = posToDelete;
            start_free = posToDelete;

            return itr;
        }
    };

    /**
     * Setter for the counter.
     * @param i value to set the counter on.
     */
    void set_counter(int i){
        if(counter < 0 || counter > 30) {
            throw std::runtime_error( "Aktion kann nicht ausgefuehrt werden " );
        }
        counter = i;
    }

    /**
     * Getter for the Counter.
     * @return will return a int-value
     */
    int get_counter() {
        return counter;
    }

    /**
     * Method to get the value of a Template Object.
     * @param index index of the object
     * @return will return the object form the linkedlist.
     */
    T& get_value (int index){
        return arr[index].data;
    }

};

/**
 *  Method to find a object with the given value.
 * @tparam Iterator typename
 * @tparam T typename
 * @param start startpoint
 * @param stop endpoint
 * @param value value to search for
 * @return will retrun a iterator pointing on this value in the datastructur.
 */
template<typename Iterator, typename T>
Iterator find(Iterator start, Iterator stop, const T& value) {
    for(typename CursorList<T>::iterator it = start; it != stop; it++) {
        if(it.m_el[it.m_index].data == value) {
            return it;
        }
    }
        return stop;
}
#endif // ALGODAT_CURSORLIST_H