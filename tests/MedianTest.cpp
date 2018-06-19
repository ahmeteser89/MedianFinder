#include <gtest/gtest.h>

#include "../Median.h"

class MedianTest : public ::testing::Test
{};

TEST_F(MedianTest, medianTest)
{
    Median median;

    median.insert(3);
    EXPECT_EQ(3, median.median());
    median.insert(5);
    EXPECT_EQ(4, median.median());
    median.insert(8);
    EXPECT_EQ(5, median.median());
    median.insert(6);
    EXPECT_EQ(5.5, median.median());
    median.insert(9);
    EXPECT_EQ(6, median.median());
    median.insert(2);
    EXPECT_EQ(5.5, median.median());
    median.insert(1);
    EXPECT_EQ(5, median.median());
}