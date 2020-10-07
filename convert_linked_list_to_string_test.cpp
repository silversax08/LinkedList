#include "gtest/gtest.h"
#include "LinkedListFunctions.hpp"


TEST(convertLinkedListToStringTest,whenConvertingEmptyLinkedListToString_ExpectCorrectString)
{
    LinkedListNode *head{nullptr};

    std::string expectedResult{"()"};

    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(convertLinkedListToStringTest,whenConvertingAOneElementListToString_ExpectCorrectString)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};

    std::string expectedResult{"(3)"};

    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}

TEST(convertLinkedListToStringTest,whenConvertingLongerLinkedListToString_ExpectCorrectString)
{
    LinkedListNode *head{nullptr};
    head = new LinkedListNode{3,nullptr};
    head->nextNode = new LinkedListNode{5,nullptr};
    head->nextNode->nextNode = new LinkedListNode{7,nullptr};

    std::string expectedResult{"(3 5 7)"};

    EXPECT_EQ(expectedResult,private_functions::convert_linked_list_to_string(head));
}
