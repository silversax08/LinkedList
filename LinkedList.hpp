#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <string>

struct LinkedListNode
{
 int item{0};
 LinkedListNode* nextNode{nullptr};
};

std::string convert_linked_list_to_string(LinkedListNode* head);

void add_item_to_beginning_of_list(LinkedListNode* &head, int value);

void add_item_to_end_of_list(LinkedListNode* &head, int value);

void remove_first_item_in_list(LinkedListNode* &head);

void remove_last_item_in_list(LinkedListNode* &head);

void remove_all_instances_of_item_from_list(LinkedListNode* &head, int value);

void clear_linked_list(LinkedListNode* &head);

void add_values_to_string_with_spacing_between(LinkedListNode* &head, std::string &linkedListString);

#endif
