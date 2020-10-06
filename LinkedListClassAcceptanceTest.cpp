#include "gtest/gtest.h"
#include "LinkedList.hpp"

void create_linked_list(LinkedList &linkedList)
{
    linkedList.add_item_to_beginning_of_list(3);
    linkedList.add_item_to_beginning_of_list(6);
    linkedList.add_item_to_end_of_list(4);
    linkedList.add_item_to_end_of_list(1);
    linkedList.add_item_to_beginning_of_list(8);
    linkedList.add_item_to_end_of_list(1);
    linkedList.add_item_to_end_of_list(9);
    linkedList.add_item_to_end_of_list(7);
    linkedList.add_item_to_beginning_of_list(5);
}

void create_another_linked_list(LinkedList &linkedList)
{
    linkedList.add_item_to_end_of_list(4);
    linkedList.add_item_to_beginning_of_list(8);
}
TEST(LinkedListAcceptanceTest,WhenCreatingALinkedList_ExpectCorrectResults)
{
    LinkedList linkedList;
    create_linked_list(linkedList);

    std::string expectedResult{"(5 8 6 3 4 1 1 9 7)"};
    EXPECT_EQ(expectedResult,linkedList.convert_linked_list_to_string());
    linkedList.clear_linked_list();
}

TEST(LinkedListAcceptanceTest,WhenCreatingAnotherLinkedList_ExpectCorrectResults)
{
    LinkedList linkedList;
    create_another_linked_list(linkedList);

    std::string expectedResult{"(8 4)"};
    EXPECT_EQ(expectedResult,linkedList.convert_linked_list_to_string());
    linkedList.clear_linked_list();
}

TEST(LinkedListAcceptanceTest,WhenModifyingAnEmptyLinkedList_ExpectCorrectResults)
{
    LinkedList linkedList;
    linkedList.remove_all_instances_of_item_from_list(6);
    linkedList.remove_first_item_in_list();
    linkedList.remove_last_item_in_list();
    linkedList.clear_linked_list();
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,linkedList.convert_linked_list_to_string());
}

TEST(LinkedListAcceptanceTest,WhenModifyingALinkedList_ExpectCorrectResults)
{
    LinkedList linkedList;
    create_linked_list(linkedList);
    linkedList.remove_all_instances_of_item_from_list(1);
    linkedList.remove_first_item_in_list();
    linkedList.remove_last_item_in_list();
    linkedList.remove_first_item_in_list();
    linkedList.remove_last_item_in_list();
    linkedList.add_item_to_beginning_of_list(4);
    linkedList.add_item_to_beginning_of_list(2);
    linkedList.add_item_to_end_of_list(4);
    linkedList.add_item_to_end_of_list(9);
    linkedList.add_item_to_end_of_list(4);
    linkedList.remove_all_instances_of_item_from_list(4);
    linkedList.add_item_to_end_of_list(1);

    std::string expectedResult{"(2 6 3 9 1)"};
    EXPECT_EQ(expectedResult,linkedList.convert_linked_list_to_string());
    linkedList.clear_linked_list();
}

TEST(LinkedListAcceptanceTest,WhenClearingALinkedList_ExpectCorrectResults)
{
    LinkedList linkedList;
    create_linked_list(linkedList);
    linkedList.clear_linked_list();

    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,linkedList.convert_linked_list_to_string());
}
