#include "gtest/gtest.h"
#include "LinkedListFunctions.hpp"

TEST(removeInstancesOfItemFromList,whenRemovingAnItemFromBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,3);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingAnItemFromAOneElementList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,3);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingNoItemsFromAList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{7,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 7)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingAnItemFromEndOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{6,nullptr};
    head->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 6 8 9)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingTwoItemsFromEndOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{6,nullptr};
    head->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 6 8)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingItemFromMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{6,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 6 8 9)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingTwoConsecutiveItemsFromMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 8 9)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingTwoSeparatedItemsFromMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 8 8 7 6)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingItemFromBeginningOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{2,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(8 2 8 9 7 6)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingMultipleItemsFromBeginningOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(8 9 7 6)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingWholeList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingItemsFromBeginningAndMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{2,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(8 2 9 7 6)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingItemsFromMiddleAndEndOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{9,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{2,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(9 8 2 9 7)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeInstancesOfItemFromList,whenRemovingItemsFromBeginningAndMiddleAndEndOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{2,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    private_functions::remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(8 2 9 7)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}
