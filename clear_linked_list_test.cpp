#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(clearList,whenRemovingItemsFromBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    private_functions::clear_linked_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(clearList,whenRemovingItemsFromOneElementList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    private_functions::clear_linked_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(clearList,whenRemovingItemsFromLongerList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{4,nullptr};
    head->nextNode->nextNode = new LinkedListNode{8,nullptr};
    head->nextNode->nextNode->nextNode = new LinkedListNode{5,nullptr};
    private_functions::clear_linked_list(head);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}
