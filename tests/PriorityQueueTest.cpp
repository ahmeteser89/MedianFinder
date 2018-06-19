#include <gtest/gtest.h>

#include "../PriorityQueue.h"

class PriorityQueueTest : public ::testing::Test
{
public:
    PriorityQueue<int> pq;
};

TEST_F(PriorityQueueTest, copyConstructor)
{
    pq.push(1);
    pq.push(2);
    pq.push(3);

    PriorityQueue<int> pqCopy(pq);

    EXPECT_EQ(3, pqCopy.top());
    pqCopy.pop();
    EXPECT_EQ(2, pqCopy.top());
    pqCopy.pop();
    EXPECT_EQ(1, pqCopy.top());
}

TEST_F(PriorityQueueTest, moveConstructor)
{
    pq.push(1);
    pq.push(2);
    pq.push(3);

    PriorityQueue<int> pqMove(std::move(pq));

    EXPECT_EQ(0, pq.size());

    EXPECT_EQ(3, pqMove.top());
    pqMove.pop();
    EXPECT_EQ(2, pqMove.top());
    pqMove.pop();
    EXPECT_EQ(1, pqMove.top());
}

TEST_F(PriorityQueueTest, copyAssignment)
{
    pq.push(1);
    pq.push(2);
    pq.push(3);

    PriorityQueue<int> pqAssign;
    pqAssign = pq;

    EXPECT_EQ(3, pqAssign.top());
    pqAssign.pop();
    EXPECT_EQ(2, pqAssign.top());
    pqAssign.pop();
    EXPECT_EQ(1, pqAssign.top());
}

TEST_F(PriorityQueueTest, moveAssignment)
{
    pq.push(1);
    pq.push(2);
    pq.push(3);

    PriorityQueue<int> pqAssign;
    pqAssign = std::move(pq);

    EXPECT_EQ(0, pq.size());

    EXPECT_EQ(3, pqAssign.top());
    pqAssign.pop();
    EXPECT_EQ(2, pqAssign.top());
    pqAssign.pop();
    EXPECT_EQ(1, pqAssign.top());
}

TEST_F(PriorityQueueTest, top)
{
    pq.push(1);
    EXPECT_EQ(1, pq.top());

    pq.push(2);
    EXPECT_EQ(2, pq.top());

    pq.push(3);
    EXPECT_EQ(3, pq.top());

    pq.push(0);
    EXPECT_EQ(3, pq.top());
}

TEST_F(PriorityQueueTest, push)
{
    pq.push(1);
    EXPECT_EQ(1, pq.size());
    EXPECT_EQ(1, pq.top());

    pq.push(2);
    EXPECT_EQ(2, pq.size());
    EXPECT_EQ(2, pq.top());

    pq.push(3);
    EXPECT_EQ(3, pq.size());
    EXPECT_EQ(3, pq.top());

    pq.push(0);
    EXPECT_EQ(4, pq.size());
    EXPECT_EQ(3, pq.top());
}

TEST_F(PriorityQueueTest, pop)
{
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(0);

    EXPECT_EQ(3, pq.top());
    pq.pop();
    EXPECT_EQ(2, pq.top());
    pq.pop();
    EXPECT_EQ(1, pq.top());
    pq.pop();
    EXPECT_EQ(0, pq.top());
}