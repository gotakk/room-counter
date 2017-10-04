#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

#include	"PlnLoader.h"

TEST(PlnLoaderTest, ShouldExpectPlan1InStdOut) {
  PlnLoader plnLoader;
  Plan plan = plnLoader.load("./plans/plan1.pln");

  testing::internal::CaptureStdout();
  std::cout << plan << std::flush;
  std::string output = testing::internal::GetCapturedStdout();
  std::string target = "##########\n#    #   #\n#    #   #\n#    #   #\n#    #   #\n#    #   #\n######   #\n#        #\n#        #\n#        #\n#        #\n#    #   #\n#    #   #\n##########\n";

  EXPECT_EQ(target, output);
}

TEST(PlnLoaderTest, ShouldExpectPlan2InStdOut) {
  PlnLoader plnLoader;
  Plan plan = plnLoader.load("./plans/plan2.pln");

  testing::internal::CaptureStdout();
  std::cout << plan;
  std::string output = testing::internal::GetCapturedStdout();
  std::string target = "#############\n##    #     #\n# #    #    #\n#  #    #   #\n#   #####   #\n#  #        #\n# #         #\n##          #\n#           #\n#           #\n#           #\n##          #\n#  ##########\n#         # #\n#############\n";

  EXPECT_EQ(target, output);
}

TEST(PlnLoaderTest, ShouldExpectPlan3InStdOut) {
  PlnLoader plnLoader;
  Plan plan = plnLoader.load("./plans/plan3.pln");

  testing::internal::CaptureStdout();
  std::cout << plan;
  std::string output = testing::internal::GetCapturedStdout();
  std::string target = "###\n# #\n###\n";

  EXPECT_EQ(target, output);
}

TEST(PlnLoaderTest, ShouldThrowInvalidArgumentException) {
  PlnLoader plnLoader;
  try {
    Plan plan = plnLoader.load("./plans/dfdsfsdfsdfd.pln");
    FAIL();
  } catch (std::invalid_argument const & exception) {
    EXPECT_STREQ("file not exists", exception.what());
  }
}
