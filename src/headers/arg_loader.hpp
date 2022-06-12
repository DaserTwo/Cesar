#pragma once

#include <vector>
#include <string>

#include "def.hpp"

void load_args(std::vector<std::string>* args);
std::pair<std::string, bool> get_arg_load_log();
arg_input get_arg_input();
void clear_loader();