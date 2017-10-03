#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <vector>

#include	"Plan.h"

// je ne sais pas quoi mettre, ShouldReturnWidth2 ? ShouldReturn224 ? Split la fonction ? ...
TEST(PlanTest, CheckValues1) {
  Plan plan(2, 2, {1, 1, 1, 1});

  EXPECT_EQ(2, plan.getWidth());
  EXPECT_EQ(2, plan.getHeight());
  EXPECT_EQ(4, plan.getSize());
}

TEST(PlanTest, CheckValues2) {
  Plan plan(3, 3, {1, 1, 1, 1, 0, 1, 1, 1, 1});

  EXPECT_EQ(3, plan.getWidth());
  EXPECT_EQ(3, plan.getHeight());
  EXPECT_EQ(9, plan.getSize());
}

TEST(PlanTest, CheckValues3) {
  std::vector<int> v(10775138, 1);
  Plan plan(1294, 8327, v);

  EXPECT_EQ(1294, plan.getWidth());
  EXPECT_EQ(8327, plan.getHeight());
  EXPECT_EQ(10775138, plan.getSize());
}

TEST(PlanTest, CheckValues4) {
  std::vector<int> v(10775138, 1);
  Plan plan(8327, 1294, v);

  EXPECT_EQ(8327, plan.getWidth());
  EXPECT_EQ(1294, plan.getHeight());
  EXPECT_EQ(10775138, plan.getSize());
}

TEST(PlanTest, CheckAccessorMutator) {
  std::vector<int> v(12, 1);
  Plan plan(4, 3, v);

  EXPECT_EQ(1, plan.getCell(6));
  EXPECT_EQ(1, plan.getCell(2, 1));
  plan.setCell(6, 0);
  EXPECT_EQ(0, plan.getCell(6));
  EXPECT_EQ(0, plan.getCell(2, 1));

  EXPECT_EQ(1, plan.getCell(5));
  EXPECT_EQ(1, plan.getCell(1, 1));
  plan.setCell(1, 1, 0);
  EXPECT_EQ(0, plan.getCell(5));
  EXPECT_EQ(0, plan.getCell(1, 1));
}
