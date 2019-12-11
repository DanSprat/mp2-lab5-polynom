#include <gtest.h>
#include "polynom.h"
#include "polynom.cpp"
TEST(polynom, can_create_polynom)
{
	ASSERT_NO_THROW(polynom(a));

}
TEST(polynom, can_set_polynom)
{
	polynom a;
	string b = "0.202xYz^2+x2yz3";
	ASSERT_NO_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_not_try_input_not_xyz)
{
	polynom a;
	string b = "TYz^2+x2yz3";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_too_large_max_exp)
{
	polynom a;
	ASSERT_ANY_THROW(a.setsize(1001));
}
TEST(polynom, throw_when_too_low_max_exp)
{
	polynom a;
	ASSERT_ANY_THROW(a.setsize(-1));
}
TEST(polynom, throw_when_try_input_polynom_with_2_ops_1_by_1)
{
	polynom a;
	string b = "x++";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_two_abr_in_monom)
{
	polynom a;
	string b = "xx+x";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_input_with_too_large_exp)
{
	polynom a;
	string b = "x1000y";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_not_int_exp)
{
	polynom a;
	string b = "x2.6";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, TEST1)
{
	polynom a;
	string b = "0..1x";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, TEST2)
{
	polynom a;
	string b = ".xyz";
	ASSERT_ANY_THROW(a.setPolynom(b));
}

TEST(polynom, TEST3)
{
	polynom a;
	string b = "x^^2";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, TEST4)
{
	polynom a;
	string b = "x.2";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, can_input_double_coeff)
{
	polynom a;
	string b = "0.2xyz";
	ASSERT_NO_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_affter_op_nothing)
{
	polynom a;
	string b = "x+";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_input_exp_after_number)
{
	polynom a;
	string b = "x2^+xyz";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, throw_when_ops_after_point)
{
	polynom a;
	string b = "0.-2x";
	ASSERT_ANY_THROW(a.setPolynom(b));
}
TEST(polynom, can_operator_ravno)
{
	string a("xyz");
	polynom b;
	b.setPolynom(a);
	ASSERT_NO_THROW(polynom c = b);
}
TEST(polynom, can_check_equal)
{
	string a("xyz");
	polynom b, c;
	b.setPolynom(a);
	c.setPolynom(a);
	EXPECT_EQ(1, b == c);
}
TEST(polynom, can_add_polynoms)
{
	string a("xyz");
	string d("2xyz");
	polynom b, c, e;
	b.setPolynom(a);
	c.setPolynom(a);
	e.setPolynom(d);
	EXPECT_EQ(1, e == b + c);
}
TEST(polynom, can_add_to_polynom)
{
	string a("xyz");
	string d("2xyz");
	polynom b, c, e;
	b.setPolynom(a);
	c.setPolynom(a);
	e.setPolynom(d);
	b += c;
	EXPECT_EQ(1, e == b);
}


TEST(polynom, can_mult_polynoms)
{
	string a = "xyz";
	string e = "x2y2z2";
	polynom b, c, d;
	b.setPolynom(a);
	c.setPolynom(a);
	d.setPolynom(e);
	EXPECT_EQ(1, d == b * c);
}
TEST(polynom, can_take_derivate)
{
	string a = "xyz";
	string e = "yz";
	polynom b, c;
	b.setPolynom(a);
	c.setPolynom(e);
	EXPECT_EQ(1, c == b.DerivativeBy('x'));
}
TEST(polynom, can_take_Integral)
{
	string a = "xyz";
	string e = "0.5x2yz";
	polynom b, c;
	b.setPolynom(a);
	c.setPolynom(e);
	EXPECT_EQ(1, c == b.IntegralBy('x'));
}
TEST(polynom, can_mult_on_double)
{
	string a("2.5xyz");
	polynom b;
	b.setPolynom(a);
	string c("xyz");
	polynom d;
	d.setPolynom(c);
	EXPECT_EQ(1, b == d * 2.5);
}
TEST(polynom, END)
{
	ASSERT_NO_THROW(true);
}