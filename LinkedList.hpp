#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <string>
#include "LinkedListFunctions.hpp"

//struct LinkedListNode{};

class LinkedList
{
private:
    LinkedListNode* head{nullptr};

public:
    LinkedList();
    ~LinkedList();

    std::string convert_linked_list_to_string();

    void add_item_to_beginning_of_list(int value);

    void add_item_to_end_of_list(int value);

    void remove_first_item_in_list();

    void remove_last_item_in_list();

    void remove_all_instances_of_item_from_list(int value);

    void clear_linked_list();
};



#endif
