#pragma once

#include <string>
#include <vector>

std::string read_file(std::string path);
void write_file(std::string path, std::string text);
std::pair<std::string, bool> get_file_io_log();
void clear_common();