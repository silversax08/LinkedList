#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(removeInstancesofItemFromList,whenRemovingAnItemFromBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    remove_all_instances_of_item_from_list(head,3);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingAnItemFromAOneElementList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    remove_all_instances_of_item_from_list(head,3);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingNoItemsFromAList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{7,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 7)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingAnItemFromEndOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{6,nullptr};
    head->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 6 8 9)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingTwoItemsFromEndOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{6,nullptr};
    head->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 6 8)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingItemFromMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{6,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 6 8 9)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingTwoConsecutiveItemsFromMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 8 9)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingTwoSeparatedItemsFromMiddleOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(3 8 8 7 6)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingItemFromBeginningOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode = new LinkedListNode{2,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(8 2 8 9 7 6)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenMultipleItemsFromBeginningOfList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{1,nullptr};
    head->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode = new LinkedListNode{1,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{9,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode->nextNode->nextNode->nextNode->nextNode = new LinkedListNode{6,nullptr};
    remove_all_instances_of_item_from_list(head,1);
    std::string expectedResult{"(8 9 7 6)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

