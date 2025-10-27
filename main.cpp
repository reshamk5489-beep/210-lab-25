#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
using namespace std;
using namespace std::chrono;

int readCodesToVector();
int readCodesToList();
int readCodesToSet();
void printRightJustified(string text, int width);

int main() {
    int readVectorTime = readCodesToVector();
    int readListTime = readCodesToList();
    int readSetTime = readCodesToSet();

    cout << "Operation\tVector\tList\tSet" << endl;
    printRightJustified("Read", 9);
    cout << "\t" << readVectorTime << "\t" << readListTime << "\t" << readSetTime << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

int readCodesToVector()
{
    ifstream fin("Codes.txt");
    vector<string> codes;
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codes.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000; // converting from milliseconds to microseconds
}

int readCodesToList()
{
    ifstream fin("Codes.txt");
    list<string> codes;
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codes.push_back(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000;
}

int readCodesToSet()
{
    ifstream fin("Codes.txt");
    set<string> codes;
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codes.insert(code);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    fin.close();

    return duration.count() * 1000;
}

void printRightJustified(string text, int width) 
{
    cout << setw(width) << text;
}