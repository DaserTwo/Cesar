#include "headers/arg_loader.hpp"

using namespace std;

namespace loader{
    short flags = 0;
    arg_input input;

    bool error = false;
    string error_log = "";

    inline bool is_flag_set(flag f){
        return flags & f;
    }

    inline void set_flag(flag f){
        flags |= f;
    }

    inline void set_load_flag(flag f){
        set_flag(f);
        set_flag(LOAD_FLAG);
    }

    inline void unset_flag(flag f){
        flags &= ~f;
    }

    inline void unset_load_flag(flag f){
        unset_flag(f);
        unset_flag(LOAD_FLAG);
    }

    inline void set_error(string l){
        error = true;
        error_log = l;
    }
}

using namespace loader;

void load_args(vector<string>* args){
    for(auto arg : *args){
        if(is_flag_set(LOAD_FLAG)){
            switch(flags & LOAD_FLAG_MASK){
                case LOAD_INCREMENTATION:
                    input.increaentation = stoi(arg);
                    set_flag(INCREMENTATION_SET);
                    break;
                case LOAD_INPUT:
                    input.input_path = arg;
                    set_flag(INPUT_SET);
                    break;
                case LOAD_OUTPUT:
                    input.output = arg;
                    set_flag(OUTPUT_SET);
                    break;
                case LOAD_SHIFT:
                    input.shift = stoi(arg);
                    set_flag(SHIFT_SET);
                    break;
                case LOAD_PASSWORD:
                    input.password = arg;
                    set_flag(PASSWORD_SET);
                    break;
                default:
                    set_error("Loading ecxeption");
                    return;
            }
            unset_load_flag((flag)(flags & LOAD_FLAG_MASK));
        } else{
            if(arg[0] == '-'){
                if(arg.length() == 2){
                    if(arg == "-c"){
                        if(is_flag_set(CODE_SET)){
                            set_error("Code/Decode cannot be set more than once");
                            break;
                        }
                        set_flag(CODE_SET);
                    } else if(arg == "-d"){
                        if(is_flag_set(CODE_SET)){
                            set_error("Code/Decode cannot be set more than once");
                            break;
                        }
                        set_flag(CODE_SET);
                        input.decode = true;
                    } else if(arg == "-i"){
                        if(is_flag_set(INPUT_SET)){
                            set_error("Input cannot be set more than once");
                            break;
                        }
                        set_flag(INPUT_SET);
                        input.input = true;
                    } else if(arg == "-b"){
                        if(is_flag_set(BINARY_SET)){
                            set_error("Binary cannot be set more than once");
                            break;
                        }
                        set_flag(BINARY_SET);
                        input.binary = true;
                    } else if(arg == "-o"){
                        if(is_flag_set(OUTPUT_SET)){
                            set_error("Output cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_OUTPUT);
                    } else if(arg == "-n"){
                        if(is_flag_set(INCREMENTATION_SET)){
                            set_error("Incrementation cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_INCREMENTATION);
                    } else if(arg == "-s"){
                        if(is_flag_set(SHIFT_SET)){
                            set_error("Shift cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_SHIFT);
                    } else if(arg == "-p"){
                        if(is_flag_set(PASSWORD_SET)){
                            set_error("Pasword cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_PASSWORD);
                    } else{
                        set_error("Unknown arg: \'" + arg + "\'");
                        break;
                    }
                } else if(arg.length() > 2){
                    if(arg[1] != '-'){
                        set_error("Unexcepted arg: \'" + arg + "\'");
                        break;
                    }

                    if(arg == "--code"){
                        if(is_flag_set(CODE_SET)){
                            set_error("Code/Decode cannot be set more than once");
                            break;
                        }
                        set_flag(CODE_SET);
                    } else if(arg == "--decode"){
                        if(is_flag_set(CODE_SET)){
                            set_error("Code/Decode cannot be set more than once");
                            break;
                        }
                        set_flag(CODE_SET);
                        input.decode = true;
                    } else if(arg == "--input"){
                        if(is_flag_set(INPUT_SET)){
                            set_error("Input cannot be set more than once");
                            break;
                        }
                        set_flag(INPUT_SET);
                        input.input = true;
                    } else if(arg == "--binary"){
                        if(is_flag_set(BINARY_SET)){
                            set_error("Binary cannot be set more than once");
                            break;
                        }
                        set_flag(BINARY_SET);
                        input.binary = true;
                    } else if(arg == "--output"){
                        if(is_flag_set(OUTPUT_SET)){
                            set_error("Output cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_OUTPUT);
                    } else if(arg == "--incrementation"){
                        if(is_flag_set(INCREMENTATION_SET)){
                            set_error("Incrementation cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_INCREMENTATION);
                    } else if(arg == "--shift"){
                        if(is_flag_set(SHIFT_SET)){
                            set_error("Shift cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_SHIFT);
                    } else if(arg == "--password"){
                        if(is_flag_set(PASSWORD_SET)){
                            set_error("Pasword cannot be defined more than once");
                            break;
                        }
                        set_load_flag(LOAD_PASSWORD);
                    } else{
                        set_error("Unknown arg: \'" + arg + "\'");
                        break;
                    }
                } else{
                    set_error("Unexcepted arg: \'" + arg + "\'");
                    break;
                }
            } else{
                if(is_flag_set(INPUT_SET)){
                    set_error("Input cannot be defined more than once (on: \'" + arg + "\')");
                    break;
                }
                input.input_path = arg;
                set_flag(INPUT_SET);
            }
        }
    }

    if(is_flag_set(LOAD_FLAG)){
        string key_word = "";
        switch(flags & LOAD_FLAG_MASK){
            case LOAD_INCREMENTATION:
                key_word = "incrementation";
                break;
            case LOAD_INPUT:
                key_word = "input";
                break;
            case LOAD_OUTPUT:
                key_word = "output";
                break;
            case LOAD_SHIFT:
                key_word = "shift";
                break;
            case LOAD_PASSWORD:
                key_word = "password";
                break;
            default:
                key_word = "unknowed";
        }
        set_error("Excepted " + key_word + " input");
    }
}

pair<string, bool> get_arg_load_log(){
    return pair<string, bool>(error_log, error);
}

arg_input get_arg_input(){
    return input;
}

void clear_loader(){
    input = {false, false, false, 0, 1, "", "out"};
    flags = CLEAR_FLAG;

    error = false;
    error_log = "";
}