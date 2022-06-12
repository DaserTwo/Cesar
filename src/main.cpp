#include <iostream>
#include <fstream>
#include <vector>

#include "headers/arg_loader.hpp"
#include "headers/common.hpp"
#include "headers/cesar.hpp"

using namespace std;

vector<string> args;
pair<string, bool> error_log;
arg_input ai;
string input_text = "";
string output_text = "";

int main(int argc, char** argv){
    for(int i = 1; i < argc; i++)
        args.push_back(argv[i]);
    
    //loading args and checking for errors
    load_args(&args);
    error_log = get_arg_load_log();
    ai = get_arg_input();
    if(error_log.second){
        cerr << "ERROR: " << error_log.first << endl;
#ifdef DEBUG
        cerr << "VALUES:" << endl << "decode{" << ai.decode << 
                                     "}\ninput{" << ai.input << 
                                     "}\nbinary{" << ai.binary << 
                                     "}\nincrementation{" << ai.increaentation << 
                                     "}\nshift{" << ai.shift << 
                                     "}\npassword{" << ai.password << 
                                     "}\ninput_path{" << ai.input_path << 
                                     "}\noutput{" << ai.output << "}" << endl;
#endif
        return -1;
    }
    clear_loader();

    //loading input
    if(ai.input){
        cout << "Input (enter = termination):";
        getline(cin, input_text);
    } else{
        input_text = read_file(ai.input_path);
        error_log = get_file_io_log();
        if(error_log.second){
            cerr << "ERROR: " << error_log.first << endl;
#ifdef DEBUG
            cerr << "VALUES:" << endl << "decode{" << ai.decode << 
                                         "}\ninput{" << ai.input << 
                                         "}\nbinary{" << ai.binary << 
                                         "}\nincrementation{" << ai.increaentation << 
                                         "}\nshift{" << ai.shift << 
                                         "}\npassword{" << ai.password << 
                                         "}\ninput_path{" << ai.input_path << 
                                         "}\noutput{" << ai.output << "}" << endl;
#endif
            return -1;
        }
        clear_common();
    }

    //process input
    if(ai.binary){
        if(ai.decode){
            if(ai.password.empty()){
                if(ai.increaentation == 0)
                    output_text = cesar_base_bin_d(input_text, ai.shift);
                else
                    output_text = cesar_inc_bin_d(input_text, ai.shift, ai.increaentation);
            } else{
                if(ai.increaentation == 0)
                    output_text = cesar_pw_bin_d(input_text, ai.shift, ai.password);
                else
                    output_text = cesar_inc_pw_bin_d(input_text, ai.shift, ai.increaentation, ai.password);
            }
        } else{
            if(ai.password.empty()){
                if(ai.increaentation == 0)
                    output_text = cesar_base_bin(input_text, ai.shift);
                else
                    output_text = cesar_inc_bin(input_text, ai.shift, ai.increaentation);
            } else{
                if(ai.increaentation == 0)
                    output_text = cesar_pw_bin(input_text, ai.shift, ai.password);
                else
                    output_text = cesar_inc_pw_bin(input_text, ai.shift, ai.increaentation, ai.password);
            }
        }
    } else{
        if(ai.decode){
            if(ai.password.empty()){
                if(ai.increaentation == 0)
                    output_text = cesar_base_d(input_text, ai.shift);
                else
                    output_text = cesar_inc_d(input_text, ai.shift, ai.increaentation);
            } else{
                if(ai.increaentation == 0)
                    output_text = cesar_pw_d(input_text, ai.shift, ai.password);
                else
                    output_text = cesar_inc_pw_d(input_text, ai.shift, ai.increaentation, ai.password);
            }
        } else{
            if(ai.password.empty()){
                if(ai.increaentation == 0)
                    output_text = cesar_base(input_text, ai.shift);
                else
                    output_text = cesar_inc(input_text, ai.shift, ai.increaentation);
            } else{
                if(ai.increaentation == 0)
                    output_text = cesar_pw(input_text, ai.shift, ai.password);
                else
                    output_text = cesar_inc_pw(input_text, ai.shift, ai.increaentation, ai.password);
            }
        }
    }

    //write out output
    write_file(ai.output, output_text);
    error_log = get_file_io_log();
    if(error_log.second){
        cerr << "ERROR: " << error_log.first << endl;
#ifdef DEBUG
        cerr << "VALUES:" << endl << "decode{" << ai.decode << 
                                     "}\ninput{" << ai.input << 
                                     "}\nbinary{" << ai.binary << 
                                     "}\nincrementation{" << ai.increaentation << 
                                     "}\nshift{" << ai.shift << 
                                     "}\npassword{" << ai.password << 
                                     "}\ninput_path{" << ai.input_path << 
                                     "}\noutput{" << ai.output << "}" << endl;
#endif
        return -1;
    }
    return 0;
}