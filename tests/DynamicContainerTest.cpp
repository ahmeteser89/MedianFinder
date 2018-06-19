#include <gtest/gtest.h>

#include "../DynamicContainer.h"

class DynamicContainerTest : public ::testing::Test
{};

TEST_F(DynamicContainerTest, constructorWithSize)
{
    DynamicContainer<int> dc(10);

    EXPECT_EQ(10, dc.size());
}

TEST_F(DynamicContainerTest, constructorWithInitialValue)
{
    DynamicContainer<int> dc(10, 5);

    EXPECT_EQ(10, dc.size());

    for (size_t i = 0; i < dc.size(); i++)
    {
        EXPECT_EQ(5, dc[i]);
    }
}

TEST_F(DynamicContainerTest, copyConstructor)
{
    DynamicContainer<int> dc(10, 5);

    DynamicContainer<int> dcCopy(dc);

    EXPECT_EQ(10, dcCopy.size());

    for (size_t i = 0; i < dcCopy.size(); i++)
    {
        EXPECT_EQ(5, dcCopy[i]);
    }
}

TEST_F(DynamicContainerTest, moveConstructor)
{
    DynamicContainer<int> dc(10, 5);

    DynamicContainer<int> dcMove(std::move(dc));

    EXPECT_EQ(0, dc.size());
    EXPECT_EQ(0, dc.capacity());

    EXPECT_EQ(10, dcMove.size());

    for (size_t i = 0; i < dcMove.size(); i++)
    {
        EXPECT_EQ(5, dcMove[i]);
    }
}

TEST_F(DynamicContainerTest, copyAssignment)
{
    DynamicContainer<int> dc(10, 5);

    DynamicContainer<int> dcCopy;
    dcCopy = dc;

    EXPECT_EQ(10, dcCopy.size());

    for (size_t i = 0; i < dcCopy.size(); i++)
    {
        EXPECT_EQ(5, dcCopy[i]);
    }
}

TEST_F(DynamicContainerTest, moveAssignment)
{
    DynamicContainer<int> dc(10, 5);

    DynamicContainer<int> dcMove;
    dcMove = std::move(dc);

    EXPECT_EQ(0, dc.size());
    EXPECT_EQ(0, dc.capacity());

    EXPECT_EQ(10, dcMove.size());

    for (size_t i = 0; i < dcMove.size(); i++)
    {
        EXPECT_EQ(5, dcMove[i]);
    }
}

TEST_F(DynamicContainerTest, accessOperator)
{
    DynamicContainer<int> dc(10, 5);

    dc[5] = 7;
    dc[8] = 9;

    EXPECT_EQ(7, dc[5]);
    EXPECT_EQ(9, dc[8]);
}

TEST_F(DynamicContainerTest, pushBack)
{
    DynamicContainer<int> dc(10, 5);

    dc.push_back(1);
    EXPECT_EQ(1, dc[10]);

    dc.push_back(2);
    EXPECT_EQ(2, dc[11]);

    dc.push_back(3);
    EXPECT_EQ(3, dc[12]);
}

TEST_F(DynamicContainerTest, popBack)
{
    DynamicContainer<int> dc(10, 5);

    dc.push_back(1);
    dc.push_back(2);
    dc.push_back(3);

    EXPECT_EQ(1, dc[10]);
    EXPECT_EQ(2, dc[11]);
    EXPECT_EQ(3, dc[12]);

    dc.pop_back();
    EXPECT_EQ(12, dc.size());
    EXPECT_EQ(2, dc[dc.size() - 1]);

    dc.pop_back();
    EXPECT_EQ(11, dc.size());
    EXPECT_EQ(1, dc[dc.size() - 1]);

    dc.pop_back();
    EXPECT_EQ(10, dc.size());
    EXPECT_EQ(5, dc[dc.size() - 1]);
}

TEST_F(DynamicContainerTest, reserve)
{
    DynamicContainer<int> dc(10, 5);

    dc.reserve(20);
    dc.push_back(9);

    EXPECT_EQ(20, dc.capacity());
    EXPECT_EQ(11, dc.size());
    EXPECT_EQ(5, dc[0]);
    EXPECT_EQ(5, dc[9]);
    EXPECT_EQ(9, dc[10]);
}

TEST_F(DynamicContainerTest, resize)
{
    DynamicContainer<int> dc(10, 5);

    dc.resize(20);
    dc[19] = 9;

    EXPECT_EQ(20, dc.size());
    EXPECT_EQ(5, dc[0]);
    EXPECT_EQ(5, dc[9]);
    EXPECT_EQ(9, dc[19]);
}

TEST_F(DynamicContainerTest, clear)
{
    DynamicContainer<int> dc(10, 5);

    dc.clear();

    EXPECT_EQ(0, dc.size());
    EXPECT_EQ(0, dc.capacity());
}