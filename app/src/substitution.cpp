#include <substitution.h>

using namespace std;

string encryptSubstitution(const string& input) {
    string output;
    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            output += char(((c - 'a' + 3) % 26) + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            output += char(((c - 'A' + 3) % 26) + 'A');
        } else {
            output += c; 
        }
    }
    return output;
}

string decryptSubstitution(const string& input){
    string output;
    for(char c: input){
        if(c >= 'a' && c <= 'z'){
            output += char(((c - 'a' - 3) % 26) + 'a');
        } else if(c >= 'A' && c <= 'Z'){
            output += char(((c - 'A' - 3) % 26) + 'A');
        } else {
            output += c;
        }
    }
}
