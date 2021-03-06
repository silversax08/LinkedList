#ifndef LINKEDLISTFUNCTIONS_HPP
#define LINKEDLISTFUNCTIONS_HPP
#include <string>

struct LinkedListNode
{
 int item{0};
 LinkedListNode* nextNode{nullptr};
};

namespace private_functions {

std::string convert_linked_list_to_string(LinkedListNode* head);

void add_item_to_beginning_of_list(LinkedListNode* &head, int value);

void add_item_to_end_of_list(LinkedListNode* &head, int value);

void remove_first_item_in_list(LinkedListNode* &head);

void remove_last_item_in_list(LinkedListNode* &head);

void remove_all_instances_of_item_from_list(LinkedListNode* &head, int value);

void clear_linked_list(LinkedListNode* &head);

}

void add_values_to_string_with_spacing_between(LinkedListNode* &head, std::string &linkedListString);

void clear_one_element_list(LinkedListNode* &head);

void remove_next_value(LinkedListNode* &head);

bool clear_beginning_of_list_until_it_hits_a_number_that_is_not_the_specified_value(LinkedListNode* &head, int value);

bool delete_multiple_of_the_same_value_that_are_in_sequence(int &value, LinkedListNode* &temp, LinkedListNode* &originMinusOne);

bool look_in_middle_of_list_for_value_and_delete_if_found(int &value, LinkedListNode* &temp, LinkedListNode* &origin, LinkedListNode* &originMinusOne);

#endif // LINKEDLISTFUNCTIONS_HPP
