#include "queue.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_queue)
{
  ASSERT_NO_THROW(Queue<int> q);
}

