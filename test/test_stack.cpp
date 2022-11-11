#include "Stack.h"
#include <gtest.h>
//
TEST(Stack, can_create_Stack) {
	ASSERT_NO_THROW(Stack<int> st);
}

TEST(Stack, can_push) {
	Stack<int> st;
	ASSERT_NO_THROW(st.push(1));
}
TEST(Stack, can_pop_no_empty_Stack) {
	Stack<int> st;
	st.push(1);
	ASSERT_NO_THROW(st.pop());
}
TEST(Stack, cant_pop_empty_Stack) {
	Stack<int> st;
	ASSERT_ANY_THROW(st.pop());
}
TEST(Stack, top_and_push_work_correctly) {
	Stack<int> st;
	st.push(2);
	EXPECT_EQ(2, st.top());
}
TEST(Stack, getSize_work_correctly) {
	Stack<int> st;
	st.push(2);
	st.push(3);
	st.push(-1);
	st.push(0);
	EXPECT_EQ(4, st.getSize());
}
TEST(Stack, can_copy_another_Stack) {
	Stack<int> st1;
	st1.push(2);
	st1.push(1);
	ASSERT_NO_THROW(Stack<int>st2(st1));
}
TEST(Stack, copy_another_Stack_is_correctly) {
	Stack<int> st1;
	st1.push(2);
	st1.push(1);
	Stack<int> st2(st1);
	EXPECT_EQ(st2.top(), st1.top());
	EXPECT_EQ(st1.getSize(), st2.getSize());

	st1.pop(), st2.pop();
	EXPECT_EQ(st2.top(), st1.top());

}
TEST(Stack, operator_can_copy_another_Stack) {
	Stack<int> st1;
	st1.push(2);
	ASSERT_NO_THROW(Stack<int>st2(st1));
}
TEST(Stack, operator_copy_another_Stack_is_correctly) {
	Stack<int> st1, st2;
	st1.push(2);
	st2 = st1;
	EXPECT_EQ(st2.top(), st1.top());
	EXPECT_EQ(st1.getSize(), st2.getSize());
}
TEST(Stack, empty_work) {
	Stack<int> st1;
	ASSERT_NO_THROW(st1.empty());
}
TEST(Stack, empty_work_correctly_on_empty_Stack) {
	Stack<int> st1;
	EXPECT_EQ(1, st1.empty());
}
TEST(Stack, empty_work_correctly_on_no_empty_Stack) {
	Stack<int> st1;
	st1.push(1);
	EXPECT_EQ(0, st1.empty());
}