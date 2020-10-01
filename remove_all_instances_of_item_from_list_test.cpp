#include "gtest/gtest.h"
#include "LinkedList.hpp"

TEST(removeInstancesofItemFromList,whenRemovingAnItemFromBlankList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    remove_all_instances_of_item_from_list(head,3);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(removeInstancesofItemFromList,whenRemovingAnItemFromAOneElementListList_ExpectCorrectList)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    remove_all_instances_of_item_from_list(head,3);
    std::string expectedResult{"()"};
    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}
