#pragma once

#include <string>

typedef enum{
    CODE_SET =              0b0001000000000000,
    INPUT_SET =             0b0000100000000000,
    BINARY_SET =            0b0000010000000000,
    INCREMENTATION_SET =    0b0000001000000000,
    OUTPUT_SET =            0b0000000100000000,
    SHIFT_SET =             0b0000000010000000,
    PASSWORD_SET =          0b0000000001000000,
    LOAD_INCREMENTATION =   0b0000000000100000,
    LOAD_INPUT =            0b0000000000010000,
    LOAD_OUTPUT =           0b0000000000001000,
    LOAD_SHIFT =            0b0000000000000100,
    LOAD_PASSWORD =         0b0000000000000010,
    LOAD_FLAG =             0b0000000000000001,
    CLEAR_FLAG  =           0b0000000000000000
} flag;

#define LOAD_FLAG_MASK      0b0000000000111110

typedef struct{
    bool decode = false;
    bool input = false;
    bool binary = false;
    int increaentation = 0;
    int shift = 1;
    std::string password = "";
    std::string input_path = "";
    std::string output = "out";
} arg_input;