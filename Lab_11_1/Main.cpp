#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void CreateNumbersFile(const char* fname) {
    ofstream fout(fname, ios::binary);
    char ch;
    int num;
    do {
        cout << "Enter number: ";
        cin >> num;
        fout.write((char*)&num, sizeof(num));
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void WriteMinMaxToFile(const char* fname, int max_odd, int min_even) {
    ofstream fout(fname, ios::binary);
    fout.write((char*)&max_odd, sizeof(max_odd));
    fout.write((char*)&min_even, sizeof(min_even));
}

void ReadMinMaxFromFile(const char* fname, int& max_odd, int& min_even) {
    ifstream fin(fname, ios::binary);
    fin.read((char*)&max_odd, sizeof(max_odd));
    fin.read((char*)&min_even, sizeof(min_even));
}

int main() {
    const char* input_file = "numbers.bin";
    const char* output_file = "min_max.bin";

    CreateNumbersFile(input_file);

    ifstream fin(input_file, ios::binary);
    int num;
    int max_odd = numeric_limits<int>::min();
    int min_even = numeric_limits<int>::max();
    while (fin.read((char*)&num, sizeof(num))) {
        if (num % 2 != 0 && num > max_odd)
            max_odd = num;
        else if (num % 2 == 0 && num < min_even)
            min_even = num;
    }

    WriteMinMaxToFile(output_file, max_odd, min_even);

    int read_max_odd, read_min_even;
    ReadMinMaxFromFile(output_file, read_max_odd, read_min_even);

    cout << "Results:\n";
    cout << "Max odd number: " << read_max_odd << endl;
    cout << "Min even number: " << read_min_even << endl;

    return 0;
}