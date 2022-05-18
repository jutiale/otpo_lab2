#ifndef FUNC_TESTS_H
#define FUNC_TESTS_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdio>

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
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
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
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(mcf, NoFile) {
	testing::internal::CaptureStderr();
	mcf(NULL);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(mcf, EmptyFile) {
	testing::internal::CaptureStderr();
	text txt = create_text();
	mcf(txt);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
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
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(rh, NoFile) {
	testing::internal::CaptureStderr();
	rh(NULL);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(save, SaveFile) {
	std::string filename = "test.txt";	
	text txt = create_text();
	append_line(txt, "12345");
	append_line(txt, "67890");	
	testing::internal::CaptureStderr();
	save(txt, (char *)filename.c_str());	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	ASSERT_EQ(output_length, 0);	
	std::ifstream f(filename);
	std::stringstream buffer;
	bool good = f.good();
	ASSERT_TRUE(good);
	buffer << f.rdbuf();
	f.close();
	std::string result = buffer.str();
	std::string test_string = "12345\n67890\n";	
	std::remove((char *)filename.c_str());
	ASSERT_EQ(result, test_string);
}

TEST(save, EmptyFile) {
	std::string filename = "test.txt";	
	testing::internal::CaptureStderr();
	text txt = create_text();
	save(txt, (char *)filename.c_str());	
	std::remove((char *)filename.c_str());
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(save, NoFile) {
	std::string filename = "test.txt";	
	testing::internal::CaptureStderr();
	save(NULL, (char *)filename.c_str());	
	std::remove((char *)filename.c_str());
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(save, FileOpenError) {
	testing::internal::CaptureStderr();
	text txt = create_text();
	save(txt, "/qwerty");	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(m, Move) {
	text txt = create_text();
	append_line(txt, "12");
	append_line(txt, "34");
	append_line(txt, "56");
	append_line(txt, "78");
	std::string test_string = "12\n34\n5|6\n78\n";
	testing::internal::CaptureStdout();
	move_cursor(txt, 2, 1);
	show(txt);	
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, test_string);
}

TEST(m, EmptyFile) {
	testing::internal::CaptureStderr();
	text txt = create_text();
	move_cursor(txt, 0, 0);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(m, NoFile) {
	testing::internal::CaptureStderr();
	move_cursor(NULL, 0, 0);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(m, InvalidLine) {
	testing::internal::CaptureStderr();
	text txt = create_text();
	append_line(txt, "1");
	append_line(txt, "2");
	move_cursor(txt, 999, 0);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}

TEST(m, InvalidPos) {
	testing::internal::CaptureStderr();
	text txt = create_text();
	append_line(txt, "1");
	append_line(txt, "2");
	move_cursor(txt, 0, 999);	
	std::string output = testing::internal::GetCapturedStderr();
	size_t output_length = output.length();
	bool gotAnyErrors = output_length > 0;
	ASSERT_TRUE(gotAnyErrors);
}
#endif // ROOTS_TEST_H
