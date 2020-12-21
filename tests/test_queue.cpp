#include "../mp2-lab4-queue/tqueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> q());
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> q(3);
	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(TQueue, copied_queue_is_equel_to_source_one)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
		q.push(i);
	q.pop();
	q.pop();
	q.push(44);
	TQueue<int> q1(q);
	EXPECT_EQ(q, q1);
}

TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> q(5);
	q.push(3);
	TQueue<int> q1(q);
	EXPECT_NE(&q, &q1);
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue <int> q(2);
	for (int i = 0; i < 2; i++)
	{
		q.push(i);
	}
	q = q;
	EXPECT_EQ(0, q.pop());
	EXPECT_EQ(1, q.pop());
}

TEST(TQueue, can_assign_queues_of_equal_size)
{
	const int size = 2;
	TQueue <int> q(size), q1(size);

	for (int i = 0; i < size; i++)
	{
		q.push(i);
	}
	q1 = q;

	EXPECT_EQ(0, q1.pop());
	EXPECT_EQ(1, q1.pop());
}

TEST(TQueue, assign_operator_change_queue_size)
{
	const int size1 = 3, size2 = 5;
	TQueue <int> q1(size1), q2(size2);
	for (int i = 0; i < size1 - 1; i++)
	{
		q1.push(i);
	}
	q2 = q1;
	EXPECT_EQ(3, q2.GetMaxSize());
	EXPECT_EQ(2, q2.GetSize());
}

TEST(TQueue, can_assign_queues_of_different_size)
{

	const int size1 = 3, size2 = 5;
	TQueue <int> q1(size1), q2(size2);
	for (int i = 0; i < size1; i++)
	{
		q1.push(i);
	}
	q2 = q1;
	EXPECT_EQ(0, q2.pop());
	EXPECT_EQ(1, q2.pop());
}

TEST(TQueue, can_get_maxsize)
{
	TQueue<int> q(5);
	EXPECT_EQ(q.GetMaxSize(), 5);
}

TEST(TQueue, can_get_size)
{
	TQueue<int> q(5);
	for(int i = 0; i < 3; i++)
		q.push(1);
	EXPECT_EQ(q.GetSize(), 3);
}

TEST(TQueue, can_get_head)
{
	TQueue<int> q(5);
	for (int i = 0; i < 4; i++)
		q.push(1);
	for (int i = 0; i < 2; i++)
		q.pop();
	EXPECT_EQ(q.GetHead(), 2);
}

TEST(TQueue, cant_push_if_queue_is_full)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
		q.push(1);
	ASSERT_ANY_THROW(q.push(11));
}

TEST(TQueue, cant_pop_if_queue_is_empty)
{
	TQueue<int> q(3);
	ASSERT_ANY_THROW(q.pop());
}





