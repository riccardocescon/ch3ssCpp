// #ifdef TESTING
#include <gtest/gtest.h>

int somma(int a, int b);

int somma(int a, int b)
{
    return a + b;
}

TEST(sommaTest, TestSommaPositiva)
{
    EXPECT_EQ(somma(3, 5), 8);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// #endif