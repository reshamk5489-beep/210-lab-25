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

int main() {
    int readVectorTime = readCodesToVector();
    int readListTime = readCodesToList();
    int readSetTime = readCodesToSet();

    cout << "Operation\tVector\tList\tSet" << endl;
    cout << "Read\t" << readVectorTime << "\t" << readListTime << "\t" << readSetTime << endl;

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
    auto start = high_resolution_clock::now();

    ifstream fin("Codes.txt");
    vector<string> codes;
    string code;

    while (fin >> code)
    {
        codes.push_back(code);
    }

    fin.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count() * 1000; // converting from milliseconds to microseconds
}

int readCodesToList()
{
    auto start = high_resolution_clock::now();

    ifstream fin("Codes.txt");
    list<string> codes;
    string code;

    while (fin >> code)
    {
        codes.push_back(code);
    }

    fin.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count() * 1000;
}

int readCodesToSet()
{
    auto start = high_resolution_clock::now();

    ifstream fin("Codes.txt");
    set<string> codes;
    string code;

    while (fin >> code)
    {
        codes.insert(code);
    }

    fin.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    return duration.count() * 1000;
}