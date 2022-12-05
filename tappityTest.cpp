/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

// Testing length_difference
TEST(tappityTest, no_length_diff_same_word) {
	tappity tap("test");
	tap.entry("test");
	int actual = tap.length_difference();
	ASSERT_EQ(actual, 0);
}

TEST(tappityTest, no_length_diff_diff_word) {
	tappity tap("test");
	tap.entry("list");
	int actual = tap.length_difference();
	ASSERT_EQ(actual, 0);
}

TEST(tappityTest, longer_ref) {
	tappity tap("hello");
	tap.entry("list");
	int actual = tap.length_difference();
	ASSERT_EQ(actual, 1);
}

TEST(tappityTest, longer_input) {
	tappity tap("list");
	tap.entry("hello");
	int actual = tap.length_difference();
	ASSERT_EQ(actual, 1);
}

// Testing accuracy
TEST(tappityTest, exact_same_simple_word) {
	tappity tap("hello");
	tap.entry("hello");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 100.00);
}

TEST(tappityTest, exact_same_simple_phrase) {
	tappity tap("the quick brown fox jumps over the lazy dog");
	tap.entry("the quick brown fox jumps over the lazy dog");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 100.00);
}

TEST(tappityTest, exact_same_case_sensitive_word) {
	tappity tap("tEsTiNg");
	tap.entry("tEsTiNg");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 100.00);
}

TEST(tappityTest, exact_same_case_sensitive_phrase) {
	tappity tap("ThE qUicK bRowN fOx jUmps Over ThE lAzy Dog");
	tap.entry("ThE qUicK bRowN fOx jUmps Over ThE lAzy Dog");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 100.00);
}

TEST(tappityTest, simple_word_off_by_one) {
	tappity tap("h3ll");
	tap.entry("hell");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 75.00);
}

TEST(tappityTest, longer_ref_acc) {
	tappity tap("testing1");
	tap.entry("test");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 50.00);
}

TEST(tappityTest, longer_input_acc) {
	tappity tap("test");
	tap.entry("testing1");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 50.00);
}

TEST(tappityTest, exact_non_generic_char_match) {
	tappity tap("12$&()");
	tap.entry("12$&()");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 100.00);
}

TEST(tappityTest, no_entry) {
	tappity tap("test");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 0);
}

TEST(tappityTest, blank_ref_no_entry) {
	tappity tap("");
	double actual = tap.accuracy();
	ASSERT_EQ(actual, 100.00);
}