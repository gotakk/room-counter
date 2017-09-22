#include "gtest/gtest.h"

TEST_MAIN(MainTest, MethodBarDoesAbc) {
  EXPECT_EQ(0, f.Bar(input_filepath, output_filepath));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
