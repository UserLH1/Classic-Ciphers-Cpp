#include <transposition.h>
using namespace std;
//key=coloane: citim pe coloane texul si daca ramane spatiu liber punem un caracter special.

string encryptTransposition(const string& input, int key) {
    int n = input.size();
    int linii = (n + key - 1) / key; //scadem 1 sa nu avem linii in plus
    string padded = input;
    padded.append(linii * key - n, '\x1F'); 

    string output;
    output.reserve(linii * key);
    for (int col=0; col<key; col++) {
        for (int lin=0; lin<linii; lin++) {
           output.push_back(padded[lin * key + col]);
        }
    }
    return output;
}

string decryptTransposition(const string& input, int key) {
    int totalSize = input.size();
    int rows = totalSize / key;

    string output(totalSize, ' ');
    int index = 0;

    for (int col = 0; col < key; col++) {
        for (int row = 0; row < rows; row++) {
            output[row * key + col] = input[index++];
        }
    }

    while (!output.empty() && output.back() == '\x1F') {
        output.pop_back();
    }

    return output;
}