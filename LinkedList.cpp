#include "LinkedListFunctions.hpp"
#include "LinkedList.hpp"
#include <string>

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{
    private_functions::clear_linked_list(head);
}

std::string LinkedList::convert_linked_list_to_string()
{
   return private_functions::convert_linked_list_to_string(head);
}

void LinkedList::add_item_to_beginning_of_list(int value)
{
    private_functions::add_item_to_beginning_of_list(head,value);
}

void LinkedList::add_item_to_end_of_list(int value)
{
    private_functions::add_item_to_end_of_list(head, value);
}

void LinkedList::remove_first_item_in_list()
{
    private_functions::remove_first_item_in_list(head);
}

void LinkedList::remove_last_item_in_list()
{
    private_functions::remove_last_item_in_list(head);
}

void LinkedList::remove_all_instances_of_item_from_list(int value)
{
    private_functions::remove_all_instances_of_item_from_list(head, value);
}

void LinkedList::clear_linked_list()
{
    private_functions::clear_linked_list(head);
}
