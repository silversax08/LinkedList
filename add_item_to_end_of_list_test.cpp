#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(addItemToEndOfList,whenAddingAnItemToBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5};
    private_functions::add_item_to_end_of_list(head,number);
    std::string expectedResult{"(5)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToEndOfList,whenAddingAnItemToAOneElementList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5};
    head = new LinkedListNode{3,nullptr};
    private_functions::add_item_to_end_of_list(head,number);
    std::string expectedResult{"(3 5)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToEndOfList,whenAddingAnItemToLongerList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode {7, nullptr};
    head->nextNode->nextNode = new LinkedListNode{7,nullptr};
    private_functions::add_item_to_end_of_list(head,number);
    std::string expectedResult{"(3 7 7 5)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(addItemToEndOfList,whenAddingMultipleItemsToLongerList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    int number{5}, number2{3}, number3{0};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode {7, nullptr};
    head->nextNode->nextNode = new LinkedListNode{7,nullptr};
    private_functions::add_item_to_end_of_list(head,number);
    private_functions::add_item_to_end_of_list(head,number2);
    private_functions::add_item_to_end_of_list(head,number3);
    std::string expectedResult{"(3 7 7 5 3 0)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}
