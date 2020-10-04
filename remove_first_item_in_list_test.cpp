#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(removeItemFromBeginningOfList,whenRemovingAnItemFromBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    private_functions::remove_first_item_in_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeItemFromBeginningOfList,whenRemovingAnItemFromListWithOneElement_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    private_functions::remove_first_item_in_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(removeItemFromBeginningOfList,whenRemovingAnItemFromListWithMultipleElements_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{7,nullptr};
    head->nextNode->nextNode = new LinkedListNode{6,nullptr};
    private_functions::remove_first_item_in_list(head);
    std::string expectedResult{"(7 6)"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}
