#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

#include	"Architect.h"

TEST(ArchitectTest, ShouldExpectOne) {
  Architect architect;
  Plan plan(3, 3, {1, 1, 1, 1, 0, 1, 1, 1, 1});

  EXPECT_EQ(1, architect.countRooms(plan));
}

TEST(ArchitectTest, ShouldExpectEight) {
  Architect architect;
  Plan plan(7, 5, {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1});

  EXPECT_EQ(8, architect.countRooms(plan));
}

TEST(ArchitectTest, ShouldExpectZero) {
  Architect architect;
  Plan plan(2, 2, {1, 1, 1, 1});

  EXPECT_EQ(0, architect.countRooms(plan));
}
