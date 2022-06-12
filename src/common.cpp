#include "headers/common.hpp"

#include <fstream>

using namespace std;

namespace common{
    bool error = false;
    string error_log = "";
}

using namespace common;

string read_file(string path){
    string line;
    string ret;
    fstream file;

    file.open(path.c_str(), ios::in);
    if(!file.good()){
        error = true;
        error_log = "Failed to open file (path: \'" + path + "\')";
        return "";
    }

    while(getline(file, line))
        ret += line + "\n";
    
    file.close();
    return ret;
}

void write_file(string path, string text){
    fstream file;
    file.open(path.c_str(), ios::out);
    if(!file.good()){
        error = true;
        error_log = "Failed to open file (path: \'" + path + "\')";
        return;
    }
    file << text;
    file.close();
}

pair<string, bool> get_file_io_log(){
    return pair<string, bool>(error_log, error);
}

void clear_common(){
    error = false;
    error_log = "";
}