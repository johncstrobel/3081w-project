#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};


//provided tests
TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

//GetDate test
TEST_F(DateTest, GetDateTest){//expect: yyyy-mm-dd
  ASSERT_EQ(first_day.GetDate(),"2018-09-04") << "first_day.GetDate() incorrect";
  ASSERT_EQ(first_day.GetDate().length(),10) << "first_day.GetDate().length() incorrect";

  ASSERT_EQ(last_day.GetDate(),"2018-12-11") << "last_day.GetDate() incorrect";
  ASSERT_EQ(last_day.GetDate().length(),10) << "last_day.GetDate().length() incorrect";
}

//GetUsDate test
TEST_F(DateTest,GetUsDateTest){//mm-dd-yyyy
  EXPECT_EQ(first_day.GetUsDate(),"09-04-2018") << "first_day not set up correctly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "last_day not set up correctly";
}

//DaysBetween test
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";

  EXPECT_EQ(first_day.DaysBetween(first_day), 0) << "Days between one date not calculated properly";
}

//+ operator test
TEST_F(DateTest, PlusOperatorTest){
  Date first_day_plus = first_day + 3;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-07") << "plus operator incorrect (standard)";

  first_day_plus = first_day + -1;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-03") << "plus operator incorrect (sneaky negative)";

  first_day_plus = first_day + 7.5;//should automatically truncate float
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-11") << "plus operator incorrect (float)";

  first_day_plus = first_day + 30;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-10-04") << "plus operator incorrect (add month)";
}

//- operator test
TEST_F(DateTest, MinusOperatorTest){
  Date first_day_minus = first_day - 1;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-03") << "minus operator incorrect (standard)";

  first_day_minus = first_day - (0-2);
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-06") << "minus operator incorrect (sneaky negative)";

  first_day_minus = first_day - 3.5;//should automatically truncate float
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-01") << "minus operator incorrect (float)";

  first_day_minus = first_day - 31;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-08-04") << "minus operator incorrect (subtract month)";
}

//constructor test: void
TEST_F(DateTest, ConstructorVoidTest){
  //these two should almost always get the same time, since time_t only 
  //stores down to the second and the CPU is faster than that
  Date current_date_actual;

  //the following is taken or inspired by the given code, 
  //written by Professor Amy Larson
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t); 
  Date current_date_expected(now->tm_year+1900,now->tm_mon+1,now->tm_mday);

  EXPECT_EQ(current_date_actual.GetDate(),current_date_expected.GetDate()) << "void constructor incorrect (standard)";
}

//constructor test: epoch
TEST_F(DateTest, ConstructorEpochTest){

}

//constructor test: 3 ints


/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
