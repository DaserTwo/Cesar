#include "headers/cesar.hpp"

using namespace std;

namespace cesar{
    char shift_char(char c, int s){
        char ret = c;
        if(c >= ' ' && c <= 'z'){
            int n = c;
            n += s;
            while(n > 'z')
                n -= 91;//'z' - ' ' + 1;
            ret = (char)n;
        }
        return ret;
    }

    char unshift_char(char c, int s){
        char ret = c;
        if(c >= ' ' && c <= 'z'){
            int n = c;
            n -= s;
            while(n < ' ')
                n += 91;
            ret = (char)n;
        }
        return ret;
    }

    char shift_char_bin(char c, int s){
        int n = c;
        n += s;
        while(n > 255)
            n -= 256;
        return (char)n;
    }

    char unshift_char_bin(char c, int s){
        int n = c;
        n -= s;
        while(n < 0)
            n += 256;
        return (char)n;
    }

    string delete_pw(string text, string pw){
        string buffer = "";
        string ret = "";
        for(int i = 0; i < text.length(); i++){
            if(text[i] == pw[0]){
                buffer = "";
                int si = i;
                for(int x = 0; i < text.length() && x < pw.length(); i++){
                    buffer += text[i];
                    x++;
                }
                if(buffer != pw){
                    i = si;
                }
            }
            ret += text[i];
        }
        if(!buffer.empty())
            ret == buffer;
        return ret;
    }
}

using namespace cesar;

string cesar_base(string text, int shift){
    string ret = "";
    for(char c : text)
        ret += shift_char(c, shift);
    return ret;
}

string cesar_base_d(string text, int shift){
    string ret = "";
    for(char c : text)
        ret += unshift_char(c, shift);
    return ret;
}

string cesar_base_bin(string text, int shift){
    string ret = "";
    for(char c : text)
        ret += shift_char_bin(c, shift);
    ret = ret.substr(0, ret.length());
    return ret;
}

string cesar_base_bin_d(string text, int shift){
    string ret = "";
    for(char c : text)
        ret += unshift_char_bin(c, shift);
    ret = ret.substr(0, ret.length() - 1);
    return ret;
}

string cesar_inc(string text, int shift, int i){
    string ret = "";
    for(char c : text){
        ret += shift_char(c, shift);
        shift += i;
    }
    return ret;
}

string cesar_inc_d(string text, int shift, int i){
    string ret = "";
    for(char c : text){
        ret += unshift_char(c, shift);
        shift += i;
    }
    return ret;
}

string cesar_inc_bin(string text, int shift, int i){
    string ret = "";
    for(char c : text){
        ret += shift_char_bin(c, shift);
        shift += i;
    }
    ret = ret.substr(0, ret.length());
    return ret;
}

string cesar_inc_bin_d(string text, int shift, int i){
    string ret = "";
    for(char c : text){
        ret += unshift_char_bin(c, shift);
        shift += i;
    }
    ret = ret.substr(0, ret.length() - 1);
    return ret;
}

string cesar_pw(string text, int shift, string pw){
    string pwx = cesar_base(pw, shift);
    string ret = "";
    for(char c : text){
        ret += shift_char(c, shift);
        if(c == pw[0] || rand()%2)
            ret += pwx;
    }
    return ret;
}

string cesar_pw_d(string text, int shift, string pw){
    return delete_pw(cesar_base_d(text, shift), pw);
}

string cesar_pw_bin(string text, int shift, string pw){
    string pwx = cesar_base_bin(pw, shift);
    string ret = "";
    for(char c : text){
        ret += shift_char_bin(c, shift);
        if(c == pw[0] || rand()%2)
            ret += pwx;
    }
    return ret;
}

string cesar_pw_bin_d(string text, int shift, string pw){
    return delete_pw(cesar_base_bin_d(text, shift), pw);
}

string cesar_inc_pw(string text, int shift, int i, string pw){
    string ret = "";
    for(char c : text){
        ret += shift_char(c, shift);
        shift += i;
        if(c == pw[0] || rand() % 2)
            ret += cesar_inc(pw, shift, i);
    }
    return ret;
}

string cesar_inc_pw_d(string text, int shift, int j, string pw){
    string buffer = "";
    string ret = "";
    for(int i = 0; i < text.length(); i++){
        char c = unshift_char(text[i], shift);
        if(c == pw[0]){
            buffer = "";
            int si = i;
            int ss = shift;
            for(int x = 0; i < text.length() && x < pw.length(); i++){
                buffer += unshift_char(text[i], shift);
                shift += j;
                x++;
            }
            if(buffer != pw)
                i = si;
            else
                c = unshift_char(text[i], ss);
            shift = ss;
        }
        ret += c;
        shift += j;
    }
    return ret;
}

string cesar_inc_pw_bin(string text, int shift, int i, string pw){
    string ret = "";
    for(char c : text){
        ret += shift_char_bin(c, shift);
        shift += i;
        if(c == pw[0] || rand() % 2)
            ret += cesar_inc_bin(pw, shift, i);
    }
    return ret;
}

string cesar_inc_pw_bin_d(string text, int shift, int j, string pw){
    string buffer = "";
    string ret = "";
    for(int i = 0; i < text.length(); i++){
        char c = unshift_char_bin(text[i], shift);
        if(c == pw[0]){
            buffer = "";
            int si = i;
            int ss = shift;
            for(int x = 0; i < text.length() && x < pw.length(); i++){
                buffer += unshift_char_bin(text[i], shift);
                shift += j;
                x++;
            }
            if(buffer != pw)
                i = si;
            else
                c = unshift_char_bin(text[i], ss);
            shift = ss;
        }
        ret += c;
        shift += j;
    }
    ret = ret.substr(0, ret.length() - 1);
    return ret;
}