#include <iostream>
#include <fstream>

using namespace std;

string read_file(string path){
    string line;
    string ret;
    fstream file;

    file.open(path.c_str(), ios::in);
    if(!file.good()){
        cerr << "ERROR: Failed to open file (path: \'" + path + "\')" << endl;
        return "";
    }

    while(getline(file, line))
        ret += line + "\n";
    
    file.close();
    return ret;
}

int main(int argc, char** argv){
    if(read_file(argv[1]) == read_file(argv[2]))
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
}