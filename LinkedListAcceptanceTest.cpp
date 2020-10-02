#include "gtest/gtest.h"
#include "LinkedList.hpp"

LinkedListNode* create_linked_list()
{
    LinkedListNode *head{nullptr};
    add_item_to_beginning_of_list(head,3);
    add_item_to_beginning_of_list(head,6);
    add_item_to_end_of_list(head,4);
    add_item_to_end_of_list(head,1);
    add_item_to_beginning_of_list(head,8);
    add_item_to_end_of_list(head,1);
    add_item_to_end_of_list(head,9);
    add_item_to_end_of_list(head,7);
    add_item_to_beginning_of_list(head,5);
    return head;
}

LinkedListNode* create_another_linked_list()
{
    LinkedListNode *head{nullptr};
    add_item_to_end_of_list(head,4);
    add_item_to_beginning_of_list(head,8);
    return head;
}
TEST(AcceptanceTest,WhenCreatingALinkedList_ExpectCorrectResults)
{
    LinkedListNode *head = create_linked_list();

    std::string expectedResult{"(5 8 6 3 4 1 1 9 7)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
    clear_linked_list(head);
}

TEST(AcceptanceTest,WhenCreatingAnotherLinkedList_ExpectCorrectResults)
{
    LinkedListNode *head = create_another_linked_list();

    std::string expectedResult{"(8 4)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
    clear_linked_list(head);
}

TEST(AcceptanceTest,WhenModifyingAnEmptyLinkedList_ExpectCorrectResults)
{
    LinkedListNode *head{nullptr};
    remove_all_instances_of_item_from_list(head,6);
    remove_first_item_in_list(head);
    remove_last_item_in_list(head);
    clear_linked_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
    clear_linked_list(head);
}

TEST(AcceptanceTest,WhenModifyingALinkedList_ExpectCorrectResults)
{
    LinkedListNode *head = create_linked_list();
    remove_all_instances_of_item_from_list(head,1);
    remove_first_item_in_list(head);
    remove_last_item_in_list(head);
    remove_first_item_in_list(head);
    remove_last_item_in_list(head);
    add_item_to_beginning_of_list(head,4);
    add_item_to_beginning_of_list(head,2);
    add_item_to_end_of_list(head,4);
    add_item_to_end_of_list(head,9);
    add_item_to_end_of_list(head,4);
    remove_all_instances_of_item_from_list(head,4);
    add_item_to_end_of_list(head,1);

    std::string expectedResult{"(2 6 3 9 1)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
    clear_linked_list(head);
}

TEST(AcceptanceTest,WhenClearingALinkedList_ExpectCorrectResults)
{
    LinkedListNode *head = create_linked_list();
    clear_linked_list(head);

    EXPECT_EQ(nullptr,head);

    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}
