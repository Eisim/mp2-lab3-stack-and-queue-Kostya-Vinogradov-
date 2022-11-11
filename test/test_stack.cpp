#include "stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack)
{
  ASSERT_NO_THROW(Stack<int> s);
}
