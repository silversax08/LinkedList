#include "LinkedList.hpp"
#include <string>
#include <iostream>

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
    {
        head = new LinkedListNode{value,nullptr};
    }
    else
    {
        LinkedListNode* newFirstNode{new LinkedListNode{value,head}};
        head = newFirstNode;
    }
}

void add_item_to_end_of_list(LinkedListNode* &head, int value)
{
    if(head == nullptr)
    {
        head = new LinkedListNode{value,nullptr};
    }
    else
    {
        LinkedListNode* placeholder{head};
        while(placeholder->nextNode != nullptr)
        {
            placeholder = placeholder->nextNode;
        }
        placeholder->nextNode = new LinkedListNode{value,nullptr};
    }
}

void remove_first_item_in_list(LinkedListNode* &head)
{
    if(head == nullptr)
        return;
    else if(head->nextNode == nullptr)
    {
        clear_one_element_list(head);
    }
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
    {
        clear_one_element_list(head);
    }
    else
    {
        LinkedListNode* temp{head};
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
    LinkedListNode *origin{nullptr}, *originMinusOne{nullptr}, *landing{nullptr}, *placeholder{nullptr};

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
            if(head->nextNode != nullptr && head->item ==value)
            {
                while(head->item == value)
                {
                    if(head->nextNode == nullptr)
                    {
                        delete head->nextNode;
                        head = nullptr;
                        return;
                    }
                    else
                    {
                        placeholder = head->nextNode;
                        delete head;
                        head = placeholder;
                    }
                }
            }
            LinkedListNode* temp{head};
            while(temp->nextNode != nullptr)
            {
                originMinusOne = origin;
                origin = temp;

                if(temp->item != value)
                    temp = temp->nextNode;
                else
                {
                    while(temp->item == value)
                    {
                        if(temp->nextNode == nullptr)
                        {
                            delete temp->nextNode;
                            originMinusOne->nextNode = nullptr;
                            return;
                        }
                        else
                        {
                            landing = temp->nextNode;
                            delete originMinusOne->nextNode;
                            originMinusOne->nextNode = landing;
                            temp = originMinusOne->nextNode;
                        }
                    }
                }
            }
            if(temp->item == value)
            {
                delete temp->nextNode;
                origin->nextNode = nullptr;
            }

        }
    }

}

void clear_linked_list(LinkedListNode* &head)
{
    if(head == nullptr)
        return;
    else
    {
        while(head != nullptr)
        {
            remove_next_value(head);
        }
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
