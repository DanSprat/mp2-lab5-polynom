#include <gtest.h>
#include "TList.h"
TEST(lList,can_create_list)
{
	ASSERT_NO_THROW(Tlist <int> a);
}
TEST(Tlist, can_know_is_list_empty)
{
	Tlist <int> a;
	EXPECT_EQ(1, a.isEmpty());
}
