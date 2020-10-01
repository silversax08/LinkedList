#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(removeItemFromEndOfList,whenRemovingAnItemFromBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    remove_last_item_in_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeItemFromEndOfList,whenRemovingAnItemFromAOneElementList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    remove_last_item_in_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeItemFromEndOfList,whenRemovingAnItemFromLongerList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{2,nullptr};
    head->nextNode->nextNode = new LinkedListNode{8,nullptr};
    remove_last_item_in_list(head);
    std::string expectedResult{"(3 2)"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}
