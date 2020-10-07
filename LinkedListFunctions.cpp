#include "LinkedListFunctions.hpp"
#include <string>
#include <iostream>

namespace private_functions {

std::string convert_linked_list_to_string(LinkedListNode* head)
{
    std::string linkedListString{""};

    if(head == nullptr)
        linkedListString="()";
    else
        add_values_to_string_with_spacing_between(head,linkedListString);

    return linkedListString;
}


void add_item_to_beginning_of_list(LinkedListNode* &head, int value)
{
    if(head == nullptr)
        head = new LinkedListNode{value,nullptr};
    else
    {
        LinkedListNode* newFirstNode{new LinkedListNode{value,head}};
        head = newFirstNode;
    }
}

void add_item_to_end_of_list(LinkedListNode* &head, int value)
{
    if(head == nullptr)
        head = new LinkedListNode{value,nullptr};
    else
    {
        LinkedListNode* placeholder{head};
        while(placeholder->nextNode != nullptr)
            placeholder = placeholder->nextNode;

        placeholder->nextNode = new LinkedListNode{value,nullptr};
    }
}

void remove_first_item_in_list(LinkedListNode* &head)
{
    if(head == nullptr)
        return;
    else if(head->nextNode == nullptr)
        clear_one_element_list(head);
    else
    {
        LinkedListNode* temp{head->nextNode};
        delete head;
        head = temp;
    }
}

void remove_last_item_in_list(LinkedListNode* &head)
{
    if(head==nullptr)
        return;
    else if(head->nextNode==nullptr)
        clear_one_element_list(head);
    else
    {
        LinkedListNode* temp{head};
        while(temp->nextNode->nextNode != nullptr)
            temp = temp -> nextNode;

        delete temp->nextNode->nextNode;
        temp->nextNode = nullptr;
    }
}

void remove_all_instances_of_item_from_list(LinkedListNode* &head, int value)
{
    if(head == nullptr)
        return;
    else
    {
        if(head->nextNode == nullptr && head->item == value)
        {
            clear_one_element_list(head);
        }
        else
        {
            if (clear_beginning_of_list_until_it_hits_a_number_that_is_not_the_specified_value(head,value)==false)
                return;

            LinkedListNode* temp{head};
            LinkedListNode* origin{nullptr};
            LinkedListNode* originMinusOne{head};

            if (look_in_middle_of_list_for_value_and_delete_if_found(value, temp, origin, originMinusOne) == false)
                return;

            if(temp->item == value)
                remove_next_value(origin->nextNode);
        }
    }

}

void clear_linked_list(LinkedListNode* &head)
{
    if(head == nullptr)
        return;
    else
        while(head != nullptr)
            remove_next_value(head);
}

}


void add_values_to_string_with_spacing_between(LinkedListNode* &head, std::string &linkedListString)
{
    LinkedListNode *whileLoopPosition{head};

    linkedListString="(";

    while(whileLoopPosition->nextNode!=nullptr)
    {
        linkedListString.append(std::to_string(whileLoopPosition->item));
        linkedListString.append(" ");
        whileLoopPosition=whileLoopPosition->nextNode;
    }

    linkedListString.append(std::to_string(whileLoopPosition->item));
    linkedListString.append(")");
}

void clear_one_element_list(LinkedListNode* &head)
{
    delete head->nextNode;
    head = nullptr;
}

void remove_next_value(LinkedListNode* &head)
{
    LinkedListNode* placeholder{head->nextNode};
    delete head;
    head = placeholder;
}

bool clear_beginning_of_list_until_it_hits_a_number_that_is_not_the_specified_value(LinkedListNode* &head, int value)
{
    if(head->nextNode != nullptr && head->item ==value)
    {
        while(head->item == value)
        {
            if(head->nextNode == nullptr)
            {
                clear_one_element_list(head);
                return false;
            }
            else
            {
                remove_next_value(head);
            }
        }
    }
    return true;
}

bool delete_multiple_of_the_same_value_that_are_in_sequence(int &value, LinkedListNode* &temp, LinkedListNode* &originMinusOne)
{
    while(temp->item == value)
    {
        if(temp->nextNode == nullptr)
        {
            delete temp->nextNode;
            originMinusOne->nextNode = nullptr;
            return false;
        }
        else
        {
            LinkedListNode* landing{temp->nextNode};
            delete originMinusOne->nextNode;
            originMinusOne->nextNode = landing;
            temp = originMinusOne->nextNode;
        }
    }
    return true;
}

bool look_in_middle_of_list_for_value_and_delete_if_found(int &value, LinkedListNode* &temp, LinkedListNode* &origin, LinkedListNode* &originMinusOne)
{
    while(temp->nextNode != nullptr)
    {
        originMinusOne = origin;
        origin = temp;

        if(temp->item != value)
            temp = origin->nextNode;
        else
            if (delete_multiple_of_the_same_value_that_are_in_sequence(value, temp, originMinusOne) == false)
                return false;
    }
    return true;
}
