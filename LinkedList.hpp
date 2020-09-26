#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <string>

struct LinkedListNode
{
 int item{0};
 LinkedListNode* nextNode{nullptr};
};

std::string convert_linked_list_to_string(LinkedListNode* head);

//void add_item_to_beginning_of_list(int *head, int value);

//void add_item_to_end_of_list(int *head, int value);

//void remove_first_item_in_list(int *head);

//void remove_last_item_in_list(int *head);

//void remove_all_instances_of_item_from_list(int *head, int value);

//void clear_linked_list(int *head);

#endif
