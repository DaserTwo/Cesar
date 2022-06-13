#include <iostream>
#include <fstream>
#include <cmath>

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
	string a = read_file(argv[1]);
	string b = read_file(argv[2]);
    if(a == b)
        cout << "Passed" << endl;
    else{
    	int i = 0;
    	while(a[i] == b[i] && a.length() > i && b.length() > i)
    		i++;
        cout << "Failed compatible=" << i << "/" << max(a.length(), b.length()) << " (" << ((float)i) / ((float)max(a.length(), b.length()))*100 << "%)" << endl;
    }
}
