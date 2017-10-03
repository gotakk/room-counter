#include <gtest/gtest.h>

// TEST(PlnLoaderTest, Should) {
//   PlnLoader plnLoader;
//   Plan plan = plnLoader.load("./plans/plan1.pln");

//   testing::internal::CaptureStdout();
//   std::cout << plan;
//   std::string output = testing::internal::GetCapturedStdout();
//   std::string target = "##########\n#    #   #\n#    #   #\n#    #   #\n#    #   #\n#    #   #\n######   #\n#        #\n#        #\n#        #\n#        #\n#    #   #\n#    #   #\n##########\n";

//   EXPECT_EQ(target, output);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
