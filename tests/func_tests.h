#ifndef FUNC_TESTS_H
#define FUNC_TESTS_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>

extern "C" {
#include "common.h"
#include "text.h"
}

TEST(shownum, Numbers) {
	text txt = create_text();
	append_line(txt, "1");
	append_line(txt, "2");
	append_line(txt, "3");	
	std::string test_string = "0 1\n1 2\n2 3\n";
	testing::internal::CaptureStdout();
	shownum(txt);	
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, test_string);
}

TEST(shownum, NoFile) {
	testing::internal::CaptureStderr();
	shownum(NULL);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	ASSERT_TRUE(output_length > 0);
}

TEST(mcf, MoveRight) {
	text txt = create_text();
	append_line(txt, "12345");
	std::string test_string = "1|2345\n";
	testing::internal::CaptureStdout();
	move_cursor(txt, 0, 0);
	mcf(txt);
	show(txt);	
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, test_string);
}

TEST(mcf, LineEnd) {
	text txt = create_text();
	append_line(txt, "12345");
	move_cursor(txt, 0, 4);
	testing::internal::CaptureStderr();
	mcf(txt);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	ASSERT_TRUE(output_length > 0);
}

TEST(mcf, NoFile) {
	testing::internal::CaptureStderr();
	mcf(NULL);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	ASSERT_TRUE(output_length > 0);
}

TEST(rh, RemoveFirstLine) {
	text txt = create_text();
	append_line(txt, "12345");
	append_line(txt, "67890");
	std::string test_string = "|67890\n";
	testing::internal::CaptureStdout();
	move_cursor(txt, 0, 0);
	rh(txt);	
	show(txt);
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, test_string);
}

TEST(rh, EmptyFile) {
	testing::internal::CaptureStderr();
	text txt = create_text();
	rh(txt);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	ASSERT_TRUE(output_length > 0);
}

TEST(rh, NoFile) {
	testing::internal::CaptureStderr();
	rh(NULL);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	ASSERT_TRUE(output_length > 0);
}

#endif // ROOTS_TEST_H