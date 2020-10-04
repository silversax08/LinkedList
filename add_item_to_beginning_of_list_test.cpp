#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(addItemToBeginningOfList,whenAddingAnItemToBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5};
    private_functions::add_item_to_beginning_of_list(head,number);
    std::string expectedResult{"(5)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToBeginningOfList,whenAddingAnItemToAOneElementList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5};
    head = new LinkedListNode{3,nullptr};
    private_functions::add_item_to_beginning_of_list(head,number);
    std::string expectedResult{"(5 3)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToBeginningOfList,whenAddingAnItemToLongerList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode {7, nullptr};
    head->nextNode->nextNode = new LinkedListNode{7,nullptr};
    private_functions::add_item_to_beginning_of_list(head,number);
    std::string expectedResult{"(5 3 7 7)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToBeginningOfList,whenAddingMultipleItemsToLongerList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5}, number2{0}, number3{2};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode {7, nullptr};
    head->nextNode->nextNode = new LinkedListNode{7,nullptr};
    private_functions::add_item_to_beginning_of_list(head,number);
    private_functions::add_item_to_beginning_of_list(head,number2);
    private_functions::add_item_to_beginning_of_list(head,number3);
    std::string expectedResult{"(2 0 5 3 7 7)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToBeginningOfList,whenAddingMultipleItemsToEmptyList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5}, number2{0}, number3{2};
    private_functions::add_item_to_beginning_of_list(head,number);
    private_functions::add_item_to_beginning_of_list(head,number2);
    private_functions::add_item_to_beginning_of_list(head,number3);
    std::string expectedResult{"(2 0 5)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

