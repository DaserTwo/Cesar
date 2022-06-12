#pragma once

#include <string>

std::string cesar_base(std::string text, int shift);
std::string cesar_base_d(std::string text, int shift);

std::string cesar_base_bin(std::string text, int shift);
std::string cesar_base_bin_d(std::string text, int shift);

std::string cesar_inc(std::string text, int shift, int i);
std::string cesar_inc_d(std::string text, int shift, int i);

std::string cesar_inc_bin(std::string text, int shift, int i);
std::string cesar_inc_bin_d(std::string text, int shift, int i);

std::string cesar_pw(std::string text, int shift, std::string pw);
std::string cesar_pw_d(std::string text, int shift, std::string pw);

std::string cesar_pw_bin(std::string text, int shift, std::string pw);
std::string cesar_pw_bin_d(std::string text, int shift, std::string pw);

std::string cesar_inc_pw(std::string text, int shift, int i, std::string pw);
std::string cesar_inc_pw_d(std::string text, int shift, int i, std::string pw);

std::string cesar_inc_pw_bin(std::string text, int shift, int i, std::string pw);
std::string cesar_inc_pw_bin_d(std::string text, int shift, int i, std::string pw);