#include "gtest/gtest.h"
#include "LinkedList.hpp"


TEST(convertLinkedListToStringTest,whenConvertingEmptyLinkedListToString_ExpectCorrectString)
{
    LinkedListNode *head{nullptr};

    std::string expectedResult{"()"};

    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(convertLinkedListToStringTest,whenConvertingLinkedListToString_ExpectCorrectString)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{5,nullptr};
    head->nextNode->nextNode = new LinkedListNode{7,nullptr};

    std::string expectedResult{"(3 5 7)"};

    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}

TEST(convertLinkedListToStringTest,whenConvertingShortLinkedListToString_ExpectCorrectString)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};

    std::string expectedResult{"(3)"};

    EXPECT_EQ(expectedResult,convert_linked_list_to_string(head));
}
