#include "LinkedList.hpp"
#include <string>
#include <iostream>

std::string convert_linked_list_to_string(LinkedListNode* head)
{
    std::string linkedListString{"("};
    LinkedListNode *while_loop_position;

    if(head==nullptr)
    {
    }
    else
    {
        while_loop_position=head;

        while(while_loop_position->nextNode!=nullptr)
        {
            linkedListString.append(std::to_string(while_loop_position->item));
            linkedListString.append(" ");
            while_loop_position=while_loop_position->nextNode;
        }
        linkedListString.append(std::to_string(while_loop_position->item));
    }

    linkedListString.append(")");

    return linkedListString;
}

void add_item_to_beginning_of_list(LinkedListNode* &head, int value)
{
    LinkedListNode* newFirstNode;

    if(head==nullptr)
    {
        head = new LinkedListNode{value,nullptr};
    }
    else
    {
        newFirstNode = new LinkedListNode{value,head};
        head = newFirstNode;
    }
}

void add_item_to_end_of_list(LinkedListNode* &head, int value)
{
    LinkedListNode *placeholder{head};

    if(head==nullptr)
    {
        head = new LinkedListNode{value,nullptr};
    }
    else
    {
        placeholder = head;
        while(placeholder->nextNode!=nullptr)
        {
            placeholder = placeholder->nextNode;
        }
        placeholder->nextNode = new LinkedListNode{value,nullptr};
    }
}

void remove_first_item_in_list(LinkedListNode* &head)
{
    LinkedListNode* temp;
    if(head==nullptr)
    {

    }
    else if(head->nextNode==nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        temp = head->nextNode;
        delete head;
        head = temp;
    }
}

void remove_last_item_in_list(LinkedListNode* &head)
{
    LinkedListNode* temp;

    if(head==nullptr)
    {

    }
    else if(head->nextNode==nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        temp = head;

        while(temp->nextNode->nextNode != nullptr)
        {
            temp = temp -> nextNode;
        }

        delete temp->nextNode->nextNode;
        temp->nextNode = nullptr;
    }
}

void remove_all_instances_of_item_from_list(LinkedListNode* &head, int value)
{
    LinkedListNode* temp;

    if(head==nullptr)
    {

    }
    else if(head->nextNode == nullptr && head->item == value)
    {
        delete head;
        head = nullptr;
    }
    else
    {

    }
}

//void clear_linked_list(int *head)
//{

//}
