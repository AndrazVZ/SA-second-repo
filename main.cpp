#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<unsigned char> readInputFile(const string &filename) {
    ifstream file(filename);
    vector<unsigned char> numbers;
    if (!file) {
        cerr << "Napaka pri odpiranju vhodne datoteke!" << endl;
        exit(1);
    }
    string line;
    getline(file, line);
    file.close();

    stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(static_cast<unsigned char>(num));
    }
    return numbers;
}

void writeOutputFile(const string &filename, const vector<unsigned char> &numbers) {
    ofstream file(filename);
    if (!file) {
        cerr << "Napaka pri odpiranju izhodne datoteke!" << endl;
        exit(1);
    }
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) file << " ";
        file << static_cast<int>(numbers[i]);
    }
    file.close();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Uporaba: " << argv[0] << " <vhodna datoteka>" << endl;
        return 1;
    }

    vector<unsigned char> numbers = readInputFile(argv[1]);
    
    return 0;
}