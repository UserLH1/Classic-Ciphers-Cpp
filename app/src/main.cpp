#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "substitution.h"
#include "transposition.h"

using namespace std;

static void printUsage() {
    cerr << "Usage:\n"
         << "  app -e <inputFile> -o <outputFile> [--sub] [--trans <key>]\n"
         << "  app -d <inputFile> -o <outputFile> [--sub] [--trans <key>]\n\n"
         << "Examples:\n"
         << "  app -e testcases/input1.txt -o testcases/output_substitution_enc.txt --sub\n"
         << "  app -d testcases/output_substitution_enc.txt -o testcases/output_substitution_dec.txt --sub\n"
         << "  app -e testcases/input1.txt -o testcases/output_transposition_enc.txt --trans 4\n"
         << "  app -d testcases/output_transposition_enc.txt -o testcases/output_transposition_dec.txt --trans 4\n";
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printUsage();
        return 1;
    }

    bool encrypt = false;
    bool decrypt = false;
    bool useSub = false;
    bool useTrans = false;
    int transKey = 0;

    string inputFile, outputFile;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-e") {
            encrypt = true;
        } else if (arg == "-d") {
            decrypt = true;
        } else if (arg == "-o" && i + 1 < argc) {
            outputFile = argv[++i];
        } else if (arg == "--sub") {
            useSub = true;
        } else if (arg == "--trans" && i + 1 < argc) {
            useTrans = true;
            transKey = stoi(argv[++i]);
        } else {
            inputFile = arg;
        }
    }

    if ((!encrypt && !decrypt) || inputFile.empty() || outputFile.empty()) {
        printUsage();
        return 1;
    }

    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Eroare la deschiderea fisierului de input: " << inputFile << endl;
        return 1;
    }
    string content((istreambuf_iterator<char>(fin)), (istreambuf_iterator<char>()));
    fin.close();

    string result;
    if (useSub) {
        if (encrypt) {
            result = encryptSubstitution(content);
        } else {
            result = decryptSubstitution(content);
        }
    } else if (useTrans) {
        if (encrypt) {
            result = encryptTransposition(content, transKey);
        } else {
            result = decryptTransposition(content, transKey);
        }
    } else {
        cerr << "Trebuie sa specifici fie --sub, fie --trans <key>.\n";
        return 1;
    }

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Eroare la deschiderea fisierului de output: " << outputFile << endl;
        return 1;
    }
    fout << result;
    fout.close();

    cout << "Operatie finalizata. Rezultat scris in: " << outputFile << endl;
    return 0;
}
