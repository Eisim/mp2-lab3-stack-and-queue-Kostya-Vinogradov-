#include "queue.h"
#include <gtest.h>

TEST(Queue, can_create_queue) {
	ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_push) {
	Queue<int> q;
	ASSERT_NO_THROW(q.push(1));
}
TEST(Queue, can_pop_no_empty_queue) {
	Queue<int> q;
	q.push(1);
	ASSERT_NO_THROW(q.pop());
}
TEST(Queue, cant_pop_empty_queue) {
	Queue<int> q;
	ASSERT_ANY_THROW(q.pop());
}
TEST(Queue, top_and_push_work_correctly) {
	Queue<int> q;
	q.push(2);
	EXPECT_EQ(2,q.top());
}
TEST(Queue, getSize_work_correctly) {
	Queue<int> q;
	q.push(2);
	q.push(3);
	q.push(-1);
	q.push(0);
	EXPECT_EQ(4, q.getSize());
}
TEST(Queue, can_copy_another_queue) {
	Queue<int> q1;
	q1.push(2);
	q1.push(1);
	ASSERT_NO_THROW(Queue<int>q2(q1));
}
TEST(Queue, copy_another_queue_is_correctly) {
	Queue<int> q1;
	q1.push(2);
	q1.push(1);
	Queue<int> q2(q1);
	EXPECT_EQ(q2.top(),q1.top());
	EXPECT_EQ(q1.getSize(), q2.getSize());

	q1.pop(), q2.pop();
	EXPECT_EQ(q2.top(), q1.top());
	
}
TEST(Queue, operator_can_copy_another_queue) {
	Queue<int> q1;
	q1.push(2);
	ASSERT_NO_THROW(Queue<int>q2(q1));
}
TEST(Queue, operator_copy_another_queue_is_correctly) {
	Queue<int> q1,q2;
	q1.push(2);
	q2 = q1;
	EXPECT_EQ(q2.top(), q1.top());
	EXPECT_EQ(q1.getSize(), q2.getSize());
}
TEST(Queue, empty_work) {
	Queue<int> q1;
	ASSERT_NO_THROW(q1.empty());
}
TEST(Queue, empty_work_correctly_on_empty_queue) {
	Queue<int> q1;
	EXPECT_EQ(1,q1.empty());
}
TEST(Queue, empty_work_correctly_on_no_empty_queue) {
	Queue<int> q1;
	q1.push(1);
	EXPECT_EQ(0, q1.empty());
}
TEST(Queue, after_move_lptr_and_repack_work_correctly) {
	Queue<int> q1;
	q1.push(1);
	q1.push(1);
	q1.pop();
	q1.pop();
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	for (int i = 2; i <= 5; i++) {
		EXPECT_EQ(i, q1.top());
		q1.pop();
	}
}